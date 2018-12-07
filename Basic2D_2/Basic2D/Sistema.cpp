#include "Sistema.h"
#include <Windows.h>
#include <time.h>
#include <math.h>


Sistema::Sistema()
{
	disponi_tessere();
	disponi_tessere2();
	tesseraSelezionata = NULL;
	eliminata = false;
}


void Sistema::disponi_tessere() {
	srand(time(NULL));
	for (int j = 0; j < N_RIGHE_SISTEMA; j++) {
		for (int i = 0; i < N_COLONNE_SISTEMA; i++) {
			matrice[i][j] = new Tessera(Img(rand() % 6));
		}
	}
}

void Sistema::disponi_tessere2() {
	srand(time(NULL));
	for (int j = 0; j < N_RIGHE_SISTEMA; j++) {
		for (int i = 0; i < N_COLONNE_SISTEMA; i++) {
				matrice2[i][j] = new Tessera(Img(rand() % 6));
				if ((i<2 || i>7) || (j < 2 || j>7)) {
					matrice2[i][j]->setEsisto(false);
					//matrice2[i][j] = NULL;
				}
		}
	}
}

Tessera* Sistema::getTesseraMatrice(int i, int j) {
	if (i >= 0 && i < N_COLONNE_SISTEMA && j >= 0 && j < N_RIGHE_SISTEMA) {
		return matrice[i][j];
	}
	return NULL;
}

Tessera* Sistema::getTesseraMatrice2(int i, int j) {
	if (i >= 0 && i < N_COLONNE_SISTEMA && j >= 0 && j < N_RIGHE_SISTEMA) {
		return matrice2[i][j];
	}
	return NULL;
}



/*Tessera* Sistema::getTesseraMatrice(int i, int j) {
	if (i >= 0 && i < N_COLONNE_SISTEMA && j >= 0 && j < N_RIGHE_SISTEMA) {
		if (matrice2[i][j] != NULL) {
			return matrice2[i][j];
		}
		else {
			return matrice[i][j];
		}
	}
	return NULL;
}*/

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
				if (tesseraSelezionata == NULL) {
					t->setSelezionata(true);
					tesseraSelezionata = t;
					this->eliminata = false;
				}else {
					if (t->getImg() != tesseraSelezionata->getImg()) {
						t->setSelezionata(true);
						tesseraSelezionata->setSelezionata(false);
						tesseraSelezionata = t;
						this->eliminata = false;
					}else {
						if (t->getX() != tesseraSelezionata->getX() || t->getY() != tesseraSelezionata->getY()) {
							t->setEsisto(false);
							tesseraSelezionata->setEsisto(false);
							tesseraSelezionata = NULL;
							this->eliminata = true;
						}
					}
				}
				
			}else {
				if (!this->getTesseraMatrice(colonna - 1, riga)->isEsisto() || !this->getTesseraMatrice(colonna + 1, riga)->isEsisto()) {
					if (tesseraSelezionata == NULL) {
						t->setSelezionata(true);
						tesseraSelezionata = t;
						this->eliminata = false;
					}
					else {
						if (t->getImg() != tesseraSelezionata->getImg()) {
							t->setSelezionata(true);
							tesseraSelezionata->setSelezionata(false);
							tesseraSelezionata = t;
							this->eliminata = false;
						}
						else {
							if (t->getX() != tesseraSelezionata->getX() || t->getY() != tesseraSelezionata->getY()) {
								t->setEsisto(false);
								tesseraSelezionata->setEsisto(false);
								tesseraSelezionata = NULL;
								this->eliminata = true;
							}
						}
					}
				}
			}
		}
	}
}

void Sistema::setSelezionata(int i, int j) {
	tesseraSelezionata = getTesseraMatrice(i, j);
}

Tessera* Sistema::getSelezionata() {
	return tesseraSelezionata;
}

void Sistema::setEliminata(bool b) {
	eliminata = b;
}

bool Sistema::isEliminata() {
	return eliminata;
}

void Sistema::setHoverTessera(int riga, int colonna) {
	if (getTesseraMatrice2(colonna, riga)!=NULL) {
		if (this->getTesseraMatrice2(colonna, riga)->isEsisto()) {
			hoverTessera = this->getTesseraMatrice2(colonna, riga);
		}
		else {
			hoverTessera = this->getTesseraMatrice(colonna, riga);
		}
	}
}

Tessera* Sistema::getHoverTessera() {
	return hoverTessera;
}
