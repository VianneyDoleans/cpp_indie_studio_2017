/*
** CarEffects.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Car/CarEffects.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 07 17:24:18 2017 Montagne Valentin
** Last update Wed Jun 07 17:24:18 2017 Montagne Valentin
*/

#include <iostream>
#include "CarEffects.hpp"

model::CarEffects::CarEffects(irr::IrrlichtDevice &device,
			      model::Car &car)
  : _device(device), _car(car),
    _fire(_device.getSceneManager()->addParticleSystemSceneNode(false)),
    _smoke(_device.getSceneManager()->addParticleSystemSceneNode(false))
{}

model::CarEffects::~CarEffects() {
}

void model::CarEffects::update(void) {
  if (_car.getLife() < _car.getLifeMax() / 2) {
    updateFire();
    updateSmoke();
    _fire->setVisible(true);
    _smoke->setVisible(true);
  }
  else
  {
    _fire->setVisible(false);
    _smoke->setVisible(false);
  }
}

void model::CarEffects::updateFire(void) {
  irr::core::vector3df 		pos = _car.getPosition();
  irr::u32 			rate = (_car.getLifeMax() / 2 - _car.getLife()) * 200;
  irr::scene::IParticleEmitter	*em = _fire->createBoxEmitter(

    irr::core::aabbox3d<irr::f32>(_car.getCar()->getBoundingBox()),		// emitter size
    irr::core::vector3df(0.0f,0.05f,0.0f),					// initial direction
    rate, rate,									// emit rate
    irr::video::SColor(0,255,0,0),						// darkest color
    irr::video::SColor(0,240,200,10),						// brightest color
    100,200,0,									// min and max age, angle
    irr::core::dimension2df(3.f,3.f),						// min size
    irr::core::dimension2df(6.f,6.f));						// max size

  _fire->setEmitter(em);
  em->drop();
  pos.Y += 5;
  _fire->setPosition(pos);
  _fire->setScale(_car.getCar()->getScale());
  _fire->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

void model::CarEffects::updateSmoke(void) {
  irr::core::vector3df 		pos = _car.getPosition();
  irr::u32 			rate = (_car.getLifeMax() / 2 - _car.getLife()) * 200;
  irr::scene::IParticleEmitter	*em = _smoke->createBoxEmitter(

    irr::core::aabbox3d<irr::f32>(_car.getCar()->getBoundingBox()),		// emitter size
    irr::core::vector3df(0.f,0.1f,0.f),						// initial direction
    rate - 100, rate,								// emit rate
    irr::video::SColor(0,0,0,0),						// darkest color
    irr::video::SColor(0,255,255,255),						// brightest color
    500,1000,0,									// min and max age, angle
    irr::core::dimension2df(2.f,2.f),						// min size
    irr::core::dimension2df(5.f,5.f));						// max size

  _smoke->setEmitter(em);
  em->drop();
  pos.Y += 30;
  _smoke->setPosition(pos);
  _smoke->setScale(_car.getCar()->getScale());
  _smoke->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

void model::CarEffects::stop(void) {
  _fire->setVisible(false);
  _smoke->setVisible(false);
}
