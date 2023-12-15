#if !defined(LEITURA_H)
#define LEITURA_H

#include "candidato.h"
#include "partido.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;


void leCandidatos(map<int, Candidato> &candidatos, map<int, Partido> &partidos, int tipoCandidato, string arquivo);
void leVotacao(map<int, Candidato> &candidatos, map<int, Partido> &partidos, int tipoCandidato, string arquivo);

#endif // LECANDIDATOS_H
