#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>
#include "color.h"
#include "shape.h"


void timer(int t);

Point c = { 230, 350 };
Point o = { 0,0 };
Point p = { 330,300 };
Point d = { 35,300 };
Point e = { 234,576 };

void setscreen()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 1280, 720, 0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
//    Rectangle(d, e, true, RED);
//    Polygon(5, l, RED);
    glEnd();
    glFlush();

}

void timer(int t)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 144, timer, 0);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Testing");
    glutTimerFunc(1000, timer, 0);
    setscreen();
    glutDisplayFunc(display);
    glutMainLoop();

}
