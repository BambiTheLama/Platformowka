#pragma once
#include "raylib.h"
#include <stdlib.h>
#include <time.h> 

class room
{
	bool ciasteczko = 0;
	int xr = 50, yr = 28;
	char t[28][50];
public:
	room();

	~room();

	void draw();

	char colision(int x,int y);

	void nowe(int x,int y);

	void usun(int x, int y);
	
	void reset();
};

