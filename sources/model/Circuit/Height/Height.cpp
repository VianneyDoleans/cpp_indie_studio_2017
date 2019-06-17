/*
** Height.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Circuit/Height/Height.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat Jun 17 10:09:56 2017 Montagne Valentin
** Last update Sat Jun 17 10:09:57 2017 Montagne Valentin
*/

#include "Boost.hpp"
#include "Bomb.hpp"
#include "Reparation.hpp"
#include "Height.hpp"

model::Height::Height(engine::RessourceManager &rm)
  : ACircuit(rm, CAMERAPOSITION_HEIGHT,
	     *(rm.getRessource<engine::Ressource<engine::MESH>>(MESHPATH_HEIGHT, engine::RessourceManager::RType::MESH)->get())),
    _rm(rm)
{

  irr::scene::ILightSceneNode *node = _rm.getDevice()->getSceneManager()->addLightSceneNode(0, irr::core::vector3df(0,500,0),
							      irr::video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 100000.f);
  node->getLightData().AmbientColor.set(1.f, 1.f, 1.f);
  _light = node;
  _startPos.push_back({-3100, 350, 1600});
  _startPos.push_back({-3100, 350, 1400});
  _startPos.push_back({-3250, 350, 1600});
  _startPos.push_back({-3250, 350, 1400});
  _checkPoints.push_back({-2865, 320, 1935, -2865, 320, 1360});
  _checkPoints.push_back({835, 320, 1660, 835, 320, 1335});
  _checkPoints.push_back({650, 115, -445, 790, 115, -160});
  _checkPoints.push_back({-4170, 330, 490, -4485, 330, 460});
  model::PowerUpManager &pwm = _colman.getPUManager();
  pwm.spawn<model::Boost>({1283, 320, 1378});
  pwm.spawn<model::Boost>({294, 112, 60});
  pwm.spawn<model::Boost>({-3267, 444, -1125});
  pwm.spawn<model::Boost>({-4093, 333, 1163});
  pwm.spawn<model::Bomb>({1182, 320, 1510});
  pwm.spawn<model::Bomb>({142, 123, -5});
  pwm.spawn<model::Bomb>({-3120, 438, -1068});
  pwm.spawn<model::Bomb>({-4100, 319, 1346});
  pwm.spawn<model::Reparation>({1088, 320, 1648});
  pwm.spawn<model::Reparation>({-16, 132, -76});
  pwm.spawn<model::Reparation>({-2949, 431, -1001});
  pwm.spawn<model::Reparation>({-4106, 310, 1479});
  pwm.dropAll();

  setPosition(irr::core::vector3df(0,-200,0));
  _playerScale = 1;
  _node->setScale({20.f, 20.f, 20.f});
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

model::Height::~Height() {}

void model::Height::grab(void) {
  _node->setVisible(true);
  _light->setVisible(true);
}

void model::Height::drop(void) {
  _node->setVisible(false);
  _light->setVisible(false);
  _colman.getPUManager().dropAll();
}

