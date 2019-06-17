/*
** BlueBird.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Car/BlueBird/BlueBird.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 07 11:24:18 2017 Montagne Valentin
// Last update Thu Jun  8 09:33:50 2017 montag-v
*/

#include <iostream>
#include 				"BlueBird.hpp"

model::BlueBird::BlueBird(engine::RessourceManager &rm)
: _rm(rm)
{
  engine::Ressource<engine::MESH> 	*mesh =
  _rm.getRessource<engine::Ressource<engine::MESH>>(MESHPATH_BLUEBIRD, engine::RessourceManager::RType::MESH);
  irr::scene::ISceneManager		*sm = _rm.getDevice()->getSceneManager();
  irr::scene::IAnimatedMeshSceneNode	*car = sm->addAnimatedMeshSceneNode(mesh->get());

  car->setPosition(irr::core::vector3df(0,0,0));
  car->setScale(irr::core::vector3df(50.f, 50.f, 50.f));
  car->setMaterialType(irr::video::EMT_SOLID);
  car->setMaterialFlag(irr::video::EMF_LIGHTING, LIGHT);
  setCar(car);
  setName("BlueBird");
  _select = _rm.getDevice()->getSceneManager()->createTriangleSelector(_car);
  car->setTriangleSelector(_select);
  _select->drop();
  setWeight(1000);
  this->speedVelocity(15);
}

model::BlueBird::~BlueBird() {}
