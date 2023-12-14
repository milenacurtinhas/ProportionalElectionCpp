#include "partido.h"

using namespace std;

Partido::Partido(int &numeroPartido, string &siglaPartido, string &nomePartido, Federacao &federacao) : 
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

void Partido::adicionaCandidato(Candidato &candidato){
    candidatos.insert(candidato.getNumero, candidato);
}

Partido verificaPartido(int &numeroPartido, string &siglaPartido,string &nomePartido, Federacao &f, map <int,Partido> &partidos){
    auto it = partidos.find(numeroPartido);
    if (it != partidos.end()) {
        return it->second; // Retorna o partido se já existir no mapa
    } else {
        Partido p(numeroPartido, siglaPartido, nomePartido, f);
        partidos.insert(make_pair(numeroPartido, p));

        return p; // Cria e retorna o novo partido
    } 
}