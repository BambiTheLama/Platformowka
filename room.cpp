#include "room.h"

room::room()
{

	for (int i = 0; i < yr; i++)
	{
		for (int j = 0; j < xr; j++)
		{
			t[i][j] = 0;
		}
	}

	for (int i = 0; i < xr; i++)
	{
		t[yr-1][i] = 1;
	}
	for (int i = 0; i < 4; i++)
	{
		t[25][i+22] = 1;
		t[18][i + 15] = 1;
		t[12][i + 3] = 1;
	}

}
void room::draw()
{

	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		nowe(GetMouseX(), GetMouseY());
	}
	if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
	{
		usun(GetMouseX(), GetMouseY());
	}
	if (IsKeyDown(KEY_R))
		reset();
	for (int i = 0; i < yr; i++)
	{
		for (int j = 0; j < xr; j++)
		{
			if (t[i][j] == 0)
			{
				DrawRectangle(j * 32, i * 32, 32, 32, YELLOW);
			}
			else
			{
				DrawRectangle(j * 32, i * 32, 32, 32, BLACK);
			}
		}
	}
}
bool room::colision(int x,int y)
{
	if(x%32==0)
		x = x / 32;
	else
		x = x / 32;
	if (y % 32 == 0)
		y = y / 32;
	else
		y = y / 32;
	if (t[y][x] == 0)
		return 1;
	else
		return 0;

}

void room::nowe(int x, int y)
{
	if (x < 0)
		return;
	if (y < 0)
		return;
	if (x % 32 == 0)
		x = x / 32;
	else
		x = x / 32;
	if (x > xr-1)
		return;
	if (y % 32 == 0)
		y = y / 32;
	else
		y = y / 32;
	if (y > yr-1)
		return;
	if (t[y][x] == 0)
		t[y][x] = 1;
}

void room::usun(int x, int y)
{
	if (x < 0)
		return;
	if (y < 0)
		return;
	if (x % 32 == 0)
		x = x / 32;
	else
		x = x / 32;

	if (x == xr - 1)
		return;
	if (x > xr-1)
		return;

	if (y % 32 == 0)
		y = y / 32;
	else
		y = y / 32;
	if (y > yr-1)
		return;
	if (y == yr - 1)
		return;

	if (t[y][x] == 1)
		t[y][x] = 0;
}

void room::reset()
{
	for (int i = 0; i < yr-1; i++)
		for (int j = 0; j < xr; j++)
			t[i][j] = 0;
}