#if !defined(LEVOTACAO_H)
#define LEVOTACAO_H

#include "candidato.h"
#include "partido.h"
#include <string>
#include <map>

class Votacao{
public:
    void leitura(map<int, Candidato> candidatos, map<int, Partido> partidos, int tipoCandidato, string arquivo);
    void setScanner(Scanner lineScanner, int q);
};

#endif // LEVOTACAO_H
