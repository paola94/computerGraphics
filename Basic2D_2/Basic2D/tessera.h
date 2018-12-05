#pragma once

enum Img { A, B, C, D, E, F };

class Tessera
{
	Img img;
	float x;
	float y;
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
};
