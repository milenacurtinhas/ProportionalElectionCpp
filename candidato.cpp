#include "candidato.h"

using namespace std;

Candidato::Candidato(int &numero, string &nomeUrna, Partido &partido, tm dataNascimento, CandidatoEleito &candidatoEleito, 
                        Genero &genero, DestinacaoVotos &destVotos, SituacaoCandidato &situacao, int quantidadeVotos = 0) : numero(numero), nomeUrna(nomeUrna), 
                        partido(partido), dataNascimento(dataNascimento), candidatoEleito(candidatoEleito), genero(genero),
                        destinacaoVotos(destVotos), situacao(situacao), quantidadeVotos(quantidadeVotos){
    
};

void Candidato::imprimeCandidato(){
    cout << "Numero: " << numero; //<< endl;
    cout << "Nome: " << nomeUrna << endl;

    //char data[80]; // Buffer para armazenar a data formatada
    //std::strftime(data, 80, "%d/%m/%Y", &dataNascimento);
    
    //std::cout << "Data de Nascimento: " << data << std::endl;
    //partido.imprimePartido();
    //cout << "Genero: " << (int)getGenero() << endl;
    cout << "Candidato Eleito: " << (int)getCandidatoEleito() << endl;
    //cout << "Destinacao dos Votos: " << (int)getDestinacao() << endl;
   // cout << "Situacao do Candidato: " << (int)getSituacao() << endl;
    cout << "Quantidade votos" << quantidadeVotos << endl;
}

void Candidato::setQuantidadeVotos(int &votos, map<int, Partido> &partidos){
    auto it = partidos.find(partido.getNumeroPartido());
    if(situacao == SituacaoCandidato::DEFERIDO){
        quantidadeVotos += votos;
        
        if (it != partidos.end()) {
            it->second.setVotosNominais(votos); // Retorna o partido se já existir no mapa
        }
    }
    else{
        if(destinacaoVotos == DestinacaoVotos::LEGENDA){
            if (it != partidos.end()) {
                it->second.setLegendaPartido(votos);
            }
        }
    }
}

int Candidato::getNumero(){
    return this->numero;
}

string Candidato::getNomeUrna(){
    return this->nomeUrna;
}

Partido Candidato::getPartido(){
    return this->partido;
}

Candidato::CandidatoEleito Candidato::getCandidatoEleito(){
    return this->candidatoEleito;
}

int Candidato::getQuantidadeVotos() const{
    return this->quantidadeVotos;
}
tm Candidato::getDataNascimento() const{
    return this->dataNascimento;
}

Candidato::SituacaoCandidato Candidato::getSituacao(){
    return this->situacao;
}

Candidato::Genero Candidato::getGenero(){
    return this->genero;
}

Candidato::DestinacaoVotos Candidato::getDestinacao(){
    return this->destinacaoVotos;
}

bool compararCandidatos(const Candidato& candidato1, const Candidato& candidato2) {
    if (candidato1.getQuantidadeVotos() != candidato2.getQuantidadeVotos()) {
        return candidato1.getQuantidadeVotos() > candidato2.getQuantidadeVotos(); // Ordena pela quantidade de votos decrescente
    } else {
         // Obtém as datas de nascimento dos candidatos
        tm dataNascimento1 = candidato1.getDataNascimento();
        tm dataNascimento2 = candidato2.getDataNascimento();

        // Calcula a representação de tempo (time_t) para cada data de nascimento
        time_t timeDataNascimento1 = mktime(&dataNascimento1);
        time_t timeDataNascimento2 = mktime(&dataNascimento2);

        // Compara os tempos de nascimento para ordenação
        return timeDataNascimento1 > timeDataNascimento2;
    }
}