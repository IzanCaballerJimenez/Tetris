#include "Joc.h"
#include <random>

Joc::Joc()
{
	m_puntuacio = 0;
}

void Joc::modeTest(const string& movimentsFitxer, const string& figuresFitxer, const string& partidaFitxer)
{

}

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);

	int tipus, fila, columna, gir;
	int color;

	if (fitxer.is_open())
	{
		fitxer >> tipus >> fila >> columna >> gir;
		m_figuraActual.inicialitza(tipus, fila, columna);
		
		for (int i = 0; i < gir; i++)
		{
			m_figuraActual.gir(GIR_HORARI);
		}

		ColorFigura tauler[MAX_FILA][MAX_COL];

		for (int i = 0; i < MAX_FILA; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
			{
				fitxer >> color;
				tauler[i][j] = ColorFigura(color);
			}
		}
		m_taulerActual.inicialitza(tauler);
		fitxer.close();
	}
}

bool Joc::giraFigura(DireccioGir direccio)
{
	m_figuraActual.gir(direccio);
	bool colisiona = m_taulerActual.colisiona(m_figuraActual);
	if (colisiona)
	{
		if (direccio == GIR_HORARI)
		{
			m_figuraActual.gir(GIR_ANTI_HORARI);
		}
		else
		{
			m_figuraActual.gir(GIR_HORARI);
		}
	}
	return !colisiona;
}

bool Joc::mouFigura(int dirX)
{
	m_figuraActual.moureX(dirX);
	bool colisiona = m_taulerActual.colisiona(m_figuraActual);
	if (colisiona)
	{
		m_figuraActual.moureX(-dirX);
	}
	return !colisiona;
}
int Joc::baixaFigura()
{
	int filesCompletades = 0;
	m_figuraActual.moureY(1);
	bool colisiona = m_taulerActual.colisiona(m_figuraActual);
	if (colisiona)
	{
		m_figuraActual.moureY(-1);
		filesCompletades = m_taulerActual.actualitzaTauler(m_figuraActual);
		m_puntuacio = m_puntuacio + 10;
		switch (filesCompletades)
		{
		case 1:
			m_puntuacio = m_puntuacio + 100;
			break;
		case 2:
			m_puntuacio = m_puntuacio + 150;
			break;
		case 3:
			m_puntuacio = m_puntuacio + 175;
			break;
		case 4:
			m_puntuacio = m_puntuacio + 200;
			break;
		default:
			break;
		}
		novaFigura();
	}

	return filesCompletades;
}

int Joc::baixaDeCopFigura()
{
	int filesCompletades = 0;
	bool colisiona = m_taulerActual.colisiona(m_figuraActual);
	
	while (!colisiona)
	{
		m_figuraActual.moureY(1);
		colisiona = m_taulerActual.colisiona(m_figuraActual);
	}

	if (colisiona)
	{
		m_figuraActual.moureY(-1);
		filesCompletades = m_taulerActual.actualitzaTauler(m_figuraActual);
		m_puntuacio = m_puntuacio + 10;
		switch (filesCompletades)
		{
		case 1:
			m_puntuacio = m_puntuacio + 100;
			break;
		case 2:
			m_puntuacio = m_puntuacio + 150;
			break;
		case 3:
			m_puntuacio = m_puntuacio + 175;
			break;
		case 4:
			m_puntuacio = m_puntuacio + 200;
			break;
		default:
			break;
		}
		novaFigura();
	}
	return filesCompletades;
}

void Joc::dibuixaOmbra()
{
	Figura ombra = m_figuraActual.crearOmbra();

	bool colisiona = m_taulerActual.colisiona(ombra);

	while (!colisiona)
	{
		ombra.moureY(1);
		colisiona = m_taulerActual.colisiona(ombra);
	}

	if (colisiona)
	{
		ombra.moureY(-1);
		ombra.dibuixaFigura();
	}
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		if (m_figuraActual.getTipus() != NO_FIGURA)
		{
			m_taulerActual.colocaFigura(m_figuraActual);
		}

		for (int i = 0; i < MAX_FILA; i++)
		{
			for (int j = 0; j < MAX_COL; j++)
			{
				fitxer << m_taulerActual.getColorTauler(i, j);
			}
			fitxer << endl;
		}
	}

	fitxer.close();
}

void Joc::dibuixaJoc()
{
	m_taulerActual.dibuixaTauler();
	dibuixaOmbra();
	m_figuraActual.dibuixaFigura();
}

void Joc::novaFigura()
{
	srand(rand() ^ time(NULL));
	int figuraRand = rand() % N_TIPUS_FIGURES + 1;
	int fila = 1;
	int col = N_COL_TAULER / 2;

	m_figuraActual.inicialitza(figuraRand, fila, col);
	bool colisiona = m_taulerActual.colisiona(m_figuraActual);
	if (colisiona)
	{
		cout << "GAAAMEE OVEEER" << endl;
	}
}
