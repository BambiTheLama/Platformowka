#include "room.h"
#include <fstream>

room::room()
{
	std::ifstream p;
	p.open("mapa.txt");
	if (p.is_open())
	{
		for (int i = 0; i < yr; i++)
		{
			for (int j = 0; j < xr; j++)
				p >> t[i][j];

		}
		for (int i = 0; i < yr; i++)
		{
			for (int j = 0; j < xr; j++)
				if (t[i][j] == 2)
				{
					if (ciasteczko == 1)
						t[i][j] = 0;
					ciasteczko = 1;

				}
					

		}
	}
	else
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
			t[yr - 1][i] = 1;
		}
		for (int i = 0; i < 4; i++)
		{
			t[25][i + 22] = 1;
			t[18][i + 15] = 1;
			t[12][i + 3] = 1;
		}
	}

	p.close();
	srand(time(NULL));


}

room::~room()
{
	std::ofstream p;
	p.open("mapa.txt");
	for (int i = 0; i < yr; i++)
	{
		for (int j = 0; j < xr; j++)
			p << t[i][j] << "  ";
		p << std::endl;
	}
	p.close();
}

void room::draw()
{
	if (ciasteczko == 0)
	{
		int a = rand() % xr;
		int b = rand() % yr;
		while (t[b][a] != 0)
		{
			a = rand() % xr;
			b = rand() % yr;
		}
		ciasteczko = 1;
		t[b][a] = 2;
	}
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
			switch (t[i][j])
			{
			case 0:
				DrawRectangle(j * 32, i * 32, 32, 32, YELLOW);
				break;
			case 1:
				DrawRectangle(j * 32, i * 32, 32, 32, BLACK);
				break;
			case 2:
				DrawRectangle(j * 32, i * 32, 32, 32, YELLOW);
				DrawCircle(j * 32+16, i * 32+16, 16, BLUE);
				break;
			}

		}
	}
}

char room::colision(int x,int y)
{
	if(x%32==0)
		x = x / 32;
	else
		x = x / 32;
	if (y % 32 == 0)
		y = y / 32;
	else
		y = y / 32;
	if (t[y][x] == 2)
	{
		ciasteczko = 0;
		t[y][x] = 0;
		return 2;
	}

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
			if(t[i][j] == 1)
				t[i][j] = 0;
}