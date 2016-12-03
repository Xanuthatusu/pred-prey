#include "Creature.h"
#include "glut_app.h"
#include <iostream>

Creature::Creature() : mCoords(0, 0) {
  for(int i=0; i < 500; i++) {
    makeRandomMove();
  }
}

Creature::~Creature() {}

void Creature::makeRandomMove() {
  bool moved = false;
  while(!moved) {
    int direction = rand() % 4 + 1;
    switch (direction) {
      case 1:
        // North
        if(mCoords.first + 1 < 15) {
          mCoords.first += 1;
          moved = true;
        }
        break;
      case 2:
        // East
        if(mCoords.second + 1 < 20) {
          mCoords.second += 1;
          moved = true;
        }
        break;
      case 3:
        // South
        if(mCoords.first - 1 > 0) {
          mCoords.first -= 1;
          moved = true;
        }
        break;
      case 4:
        // West
        if(mCoords.second - 1 > 0) {
          mCoords.second -= 1;
          moved = true;
        }
        break;
      default:
        return;
    }
  }
}

void Creature::update() {}

void Creature::draw(int grid_width, int grid_height) {
  int deltaX = g_screen_x / grid_width;
  int deltaY = g_screen_y / grid_height;

  int x1 = deltaX * mCoords.first;
  int x2 = deltaX * (mCoords.first + 1);
  int y1 = deltaY * mCoords.second;
  int y2 = deltaY * (mCoords.second + 1);

  glBegin(GL_QUADS);
  glVertex2d(x1, y1);
  glVertex2d(x2, y1);
  glVertex2d(x2, y2);
  glVertex2d(x1, y2);
  glEnd();
}

