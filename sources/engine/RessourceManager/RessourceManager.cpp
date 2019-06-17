/*
** RessourceManager.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/engine/RessourceManager.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri May 19 17:15:41 2017 Montagne Valentin
** Last update Fri May 19 17:15:41 2017 Montagne Valentin
*/

#include <System/System.hpp>
#include "MRessource.hpp"
#include "RessourceManager.hpp"

engine::RessourceManager::RessourceManager(irr::IrrlichtDevice &d)
  : _device(d), _smgr(_device.getSceneManager()),
    _driver(_device.getVideoDriver()), _env(_device.getGUIEnvironment())
{}

engine::RessourceManager::~RessourceManager()
{
  this->_ressources.clear();
}

std::shared_ptr<engine::IRessource> engine::RessourceManager::createRessource(const std::string &path,
									      engine::RessourceManager::RType &type) {
  if (type == RType::MESH)
    _ressources.push_back(
      std::make_shared<Ressource<engine::MESH>>( Ressource<engine::MESH>(path, loadMesh(path)) ));
  else if (type == RType::TEXTURE)
    _ressources.push_back(
      std::make_shared<Ressource<engine::TEX>>( Ressource<engine::TEX>(path, loadTex(path)) ));
  else if (type == RType::SOUND)
    _ressources.push_back(
      std::make_shared<MRessource>( MRessource(path)));
  else
    _ressources.push_back(
      std::make_shared<Ressource<engine::FONT>>( Ressource<engine::FONT>(path, loadFont(path)) ));
  return (_ressources.back());
}

void engine::RessourceManager::removeRessource(const engine::IRessource &res) {
  for (auto it = _ressources.begin(); it != _ressources.end(); it++)
    if (it->get()->getPath() == res.getPath())
      _ressources.erase(it);
}

engine::MESH engine::RessourceManager::loadMesh(const std::string &path) {
  MESH mesh = _smgr->getMesh(path.c_str());
  if (mesh == nullptr)
    throw (core::LoadError(path));
  return (mesh);
}

engine::TEX engine::RessourceManager::loadTex(const std::string &path) {
  TEX tex = _driver->getTexture(path.c_str());
  if (tex == nullptr)
    throw (core::LoadError(path));
  return (tex);
}

engine::FONT engine::RessourceManager::loadFont(const std::string &path) {
  FONT font = _env->getFont(path.c_str());
  if (font == nullptr)
    throw (core::LoadError(path));
  return (font);
}

irr::IrrlichtDevice *engine::RessourceManager::getDevice(void) const {
  return (&this->_device);
}
