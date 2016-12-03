#include "Predator.h"
#include "glut_app.h"

Predator::Predator() : Creature() {}

void Predator::update() {
  makeRandomMove();
}

void Predator::draw(int grid_width, int grid_height) {
  glColor3d(1, 0, 0);
  Creature::draw(grid_width, grid_height);
}

