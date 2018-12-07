#pragma once

enum Img { A, B, C, D, E, F, G, H, I, J, K};

class Tessera
{
	Img img;
	float x;
	float y;
	bool esisto;
	bool selezionata;

public:
	Tessera(Img img);
	~Tessera();
	bool isfree();
	void setImg(Img i);
	int getImg();
	void setX(float x);
	float getX();
	void setY(float y);
	float getY();
	void setEsisto(bool e);
	bool isEsisto();
	void setSelezionata(bool s);
	bool isSelezionata();
};
