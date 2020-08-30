#pragma once
#include "color.h"
#include <stdbool.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

typedef struct Point
{
    float x, y;

} Point;

void Rectangle(Point beg, Point end, bool Fill, Color color);

void Circle(struct Point Center, int radius, Color color);

void Triangle(Point Verticies[3], bool Fill, Color color);

void Line(Point beg, Point end, Color color);

void Polygon(int size, Point p[], Color c);

void Pixel(float x, float y);
