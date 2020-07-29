#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>
#include "shape.h"
#include "helper.h"
#define pi  3.1415


void Rectangle(Point beg, Point end, bool Fill, Color color)
{
	bool steep = false;

	if (abs(beg.x - end.x) < abs(beg.y - end.y))
	{
		swap(&beg.x, &beg.y);
		swap(&end.x, &end.y);

		steep = true;
	}

	if (beg.x > end.x)
	{
		swap(&beg.x, &end.x);
		swap(&beg.y, &end.y);
	}

	setColor(color);

	if (Fill)
	{
		for (int i = beg.y; i <= end.y; i++)
		{
			for (int j = beg.x; j <= end.x; j++)
			{
				glVertex2d(j, i);
			}
		}
	}
	else
	{
		for (int i = beg.y; i <= end.y; i++)
		{
			for (int j = beg.x; j <= end.x; j++)
			{
				if (!(((j > beg.x) && (j < end.x) && ((i > beg.y) && (i < end.y)))))
				{
					glVertex2d(j, i);
				}
			}
		}
	}
	setColor(WHITE);
}

void Circle(Point Center, int radius, Color color)
{
	setColor(color);
	float x, y, i;

	for (i = 0; i < (2 * pi); i += 0.001)
	{
		x = (radius * cos(i) + Center.x);
		y = (radius * sin(i) + Center.y);

		glVertex2d(x, y);
	}
	setColor(WHITE);
}

/*
float area(Point Verticies[3])
{
	return abs(Verticies[0].x *(Verticies[1].y - Verticies[2].y) + Verticies[1].x * (Verticies[2].y - Verticies[1].y) + Verticies[2].x * (Verticies[0].y - Verticies[1].y)) / 2;
}
*/

bool inTriangle(Point Verticies[3], Point P)
{
	float scalar1 = Verticies[2].y - Verticies[0].y;
	float scalar2 = Verticies[2].x - Verticies[0].x;
	float scalar3 = Verticies[1].y - Verticies[0].y;
	float scalar4 = P.y - Verticies[0].y;

	float vector1 = (Verticies[0].x * scalar1 + scalar4 * scalar2 - P.x * scalar1) / (scalar3 * scalar2 - (Verticies[1].x - Verticies[0].x) * scalar1);
	float vector2 = (scalar4 - vector1 * scalar3) / scalar1;

	return vector1 >= 0 && vector2 >= 0 && (vector1 + vector2) <= 1;
}

void Triangle(Point Verticies[3], bool Fill, Color color)
{
	setColor(color);
	if (Fill) {
		for (int i = 0; i < 720; i++)
		{
			for (int j = 0; j < 1280; j++)
			{
				Point P = { j,i };
				if (inTriangle(Verticies, P))
				{
					glVertex2d(P.x, P.y);
				}
			}
		}
	}
	else
	{
		Line(Verticies[0], Verticies[1], color);
		Line(Verticies[1], Verticies[2], color);
		Line(Verticies[2], Verticies[0], color);
	}
	setColor(WHITE);
}

void Line(Point beg, Point end, Color color)
{
	setColor(color);
	bool steep = false;

	if (abs(beg.x - end.x) < abs(beg.y - end.y))
	{
		swap(&beg.x, &beg.y);
		swap(&end.x, &end.y);

		steep = true;
	}

	if (beg.x > end.x)
	{
		swap(&beg.x, &end.x);
		swap(&beg.y, &end.y);
	}

	int deltaX = end.x - beg.x;
	int deltaY = end.y - beg.y;
	int deltaErr = abs(deltaY) * 2;
	int Err = 0;
	int y = beg.y;

	for (int i = beg.x; i <= end.x; i++)
	{
		if (steep)
		{
			glVertex2d(y, i);
		}
		else
		{
			glVertex2d(i, y);
		}
		Err += deltaErr;
		if (Err > deltaX)
		{
			y += (end.y > beg.y ? 1 : -1);
			Err -= deltaX * 2;
		}
	}
	setColor(WHITE);
}

void Polygon(int size, Point p[], Color c)
{
	for (int i = 0; i < size - 1; i++)
	{
		Line(p[i], p[i + 1], c);
	}

	Line(p[0], p[size - 1], c);
}