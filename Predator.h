#ifndef PREDATOR_H
#define PREDATOR_H

#include "Creature.h"

class Predator: public Creature {
public:
  Predator();
  int getX() const;
  int getY() const;
  void printType();
  void update();
  void printLocation();
  void draw();
};

#endif // PREDATOR_H

