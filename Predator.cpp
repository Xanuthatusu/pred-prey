#include "Predator.h"
#include "glut_app.h"
#include <iostream>

Predator::Predator() : Creature() {}

void Predator::printType() {
  std::cout << "I am a Predator Creature" << std::endl;
}

int Predator::getX() const {
  return mCoords.first;
}

int Predator::getY() const {
  return mCoords.second;
}

void Predator::update() {
  makeRandomMove(mCoords.first, mCoords.second);
}

void Predator::printLocation() {
  std::cout << "x: " << mCoords.first << "\ty: " << mCoords.second << std::endl;
}

void Predator::draw() {
  int deltaX = g_screen_x / 15;
  int deltaY = g_screen_y / 20;

  int x1 = deltaX * mCoords.first;
  int x2 = deltaX * (mCoords.first + 1);
  int y1 = deltaY * mCoords.second;
  int y2 = deltaY * (mCoords.second + 1);

  glColor3d(1, 0, 0);
  glBegin(GL_QUADS);
  glVertex2d(x1, y1);
  glVertex2d(x2, y1);
  glVertex2d(x2, y2);
  glVertex2d(x1, y2);
  glEnd();
}

