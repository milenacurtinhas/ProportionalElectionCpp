#if !defined(PARTIDO_H)
#define PARTIDO_H

#include <string>

using namespace std;

class Partido{
    int numeroPartido;
    string siglaPartido;
    string nomePartido;
    int legendaPartido;
    int votosNominais;
    Federacao federacao;
    List<Candidato> candidatos = new ArrayList<>();


};

#endif // PARTIDO_H
