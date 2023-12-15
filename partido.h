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
    Partido(int numeroPartido, string &siglaPartido,  int votosNominais, int legendaPartido, Federacao federacao);
    void setVotosNominais(int &votos);
    int getNumeroPartido() const;
    int getLegendaPartido() const;
    int getVotosNominais() const;
    string getSiglaPartido();
    Federacao getFederacao();
    list<Candidato> getCandidatos();
    void adicionaCandidato(Candidato &c);
    void setLegendaPartido(int &legenda);
    int calculaEleitos();

    void imprimePartido();
    
private:
    int numeroPartido;
    string siglaPartido;
    int legendaPartido;
    int votosNominais;
    Federacao federacao;
    list<Candidato> candidatos;
};

Partido &verificaPartido(int &numeroPartido, string &siglaPartido, Partido::Federacao &f, map <int,Partido> &partidos, int votosNominais, int legendaPartido);
bool compararPartidos(const Partido& partido1, const Partido& partido2);

#endif // PARTIDO_H
