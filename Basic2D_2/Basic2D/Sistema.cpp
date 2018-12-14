#include "Sistema.h"
#include <Windows.h>
#include <time.h>
#include <math.h>
#include <vector>


Sistema::Sistema()
{
	disponi_tessere();
	disponi_tessere2();
	tesseraSelezionata = NULL;
	hoverTessera = NULL;
	eliminata = false;
}


void Sistema::disponi_tessere() {
	srand(time(NULL));
	/*std::vector<int> i_vector(N_RIGHE_SISTEMA);
	std::vector<int> j_vector(N_RIGHE_SISTEMA);
	int finish_i = 0;
	int finish_j = 0;
	int i = 0;
	int j = 0;
	while(finish_i < N_RIGHE_SISTEMA || finish_j < N_RIGHE_SISTEMA){
		i = rand() % N_RIGHE_SISTEMA;
		bool insert = true;
		for (int w = 0; w < i_vector.size(); w++) {
			if (i_vector[w] == i) {
				insert = false;
			}
		}
		if (insert) {
			i_vector[finish_i] = i;
			finish_i += 1;
		}
		j = rand() % N_RIGHE_SISTEMA;
		insert = true;
		for (int w = 0; w < j_vector.size(); w++) {
			if (j_vector[w] == j) {
				insert = false;
			}
		}
		if (insert) {
			j_vector[finish_j] = j;
			finish_j += 1;
		}
	}*/

	for (int j = 0; j < N_RIGHE_SISTEMA; j++) {
		for (int i = 0; i < N_COLONNE_SISTEMA; i++) {
			matrice[i][j] = new Tessera();
		}
	}
	int count = 0;
	while (count < N_RIGHE_SISTEMA*N_COLONNE_SISTEMA) {
		int i = rand() % N_COLONNE_SISTEMA;
		int j = rand() % N_RIGHE_SISTEMA;
		int a = rand() % 12;
		if (!matrice[i][j]->isInizializzata()) {
			matrice[i][j] = new Tessera(Img(a));
			do {
				i = rand() % N_COLONNE_SISTEMA;
				j = rand() % N_RIGHE_SISTEMA;
				
			} while (matrice[i][j]->isInizializzata());
			matrice[i][j] = new Tessera(Img(a));
			count = count + 2;
		}
	}
	

	


	//generazione simmetrica a blocchi di 5
	/*for (int j = 0; j < N_RIGHE_SISTEMA/2; j++) {
		for (int i = 0; i < N_COLONNE_SISTEMA/2; i++) {
			int img = rand() % 12;
			matrice[i][j] = new Tessera(Img(img));
			matrice[N_RIGHE_SISTEMA-1 - i][N_COLONNE_SISTEMA-1 - j] = new Tessera(Img(img));
		}
	}
	for (int j = 9; j >= N_RIGHE_SISTEMA/2; j--) {
		for (int i = 0; i < N_COLONNE_SISTEMA/2; i++) {
			int img = rand() % 12;
			matrice[i][j] = new Tessera(Img(img));
			matrice[N_RIGHE_SISTEMA - 1 - i][N_COLONNE_SISTEMA - 1 - j] = new Tessera(Img(img));
		}
	}*/

	// generazione random non a coppie
	/*for (int j = 0; j < N_RIGHE_SISTEMA; j++) {
		for (int i = 0; i < N_COLONNE_SISTEMA; i++) {
			matrice2[i][j] = new Tessera(Img(rand() % 12));
		}
	}*/

}

void Sistema::disponi_tessere2() {
	srand(time(NULL));
	for (int j = 0; j < N_RIGHE_SISTEMA; j++) {
		for (int i = 0; i < N_COLONNE_SISTEMA; i++) {
			matrice2[i][j] = new Tessera();
		}
	}
	int count = 0;
	while (count < (N_RIGHE_SISTEMA-4)*(N_COLONNE_SISTEMA-4)) {
		int i = rand() % (N_COLONNE_SISTEMA-4) + 2;
		int j = rand() % (N_RIGHE_SISTEMA-4) + 2;
		int a = rand() % 12;
		if (!matrice2[i][j]->isInizializzata()) {
			matrice2[i][j] = new Tessera(Img(a));
			do {
				i = rand() % (N_COLONNE_SISTEMA-4) + 2;
				j = rand() % (N_RIGHE_SISTEMA-4) + 2;

			} while (matrice2[i][j]->isInizializzata());
			matrice2[i][j] = new Tessera(Img(a));
			count = count + 2;
		}
	}
	/*for (int j = 0; j < N_RIGHE_SISTEMA; j++) {
		for (int i = 0; i < N_COLONNE_SISTEMA; i++) {
				matrice2[i][j] = new Tessera(Img(rand() % 12));
				if ((i<2 || i>7) || (j < 2 || j>7)) {
					matrice2[i][j]->setEsisto(false);
				}
		}
	}*/
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
	//dobbiamo controllare efficientemente quale sia la tessera al livello pi� alto e renderla cliccabile!
	if (riga >= 0 && riga < N_RIGHE_SISTEMA && colonna >= 0 && colonna < N_COLONNE_SISTEMA) {
		Tessera* t = NULL;
		int livello = 0;
		if (this->getTesseraMatrice2(colonna, riga)->isEsisto()) {
			t = this->getTesseraMatrice2(colonna, riga);
			livello = 2;
		}
		else if(this->getTesseraMatrice(colonna,riga)->isEsisto()) {
			t = this->getTesseraMatrice(colonna, riga);
			livello = 1;
		}
		if (t->isEsisto()) {
			if (colonna == 0 || colonna == N_COLONNE_SISTEMA - 1) {
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
						else {
							t->setSelezionata(false);
							tesseraSelezionata = NULL;
						}
					}
				}

			}
			else {
				if (livello == 2) {
					if (!this->getTesseraMatrice2(colonna - 1, riga)->isEsisto() || !this->getTesseraMatrice2(colonna + 1, riga)->isEsisto()) {
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
								else if (t->getX() == tesseraSelezionata->getX() || t->getY() == tesseraSelezionata->getY()) {
									tesseraSelezionata = NULL;
									t->setSelezionata(false);
								}
							}
						}
					}
				}
				else if (livello == 1) {
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
								else if (t->getX() == tesseraSelezionata->getX() || t->getY() == tesseraSelezionata->getY()) {
									tesseraSelezionata = NULL;
									t->setSelezionata(false);
								}
							}
						}
					}
				}
			}
		}
	}

	/*if (riga >= 0 && riga < N_RIGHE_SISTEMA && colonna >= 0 && colonna < N_COLONNE_SISTEMA) {
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
						else {
							t->setSelezionata(false);
							tesseraSelezionata = NULL;
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
							else if(t->getX() == tesseraSelezionata->getX() || t->getY() == tesseraSelezionata->getY()) {
								tesseraSelezionata = NULL;
								t->setSelezionata(false);
							}
						}
					}
				}
			}
		}
	}*/
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
	Tessera* t = NULL;
	if (riga >= 0 && riga < N_RIGHE_SISTEMA && colonna >= 0 && colonna < N_COLONNE_SISTEMA) {
		if (this->getTesseraMatrice2(colonna, riga)->isEsisto()) {
			t = this->getTesseraMatrice2(colonna, riga);
		}
		else {
			t = this->getTesseraMatrice(colonna, riga);
		}
	}
	hoverTessera = t;
	/*if (getTesseraMatrice(colonna, riga)!=NULL) {
		if (this->getTesseraMatrice(colonna, riga)->isEsisto()) {
			hoverTessera = this->getTesseraMatrice(colonna, riga);
		}
	}*/
}

Tessera* Sistema::getHoverTessera() {
	return hoverTessera;
}
