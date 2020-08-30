#include "headers/everyone.h"

Point c = { 230, 350 };
Point o = { 0,0 };
Point p = { 330,300 };
Point d = { 35,300 };
Point e = { 234,576 };


void display()
{
    start();

    Rectangle(o, c, true, RED);

    end();
}