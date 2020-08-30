#include "../headers/everyone.h"

void swap(float* a, float* b)
{
	float temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void timer(int t)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / SCREEN_FPS, timer, 0);

}

void start()
{
	glClear(GL_COLOR_BUFFER_BIT);;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
}

void end()
{
	glEnd();
    glFlush();
}

void setscreen()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
}