#if !defined(MACRO)
#define MACRO

#include <iostream>
#include <string>

class Data{
    int mes;
    int ano;
    int dia;
public:
    Data(){};
    Data(int &dia, int &mes, int &ano) : dia(dia), mes(mes), ano(ano){};
    string dataParaString() {auto converterData = [this]() {
            return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(ano);
        };

        return converterData();
    }

#endif // MACRO

