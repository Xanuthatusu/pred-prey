#ifndef PREY_H
#define PREY_H

#include "Creature.h"

class Prey : public Creature {
public:
  Prey(int x, int y, int gen);
  Prey(std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height);
  void update(std::vector<Creature *> &creatures, std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height);
  void draw(int grid_width, int grid_height);
  std::pair<int, int> getCoords();
private:
  int timeUntilReproduce;
};

#endif // PREY_H

