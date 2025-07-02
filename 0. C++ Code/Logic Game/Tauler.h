#pragma once
#include "Figura.h"
#include <string>
using namespace std;

const int MAX_FILA = N_FILES_TAULER;
const int MAX_COL = N_COL_TAULER;

class Tauler
{
public:
	Tauler();
	void inicialitza(ColorFigura taulerInicial[MAX_FILA][MAX_COL]);
	bool colisiona(Figura figura);
	int actualitzaTauler(Figura figura);
	void colocaFigura(Figura figura);
	
	void setColor(int i, int j, int color) { m_tauler[i][j] = ColorFigura(color); }

	ColorFigura getColorTauler(int fila, int columna) const { return m_tauler[fila][columna]; }
	int getBuides(int columna) const { return m_buides[columna]; }
	void dibuixaTauler();

private:
	void eliminaFila(int fila);
	void actualitzarBuides();

	ColorFigura m_tauler[MAX_FILA][MAX_COL];
	int m_buides[MAX_FILA];
};
