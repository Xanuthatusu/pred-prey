#include "creature_app.h"
#include "glut_app.h"

#include "Predator.h"
#include "Prey.h"

#include <stdlib.h>
#include <time.h>

CreatureApp::CreatureApp(
    int screen_x,
    int screen_y,
    int grid_width,
    int grid_height,
    int num_pred,
    int num_prey) : mCurrentCreatureIndex(0), mGridWidth(grid_width), mGridHeight(grid_height) {

  srand(time(0));
  int preyAdded = 0;
  int predAdded = 0;
  for(int i=0; i < num_pred + num_prey; i++) {
    if (preyAdded >= num_prey) {
      mCreatures.push_back(new Predator);
    } else if (predAdded >= num_pred) {
      mCreatures.push_back(new Prey);
    } else {
      if (rand() % 2 + 1 == 1) {
        mCreatures.push_back(new Prey);
        preyAdded += 1;
      } else {
        mCreatures.push_back(new Predator);
        predAdded += 1;
      }
    }
  }
}

CreatureApp::~CreatureApp() {
  for (size_t i=0; i < mCreatures.size(); i++) {
    delete mCreatures[i];
  }
}

void CreatureApp::displayCallback() {
  glClear(GL_COLOR_BUFFER_BIT);

  for(size_t i=0; i < mCreatures.size(); i++) {
    mCreatures[i]->draw(mGridWidth, mGridHeight);
  }

  glutSwapBuffers();
}

void CreatureApp::keyboardCallback(unsigned char code, int x, int y) {
  switch (code) {
    case 'q':
    case 27:
      exit(0);
      break;
    case 's':
      mCreatures[mCurrentCreatureIndex]->update();
      mCurrentCreatureIndex += 1;
      if ((unsigned)mCurrentCreatureIndex >= mCreatures.size()) {
        mCurrentCreatureIndex = 0;
      }
      break;
    default:
      return;
  }

  glutPostRedisplay();
}

void CreatureApp::reshapeCallback(int w, int h) {
  g_screen_x = w;
  g_screen_y = h;

  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, 0, h);
  glMatrixMode(GL_MODELVIEW);
}

