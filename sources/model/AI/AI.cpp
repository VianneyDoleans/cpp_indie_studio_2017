#include <iostream>
#include <cmath>
#include "AI.hpp"

model::AI::AI(model::Car &car, unsigned int id) : Player("AI" + id, car), _target(0, 0, 0) {
}

model::AI::~AI() {
}

const irr::core::vector3df &model::AI::getTarget() const {
  return this->_target;
}

void model::AI::setTarget(const irr::core::vector3df &target) {
  this->_target = target;
}

void model::AI::dump() const {
  std::cout << this->_car << std::endl;
}

void model::AI::takeDecision() {
  irr::core::vector2df direction;
  irr::core::vector2df acceleration;
  irr::core::vector3df pos;
  float angle;
  float maxAngle;

  pos = this->getPosition();
  direction.X = this->_target.X - pos.X;
  direction.Y = this->_target.Z - pos.Z;
  acceleration.X = this->getCar().getDirectionnal().X;
  acceleration.Y = this->getCar().getDirectionnal().Z;
  maxAngle = 5 * (this->getCar().speed() / this->getCar().speedVelocity());
  angle = direction.getAngle() - acceleration.getAngle();
  if (std::abs(angle) > maxAngle)
    angle = (angle / abs(angle)) * maxAngle;
  this->getCar().setRotation((this->getCar().getRotation() + angle));
  this->getCar().accelerate(2);
}