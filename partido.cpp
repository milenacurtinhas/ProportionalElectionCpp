#include "partido.h"
#include "candidato.h"

using namespace std;

Partido::Partido(int &numeroPartido, string &siglaPartido, Federacao &federacao) : 
                numeroPartido(numeroPartido), siglaPartido(siglaPartido), federacao(federacao){}

void Partido::imprimePartido(){
    cout << "Numero do Partido: " << numeroPartido << endl;
    cout << "Sigla do Partido: " << siglaPartido << endl;
    cout << "Numero da Federacao: " << (int)federacao << endl;
}

void Partido::setVotosNominais(int votosNominais){
    this->votosNominais += votosNominais;
}

int Partido::getNumeroPartido(){
    return this->numeroPartido;
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

list<Candidato> Partido::getCandidatos(){
    list<Candidato> listaCandidatos;

    for(auto it = candidatos.begin(); it != candidatos.end(); ++it){
        listaCandidatos.push_back(it->second);
    }

    return listaCandidatos;
}

void Partido::adicionaCandidato(Candidato &candidato){
    candidatos.insert(make_pair(candidato.getNumero(), candidato));
}

void Partido::setLegendaPartido(int legenda){
    this->legendaPartido += legenda;
}

int Partido::calculaEleitos(){
    int count = 0;

    for(auto it = candidatos.begin(); it != candidatos.end(); ++it){
        if(it->second.getCandidatoEleito() == Candidato::CandidatoEleito::ELEITO)
            count++;
    }

    return count;
}

Partido verificaPartido(int &numeroPartido, string &siglaPartido, Partido::Federacao &f, map <int,Partido> &partidos){
    auto it = partidos.find(numeroPartido);
    if (it != partidos.end()) {
        return it->second; // Retorna o partido se já existir no mapa
    } else {
        Partido p(numeroPartido, siglaPartido, f);
        partidos.insert(make_pair(numeroPartido, p));

        return p; // Cria e retorna o novo partido
    } 
}