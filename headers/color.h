#pragma once

typedef struct Color
{
	int R, G, B;
} Color;

//Color RED = { 255, 0, 0 };
//Color GREEN = { 0, 255, 0 };
//Color BLUE = { 0, 0, 255 };
//Color WHITE = { 255,255,255 };
//Color BLACK = { 0,0,0 };

Color RED, GREEN, BLUE, WHITE, BLACK;

void setColor(Color C);