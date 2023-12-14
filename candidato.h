#if !defined(CANDIDATO_H)
#define CANDIDATO_H

#include <string>
#include <iostream>
#include <ctime>
#include "partido.h"

using namespace std;

class Candidato{
public:
    enum class CandidatoEleito {ELEITO, NAO_ELEITO };
    enum class Genero {FEMININO, MASCULINO};
    enum class SituacaoCandidato {DEFERIDO, INDEFERIDO };
    enum class DestinacaoVotos {LEGENDA, NOMINAL, INVALIDO};
    Candidato(){};
    Candidato(int &numero, string &nomeUrna/*, Partido *partido*/, tm &dataNascimento, CandidatoEleito &candidatoEleito, Genero &genero, DestinacaoVotos &destVotos, SituacaoCandidato &situacao);
    void setQuantidadeVotos(int quantidadeVotos);
    int getNumero();
    string getNomeUrna();
    Partido getPartido();
    CandidatoEleito getCandidatoEleito();
    int getQuantidadeVotos();
    tm getDataNascimento();
    SituacaoCandidato getSituacao();
    Genero getGenero();
    DestinacaoVotos getDestinacao();

    void imprimeCandidato();

private:
    int numero; //NR_CANDIDATO (16)
    string nomeUrna; //NM_URNA_CANDIDATO (18)
    Partido partido; //NR_PARTIDO (27) e SG_PARTIDO (28) e NM_PARTIDO (29) e NR_FEDERACAO (30) e NM_FEDERACAO (31)
    tm dataNascimento; //DT_NASCIMENTO (42)
    CandidatoEleito candidatoEleito; //CD_SIT_TOT_TURNO (56)
    Genero genero; //CD_GENERO (45)
    DestinacaoVotos destinacaoVotos; //NM_TIPO_DESTINACAO_VOTOS (66)
    SituacaoCandidato situacao; //CD_SITUACAO_CANDIDADO_TOT (67)
    int quantidadeVotos; //QT_VOTOS (21)
};

#endif // CANDIDATO_H
