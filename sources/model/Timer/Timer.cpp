/*
** Timer.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Timer/Timer.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 16 09:56:44 2017 Montagne Valentin
** Last update Fri Jun 16 09:56:46 2017 Montagne Valentin
*/

#include "Timer.hpp"

model::Timer::Timer()
  : AModel("Timer"), _elapsdedTime(0), _isRunning(false)
{}

model::Timer::~Timer()
{}

void model::Timer::start(void) {
  _isRunning = true;
  _start = std::chrono::high_resolution_clock::now();
}

double model::Timer::getElapsedTime(void) const {
  std::chrono::duration<double> time =
    std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::high_resolution_clock::now() - _start);
  return (time.count() + _elapsdedTime);
}

void model::Timer::resetTimer()
{
  this->_elapsdedTime = 0;
}

void model::Timer::pause(void) {
  _isRunning = false;
  _elapsdedTime = getElapsedTime();
}

void model::Timer::stop(void) {
  _isRunning = false;
  this->_elapsdedTime = 0;
}

void model::Timer::grab(void) {
  start();
}

void model::Timer::drop(void) {
  pause();
}

bool model::Timer::run() {
  return (_isRunning);
}
