#include "Sistema.h"
#include <Windows.h>
#include <time.h>
#include <math.h>


Sistema::Sistema()
{
	disponi_tessere();
}


void Sistema::disponi_tessere() {
	srand(time(NULL));
	for (int j = 0; j < N_RIGHE_SISTEMA; j++) {
		for (int i = 0; i < N_COLONNE_SISTEMA; i++) {
			matrice[i][j] = new Tessera(Img(rand() % 6));
		}
	}
}

Tessera* Sistema::getTesseraMatrice(int i, int j) {
	return matrice[i][j];
}

int Sistema::getColonna(int cx, int Wwidth) {
	float x_r = (2.0f * (float)cx / (float) Wwidth);
	x_r = x_r - 0.611979f;
	int colonna = floor(x_r / 0.070313f);
	return colonna;
}

int Sistema::getRiga(int cy, int Wheight) {
	float y_r = -((2.0f * (float)cy / (float) Wheight) - 2.0f);
	y_r = y_r - 0.302122f;
	int riga = floor(y_r / 0.132335f);
	return riga;
}

void Sistema::selectTessera(int riga, int colonna) {
	if (riga >= 0 && riga < N_RIGHE_SISTEMA && colonna >= 0 && colonna < N_COLONNE_SISTEMA) {
		Tessera* t = this->getTesseraMatrice(colonna, riga);
		if (t->isEsisto()) {
			if (colonna == 0 || colonna == N_COLONNE_SISTEMA-1) {
				t->setSelezionata(true);
			}else {
				if (!this->getTesseraMatrice(colonna - 1, riga)->isEsisto() || !this->getTesseraMatrice(colonna + 1, riga)->isEsisto()) {
					t->setSelezionata(true);
				}
			}
		}
	}
}

void Sistema::setSelezionata(int i, int j) {
	selezionata = getTesseraMatrice(i, j);
}

