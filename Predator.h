#ifndef PREDATOR_H
#define PREDATOR_H

#include "Creature.h"
#include "Prey.h"
#include <vector>

class Predator: public Creature {
public:
  Predator(int x, int y);
  Predator(std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height);
  void update(std::vector<Creature *> &creatures, std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height);
  std::vector<Prey *> canEat(std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height);
  void draw(int grid_width, int grid_height);
private:
  int timeUntilReproduce;
  int timeUntilDeath;
};

#endif // PREDATOR_H

