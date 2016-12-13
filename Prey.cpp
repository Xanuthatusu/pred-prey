#include "Prey.h"
#include "glut_app.h"
#include <iostream>

Prey::Prey(int x, int y) : Creature(x, y), timeUntilReproduce(3) {}

Prey::Prey(std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height) : Creature(grid, grid_width, grid_height), timeUntilReproduce(3) {}

void Prey::update(std::vector<Creature *> &creatures, std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height) {
  makeRandomMove(grid, grid_width, grid_height);
  timeUntilReproduce -= 1;
  if (timeUntilReproduce == 0) {
    std::map<std::pair<int, int>, Creature *>::iterator northernNeighbor = grid.find(std::make_pair(mCoords.first, mCoords.second + 1));
    std::map<std::pair<int, int>, Creature *>::iterator easternNeighbor = grid.find(std::make_pair(mCoords.first + 1, mCoords.second));
    std::map<std::pair<int, int>, Creature *>::iterator southernNeighbor = grid.find(std::make_pair(mCoords.first, mCoords.second - 1));
    std::map<std::pair<int, int>, Creature *>::iterator westernNeighbor = grid.find(std::make_pair(mCoords.first - 1, mCoords.second));

    std::pair<int, int> newCoords;

    bool done = false;
    bool tried[4] = { false, false, false, false };
    while (!done) {
      int direction = rand() % 4 + 1;
      if (tried[0] && tried[1] && tried[2] && tried[3]) {
        done = true;
      }
      switch (direction) {
        case 1:
          // North
          if(mCoords.second + 1 < grid_height && northernNeighbor == grid.end() && not tried[0]) {
            newCoords = std::make_pair(mCoords.first, mCoords.second + 1);
            done = true;
          }
          tried[0] = true;
          break;
        case 2:
          // East
          if(mCoords.first + 1 < grid_width && easternNeighbor == grid.end() && not tried[1]) {
            newCoords = std::make_pair(mCoords.first + 1, mCoords.second);
            done = true;
          }
          tried[1] = true;
          break;
        case 3:
          // South
          if(mCoords.second - 1 > 0 && southernNeighbor == grid.end() && not tried[2]) {
            newCoords = std::make_pair(mCoords.first, mCoords.second - 1);
            done = true;
          }
          tried[2] = true;
          break;
        case 4:
          // West
          if(mCoords.first - 1 > 0 && westernNeighbor == grid.end() && not tried[3]) {
            newCoords = std::make_pair(mCoords.first - 1, mCoords.second);
            done = true;
          }
          tried[3] = true;
          break;
        default:
          return;
      }
    }

    Prey *newPrey = new Prey(newCoords.first, newCoords.second);
    creatures.push_back(newPrey);
    grid[newCoords] = newPrey;
    timeUntilReproduce = 3;
  }
}

void Prey::draw(int grid_width, int grid_height) {
  glColor3d(0, 1, 0);
  Creature::draw(grid_width, grid_height);
}

std::pair<int, int> Prey::getCoords() {
  return mCoords;
}

