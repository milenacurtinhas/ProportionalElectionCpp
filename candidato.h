#if !defined(CANDIDATO_H)
#define CANDIDATO_H

#include <string>

using namespace std;

class Candidato{
    int numero; //NR_CANDIDATO (16)
    string nomeUrna; //NM_URNA_CANDIDATO (18)
    Partido partido; //NR_PARTIDO (27) e SG_PARTIDO (28) e NM_PARTIDO (29) e NR_FEDERACAO (30) e NM_FEDERACAO (31)
    LocalDate dataNascimento; //DT_NASCIMENTO (42)
    CandidatoEleito candidatoEleito; //CD_SIT_TOT_TURNO (56)
    Genero genero; //CD_GENERO (45)
    string destinacaoVotos; //NM_TIPO_DESTINACAO_VOTOS (66)
    SituacaoCandidato situacao; //CD_SITUACAO_CANDIDADO_TOT (67)
    int quantidadeVotos; //QT_VOTOS (21)

public:
    
};

#endif // CANDIDATO_H
