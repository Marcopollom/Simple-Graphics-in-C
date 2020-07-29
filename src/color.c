#include <GL/glut.h>
#include "color.h"

void setColor(Color C)
{
	(float) C.R, C.B, C.G /= 255;

	glColor3f(C.R, C.G, C.B);

}

Color RED = { 255, 0, 0 };
Color GREEN = { 0, 255, 0 };
Color BLUE = { 0, 0, 255 };
Color WHITE = { 255,255,255 };
Color BLACK = { 0,0,0 };