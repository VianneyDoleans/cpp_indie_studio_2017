/*
** Basic.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Circuit/Basic/Basic.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 08 20:45:40 2017 Montagne Valentin
** Last update Thu Jun 08 20:45:41 2017 Montagne Valentin
*/

#include 	<iostream>
#include 	"Reparation.hpp"
#include 	"Basic.hpp"
#include	"Boost.hpp"
#include 	"Bomb.hpp"

model::Basic::Basic(engine::RessourceManager &rm)
  : ACircuit(rm, CAMERAPOSITION_BASIC,
	    *(rm.getRessource<engine::Ressource<engine::MESH>>(MESHPATH_BASIC, engine::RessourceManager::RType::MESH)->get())),
    _rm(rm)
{
  _startPos.push_back({-135, 200, -190});
  _startPos.push_back({-135, 200, -290});
  _startPos.push_back({-135, 200, -390});
  _startPos.push_back({-135, 200, -490});
  _checkPoints.push_back({10, 180, -130, 10, 180, -600});
  _checkPoints.push_back({230, 180, 53, 600, 180, 53});
  _checkPoints.push_back({-610, 180, 55, -220, 180, 12});

  model::PowerUpManager &pwm = _colman.getPUManager();
  pwm.spawn<model::Boost>({-385, 200, 63});
  pwm.spawn<model::Boost>({-27, 200, 196});
  pwm.spawn<model::Bomb>({421, 200, 63});
  pwm.spawn<model::Bomb>({182, 200, -127});
  pwm.dropAll();

  _colman.getPUManager().spawn<model::Boost>({40, 200, -300});
  _colman.getPUManager().dropAll();
  setPosition(irr::core::vector3df(0,-150,0));
  _node->setScale({100.f, 100.f, 100.f});
  _playerScale = 1;
}

model::Basic::~Basic() {

}

void model::Basic::grab(void) {
  this->_node->setVisible(true);
}

void model::Basic::drop(void) {
  this->_node->setVisible(false);
  this->_colman.getPUManager().dropAll();
}
