#pragma once

//ciao paola

// Sistema.h
#ifndef Sistema_h
#define Sistema_h
#include "Tessera.h"

#define N_RIGHE_SISTEMA 10
#define N_COLONNE_SISTEMA 10

#define PI 3.14159265


class Sistema
{
	int livello;
	Tessera *matrice[N_RIGHE_SISTEMA][N_COLONNE_SISTEMA];
	bool game_over;
	bool win;
	int hover_riga;
	int hover_colonna;


	/*const int livello_1[N_RIGHE_SISTEMA][N_COLONNE_SISTEMA] = {
		{ -1,	-1,	0,	0,	0,	0,	-1,	-1},
		{ -1,	-1,	1,	1,	1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	2,2,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	3,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 }
	};

	const int livello_2[N_RIGHE_SISTEMA][N_COLONNE_SISTEMA] = {
		{ 1,	2,	3,	0,	1,	2,	3,	0 },
		{ 1,	2,	3,	0,	1,	2,	3,	0 },
		{ 1,	2,	3,	0,	1,	2,	3,	0 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 }
	};

	const int livello_3[N_RIGHE_SISTEMA][N_COLONNE_SISTEMA] = {
		{ 1,	2,	3,	0,	1,	2,	3,	0 },
		{ 3,	0,	1,	3,	2,	1,	0,	0 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 }
	};

	const int livello_4[N_RIGHE_SISTEMA][N_COLONNE_SISTEMA] = {
		{ -1,	1,	0,	0,	0,	1,	2,	1 },
		{ 1,	-1,	-1,	-1,	-1,	-1,	-1,	3 },
		{ 2,	2,	3,	0,	1,	2,	2,	0 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 },
		{ -1,	-1,	-1,	-1,	-1,	-1,	-1,	-1 }
	};*/



public:
	Sistema();
	void disponi_tessere();
	Tessera* getTesseraMatrice(int i, int j);
	int getColonna(int cx, int width);
	int getRiga(int cy, int height);
	void selectTessera(int i, int j);
};

#endif