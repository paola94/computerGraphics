#pragma once

//ciao paola

// Sistema.h
#ifndef Sistema_h
#define Sistema_h
#include "Tessera.h"

#define N_RIGHE_SISTEMA 10
#define N_COLONNE_SISTEMA 10

#define PI 3.14159265

enum Stato {start, gioco, win, game_over };

class Sistema
{
	int livello;
	Tessera *matrice[N_RIGHE_SISTEMA][N_COLONNE_SISTEMA];
	Tessera *matrice2[N_RIGHE_SISTEMA][N_COLONNE_SISTEMA];
	Tessera *matrice3[N_RIGHE_SISTEMA][N_COLONNE_SISTEMA];
	//int hover_riga;
	//int hover_colonna;
	Tessera* tesseraSelezionata;
	bool eliminata;
	Tessera* hoverTessera;
	Stato stato;
	int nTessere;
	

public:
	Sistema();
	void disponi_tessere();
	void disponi_tessere2();
	void disponi_tessere3();
	Tessera* getTesseraMatrice(int i, int j);
	Tessera* getTesseraMatrice2(int i, int j);
	Tessera* getTesseraMatrice3(int i, int j);
	int getColonna(int cx, int width);
	int getRiga(int cy, int height);
	void selectTessera(int i, int j);
	void setSelezionata(int i, int j);
	Tessera* getSelezionata();
	void setEliminata(bool b);
	bool isEliminata();
	void setHoverTessera(int riga, int colonna);
	Tessera* getHoverTessera();
	void setStato(Stato s);
	int getStato();
	void setNTessere(int n);
	int getNTessere();
};

#endif