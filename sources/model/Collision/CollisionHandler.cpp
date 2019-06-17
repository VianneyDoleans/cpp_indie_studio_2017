/*
** CollisionHandler.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Collision/CollisionHandler.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 15 13:48:39 2017 Montagne Valentin
** Last update Thu Jun 15 13:48:40 2017 Montagne Valentin
*/

#include <iostream>
#include "CollisionHandler.hpp"

model::CollisionHandler::CollisionHandler(Collision col, double timeout)
  : AModel("Collision"), _col(col), _timeout(timeout)
{
  _timer.start();
}

model::CollisionHandler::~CollisionHandler() {
}

double model::CollisionHandler::getTimeout(void) const {
  return (_timeout);
}

bool model::CollisionHandler::isEnd(void) const {
  return (_timer.getElapsedTime() >= _timeout);
}

const model::Collision &model::CollisionHandler::getCol(void) const {
  return (_col);
}

void model::CollisionHandler::grab(void) {}

void model::CollisionHandler::drop(void) {}

const model::Timer model::CollisionHandler::getTimer(void) const {
  return (_timer);
}