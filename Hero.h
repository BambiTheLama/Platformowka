#pragma once
#include "raylib.h"
#include "room.h"

class Hero
{
private:
	int hp;
	double x, y,speed,jumpfar,jump,jumpspeed,fallspeed,fallspeedmax,r;
	int levelpoints;
	

public:
	
	Hero(int hp, double x, double y, int r, double speed, int levelpoints, double jumpfar, double jumpspeed,double fallspeedmax=20);

	void draw();

	void updata(room *Room);

	int atack();

	int use();

	void levelup();
};

