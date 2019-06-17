/*
** ModelManager.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/core/ModelManager/ModelManager.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat May 20 14:18:11 2017 Montagne Valentin
** Last update Sat May 20 14:18:11 2017 Montagne Valentin
*/

#include "ModelManager.hpp"

core::ModelManager::ModelManager()
{}

core::ModelManager::~ModelManager()
{}

void core::ModelManager::removeModel(const std::string &name) {
  this->_models.erase(name);
}

bool core::ModelManager::isHere(const std::string &name) {
  return (_models.find(name) != _models.end());
}
