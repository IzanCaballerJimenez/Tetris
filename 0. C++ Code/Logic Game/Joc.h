#pragma once
#include "Tauler.h"
#include "Figura.h"
#include <fstream>
#include <string>
using namespace std;

class Joc
{
public:
	Joc();
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	int baixaDeCopFigura();
	void escriuTauler(const string& nomFitxer);
	void novaFigura();
	void dibuixaJoc();
	Figura getFigura() { return m_figuraActual; }
	int getPunt() { return m_puntuacio; }
	// borrar
	void setFigura(Figura figura) { m_figuraActual = figura; }
	Tauler getTauler() { return m_taulerActual; }

private:
	Figura m_figuraActual;
	Tauler m_taulerActual;
	int m_puntuacio;
	void modeTest(const string& movimentsFitxer, const string& figuresFitxer, const string& partidaFitxer);
	void dibuixaOmbra();
};
