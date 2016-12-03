#ifndef CREATURE_H
#define CREATURE_H

#include <utility>

class Creature {
public:
  Creature();
  virtual ~Creature();
  virtual void update();
  virtual void draw(int grid_width, int grid_height);
  void makeRandomMove();
protected:
  std::pair<int, int> mCoords;
};

#endif // CREATURE_H

