#include "Hero.h"

Hero::Hero(int hp, double x, double y, int r, double speed, int levelpoints, double jumpfar, double jumpspeed,double fallspeedmax)
{
	this->hp = hp;
	this->x = x;
	this->y = y;
	this->r = r;
	this->speed = speed;
	this->levelpoints = levelpoints;
	this->jumpfar = jumpfar;
	this->jumpspeed = jumpspeed;
	this->fallspeedmax = fallspeedmax;
	jump = 0;
	fallspeed = 0;
}

void Hero::draw()
{
	DrawCircle(x, y, r, GREEN);
	DrawText(FormatText("Punkty %d", levelpoints), 0, 850, 50, PINK);
}

void Hero::updata(room *Room)
{

	if (IsKeyDown(KEY_SPACE)&&jump>0)
	{
		if (jump - jumpspeed > 0)
		{
			if (Room->colision(x, y - jumpspeed - r) == 2 || Room->colision(x + r, y - jumpspeed - r) == 2 || Room->colision(x - r, y - jumpspeed - r) == 2)
				levelpoints++;

			if (Room->colision(x, y - jumpspeed - r) == 1 && Room->colision(x+r, y - jumpspeed - r) == 1 && Room->colision(x-r, y - jumpspeed - r) == 1)
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
		if (Room->colision(x, y + fallspeed + r) == 2 || Room->colision(x + r, y + fallspeed + r) == 2 || Room->colision(x - r, y + fallspeed + r) == 2)
			levelpoints++;
		if (Room->colision(x, y + fallspeed+r) == 1 && Room->colision(x+r, y + fallspeed + r) == 1 && Room->colision(x - r, y + fallspeed + r) == 1)
		{
			jump = 0;
			y = y + fallspeed;
			if (fallspeed < fallspeedmax)
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
		if (Room->colision(x - speed - r, y) == 2 || Room->colision(x - speed - r, y - r) == 2 || Room->colision(x - speed - r, y + r) == 2)
			levelpoints++;
		if(Room->colision(x - speed-r, y) == 1 &&Room->colision(x - speed - r, y-r) == 1 && Room->colision(x - speed - r, y+r) == 1)
			x = x-speed;
		else
		{
			for (int i = 1; i < speed - 1; i++)
			{
				if (Room->colision(x - speed - r, y) == 1 && Room->colision(x - speed - r, y - r) == 1 && Room->colision(x - speed - r, y + r) == 1)
				{
					x = x + speed - i;
					break;
				}

			}
		}

		
	}
	if (IsKeyDown(KEY_D))
	{
		if (Room->colision(x + speed + r, y) == 2 || Room->colision(x + speed + r, y - r) == 2 || Room->colision(x + speed + r, y + r) == 2)
			levelpoints++;
		if(Room->colision(x + speed+r, y) == 1 &&Room->colision(x + speed + r, y-r) == 1 && Room->colision(x + speed + r, y + r) == 1)
			x = x+speed;
		else
		{
			for (int i = 1; i < speed - 1; i++)
			{
				if (Room->colision(x + speed + r, y) == 1 && Room->colision(x + speed + r, y - r) == 1 && Room->colision(x + speed + r, y + r) == 1)
				{
					x = x + speed - i;
					break;
				}
					
			}
		}
	}
	if (IsKeyDown(KEY_LEFT_SHIFT))
		speed = speed / 2;
	
}
