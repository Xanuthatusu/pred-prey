#ifndef PREY_H
#define PREY_H

#include "Creature.h"

class Prey : public Creature {
public:
  Prey();
  void update();
  void draw(int grid_width, int grid_height);
};

#endif // PREY_H

