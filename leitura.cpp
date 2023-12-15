#include "leitura.h"
#include <stdio.h>
#include "partido.h"
#include "candidato.h"

using namespace std;

string iso_8859_1_to_utf8(string &str)
{
  // adaptado de: https://stackoverflow.com/a/39884120 :-)
  string strOut;
  for (string::iterator it = str.begin(); it != str.end(); ++it)
  {
    uint8_t ch = *it;
    if (ch < 0x80)
    {
      // já está na faixa ASCII (bit mais significativo 0), só copiar para a saída
      strOut.push_back(ch);
    }
    else
    {
      // está na faixa ASCII-estendido, escrever 2 bytes de acordo com UTF-8
      // o primeiro byte codifica os 2 bits mais significativos do byte original (ISO-8859-1)
      strOut.push_back(0b11000000 | (ch >> 6));
      // o segundo byte codifica os 6 bits menos significativos do byte original (ISO-8859-1)
      strOut.push_back(0b10000000 | (ch & 0b00111111));
    }
  }
  return strOut;
}

tm stringParaTM(const std::string& dataString) {
    std::tm tempo = {0};
    std::stringstream ss(dataString);
    char delimiter;
    ss >> tempo.tm_mday >> delimiter >> tempo.tm_mon >> delimiter >> tempo.tm_year;
    tempo.tm_mon -= 1; // Número do mês começa em zero (0 - janeiro, 11 - dezembro)
    tempo.tm_year -= 1900; // Ano deve ser contado a partir de 1900

    return tempo;
}

void leCandidatos(map<int, Candidato> &candidatos, map<int, Partido> &partidos, int tipoCandidato, string arquivo){
    ifstream inputStream(arquivo);
    string linha;
    getline(inputStream, linha);

    string cargo, numero, nome, numeroPartido, siglaPartido, numeroFederacao,dataNascimento;
    string genero, candidatoEleito, destinacaoVotos, situacaoCandidato;
    int i = 0;
    string linhaNao;

    while(getline(inputStream, linhaNao)){
        linha = iso_8859_1_to_utf8(linhaNao);

        istringstream linhaStream(linha);
        string coluna;
        i = 0;
        while(getline(linhaStream, coluna, ';')) {
            size_t found_first = coluna.find_first_of('"');
            size_t found_last = coluna.find_last_of('"');

            if (found_first != string::npos && found_last != string::npos && found_first != found_last) {
                // Remover as aspas do início e do fim da string
                coluna = coluna.substr(found_first + 1, found_last - found_first - 1);
            }

            switch(i++) {
                case 13:
                    cargo = coluna;
                    break;
                case 16:
                    numero = coluna;
                    break;
                case 18:
                    nome = coluna;
                    break;
                case 27:
                    numeroPartido = coluna;
                    break;
                case 28:
                    siglaPartido = coluna;
                    break;
                case 30:
                    numeroFederacao = coluna;
                    break;
                case 42:
                    dataNascimento = coluna;
                    break;
                case 45:
                    genero = coluna;
                    break;
                case 56:
                    candidatoEleito = coluna;
                    break;
                case 67:
                    destinacaoVotos = coluna;
                    break;
                case 68:
                    situacaoCandidato = coluna;
                    break;
                default:
                    break;
            }
        }

        Candidato::CandidatoEleito candEleito;
        Candidato::Genero gen;
        Candidato::DestinacaoVotos destVotos;
        Candidato::SituacaoCandidato stCandidato;
        Partido::Federacao temFederacao;

        if(stoi(candidatoEleito) == 2 || stoi(candidatoEleito) == 3){
            candEleito = Candidato::CandidatoEleito::ELEITO;
        }
        else{
            candEleito = Candidato::CandidatoEleito::NAO_ELEITO;
        }
        if(stoi(genero) == 2){
            gen = Candidato::Genero::MASCULINO;
        }
        else{
            gen = Candidato::Genero::FEMININO;
        }
        
        //string valido = iso_8859_1_to_utf8("Válido");

        if(!destinacaoVotos.compare("Válido (legenda)")){
            destVotos = Candidato::DestinacaoVotos::LEGENDA;
        }
        else if(!destinacaoVotos.compare("Válido")){
            destVotos = Candidato::DestinacaoVotos::NOMINAL;
        }
        else{
            destVotos = Candidato::DestinacaoVotos::INVALIDO;
        }
        if(stoi(situacaoCandidato) == 2 || stoi(situacaoCandidato) == 16){
            stCandidato = Candidato::SituacaoCandidato::DEFERIDO;
        }
        else{
            stCandidato = Candidato::SituacaoCandidato::INDEFERIDO;
        }
        if(stoi(numeroFederacao) == -1){
            temFederacao = Partido::Federacao::NAO_TEM_FEDERACAO;
        }
        else{
            temFederacao = Partido::Federacao::TEM_FEDERACAO;
        }


        tm data;
        data = stringParaTM(dataNascimento);

        int num = stoi(numero);
        int numPartido = stoi(numeroPartido);

        Partido p = verificaPartido(numPartido, siglaPartido, temFederacao, partidos, 0, 0);

        if(stoi(cargo) == tipoCandidato && destVotos != Candidato::DestinacaoVotos::INVALIDO){
            Candidato c(num, nome, p, data, candEleito, gen, destVotos, stCandidato, 0);
            candidatos.insert(make_pair(num, c));

            auto it = candidatos.find(c.getNumero());
            if (it != candidatos.end()) {
                it->second.imprimeCandidato();
                p.adicionaCandidato(it->second);
            }
            
        }
    }
    
    inputStream.close();
}

void leVotacao(map<int, Candidato> &candidatos, map<int, Partido> &partidos, int tipoCandidato, string arquivo){
    ifstream inputStream(arquivo);
    string linha;
    getline(inputStream, linha);

    string cargo, destinoVotos, qtdVotos;
    int candidatoVotado;
    string linhaNao;

    while(getline(inputStream, linhaNao)){
        int i = 0;
        linha = iso_8859_1_to_utf8(linhaNao);

        istringstream linhaStream(linha);
        string coluna;
        while(getline(linhaStream, coluna, ';')) {
            size_t found_first = coluna.find_first_of('"');
            size_t found_last = coluna.find_last_of('"');

            if (found_first != string::npos && found_last != string::npos && found_first != found_last) {
                // Remover as aspas do início e do fim da string
                coluna = coluna.substr(found_first + 1, found_last - found_first - 1);
            }

            switch(i++) {
                case 17:
                    cargo = coluna;
                    break;
                case 19:
                    if(stoi(cargo) == tipoCandidato){
                        destinoVotos = coluna;
                        candidatoVotado = stoi(destinoVotos);
                    }
                    break;
                case 21:
                    if(stoi(cargo) == tipoCandidato && (candidatoVotado < 95 ||candidatoVotado > 98)){
                        qtdVotos = coluna;
                        if(candidatos.count(candidatoVotado) != 0){
                            auto it = candidatos.find(candidatoVotado);
                            if(it != candidatos.end()){
                                int qtdVotosInt = stoi(qtdVotos);
                                it->second.setQuantidadeVotos(qtdVotosInt, partidos);
                            }
                        }
                        else if(partidos.count(candidatoVotado) != 0){
                            auto it = partidos.find(candidatoVotado);
                            if(it != partidos.end()){
                                int qtdVotosInt = stoi(qtdVotos);
                                it->second.setLegendaPartido(qtdVotosInt);
                            }
                        }
                    }
                    break;
                
                default:
                    break;
            }
        }
    }
}