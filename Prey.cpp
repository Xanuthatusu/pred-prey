#include "Prey.h"
#include "glut_app.h"

Prey::Prey() : Creature() {}

void Prey::update() {
  makeRandomMove();
}

void Prey::draw(int grid_width, int grid_height) {
  glColor3d(0, 1, 0);
  Creature::draw(grid_width, grid_height);
}

