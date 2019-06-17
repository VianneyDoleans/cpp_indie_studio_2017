#include <cmath>
#include "AAccelerable.hpp"

AAccelerable::AAccelerable(unsigned int speedVelocity) : _speedVelocity(speedVelocity), _acceleration(0, 0, 0) {
}

AAccelerable::AAccelerable(const AAccelerable &aAccelerable) : _speedVelocity(aAccelerable._speedVelocity), _acceleration(aAccelerable._acceleration){
}

AAccelerable::~AAccelerable() {
}

unsigned int AAccelerable::speedVelocity() const {
  return this->_speedVelocity;
}

const irr::core::vector3df &AAccelerable::acceleration() const {
  return this->_acceleration;
}

void AAccelerable::speedVelocity(const unsigned int speedVelocity) {
  this->_speedVelocity = speedVelocity;
}

void AAccelerable::acceleration(const irr::core::vector3df &acceleration) {
  this->_acceleration = acceleration;
}

void AAccelerable::applyAcceleration(const irr::core::vector3df &acceleration) {
  this->_acceleration += acceleration;
  double speedRatio = this->speed() / this->speedVelocity();
  if (speedRatio > 1)
    this->_acceleration /= speedRatio;
}

double AAccelerable::speed() const {
  return std::sqrt(std::pow(this->acceleration().X, 2) + std::pow(this->acceleration().Y, 2) + std::pow(this->acceleration().Z, 2));
}

AAccelerable &AAccelerable::operator=(const AAccelerable &aAccelerable) {
  if (this != &aAccelerable)
  {
    this->acceleration(aAccelerable.acceleration());
    this->speedVelocity(aAccelerable.speedVelocity());
  }
  return *this;
}

void AAccelerable::applyFriction(double deltaTime, irr::core::vector3df direction, unsigned int weight) {
  irr::core::vector3df intermediate(this->acceleration());
  irr::core::vector3df friction;

  intermediate.rotationToDirection(direction);
  intermediate += this->acceleration();
  if (this->speed() != 0)
    intermediate *= intermediate.getLength() / this->speed();
  else
    intermediate = irr::core::vector3df(0, 0, 0);
  friction = -(intermediate * 0.05 / 100) * deltaTime * (weight / 100);
  this->applyAcceleration(friction);
}
