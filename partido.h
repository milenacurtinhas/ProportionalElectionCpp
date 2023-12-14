#if !defined(PARTIDO_H)
#define PARTIDO_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Partido{
public:
    enum class Federacao : u_int8_t {TEM_FEDERACAO, NAO_TEM_FEDERACAO};
    Partido(){};
    Partido(int numeroPartido, string siglaPartido, string nomePartido, Federacao federacao);
    void setVotosNominais(int votosNominais);
    int getNumeroPartido();
    string getNomePartido();
    int getLegendaPartido();
    int getVotosNominais();
    string getSiglaPartido();
    Federacao getFederacao();
    //List<Candidato> getCandidatos();
    Partido verificaPartido(int numeroPartido, String siglaPartido, String nomePartido, Federacao f, map<int, Partido> partidos);
    /*void adicionaCandidatos(Candidato c);
    void setLegendaPartido(int legendaPartido);
    int calculaEleitos();*/

    void imprimePartido();
    
private:
    int numeroPartido;
    string siglaPartido;
    string nomePartido;
    int legendaPartido;
    int votosNominais;
    Federacao federacao;
    //List<Candidato> candidatos = new ArrayList<>();
};

#endif // PARTIDO_H
