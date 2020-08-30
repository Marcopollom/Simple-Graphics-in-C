// Example use of Library

#include "headers/everyone.h"

Point p = {SCREEN_WIDTH, SCREEN_HEIGHT / 2 + 101};
Point rp = {SCREEN_WIDTH, SCREEN_HEIGHT / 2 - 101};
Point c = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
Point o = {0, 0};
Point edge = {SCREEN_WIDTH, SCREEN_HEIGHT};
Point SW = {SCREEN_WIDTH, 0};
Point SH = {0, SCREEN_HEIGHT};

void display()
{
    start();
    
    for (int i = 0; i < rp.x; i++)
        Pixel(i, rp.y);

    Line(o, edge, WHITE);
    Circle(c, 100, BLUE);
    Line(SW, SH, WHITE);

    for (int i = 0; i < p.x; i++)
        Pixel(i, p.y);

    end();
}