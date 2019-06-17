//
// Sinder.cpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/model/Car/Sindir
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Thu Jun	15 11:21:22 2017 Guillaume Bouxin
// Last update	Thu Jun	15 11:21:22 2017 Guillaume Bouxin
//

#include "Sinder.hpp"

model::Sinder::Sinder(engine::RessourceManager &rm)
  : _rm(rm)
{
  engine::Ressource<engine::MESH> 	*mesh = _rm.getRessource<engine::Ressource<engine::MESH>>(MESHPATH_SINDER, engine::RessourceManager::RType::MESH);
  irr::scene::ISceneManager		*sm = _rm.getDevice()->getSceneManager();
  irr::scene::IAnimatedMeshSceneNode	*car = sm->addAnimatedMeshSceneNode(mesh->get());

  car->setPosition(irr::core::vector3df(0,0,0));
  car->setScale(irr::core::vector3df(4.f, 4.f, 4.f));
  car->setMaterialType(irr::video::EMT_SOLID);
  car->setMaterialFlag(irr::video::EMF_LIGHTING, LIGHT);
  setCar(car);
  setName("Sinder");
  setWeight(2500);
  _select = _rm.getDevice()->getSceneManager()->createTriangleSelector(_car);
  car->setTriangleSelector(_select);
  _select->drop();
  this->speedVelocity(15);
}

model::Sinder::~Sinder() {}