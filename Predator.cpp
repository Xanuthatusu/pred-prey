#include "Predator.h"
#include "glut_app.h"
#include <iostream>
#include <algorithm>

Predator::Predator(int x, int y) : Creature(x, y), timeUntilReproduce(4), timeUntilDeath(3) {}

Predator::Predator(std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height) : Creature(grid, grid_width, grid_height), timeUntilReproduce(8), timeUntilDeath(3) {}

void Predator::update(std::vector<Creature *> &creatures, std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height) {
  if (timeUntilDeath == 0) {
    grid.erase(mCoords);
    creatures.erase(std::remove(creatures.begin(), creatures.end(), this), creatures.end());
  } else if (timeUntilReproduce == 0) {
    std::map<std::pair<int, int>, Creature *>::iterator northernNeighbor = grid.find(std::make_pair(mCoords.first, mCoords.second + 1));
    std::map<std::pair<int, int>, Creature *>::iterator easternNeighbor = grid.find(std::make_pair(mCoords.first + 1, mCoords.second));
    std::map<std::pair<int, int>, Creature *>::iterator southernNeighbor = grid.find(std::make_pair(mCoords.first, mCoords.second - 1));
    std::map<std::pair<int, int>, Creature *>::iterator westernNeighbor = grid.find(std::make_pair(mCoords.first - 1, mCoords.second));

    std::pair<int, int> newCoords;

    bool done = false;
    bool canReproduce = true;
    bool tried[4] = { false, false, false, false };
    while (!done) {
      int direction = rand() % 4 + 1;
      if (tried[0] && tried[1] && tried[2] && tried[3]) {
        canReproduce = false;
        break;
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

    if (canReproduce) {
      Predator *newPred = new Predator(newCoords.first, newCoords.second);
      creatures.push_back(newPred);
      grid[newCoords] = newPred;
      timeUntilReproduce = 4;
    }
  } else {
    std::vector<Prey *> prey = canEat(grid, grid_width, grid_height);
    if (prey.size() > 0) {
      int preyToEat = rand() % prey.size();
      grid.erase(mCoords);
      mCoords = prey[preyToEat]->getCoords();
      grid[mCoords] = this;

      for (std::map<std::pair<int, int>, Creature *>::iterator it=grid.begin(); it != grid.end(); it++) {
        if (it->second == prey[preyToEat]) {
          grid.erase(it->first);
          break;
        }
      }

      creatures.erase(std::remove(creatures.begin(), creatures.end(), prey[preyToEat]), creatures.end());

      timeUntilDeath = 3;
      timeUntilReproduce -= 1;
    } else {
      makeRandomMove(grid, grid_width, grid_height);
      timeUntilDeath -= 1;
    }
  }
}

std::vector<Prey *> Predator::canEat(std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height) {
  std::vector<Prey *> vector;

  std::map<std::pair<int, int>, Creature *>::iterator northernNeighbor = grid.find(std::make_pair(mCoords.first, mCoords.second + 1));
  std::map<std::pair<int, int>, Creature *>::iterator easternNeighbor = grid.find(std::make_pair(mCoords.first + 1, mCoords.second));
  std::map<std::pair<int, int>, Creature *>::iterator southernNeighbor = grid.find(std::make_pair(mCoords.first, mCoords.second - 1));
  std::map<std::pair<int, int>, Creature *>::iterator westernNeighbor = grid.find(std::make_pair(mCoords.first - 1, mCoords.second));

  if (northernNeighbor != grid.end()) {
    Prey *prey = dynamic_cast<Prey *>(northernNeighbor->second);
    if (prey != 0) {
      vector.push_back(prey);
    }
  }

  if (easternNeighbor != grid.end()) {
    Prey *prey = dynamic_cast<Prey *>(easternNeighbor->second);
    if (prey != 0) {
      vector.push_back(prey);
    }
  }

  if (southernNeighbor != grid.end()) {
    Prey *prey = dynamic_cast<Prey *>(southernNeighbor->second);
    if (prey != 0) {
      vector.push_back(prey);
    }
  }

  if (westernNeighbor != grid.end()) {
    Prey *prey = dynamic_cast<Prey *>(westernNeighbor->second);
    if (prey != 0) {
      vector.push_back(prey);
    }
  }

  return vector;
}

void Predator::draw(int grid_width, int grid_height) {
  glColor3d(1, 0, 0);
  Creature::draw(grid_width, grid_height);
}

