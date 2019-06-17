/*
** Bomb.cpp for cpp_indie_studio in /home/antoine/TEK2/INDIE_STUDIO/cpp_indie_studio/sources/model/PowerUp/Bomb.cpp
**
** Made by Antoine CAFFIER
** Login   <antoine.caffier@epitech.eu>
**
** Started on  Sun Jun 18 16:31:44 2017 Antoine CAFFIER
** Last update Sun Jun 18 16:31:44 2017 Antoine CAFFIER
*/

#include "Bomb.hpp"

model::Bomb::Bomb(engine::RessourceManager &rm)
  : APowerUp(), _device(rm.getDevice())
{
  irr::scene::IAnimatedMesh *mesh = rm.getRessource<engine::Ressource<engine::MESH>>(
    "ressources/Bomb/Bomb.obj", engine::RessourceManager::RType::MESH)->get();
  _node = _device->getSceneManager()->addAnimatedMeshSceneNode(mesh);
  _node->setPosition(irr::core::vector3df(100, 180, -300));
  _node->setScale(irr::core::vector3df(10.f, 10.f, 10.f));
  _node->setMaterialType(irr::video::EMT_SOLID);
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, LIGHT);
  irr::scene::ITriangleSelector *select = _device->getSceneManager()->createTriangleSelector(_node);
  _node->setTriangleSelector(select);
  select->drop();
}

model::Bomb::~Bomb()
{}

void 	model::Bomb::unlockPowerup(model::Player &player)
{
  if (static_cast<int>(player.getCar().getLife() - 2) < 0)
    player.getCar().setLife(0);
  else
    player.getCar().setLife(player.getCar().getLife() - 2);
}

void 	model::Bomb::grab()
{
  this->getNode()->setVisible(true);
}

void	model::Bomb::drop()
{
  this->getNode()->setVisible(false);
}