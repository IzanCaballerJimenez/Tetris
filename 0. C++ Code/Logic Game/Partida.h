#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"

using namespace std;

class Partida 
{
public:
    Partida();
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures,const string& fitxerMoviments);
    
    void actualitza( double deltaTime);
private:
    double m_temps;
    Joc m_jocActual;
    int m_nivell;
};
#endif