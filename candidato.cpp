#include "candidato.h"

using namespace std;

Candidato::Candidato(int &numero, string &nomeUrna, Partido &partido, tm dataNascimento, CandidatoEleito &candidatoEleito, 
                        Genero &genero, DestinacaoVotos &destVotos, SituacaoCandidato &situacao) : numero(numero), nomeUrna(nomeUrna), 
                        partido(partido), dataNascimento(dataNascimento), candidatoEleito(candidatoEleito), genero(genero),
                        destinacaoVotos(destVotos), situacao(situacao){
    
};

void Candidato::imprimeCandidato(){
    cout << "Numero: " << numero << endl;
    cout << "Nome: " << nomeUrna << endl;

    char data[80]; // Buffer para armazenar a data formatada
    std::strftime(data, 80, "%d/%m/%Y", &dataNascimento);
    
    std::cout << "Data de Nascimento: " << data << std::endl;
    partido.imprimePartido();
    cout << "Genero: " << (int)getGenero() << endl;
    cout << "Candidato Eleito: " << (int)getCandidatoEleito() << endl;
    cout << "Destinacao dos Votos: " << (int)getDestinacao() << endl;
    cout << "Situacao do Candidato: " << (int)getSituacao() << endl;
}

void Candidato::setQuantidadeVotos(int quantidadeVotos){
    if(situacao == SituacaoCandidato::DEFERIDO){
        this->quantidadeVotos += quantidadeVotos;
        //partido.setVotosNominais(quantidadeVotos);
    }
    else{
        if(destinacaoVotos == DestinacaoVotos::LEGENDA);
          //  partido.setLegendaPartido(quantidadeVotos);
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

int Candidato::getQuantidadeVotos(){
    return this->quantidadeVotos;
}
tm Candidato::getDataNascimento(){
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