#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"

Partida::Partida()
{
    m_temps = 0;
    m_jocActual.novaFigura();
    m_nivell = 0;
}

void Partida::inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures,
    const string& fitxerMoviments)
{
    m_jocActual.inicialitza(fitxerInicial);
}

void Partida::actualitza(double deltaTime)
{
    m_jocActual.dibuixaJoc();

    int fila = m_jocActual.getFigura().getFila();
    int columna = m_jocActual.getFigura().getColumna();
    int puntuacio = m_jocActual.getPunt();

    m_nivell = puntuacio / 10;
    
    m_temps += deltaTime;

        if (m_temps > 1.75 - (1.5 - (m_nivell * 0.5)))
        {
            if (fila < N_FILES_TAULER)
                m_jocActual.baixaFigura();
            m_temps = 0.0;
        }

    if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
        m_jocActual.mouFigura(1);
    if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
        m_jocActual.mouFigura(-1);

    if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
        m_jocActual.baixaDeCopFigura();

    if (Keyboard_GetKeyTrg(KEYBOARD_X))
        m_jocActual.giraFigura(GIR_HORARI);
    if (Keyboard_GetKeyTrg(KEYBOARD_Z))
        m_jocActual.giraFigura(GIR_ANTI_HORARI);

    if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
        m_jocActual.baixaFigura();

    string msg = "Fila: " + to_string(fila) + ", Columna: " + to_string(columna) + ", Puntuacio: " + to_string(puntuacio);
    string msg2 = "Nivell: " + to_string(m_nivell);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER - 50, POS_Y_TAULER - 85, 1.0, msg);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER - 115, POS_Y_TAULER - 20, 1.0, msg2);
}