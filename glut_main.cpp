#include "glut_app.h"
#include "Predator.h"
#include "creature_app.h"

double g_screen_x = 700;
double g_screen_y = 500;

CreatureApp g_app(g_screen_x, g_screen_y, 15, 20, 5, 10);

void display() {
  g_app.displayCallback();
}

void keyboard(unsigned char code, int x, int y) {
  g_app.keyboardCallback(code, x, y);
}

void reshape(int w, int h) {
  g_app.reshapeCallback(w, h);
}

void mouse(int mouse_button, int state, int x, int y) {}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(g_screen_x, g_screen_y);
  glutInitWindowPosition(50, 50);

  int fullscreen = 0;
  if (fullscreen) 
    {
      glutGameModeString("800x600:32");
      glutEnterGameMode();
    } 
  else 
    {
      glutCreateWindow("Predator and Prey");
    }

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);

  glColor3d(0,0,0); // forground color
  glClearColor(0, 0, 0, 0); // background color

  initialize_app();

  glutMainLoop();

  return 0;
}
