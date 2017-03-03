#ifndef CREATURE_H
#define CREATURE_H

#include <utility>
#include <map>
#include <vector>
#include <string>

class Creature {
public:
  Creature(int x, int y, int gen);
  Creature(std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height);
  virtual ~Creature();
  virtual void update(std::vector<Creature *> &creatures, std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height);
  virtual void draw(int grid_width, int grid_height);
  void makeRandomMove(std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height);
  const char* getType();
protected:
  std::pair<int, int> mCoords;
  int mGeneration;
};

#endif // CREATURE_H

