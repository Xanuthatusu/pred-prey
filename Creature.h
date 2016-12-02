#ifndef CREATURE_H
#define CREATURE_H

#include <utility>

class Creature {
public:
  Creature();
  virtual void printType();
  virtual void update();
  virtual void printLocation();
  virtual void draw();
  void makeRandomMove(int &x, int &y);
protected:
  std::pair<int, int> mCoords;
};

#endif // CREATURE_H

