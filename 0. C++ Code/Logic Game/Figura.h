#pragma once
#include "InfoJoc.h"
#include "GraphicManager.h"
#include <iostream>

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
	GIR_HORARI = 0,
	GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
	Figura();
	void inicialitza(int tipus, int fila, int columna);
	void gir(DireccioGir direccioGir);
	void moureX(int x);
	void moureY(int y);

	int getFila() const { return m_fila; };
	int getColumna() const { return m_columna; };
	int getAlcada() const { return m_alcada; };
	int getAmplada() const { return m_amplada; };
	int getGir() const { return m_gir; };
	int getMatriu(int fila, int columna) const { return m_matriuFigura[fila][columna]; };
	ColorFigura getColor() const { return m_color; };
	TipusFigura getTipus() const { return m_tipus; };
	void dibuixaFigura();
	Figura crearOmbra();

private:
	ColorFigura m_color;
	TipusFigura m_tipus;
	int m_fila;
	int m_columna;
	int m_alcada;
	int m_amplada;
	int m_matriuFigura[MAX_ALCADA][MAX_AMPLADA];
	int m_gir;

	void inicialitzaFigura(TipusFigura tipus);
	void transposada();
	void invertirColumnes();
	void invertirFiles();
	void inicialitzaMatriu();
};