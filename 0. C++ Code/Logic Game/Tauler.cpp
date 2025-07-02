#include "Tauler.h"

Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			m_tauler[i][j] = COLOR_NEGRE;
		}
	}

	for (int i = 0; i < MAX_FILA; i++)
	{
		m_buides[i] = MAX_COL;
	}
}

void Tauler::inicialitza(ColorFigura taulerInicial[MAX_FILA][MAX_COL])
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		m_buides[i] = MAX_COL;
	}
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			m_tauler[i][j] = taulerInicial[i][j];
			if (m_tauler[i][j] != COLOR_NEGRE)
			{
				m_buides[i]--;
			}
		}
	}
}

void Tauler::colocaFigura(Figura figura)
{
	int fila = figura.getFila();
	int columna = figura.getColumna();
	int amplada = figura.getAmplada();
	int alcada = figura.getAlcada();

	int mitadAmplada = amplada / 2;
	int mitadAlcada = alcada / 2;

	if (amplada % 2 == 0) {
		mitadAmplada--;
	}
	if (alcada % 2 == 0) {
		mitadAlcada--;
	}

	if (alcada == 2 && amplada == 2) {
		mitadAlcada = 1;
		mitadAmplada = 0;
	}

	for (int i = 0; i < amplada; i++)
	{
		for (int j = 0; j < alcada; j++)
		{
			int x = fila - mitadAlcada + i;
			int y = columna - mitadAmplada + j;

			if (figura.getMatriu(i, j) == 1)
			{
				m_tauler[x][y] = figura.getColor();
			}
		}
	}
}

void Tauler::eliminaFila(int fila)
{
	// Baixar tot el tauler, menys la primera fila, una cap abaix a partir de la fila  wasa
	for (int i = fila; i > 0; i--)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			m_tauler[i][j] = m_tauler[i - 1][j];
		}
		m_buides[i] = m_buides[i - 1];
	}

	// Primera fila a color negre
	for (int j = 0; j < MAX_COL; j++)
	{
		m_tauler[0][j] = ColorFigura(COLOR_NEGRE);
		m_buides[0] = MAX_COL;
	}
}

void Tauler::actualitzarBuides()
{
	for (int i = 0; i < MAX_FILA; i++)
	{
		m_buides[i] = MAX_COL;
	}
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			if (m_tauler[i][j] != COLOR_NEGRE)
			{
				m_buides[i]--;
			}
		}
	}
}

int Tauler::actualitzaTauler(Figura figura)
{
	int filesCompletades = 0;
	colocaFigura(figura);
	actualitzarBuides();

	int i = 0;
	while (i < MAX_FILA)
	{
		if (m_buides[i] == 0)
		{
			eliminaFila(i);
			filesCompletades++;
		}
		else
		{
			i++;
		}
	}
	return filesCompletades;
}

bool Tauler::colisiona(Figura figura)
{
	bool colisiona = false;
	int fila = figura.getFila();
	int columna = figura.getColumna();
	int amplada = figura.getAmplada();
	int alcada = figura.getAlcada();

	int mitadAmplada = amplada / 2;
	int mitadAlcada = alcada / 2;

	if (amplada % 2 == 0) {
		mitadAmplada--;
	}
	if (alcada % 2 == 0) {
		mitadAlcada--;
	}

	if (alcada == 2 && amplada == 2) {
		mitadAlcada = 1;
		mitadAmplada = 0;
	}

	for (int i = 0; i < amplada; i++)
	{
		for (int j = 0; j < alcada; j++)
		{
			int mat = figura.getMatriu(i, j);
			if (mat == 1)
			{
				int x = fila - mitadAlcada + i;
				int y = columna - mitadAmplada + j;

				if (x < 0 || y < 0 || x >= MAX_FILA || y >= MAX_COL) {
					colisiona = true;
				}
				else if (m_tauler[x][y] != COLOR_NEGRE) {
					colisiona = true;
				}
			}
		}
	}

	return colisiona;
}

void Tauler::dibuixaTauler()
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);

	for (int i = 0; i < N_FILES_TAULER; i++)
	{
		for (int j = 0; j < N_COL_TAULER; j++)
		{
			if (m_tauler[i][j] != COLOR_NEGRE)
			{
				GraphicManager::getInstance()->drawSprite(IMAGE_NAME(m_tauler[i][j] + 1), POS_X_TAULER + ((j + 1)*MIDA_QUADRAT),
														POS_Y_TAULER + ((i) * MIDA_QUADRAT), false);
			}
		}
	}
}