#include "Sistema.h"
#include <Windows.h>



Sistema::Sistema()
{
	disponi_tessere();
}


void Sistema::disponi_tessere() {
	for (int j = 0; j < N_RIGHE_SISTEMA; j++) {
		for (int i = 0; i < N_COLONNE_SISTEMA; i++) {
			matrice[i][j] = new Tessera(Img(rand() % 6));
		}
	}
}

Tessera* Sistema::getTesseraMatrice(int i, int j) {
	return matrice[i][j];
}