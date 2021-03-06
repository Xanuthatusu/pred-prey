#ifndef CREATURE_APP_H
#define CREATURE_APP_H

#include "Creature.h"
#include <vector>
#include <map>

class CreatureApp {
public:
  CreatureApp(int screen_x, int screen_y, int grid_width, int grid_height, int num_pred, int num_prey);
  ~CreatureApp();
  void displayCallback();
  void keyboardCallback(unsigned char code, int x, int y);
  void reshapeCallback(int w, int h);
private:
  std::map<std::pair<int, int>, Creature *> mGrid;
  std::vector<Creature *> mCreatures;
  int mCurrentCreatureIndex;
  int mGridWidth;
  int mGridHeight;
};

#endif // CREATURE_APP_H

