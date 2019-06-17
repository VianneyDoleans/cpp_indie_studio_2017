//
// Car.cpp for cpp_indie_studio in /home/vianney/cpp_indie_studio/sources/core/Car
// 
// Made by Vianney
// Login   <vianney.doleans@epitech.eu>
// 
// Started on  Mon May 22 16:29:15 2017 Vianney
// Last update Tue Jun 13 17:16:29 2017 Vianney
//

#include	<iostream>
#include <cmath>
#include	"Car.hpp"

model::Car::Car()
  : AModel("Car"), _state(State::ALIVE), _weight(0), _life(0),
    _currentLife(0), _speed(0), _turbo(0), _car(nullptr),
    _direction(1, 0, 0), _rotation(0)
{}
model::Car::~Car()
{}

const irr::core::vector3df 			&model::Car::getPosition() const {
  return (_car->getPosition());
}

const irr::core::vector3df			&model::Car::getDirection() const
{
  return (_direction);
}

void						model::Car::setDirection(const irr::core::vector3df &direction)
{
  _direction = direction;
}

void						model::Car::setRotation(const float angle)
{
  _rotation = angle;
  _car->setRotation(irr::core::vector3df(0,  _rotation, 0));
}

const float					&model::Car::getRotation() const
{
  return (_rotation);
}

void						model::Car::move(float deltaTime)
{
  float deg;
  irr::core::vector3df result;
  irr::core::vector3df npos;
  irr::core::vector3df direction(1, 0, 0);

  deg = static_cast<float>(this->_rotation * M_PI / 180);
  direction.X = std::cos(deg);
  direction.Z = -std::sin(deg);
  npos = this->getPosition();
  result.X = (this->acceleration().X * deltaTime) + npos.X;
  result.Y = (this->acceleration().Y * deltaTime) + npos.Y;
  result.Z = (this->acceleration().Z * deltaTime) + npos.Z;

  this->setPosition(result);
  this->applyFriction(deltaTime, direction, this->_weight);
}

unsigned int					model::Car::getWeight() const {
  return (_weight);
}

unsigned int					model::Car::getLife() const {
  return (_currentLife);
}

unsigned int 					model::Car::getLifeMax() const {
  return (_life);
}

double					model::Car::getSpeed() const {
  return (this->speed());
}

unsigned int 					model::Car::getMaxSpeed() const {
  return (this->speedVelocity());
}

irr::scene::IAnimatedMeshSceneNode		*model::Car::getCar() const
{
  return (_car);
}

unsigned int 					model::Car::getTurbo() const {
  return (_turbo);
}

const std::string &model::Car::getName() const
{
  return (this->_name);
}

void						model::Car::setPosition(const irr::core::vector3df &position)
{
  if (_car == nullptr)
    return ;
  _car->setPosition(position);
}

void						model::Car::setWeight(unsigned int weight)
{
  int coef = (weight - 1000) / 100;

  _weight = weight;
  _life = static_cast<unsigned int>(10 + coef);
  _currentLife = _life;
  _maxSpeed = static_cast<unsigned int>(100 - (coef * 5));
}

void						model::Car::setLife(unsigned int life)
{
  _currentLife = life;
  if (_currentLife <= 0)
    _state = State::BROKEN;
  else
    _state = State::ALIVE;
}

void						model::Car::setSpeed(int speed)
{
  _speed = speed;
}

void						model::Car::setCar(irr::scene::IAnimatedMeshSceneNode *car)
{
  _car = car;
}

void 						model::Car::setTurbo(unsigned int turbo) {
  _turbo = turbo;
}

void 						model::Car::grab(void) {
  _car->setVisible(true);
}

void 						model::Car::drop(void) {
  _car->setVisible(false);
}

void model::Car::accelerate(float speed) {
  float deg;
  irr::core::vector3df direction(1, 0, 0);

  deg = static_cast<float>(this->_rotation * M_PI / 180);
  direction.X = std::cos(deg);
  direction.Z = -std::sin(deg);
  this->applyAcceleration(direction * speed);
}

void model::Car::decelerate(float speed) {
  float deg;
  irr::core::vector3df direction(1, 0, 0);

  deg = static_cast<float>(this->_rotation * M_PI / 180);
  direction.X = std::cos(deg);
  direction.Z = -std::sin(deg);
  this->applyAcceleration(direction * -speed);
}

irr::scene::ITriangleSelector 			*model::Car::getSelect() const {
  return (_select);
}

model::Car::State 				model::Car::getState() const {
  return (_state);
}

void 						model::Car::setState(model::Car::State state) {
  _state = state;
}

irr::core::vector3df 				model::Car::getDirectionnal(void) const {
  irr::core::vector3df rotate;
  double rot;

  rot = _rotation * M_PI / 180;
  rotate.X = static_cast<float>(std::cos(rot)) * _direction.X + 0 * _direction.Y + static_cast<float>(std::sin(rot)) * _direction.Z;
  rotate.Z = static_cast<float>((-std::sin(rot))) * _direction.X + 0 * _direction.Y + _direction.Z * static_cast<float>(std::cos(rot));
  return (rotate);
}

void model::Car::setName(const std::string &name)
{
  this->_name = name;
}

void model::Car::breakSpeed() {
  double		acceleration;
  irr::core::vector3df	acceleration_vector;

  acceleration = 5.0 / 100.0;
  if (this->speed() >= 0)
    acceleration *= -1;
  acceleration_vector = acceleration * this->acceleration();
  this->applyAcceleration(acceleration_vector);
}

std::ostream					&operator<<(std::ostream &os, model::Car &car)
{
  irr::core::vector3df pos = car.getPosition();

  os << "<Car>" << std::endl
     << "Position : " << pos.X << " " << pos.Y << " " << pos.Z << std::endl
     << "Weight : " << car.getWeight() << std::endl
     << "Life : " << car.getLife() << "/" << car.getLifeMax() << std::endl
     << "Speed : " << car.getSpeed() << "/" << car.getMaxSpeed() << " | Turbo : " << car.getTurbo() << std::endl
     << "Acceleration : " << car.speed();
  return (os);
}
