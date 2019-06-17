/*
** Reparation.cpp for cpp_indie_studio in /home/antoine/TEK2/INDIE_STUDIO/cpp_indie_studio/sources/model/PowerUp/Reparation.cpp
**
** Made by Antoine CAFFIER
** Login   <antoine.caffier@epitech.eu>
**
** Started on  Sun Jun 18 16:32:19 2017 Antoine CAFFIER
** Last update Sun Jun 18 16:32:19 2017 Antoine CAFFIER
*/

#include "Reparation.hpp"

model::Reparation::Reparation(engine::RessourceManager &rm)
  : APowerUp(), _device(rm.getDevice())
{
  irr::scene::IAnimatedMesh *mesh = rm.getRessource<engine::Ressource<engine::MESH>>(
    "ressources/Heart/ItmHeart.obj", engine::RessourceManager::RType::MESH)->get();
  _node = _device->getSceneManager()->addAnimatedMeshSceneNode(mesh);
  _node->setPosition(irr::core::vector3df(100, 300, -300));
  _node->setScale(irr::core::vector3df(10.f, 10.f, 10.f));
  _node->setMaterialType(irr::video::EMT_SOLID);
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, LIGHT);
  irr::scene::ITriangleSelector *select = _device->getSceneManager()->createTriangleSelector(_node);
  _node->setTriangleSelector(select);
  select->drop();
}

model::Reparation::~Reparation()
{}

void 	model::Reparation::unlockPowerup(model::Player &player)
{
  player.getCar().setLife(player.getCar().getLifeMax());
}

void 	model::Reparation::grab()
{
  this->getNode()->setVisible(true);
}

void	model::Reparation::drop()
{
  this->getNode()->setVisible(false);
}