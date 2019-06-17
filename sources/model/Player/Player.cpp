//
// Player.cpp for cpp_indie_studio in /home/vianney/cpp_indie_studio/sources/core/Player
// 
// Made by Vianney
// Login   <vianney.doleans@epitech.eu>
// 
// Started on  Mon May 22 17:00:38 2017 Vianney
// Last update Mon Jun  5 18:39:25 2017 Vianney
//

#include		"Player.hpp"

model::Player::Player(const std::string &name, Car &car)
: AModel("Player"), _name(name), _car(car), _currentCheckPointID(0), _lap(0), _bestLap(0), _lastLap(0)
{}

model::Player::~Player()
{}

model::Car			&model::Player::getCar()
{
  return (_car);
}

size_t				model::Player::getRanking() const
{
  return (_ranking);
}

void				model::Player::setCar(model::Car &car)
{
  _car = car;
}

void				model::Player::setRanking(size_t ranking)
{
  _ranking = ranking;
}

const irr::core::vector3df &model::Player::getPosition(void) const {
  return (_car.getPosition());
}

void model::Player::setPosition(const irr::core::vector3df &pos) {
  _car.setPosition(pos);
}

const std::string &model::Player::getName() const {
  return (_name);
}

void model::Player::grab(void) {
  _car.grab();
  _state = State::ALIVE;
}

void model::Player::drop(void) {
  _car.drop();
  _state = State::FREEZE;
}

size_t model::Player::getCurrentCheckPointID() const {
  return (_currentCheckPointID);
}

void model::Player::setCurrentCheckPointID(size_t checkPoint) {
  _currentCheckPointID = checkPoint;
}

void model::Player::respawn()
{
  _state = State::ALIVE;
  _currentCheckPointID = 0;
  _car.setLife(getCar().getLifeMax());
  _car.setRotation(0);
  _car.accelerate(0);
  _car.setTurbo(0);
}

bool model::Player::die(void)
{
  if (getCar().getLife() <= 0) {
    _state = State::DEAD;
    return (true);
  }
  return (false);
}

size_t model::Player::getLap() {
  return (_lap);
}

void model::Player::setLap(size_t lap)
{
  _lap = lap;
}

double model::Player::getTime() const
{
  return (_time);
}

void model::Player::setTime(double time)
{
  _time = time;
}

double model::Player::getBestLap() {
  return (_bestLap);
}

double model::Player::getlastLap() {
  return (_lastLap);
}

void model::Player::setBestLap(double time)
{
  _bestLap = time;
}

void model::Player::setlastLap(double time)
{
  _lastLap = time;
}

model::Timer &model::Player::getTimeBoost()
{
  return (_timeBoost);
}
