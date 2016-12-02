#ifndef _GLUT_APP_H_
#define _GLUT_APP_H_

/*
 * These #ifdef clauses ensure that the glut library header
 * files will be found, regardless of your environment.
 * Don't change them.
 */
#ifdef _WIN32
  #include "glut.h"
#else
  #ifdef __APPLE__
    #include <GLUT/glut.h>
  #else
    #include <GL/glut.h>
  #endif
#endif

#include "Creature.h"
#include <vector>

// Global variables defined in glut_main.cpp
extern double g_screen_x;
extern double g_screen_y;

//
// Application specific functions
// app.cpp
void initialize_app();

#endif /* _GLUT_APP_H_ */
/* Local Variables: */
/* mode:c++         */
/* End:             */
