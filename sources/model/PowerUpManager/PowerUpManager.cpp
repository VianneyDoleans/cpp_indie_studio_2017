/*
** PowerUpManager.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/PowerUpManager/PowerUpManager.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sun Jun 18 13:30:27 2017 Montagne Valentin
** Last update Sun Jun 18 13:30:27 2017 Montagne Valentin
*/

#include "RessourceManager.hpp"
#include "PowerUpManager.hpp"

model::PowerUpManager::PowerUpManager(engine::RessourceManager &rm)
:	_rm(rm), _device(rm.getDevice())
{}

model::PowerUpManager::~PowerUpManager()
{}

void			model::PowerUpManager::update(std::vector<PlayerRef> &players)
{
  for (auto &p:players)
  {
    for (auto &pw : _pows)
    {
      APowerUp		&power = *pw.get();

      power.rotate();
      if (isTaking(p.get().getCar(), power))
	{
	  power.unlockPowerup(p);
	  power.setState(APowerUp::State::NOT);
	  power.drop();
	  power.getTimer().start();
	}
      if (canRespawn(power))
      {
	power.getTimer().drop();
	power.getTimer().resetTimer();
	power.setState(APowerUp::State::ACTIVE);
	power.grab();
      }
    }
  }
}

bool 			model::PowerUpManager::isTaking(const model::Car &car,
							    const model::APowerUp &p) {
  return (p.isActive() && car.getCar()->getTransformedBoundingBox().intersectsWithBox(p.getNode()->getTransformedBoundingBox()));
}

bool model::PowerUpManager::canRespawn(model::APowerUp &p) {
  return (!p.isActive() && p.getTimer().getElapsedTime() >= 3);
}

void model::PowerUpManager::grabAll(void) {
  for (auto &p : _pows)
    p.get()->grab();
}

void model::PowerUpManager::dropAll(void) {
  for (auto &p : _pows)
    p.get()->drop();
}
