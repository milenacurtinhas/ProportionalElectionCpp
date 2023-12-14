#include "partido.h"

using namespace std;

Partido::Partido(int numeroPartido, string siglaPartido, string nomePartido, Federacao federacao) : 
                numeroPartido(numeroPartido), siglaPartido(siglaPartido), nomePartido(nomePartido), federacao(federacao){}

void Partido::imprimePartido(){
    cout << "Numero do Partido: " << numeroPartido << endl;
    cout << "Sigla do Partido: " << siglaPartido << endl;
    cout << "Nome do Partido: " << nomePartido << endl;
    //cout << "Numero da Federacao: " << federacao << endl;
}

void Partido::setVotosNominais(int votosNominais){
    this->votosNominais += votosNominais;
}

int Partido::getNumeroPartido(){
    return this->numeroPartido;
}

string Partido::getNomePartido(){
    return this->nomePartido;
}

int Partido::getLegendaPartido(){
    return this->legendaPartido;
}

int Partido::getVotosNominais(){
    return this->votosNominais;
}

string Partido::getSiglaPartido(){
    return this->siglaPartido;
}

Partido::Federacao Partido::getFederacao(){
    return this->federacao;
}

Partido::Partido Partido::verificaPartido(int numeroPartido, String siglaPartido, String nomePartido, Federacao f, unordered_map <Integer,Partido> partidos){
    if(partidos.find(numeroPartido))
        return partidos[numeroPartido];
    else{
        Partido p(numeroPartido, siglaPartido, nomePartido, f);
        partidos.insert(pair<int, Partido>(numeroPartido, p));

        return p;
    } 
}