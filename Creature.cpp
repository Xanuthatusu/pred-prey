#include "Creature.h"
#include <iostream>

Creature::Creature() : mCoords(0, 0) {
  for(int i=0; i < 500; i++) {
    makeRandomMove(mCoords.first, mCoords.second);
  }
}

void Creature::printType() {
  std::cout << "I'm just a generic Creature" << std::endl;
}

void Creature::makeRandomMove(int &x, int &y) {
  bool moved = false;
  while(!moved) {
    int direction = rand() % 4 + 1;
    switch (direction) {
      case 1:
        // North
        if(x + 1 < 15) {
          x += 1;
          moved = true;
        }
        break;
      case 2:
        // East
        if(y + 1 < 20) {
          y += 1;
          moved = true;
        }
        break;
      case 3:
        // South
        if(x - 1 > 0) {
          x -= 1;
          moved = true;
        }
        break;
      case 4:
        // West
        if(y - 1 > 0) {
          y -= 1;
          moved = true;
        }
        break;
      default:
        return;
    }
  }
}

void Creature::update() {}
void Creature::printLocation() {}
void Creature::draw() {}

