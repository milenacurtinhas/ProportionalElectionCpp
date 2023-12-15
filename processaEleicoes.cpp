#include "processaEleicoes.h"
using namespace std;

int processaQtdVagas(map<int, Candidato> candidatos){
    int count = 0;

    for (auto it = candidatos.begin(); it != candidatos.end(); ++it) {
        if(it->second.getCandidatoEleito() == Candidato::CandidatoEleito::ELEITO){
            count++;
        }
    }
    cout << "Número de vagas: " << count << endl;

    return count;
}

void processaEleitos(list<Candidato> listCandidatos){
    int i = 1;

    for (auto& candidato : listCandidatos) {
        if(candidato.getCandidatoEleito() == Candidato::CandidatoEleito::ELEITO){
            cout << i << " - ";
            if(candidato.getPartido().getFederacao() == Partido::Federacao::TEM_FEDERACAO){
                cout << "*";
            }
            cout << candidato.getNomeUrna() << " (" << candidato.getPartido().getSiglaPartido() << ", " << candidato.getQuantidadeVotos() << " votos)" << endl;
            
            i++;
        }
    }
    cout << endl;
}

void processaMaisVotados(list<Candidato> listCandidatos, int quantidadeVagas){
    int i = 1;

    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    for(auto& c : listCandidatos){
        
        cout << i << " - ";
        if(c.getPartido().getFederacao() == Partido::Federacao::TEM_FEDERACAO){
            cout << "*";
        }
        cout << c.getNomeUrna() << " (" << c.getPartido().getSiglaPartido() << ", " << c.getQuantidadeVotos() << " votos)" << endl;

        if(i == quantidadeVagas){
            break;
        }
        i++;
    }
    cout << endl;
}

void processaNaoEleitosMajoritaria(list<Candidato> listCandidatos, int quantidadeVagas){
    int i = 1;

        cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:" << endl;
        cout << "(com sua posição no ranking de mais votados)" << endl;

        for(auto& c : listCandidatos){
            if(c.getCandidatoEleito() == Candidato::CandidatoEleito::NAO_ELEITO){
                
                cout << i << " - ";
                if(c.getPartido().getFederacao() == Partido::Federacao::TEM_FEDERACAO){
                    cout << "*";
                }
                cout << c.getNomeUrna() << " (" << c.getPartido().getSiglaPartido() << ", " << c.getQuantidadeVotos() << " votos)" << endl;
            }

            if(i == quantidadeVagas){
                break;
            }

            i++;
        }
        cout << endl;
}

void processaEleitosSistemaProporcional(list<Candidato> listCandidatos,int quantidadeVagas){
    int i = 1;
        
        cout << "Eleitos, que se beneficiaram do sistema proporcional:" << endl;
        cout << "(com sua posição no ranking de mais votados)" << endl;

        for(auto& c : listCandidatos){
            if(c.getCandidatoEleito() == Candidato::CandidatoEleito::ELEITO){
                if(i > quantidadeVagas){
                    cout << i << " - ";
                    if(c.getPartido().getFederacao() == Partido::Federacao::TEM_FEDERACAO){
                        cout << "*";
                    }
                    cout << c.getNomeUrna() << " (" + c.getPartido().getSiglaPartido() << ", " << c.getQuantidadeVotos() << " votos)" << endl;
                }
            }
            i++;
        }
        cout << endl;
}

void processaPartidos(list<Partido> listPartidos){
    int i = 1;

        cout << "Votação dos partidos e número de candidatos eleitos:" << endl;

        for (auto& p: listPartidos) {
            int quantidadeEleitos = p.calculaEleitos();
            int quantidadeVotos = p.getLegendaPartido() + p.getVotosNominais();

            cout << i << " - " << p.getSiglaPartido() <<  " - " << p.getNumeroPartido() <<  ", ";
            if(quantidadeVotos > 1){
               cout << quantidadeVotos << " votos (";
            }
            else{
                cout << quantidadeVotos << " voto (";
            }
            cout << p.getVotosNominais();

            if(p.getVotosNominais() > 1){
                cout << " nominais e ";
            }
            else{
               cout << " nominal e ";
            }
            cout << p.getLegendaPartido() << " de legenda), " << quantidadeEleitos;
            if(quantidadeEleitos > 1){
                cout <<" candidatos eleitos" << endl;
            }
            else{
                cout << " candidato eleito" << endl;
            }    
            i++;
        }
        cout << endl;
}

void processaPrimeiroUltimoColocados(list<Partido> listPartidos){

}

void processaFaixaEtaria(list<Candidato> listCandidatos, int quantidadeVagas, tm data){

}

void processaGenero(list<Candidato> listCandidatos, int quantidadeVagas){
    
}

void processaVotosTotais(list<Partido>listPartidos){
    
}