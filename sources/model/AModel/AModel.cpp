/*
** Model.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/core/Model.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat May 20 14:02:08 2017 Montagne Valentin
** Last update Sat May 20 14:02:08 2017 Montagne Valentin
*/

#include "AModel.hpp"

model::AModel::AModel(const std::string &type)
  : _type(type)
{}

const std::string &model::AModel::getType(void) const {
  return (this->_type);
}

model::AModel::~AModel() {}
