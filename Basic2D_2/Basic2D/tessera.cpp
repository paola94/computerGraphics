#include "Tessera.h"

Tessera::Tessera() {
	inizializzata = false;
	esisto = false;
}

Tessera::Tessera(Img i) {
	img = i;
	esisto = true;
	selezionata = false;
	inizializzata = true;
}


Tessera::~Tessera() {
}

bool Tessera::isfree() {

}

void Tessera::setImg(Img i) {
	img = i;
}

int Tessera::getImg() {
	return img;
}

void Tessera::setX(float coord_x) {
	x = coord_x;
}

float Tessera::getX() {
	return x;
}

void Tessera::setY(float coord_y) {
	y = coord_y;
}

float Tessera::getY() {
	return y;
}

void Tessera::setEsisto(bool e) {
	esisto = e;
}

bool Tessera::isEsisto() {
	return esisto;
}

void Tessera::setSelezionata(bool s) {
	selezionata = s;
}

bool Tessera::isSelezionata() {
	return selezionata;
}

void Tessera::setInizializzata(bool s) {
	inizializzata = s;
}

bool Tessera::isInizializzata() {
	return inizializzata;
}