#include "leCandidatos.h"
#include "data.h"

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

void LeCandidato::leitura(/*map<int, Candidato> candidatos, map<int, Partido> partidos, int tipoCandidato, string arquivo*/){
    ifstream inputStream("teste.csv");
    string linha;
    getline(inputStream, linha);

    string cargo, numero, nome, numeroPartido, siglaPartido, nomePartido, numeroFederacao,dataNascimento;
    string genero, candidatoEleito, destinacaoVotos, situacaoCandidato;
    int i = 0;
    
    while(getline(inputStream, linha)){
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
                case 13:
                    cargo = iso_8859_1_to_utf8(coluna);
                    break;
                case 16:
                    numero = iso_8859_1_to_utf8(coluna);
                    break;
                case 17:
                    nome = iso_8859_1_to_utf8(coluna);
                    break;
                case 27:
                    numeroPartido = iso_8859_1_to_utf8(coluna);
                    break;
                case 28:
                    siglaPartido = iso_8859_1_to_utf8(coluna);
                    break;
                case 30:
                    numeroFederacao = iso_8859_1_to_utf8(coluna);
                    break;
                case 42:
                    dataNascimento = iso_8859_1_to_utf8(coluna);
                    break;
                case 45:
                    genero = iso_8859_1_to_utf8(coluna);
                    break;
                case 56:
                    candidatoEleito = iso_8859_1_to_utf8(coluna);
                    break;
                case 67:
                    destinacaoVotos = iso_8859_1_to_utf8(coluna);
                    break;
                case 68:
                    situacaoCandidato = iso_8859_1_to_utf8(coluna);
                    break;
                default:
                    break;
            }
        }

        Candidato::CandidatoEleito candEleito;
        Candidato::Genero gen;
        Candidato::DestinacaoVotos destVotos;
        Candidato::SituacaoCandidato stCandidato;

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
        tm data;
        data = stringParaTM(dataNascimento);

        int num = stoi(numero);
        Candidato c(num, nome, /*new Partido(),*/ data, candEleito, gen, destVotos, stCandidato);
        c.imprimeCandidato();
    }
    inputStream.close();
}