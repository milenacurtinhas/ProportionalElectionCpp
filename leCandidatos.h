#if !defined(LECANDIDATOS_H)
#define LECANDIDATOS_H

#include "candidato.h"
#include "partido.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

class LeCandidato{
public:
    static void leitura(map<int, Candidato> candidatos, map<int, Partido> partidos, int tipoCandidato, string arquivo);
    static void setStringStream(istringstream lineScanner, int q);
};

#endif // LECANDIDATOS_H
