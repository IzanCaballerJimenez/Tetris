#include "Figura.h"

Figura::Figura()
{
	m_color = NO_COLOR;
	m_tipus = NO_FIGURA;
	m_fila = 0;
	m_columna = 0;
	m_alcada = MAX_ALCADA;
	m_amplada = MAX_AMPLADA;
	m_gir = 0;
    inicialitzaMatriu();
}

void Figura::inicialitzaMatriu()
{
    for (int i = 0; i < m_alcada; i++)
    {
        for (int j = 0; j < m_amplada; j++)
        {
            m_matriuFigura[i][j] = 0;
        }
    }
}

void Figura::inicialitzaFigura(TipusFigura tipus)
{
    switch (tipus)
    {
    case FIGURA_J:
        m_amplada = 3;
        m_alcada = 3;
        inicialitzaMatriu();
        m_matriuFigura[0][0] = 1;
        m_matriuFigura[1][0] = 1;
        m_matriuFigura[1][1] = 1;
        m_matriuFigura[1][2] = 1;
        m_color = COLOR_BLAUFOSC;
        break;
    case FIGURA_L:
        m_amplada = 3;
        m_alcada = 3;
        inicialitzaMatriu();
        m_matriuFigura[0][2] = 1;
        m_matriuFigura[1][0] = 1;
        m_matriuFigura[1][1] = 1;
        m_matriuFigura[1][2] = 1;
        m_color = COLOR_TARONJA;
        break;
    case FIGURA_S:
        m_amplada = 3;
        m_alcada = 3;
        inicialitzaMatriu();
        m_matriuFigura[0][1] = 1;
        m_matriuFigura[0][2] = 1;
        m_matriuFigura[1][0] = 1;
        m_matriuFigura[1][1] = 1;
        m_color = COLOR_VERD;
        break;
    case FIGURA_Z:
        m_amplada = 3;
        m_alcada = 3;
        inicialitzaMatriu();
        m_matriuFigura[0][0] = 1;
        m_matriuFigura[0][1] = 1;
        m_matriuFigura[1][1] = 1;
        m_matriuFigura[1][2] = 1;
        m_color = COLOR_VERMELL;
        break;
    case FIGURA_T:
        m_amplada = 3;
        m_alcada = 3;
        inicialitzaMatriu();
        m_matriuFigura[0][1] = 1;
        m_matriuFigura[1][0] = 1;
        m_matriuFigura[1][1] = 1;
        m_matriuFigura[1][2] = 1;
        m_color = COLOR_MAGENTA;
        break;
    case FIGURA_I:
        m_amplada = 4;
        m_alcada = 4;
        inicialitzaMatriu();
        m_matriuFigura[1][0] = 1;
        m_matriuFigura[1][1] = 1;
        m_matriuFigura[1][2] = 1;
        m_matriuFigura[1][3] = 1;
        m_color = COLOR_BLAUCEL;
        break;
    case FIGURA_O:
        m_amplada = 2;
        m_alcada = 2;
        m_matriuFigura[0][0] = 1;
        m_matriuFigura[0][1] = 1;
        m_matriuFigura[1][0] = 1;
        m_matriuFigura[1][1] = 1;
        m_color = COLOR_GROC;
        break;
    default:
        break;
    }
    

}
void Figura::inicialitza(int tipus, int fila, int columna)
{
	m_tipus = TipusFigura(tipus);
	m_fila = fila;
	m_columna = columna;
    m_gir = 0;
    inicialitzaFigura(m_tipus);
}

void Figura::transposada()
{
    int aux;
    for (int i = 1; i < m_alcada; i++)
    {
        for (int j = 0; j < i; j++)
        {
            aux = m_matriuFigura[i][j];
            m_matriuFigura[i][j] = m_matriuFigura[j][i];
            m_matriuFigura[j][i] = aux;
        }
    }
}

void Figura::invertirColumnes()
{
    int columna1, columna2;
    if (m_amplada != 2)
    {
        if (m_amplada == 3)
        {
            columna1 = 0;
            columna2 = 2;
        }
        else
        {
            columna1 = 1;
            columna2 = 2;
        }
        int aux;
        for (int i = 0; i < m_alcada; i++)
        {
            aux = m_matriuFigura[i][columna1];
            m_matriuFigura[i][columna1] = m_matriuFigura[i][columna2];
            m_matriuFigura[i][columna2] = aux;
        }
    }
}

void Figura::invertirFiles()
{
    int fila1, fila2;
    if (m_alcada != 2)
    {
        if (m_alcada == 3)
        {
            fila1 = 0;
            fila2 = 2;
        }
        else
        {
            fila1 = 1;
            fila2 = 2;
        }
        int aux;
        for (int i = 0; i < m_amplada; i++)
        {
            aux = m_matriuFigura[fila1][i];
            m_matriuFigura[fila1][i] = m_matriuFigura[fila2][i];
            m_matriuFigura[fila2][i] = aux;
        }
    }
}

void Figura::gir(DireccioGir gir)
{
    transposada();
    if (gir == GIR_HORARI)
    {
        invertirColumnes();
        m_gir = (m_gir + 1) % 4;
    }
    else
    {
        invertirFiles();
        m_gir = (m_gir - 1) % 4;
        if (m_gir < 0) {
            m_gir += 4;
        }
    }
}

void Figura::moureX(int x)
{
    m_columna += x;
}

void Figura::moureY(int y)
{
    m_fila += y;
}

void Figura::dibuixaFigura()
{
    int mitadAmplada = m_amplada / 2;
    int mitadAlcada = m_alcada / 2;

    if (m_amplada % 2 == 0) {
        mitadAmplada--;
    }
    if (m_alcada % 2 == 0) {
        mitadAlcada--;
    }

    if (m_alcada == 2 && m_amplada == 2) {
        mitadAlcada = 1;
        mitadAmplada = 0;
    }

    for (int i = 0; i < m_amplada; i++)
    {
        for (int j = 0; j < m_alcada; j++)
        {
            if (m_matriuFigura[i][j] == 1)
            {
                int y = m_fila - mitadAlcada + i;
                int x = m_columna - mitadAmplada + j;

                GraphicManager::getInstance()->drawSprite(IMAGE_NAME(m_color + 1), POS_X_TAULER + ((x + 1) * MIDA_QUADRAT),
                    POS_Y_TAULER + (y * MIDA_QUADRAT), false);
            }
        }
    }
}

Figura Figura::crearOmbra()
{
    Figura ombra;
    ombra.inicialitza(m_tipus, m_fila, m_columna);

    ombra.m_color = COLOR_OMBRA;
    ombra.m_gir = m_gir;
    for (int i = 0; i < m_gir; i++)
        ombra.gir(GIR_HORARI);

    return ombra;
}