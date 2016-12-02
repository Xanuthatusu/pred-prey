#ifndef PREDATOR_H
#define PREDATOR_H

#include "Creature.h"

class Predator: public Creature {
public:
  Predator();
  void update();
  void draw(int grid_width, int grid_height);
};

#endif // PREDATOR_H

