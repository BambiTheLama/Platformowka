#pragma once
#include "raylib.h"


class room
{
	bool ciasteczko = 0;
	int xr = 50, yr = 28;
	char t[28][50];
public:
	room();

	void draw();

	bool colision(int x,int y);

	void nowe(int x,int y);

	void usun(int x, int y);
	
	void reset();
};

