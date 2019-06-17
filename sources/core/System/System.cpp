//
// Created by vianney on 15/06/17.
//

#include "System.hpp"

core::System::System() : _nbrPlayer(2), _nbrLap(3), _modeCamera(1), _volume(100),
			 _timer(nullptr)
{
}

core::System::~System()
{
}

unsigned int core::System::getNbrPlayer() const
{
  return (_nbrPlayer);
}

unsigned int core::System::getNbrLap() const
{
  return (_nbrLap);
}

unsigned int core::System::getVolume() const {
  return (_volume);
}

void core::System::setNbrPlayer(unsigned int nb)
{
  _nbrPlayer = nb;
}

void core::System::setNbrLap(unsigned int nb)
{
  _nbrLap = nb;
}

void core::System::setVolume(unsigned int volume) {
  _volume = volume;
}

void core::System::setModeCamera(unsigned int mode)
{
  _modeCamera = mode;
}

unsigned int core::System::getModeCamera() const
{
  return _modeCamera;
}

void core::System::setTimer(model::Timer * timer)
{
  _timer = timer;
}

model::Timer *core::System::getTimer() const
{
  return (_timer);
}

core::LoadError::LoadError(std::string const &message)
  : _message(message)
{}

std::string const core::LoadError::getMessage() const {
  return ("LoadError: Couldn't load this => " + _message);
}
