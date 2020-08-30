#pragma once

#include "shape.h"
#include "color.h"
#include "helper.h"


#ifdef _WIN32 || __linux__
  #include <GL/glut.h>
#else
  #include <GLUT/glut.h>
#endif

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define SCREEN_FPS 60
#define PROGRAM_NAME "Window"


#define APP_FILE "../app.c"
