//
// SunnyGo.cpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/model/Car/SunnyGo
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Thu Jun	15 09:41:29 2017 Guillaume Bouxin
// Last update	Thu Jun	15 09:41:29 2017 Guillaume Bouxin
//

#include "SunnyGo.hpp"

model::SunnyGo::SunnyGo(engine::RessourceManager &rm)
  : _rm(rm)
{
  engine::Ressource<engine::MESH> 	*mesh = _rm.getRessource<engine::Ressource<engine::MESH>>(MESHPATH_SUNNYGO, engine::RessourceManager::RType::MESH);
  irr::scene::ISceneManager		*sm = _rm.getDevice()->getSceneManager();
  irr::scene::IAnimatedMeshSceneNode	*car = sm->addAnimatedMeshSceneNode(mesh->get());

  car->setPosition(irr::core::vector3df(0,0,0));
  car->setScale(irr::core::vector3df(25.f, 25.f, 25.f));
  car->setMaterialType(irr::video::EMT_SOLID);
  car->setMaterialFlag(irr::video::EMF_LIGHTING, LIGHT);
  setCar(car);
  setName("SunnyGo");
  _select = _rm.getDevice()->getSceneManager()->createTriangleSelector(_car);
  car->setTriangleSelector(_select);
  _select->drop();
  setWeight(1000);
  this->speedVelocity(15);
}

model::SunnyGo::~SunnyGo() {}