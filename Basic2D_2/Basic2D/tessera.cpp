#include "Tessera.h"



Tessera::Tessera(Img i) {
	img = i;
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