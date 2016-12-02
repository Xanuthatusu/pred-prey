#ifndef CREATURE_APP_H
#define CREATURE_APP_H

#include "Creature.h"
#include <vector>

class CreatureApp {
public:
  CreatureApp(int screen_x, int screen_y, int grid_width, int grid_height, int num_pred, int num_prey);
  void displayCallback();
  void keyboardCallback(unsigned char code, int x, int y);
  void reshapeCallback(int w, int h);
private:
  std::vector<Creature *> mCreatures;
  int mCurrentCreatureIndex;
};

#endif // CREATURE_APP_H

