#include "partido.h"
#include "candidato.h"

using namespace std;

Partido::Partido(int numeroPartido, string &siglaPartido, int legendaPartido, int votosNominais,  Federacao federacao) : 
                numeroPartido(numeroPartido), siglaPartido(siglaPartido), legendaPartido(legendaPartido), votosNominais(votosNominais),  federacao(federacao){}

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

    return candidatos;
}

void Partido::adicionaCandidato(Candidato &candidato){
    candidatos.push_back(candidato);
}

void Partido::setLegendaPartido(int &legenda){
    this->legendaPartido += legenda;
}

int Partido::calculaEleitos(){
    int count = 0;

    for(Candidato &candidato : candidatos){
        if(candidato.getCandidatoEleito() == Candidato::CandidatoEleito::ELEITO){
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
        Partido p(numeroPartido, siglaPartido, votosNominais, legendaPartido, f);
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
