#include "glut_app.h"
#include "Predator.h"
#include <random>
#include <time.h>

double g_screen_x = 700;
double g_screen_y = 500;

std::vector<Creature *> creatures;

int main(int argc, char **argv)
{
  for(int i=0; i < 15; i++) {
    if (i > 5) {
      creatures.push_back(new Predator);
    } else {
      //Prey newPrey;
      //creatures.push_back(newPrey);
    }
  }

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
      glutCreateWindow("This appears in the title bar");
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
