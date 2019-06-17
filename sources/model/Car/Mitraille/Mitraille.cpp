//
// Mitraille.cpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/model/Car/Mitraille
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Sat Jun	17 14:24:47 2017 Guillaume Bouxin
// Last update	Sat Jun	17 14:24:47 2017 Guillaume Bouxin
//

#include "Mitraille.hpp"

model::Mitraille::Mitraille(engine::RessourceManager &rm)
  : _rm(rm)
{
  engine::Ressource<engine::MESH> 	*mesh = _rm.getRessource<engine::Ressource<engine::MESH>>(MESHPATH_MITRAILLE, engine::RessourceManager::RType::MESH);
  irr::scene::ISceneManager		*sm = _rm.getDevice()->getSceneManager();
  irr::scene::IAnimatedMeshSceneNode	*car = sm->addAnimatedMeshSceneNode(mesh->get());

  car->setPosition(irr::core::vector3df(0,0,0));
  car->setScale(irr::core::vector3df(50.f, 50.f, 50.f));
  car->setMaterialType(irr::video::EMT_SOLID);
  car->setMaterialFlag(irr::video::EMF_LIGHTING, LIGHT);
  setCar(car);
  setName("Mitraille");
  setWeight(1000);
  _select = _rm.getDevice()->getSceneManager()->createTriangleSelector(_car);
  car->setTriangleSelector(_select);
  _select->drop();
  this->speedVelocity(15);
}

model::Mitraille::~Mitraille() {}