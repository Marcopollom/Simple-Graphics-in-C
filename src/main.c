#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "../headers/everyone.h"

#include APP_FILE


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(PROGRAM_NAME);
    glutTimerFunc(1000, timer, 0);
    setscreen();
    glutDisplayFunc(display);
    glutMainLoop();
}
