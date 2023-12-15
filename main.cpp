#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "leCandidatos.h"
using namespace std;


int main (int argc, char **argv){
    map<int, Candidato> candidatos;
    map<int, Partido> partidos;
    string arquivo = "teste.csv";
    int tipoCandidato = 7;

    leitura(candidatos, partidos, tipoCandidato, arquivo);
    
    /*for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        it->second.imprimeCandidato(); // Chamada da função para imprimir cada candidato
    }*/
    for (auto it = partidos.begin(); it != partidos.end(); ++it) {
        it->second.imprimePartido(); // Chamada da função para imprimir cada candidato
    }
    return 0;
}