#include "partido.h"
#include "candidato.h"

using namespace std;

Partido::Partido(int &numeroPartido, string &siglaPartido, Federacao &federacao, int votosNominais = 0, int legendaPartido = 0) : 
                numeroPartido(numeroPartido), siglaPartido(siglaPartido), federacao(federacao){}

void Partido::imprimePartido(){
    cout << "Numero do Partido: " << numeroPartido << endl;
    cout << "Sigla do Partido: " << siglaPartido << endl;
    cout << "Numero da Federacao: " << (int)federacao << endl;
}

void Partido::setVotosNominais(int &votos){
    this->votosNominais += votos;
}

int Partido::getNumeroPartido() const{
    return this->numeroPartido;
}

int Partido::getLegendaPartido() const{
    return this->legendaPartido;
}

int Partido::getVotosNominais() const{
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

void Partido::setLegendaPartido(int &legenda){
    this->legendaPartido += legenda;
}

int Partido::calculaEleitos(){
    int count = 0;

    for(auto it = candidatos.begin(); it != candidatos.end(); ++it){
        cout << "eleito" << endl;
        if(it->second.getCandidatoEleito() == Candidato::CandidatoEleito::ELEITO){
            
            cout << "eleito" << endl;
            count++;
        }          
            
    }

    return count;
}

Partido &verificaPartido(int &numeroPartido, string &siglaPartido, Partido::Federacao &f, map <int,Partido> &partidos, int votosNominais, int legendaPartido){
    auto it = partidos.find(numeroPartido);
    if (it != partidos.end()) {
        return it->second; // Retorna o partido se já existir no mapa
    } else {
        Partido p(numeroPartido, siglaPartido, f, votosNominais, legendaPartido);
        partidos.insert(make_pair(numeroPartido, p));
        auto it = partidos.find(numeroPartido);
        return it->second; // Cria e retorna o novo partido
    } 
}

bool compararPartidos(const Partido& partido1, const Partido& partido2) {
    int votos1 = partido1.getLegendaPartido() + partido1.getVotosNominais();
    int votos2 = partido2.getLegendaPartido() + partido2.getVotosNominais();

    if (votos1 != votos2) {
        return votos2 < votos1; // Ordena pela soma dos votos decrescente
    } else {
        return partido1.getNumeroPartido() < partido2.getNumeroPartido(); // Em caso de empate, compara pelos números do partido
    }
}
