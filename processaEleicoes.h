#if !defined(PROCESSAELEICOES_H)
#define PROCESSAELEICOES_H

#include <list>
#include "candidato.h"
#include "partido.h"

using namespace std;

int processaQtdVagas(map<int, Candidato> candidatos);
void processaEleitos(list<Candidato> listCandidatos);
void processaMaisVotados(list<Candidato> listCandidatos, int quantidadeVagas);
void processaNaoEleitosMajoritaria(list<Candidato> listCandidatos, int quantidadeVagas);
void processaEleitosSistemaProporcional(list<Candidato> listCandidatos,int quantidadeVagas);
void processaPartidos(list<Partido> listPartidos);
void processaPrimeiroUltimoColocados(list<Partido> listPartidos);
void processaFaixaEtaria(list<Candidato> listCandidatos, int quantidadeVagas, tm data);
void processaGenero(list<Candidato> listCandidatos, int quantidadeVagas);
void processaVotosTotais(list<Partido>listPartidos);

#endif // PROCESSAELEICOES_H
