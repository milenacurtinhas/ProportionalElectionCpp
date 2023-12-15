#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string.h>
#include "leitura.h"
#include "partido.h"
#include "processaEleicoes.h"

using namespace std;


int main (int argc, char **argv){
    map<int, Candidato> candidatos;
    map<int, Partido> partidos;

    if(strcmp(argv[1], "--federal") == 0){
        leCandidatos(candidatos, partidos, 6, argv[2]);
        leVotacao(candidatos, partidos, 6, argv[3]);
    }
    else if(strcmp(argv[1], "--estadual") == 0){
        leCandidatos(candidatos, partidos, 7, argv[2]);
        leVotacao(candidatos, partidos, 7, argv[3]);
    }

    list<Candidato> listaCandidatos;
    list<Partido> listaPartidos;
    
    // Percorre o mapa e insere os candidatos na lista
    for (const auto& par : candidatos) {
        listaCandidatos.push_back(par.second); // Adiciona o valor (Candidato) na lista
    }
    for (const auto& par : partidos) {
        listaPartidos.push_back(par.second); // Adiciona o valor (Partido) na lista
    }

    listaCandidatos.sort(compararCandidatos);
    listaPartidos.sort(compararPartidos);
    int quantidadeEleitos = processaQtdVagas(candidatos);
    
    if(strcmp(argv[1], "--federal") == 0){
        cout << "\nDeputados federais eleitos:" << endl;
    }
    else if(strcmp(argv[1], "--estadual") == 0){
        cout << "\nDeputados estaduais eleitos:" << endl;
    }

    
    processaEleitos(listaCandidatos);
    processaMaisVotados(listaCandidatos, quantidadeEleitos);
    processaNaoEleitosMajoritaria(listaCandidatos, quantidadeEleitos);
    processaEleitosSistemaProporcional(listaCandidatos, quantidadeEleitos);
    processaPartidos(listaPartidos);

    /*for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        it->second.imprimeCandidato(); // Chamada da função para imprimir cada candidato
    }
    for (auto it = partidos.begin(); it != partidos.end(); ++it) {
         // Chamada da função para imprimir cada candidato
         it->second.imprimePartido();
        for(Candidato &candidato : it->second.getCandidatos()){
            candidato.imprimeCandidato();
        }
    }*/

    return 0;
}