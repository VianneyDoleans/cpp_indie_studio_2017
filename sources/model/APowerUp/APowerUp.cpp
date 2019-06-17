/*
** APowerUp.cpp for cpp_indie_studio in /home/antoine/TEK2/INDIE_STUDIO/cpp_indie_studio/sources/model/APowerUp/APowerUp.cpp
**
** Made by Antoine CAFFIER
** Login   <antoine.caffier@epitech.eu>
**
** Started on  Thu Jun 15 19:16:29 2017 Antoine CAFFIER
** Last update Thu Jun 15 19:16:29 2017 Antoine CAFFIER
*/

#include 				"APowerUp.hpp"

model::APowerUp::APowerUp()
  : AModel("PowerUp"), _node(nullptr), _state(State::ACTIVE)
{}

model::APowerUp::~APowerUp()
{}

irr::scene::IAnimatedMeshSceneNode 	*model::APowerUp::getNode() const
{
  return (this->_node);
}

model::Timer				&model::APowerUp::getTimer()
{
  return (this->_timer);
}

model::APowerUp::State 			model::APowerUp::getState(void) const {
  return (_state);
}

void 					model::APowerUp::setState(model::APowerUp::State state) {
  _state = state;
}

bool 					model::APowerUp::isActive(void) const {
  return (_state == State::ACTIVE);
}

void 					model::APowerUp::rotate() {
  _node->setRotation(_node->getRotation() + 1);
}
