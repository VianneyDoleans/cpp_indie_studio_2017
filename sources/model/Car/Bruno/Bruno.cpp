//
// Bruno.cpp for indie_studio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/model/Car/Bruno
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Wed Jun	14 13:38:18 2017 Guillaume Bouxin
// Last update	Wed Jun	14 13:38:18 2017 Guillaume Bouxin
//

#include 				"Bruno.hpp"
#include <iostream>

model::Bruno::Bruno(engine::RessourceManager &rm)
  : _rm(rm)
{
  engine::Ressource<engine::MESH> 	*mesh =
    _rm.getRessource<engine::Ressource<engine::MESH>>(MESHPATH_BRUNO, engine::RessourceManager::RType::MESH);
  irr::scene::ISceneManager		*sm = _rm.getDevice()->getSceneManager();
  irr::scene::IAnimatedMeshSceneNode	*car = sm->addAnimatedMeshSceneNode(mesh->get());

  car->setPosition(irr::core::vector3df(0,0,0));
  car->setScale(irr::core::vector3df(5.f, 5.f, 5.f));
  car->setMaterialType(irr::video::EMT_SOLID);
  car->setMaterialFlag(irr::video::EMF_LIGHTING, LIGHT);
  setCar(car);
  setName("Bruno");
  _select = _rm.getDevice()->getSceneManager()->createOctreeTriangleSelector(_car->getMesh(), _car);
  car->setTriangleSelector(_select);
  _select->drop();
  setWeight(3000);
  this->speedVelocity(15);
}

model::Bruno::~Bruno() {}