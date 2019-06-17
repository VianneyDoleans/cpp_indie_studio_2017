/*
** Boost.cpp for cpp_indie_studio in /home/antoine/TEK2/INDIE_STUDIO/cpp_indie_studio/sources/model/PowerUp/Boost.cpp
**
** Made by Antoine CAFFIER
** Login   <antoine.caffier@epitech.eu>
**
** Started on  Thu Jun 15 19:17:07 2017 Antoine CAFFIER
** Last update Thu Jun 15 19:17:10 2017 Antoine CAFFIER
*/

#include "Player.hpp"
#include "Boost.hpp"

model::Boost::Boost(engine::RessourceManager &rm)
: APowerUp(), _device(rm.getDevice())
{
  irr::scene::IAnimatedMesh *mesh = rm.getRessource<engine::Ressource<engine::MESH>>("ressources/Flamer_Fuel/flamer_fuel.obj", engine::RessourceManager::RType::MESH)->get();
  _node = _device->getSceneManager()->addAnimatedMeshSceneNode(mesh);
  _node->setPosition(irr::core::vector3df(100,180,-300));
  _node->setScale(irr::core::vector3df(3.f, 3.f, 3.f));
  _node->setMaterialType(irr::video::EMT_SOLID);
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, LIGHT);
  irr::scene::ITriangleSelector *select = _device->getSceneManager()->createTriangleSelector(_node);
  _node->setTriangleSelector(select);
  select->drop();
}

model::Boost::~Boost()
{}

void 	model::Boost::unlockPowerup(model::Player &player)
{
  unsigned int turbo = player.getCar().getTurbo();

  player.getCar().setTurbo(turbo + 30);
}

void	model::Boost::grab()
{
  this->getNode()->setVisible(true);
}

void	model::Boost::drop()
{
  this->getNode()->setVisible(false);
}