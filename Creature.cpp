#include "Creature.h"
#include "glut_app.h"
#include <iostream>

void DrawText(double x, double y, const char *string)
{
  void *font = GLUT_BITMAP_9_BY_15;

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
	
  size_t len, i;
  glRasterPos2d(x, y);
  len = strlen(string);
  for (i = 0; i < len; i++) 
    {
      glutBitmapCharacter(font, string[i]);
    }

  glDisable(GL_BLEND);
}

Creature::Creature(int x, int y, int gen) : mCoords(x, y), mGeneration(gen) {}

Creature::Creature(std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height) : mCoords(0, 0), mGeneration(0) {
  bool foundRandomLocation = false;
  while (!foundRandomLocation) {
    int randomX = rand() % grid_width;
    int randomY = rand() % grid_height;
    if (grid.find(std::make_pair(randomX, randomY)) == grid.end()) {
      foundRandomLocation = true;
      mCoords = std::make_pair(randomX, randomY);
    }
  }
  grid[std::make_pair(mCoords.first, mCoords.second)] = this;
}

Creature::~Creature() {}

void Creature::makeRandomMove(std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height) {
  grid.erase(std::make_pair(mCoords.first, mCoords.second));

  std::map<std::pair<int, int>, Creature *>::iterator northernNeighbor = grid.find(std::make_pair(mCoords.first, mCoords.second + 1));
  std::map<std::pair<int, int>, Creature *>::iterator easternNeighbor = grid.find(std::make_pair(mCoords.first + 1, mCoords.second));
  std::map<std::pair<int, int>, Creature *>::iterator southernNeighbor = grid.find(std::make_pair(mCoords.first, mCoords.second - 1));
  std::map<std::pair<int, int>, Creature *>::iterator westernNeighbor = grid.find(std::make_pair(mCoords.first - 1, mCoords.second));

  bool moved = false;
  bool tried[4] = { false, false, false, false };
  while(!moved) {
    int direction = rand() % 4 + 1;
    if (tried[0] && tried[1] && tried[2] && tried[3]) {
      moved = true;
    }
    switch (direction) {
      case 1:
        // North
        if(mCoords.second + 1 < grid_height + 1 && northernNeighbor == grid.end() && not tried[0]) {
          mCoords.second += 1;
          moved = true;
        }
        tried[0] = true;
        break;
      case 2:
        // East
        if(mCoords.first + 1 < grid_width + 1 && easternNeighbor == grid.end() && not tried[1]) {
          mCoords.first += 1;
          moved = true;
        }
        tried[1] = true;
        break;
      case 3:
        // South
        if(mCoords.second - 1 > 0 && southernNeighbor == grid.end() && not tried[2]) {
          mCoords.second -= 1;
          moved = true;
        }
        tried[2] = true;
        break;
      case 4:
        // West
        if(mCoords.first - 1 > 0 && westernNeighbor == grid.end() && not tried[3]) {
          mCoords.first -= 1;
          moved = true;
        }
        tried[3] = true;
        break;
      default:
        return;
    }
  }

  grid[std::make_pair(mCoords.first, mCoords.second)] = this;
}

void Creature::update(std::vector<Creature *> &creatures, std::map<std::pair<int, int>, Creature *> &grid, int grid_width, int grid_height) {}

void Creature::draw(int grid_width, int grid_height) {
  int deltaX = g_screen_x / grid_width;
  int deltaY = g_screen_y / grid_height;

  int x1 = deltaX * mCoords.first;
  int x2 = deltaX * (mCoords.first - 1);
  int y1 = deltaY * mCoords.second;
  int y2 = deltaY * (mCoords.second - 1);

  glBegin(GL_QUADS);
  glVertex2d(x1, y1);
  glVertex2d(x2, y1);
  glVertex2d(x2, y2);
  glVertex2d(x1, y2);
  glEnd();

  std::string str = std::to_string(mGeneration);

  glColor3d(0,0,0);
  DrawText(double(x2), double(y2), str.c_str());
}

const char* Creature::getType() {
  char const *string = "generic";
  return string;
}

