#if !defined(PARTIDO_H)
#define PARTIDO_H

#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

class Candidato;

class Partido{
public:
    enum class Federacao : u_int8_t {TEM_FEDERACAO, NAO_TEM_FEDERACAO};
    Partido(){};
    Partido(int &numeroPartido, string &siglaPartido, Federacao &federacao);
    void setVotosNominais(int votosNominais);
    int getNumeroPartido();
    int getLegendaPartido();
    int getVotosNominais();
    string getSiglaPartido();
    Federacao getFederacao();
    list<Candidato> getCandidatos();
    void adicionaCandidato(Candidato &c);
    void setLegendaPartido(int legenda);
    int calculaEleitos();

    void imprimePartido();
    
private:
    int numeroPartido;
    string siglaPartido;
    int legendaPartido;
    int votosNominais;
    Federacao federacao;
    map<int, Candidato> candidatos;
};

Partido verificaPartido(int &numeroPartido, string &siglaPartido, Partido::Federacao &f, map <int,Partido> &partidos);

#endif // PARTIDO_H
