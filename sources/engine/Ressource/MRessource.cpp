/*
** MRessource.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/engine/Ressource/MRessource.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat Jun 17 13:58:58 2017 Montagne Valentin
** Last update Sat Jun 17 13:58:58 2017 Montagne Valentin
*/

#include 				"System.hpp"
#include				"MRessource.hpp"

engine::MRessource::MRessource(const std::string &path)
  : _path(path)
{
  if (!_src.openFromFile(path))
    throw (core::LoadError(path));
}

engine::MRessource::MRessource(const engine::MRessource &other)
{
  if (!_src.openFromFile(other._path))
    throw (core::LoadError(other._path));
}

engine::MRessource::~MRessource() {}

void engine::MRessource::play(unsigned int volume) {
  _src.setVolume(static_cast<float>(volume));
  _src.play();
}

void engine::MRessource::stop(void) {
  _src.stop();
}

sf::Music &engine::MRessource::get(void) {
  return (_src);
}

const std::string &engine::MRessource::getPath(void) const {
  return (_path);
}
