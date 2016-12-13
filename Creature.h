#ifndef CREATURE_H
#define CREATURE_H

#include <utility>
#include <map>
#include <vector>

class Creature {
public:
  Creature(int x, int y);
  Creature(std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height);
  virtual ~Creature();
  virtual void update(std::vector<Creature *> &creatures, std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height);
  virtual void draw(int grid_width, int grid_height);
  void makeRandomMove(std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height);
  char* getType();
protected:
  std::pair<int, int> mCoords;
};

#endif // CREATURE_H

