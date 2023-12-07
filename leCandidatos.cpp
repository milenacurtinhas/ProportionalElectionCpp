#include "leCandidatos.h"

using namespace std;

void LeCandidato::leitura(map<int, Candidato> candidatos, map<int, Partido> partidos, int tipoCandidato, string arquivo){
    ifstream inputStream("candidatos.csv");
    string linha;
    getline(inputStream, linha);

    while(getline(inputStream, linha)){
        istringstream linhaStream(linha);
        setStringStream(linhaStream, 13);
    }
}

void LeCandidato::setStringStream(istringstream *lineStream, int q){
    // Faça algo com lineStream aqui
    // Por exemplo, você pode ler os próximos 'q' valores da linhaStream
    // e realizar alguma operação com esses valores.
    // Exemplo hipotético:
    for (int i = 0; i < q; ++i) {
        string value;
        lineStream >> value;
        // Faça algo com 'value'
    }
}
