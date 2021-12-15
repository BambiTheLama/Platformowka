#include "Hero.h"

Hero::Hero(int hp, double x, double y, int r, double speed, int levelpoints, double jumpfar, double jumpspeed)
{
	this->hp = hp;
	this->x = x;
	this->y = y;
	this->r = r;
	this->speed = speed;
	this->levelpoints = levelpoints;
	this->jumpfar = jumpfar;
	this->jumpspeed = jumpspeed;
	jump = 0;
	fallspeed = 0;
}

void Hero::draw()
{
	DrawCircle(x, y, r, GREEN);
}

void Hero::updata(room *Room)
{

	if (IsKeyDown(KEY_SPACE)&&jump>0)
	{
		if (jump - jumpspeed > 0)
		{
			if (Room->colision(x, y - jumpspeed - r)&& Room->colision(x+r, y - jumpspeed - r)&& Room->colision(x-r, y - jumpspeed - r))
			{
				jump = jump - jumpspeed;
				y = y - jumpspeed;
			}
			else
			{
				jump = 0;
			}

		}
		else
		{
			jump = 0;
			y = y - jump;
		}
	}
	else
	{
		if (Room->colision(x, y + fallspeed+r)&& Room->colision(x+r, y + fallspeed + r) && Room->colision(x - r, y + fallspeed + r))
		{
			jump = 0;
			y = y + fallspeed;
			if (fallspeed < 20)
				fallspeed = fallspeed + 1;

		}
		else
		{
			if (jump != jumpfar)
				jump = jumpfar;
			if (fallspeed != 0)
				fallspeed = 0;

		}
			
	}
	if (IsKeyDown(KEY_LEFT_SHIFT))
		speed = speed * 2;
	if (IsKeyDown(KEY_A))
	{
		if(Room->colision(x - speed-r, y)&&Room->colision(x - speed - r, y-r)&& Room->colision(x - speed - r, y+r))
			x = x-speed;
	}
	if (IsKeyDown(KEY_D))
	{
		if(Room->colision(x + speed+r, y)&&Room->colision(x + speed + r, y-r) && Room->colision(x + speed + r, y + r))
			x = x+speed;
	}
	if (IsKeyDown(KEY_LEFT_SHIFT))
		speed = speed / 2;
	
}
