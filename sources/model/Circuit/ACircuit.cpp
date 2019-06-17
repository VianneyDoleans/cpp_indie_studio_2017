/*
** Circuit.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Circuit/Circuit.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 08 10:45:13 2017 Montagne Valentin
** Last update Thu Jun 08 10:45:13 2017 Montagne Valentin
*/

#include 	<iostream>
#include 	"ACircuit.hpp"

model::ACircuit::ACircuit(engine::RessourceManager &rm, irr::core::vector3df camPos,
			irr::scene::IAnimatedMesh &circuit)
  : AModel("ACircuit"), _device(*rm.getDevice()), _camPos(camPos), _playerScale(0), _mesh(circuit),
    _node(nullptr), _selector(nullptr), _colman(rm)
{
  _node = _device.getSceneManager()->addOctreeSceneNode(&_mesh);
  _node->setMaterialType(irr::video::EMT_SOLID);
  _node->setMaterialFlag(irr::video::EMF_LIGHTING, LIGHT);
}

model::ACircuit::~ACircuit() {}

irr::scene::IMeshSceneNode 		*model::ACircuit::getCircuit(void) const {
  return (_node);
}

const irr::core::vector3df 		&model::ACircuit::getPosition(void) const {
  return (_node->getPosition());
}

void 					model::ACircuit::setPosition(const irr::core::vector3df &pos) {
  _node->setPosition(pos);
}

void 					model::ACircuit::addPlayer(model::Player &player) {
  irr::scene::ISceneNode *playerCar = player.getCar().getCar();

  playerCar->setScale(playerCar->getScale() * _playerScale);
  _players.push_back(std::ref(player));
}

void 					model::ACircuit::removePlayer(model::Player &player) {
  for (auto it = _players.begin(); it != _players.end(); ++it)
    if (it->get().getName() == player.getName()) {
      _players.erase(it);
      break;
    }
}

void 					model::ACircuit::toStart(const std::string &playerName) {
  for (size_t id = 0; id < _startPos.size(); id++)
    if (_players[id].get().getName() == playerName) {
      _players[id].get().setPosition(_startPos[id]);
      break;
    }
}

void					model::ACircuit::link(irr::scene::ISceneNode *node) {
  _selector = _device.getSceneManager()->createOctreeTriangleSelector(&_mesh, _node, 256);
  _node->setTriangleSelector(_selector);
  irr::scene::ISceneNodeAnimator *anim =
    _device.getSceneManager()->createCollisionResponseAnimator(
      _selector, node, node->getBoundingBox().MaxEdge * node->getScale() / 2 - node->getBoundingBox().getCenter());
  _selector->drop();
  node->addAnimator(anim);
  anim->drop();
}

bool 					model::ACircuit::onCheckPoint(size_t checkPointID, model::Player &p) {
  size_t check = checkPointID;
  irr::scene::ISceneNode *selected;
  irr::core::vector3df intersection;
  irr::core::triangle3df hitTriangle;

  check %= _checkPoints.size();
  selected = _device.getSceneManager()->getSceneCollisionManager()->getSceneNodeAndCollisionPointFromRay(
    _checkPoints[check], intersection, hitTriangle);
  if (selected && selected == p.getCar().getCar())
    return (true);
  irr::core::line3df	line = _checkPoints[check];
  irr::core::vector3df	start = line.start;
  line.start = line.end;
  line.end = start;
  selected = _device.getSceneManager()->getSceneCollisionManager()->getSceneNodeAndCollisionPointFromRay(
    line, intersection, hitTriangle);
  return (selected && selected == p.getCar().getCar());
}

model::ACircuit::CollisionManager 	&model::ACircuit::getColManager(void) {
  return (_colman);
}

std::vector<model::PlayerRef> 		&model::ACircuit::
getPlayers(void) {
  return (_players);
}

const irr::core::vector3df 		&model::ACircuit::getCameraPosition(void) const {
  return (_camPos);
}

double 					model::ACircuit::getPlayerScale(void) const {
  return (_playerScale);
}

size_t 					model::ACircuit::getCheckpointsCount(void) const {
  return (_checkPoints.size());
}

const irr::core::line3df 		&model::ACircuit::getCheckPoint(size_t checkPointID) const {
  return (_checkPoints[checkPointID]);
}

const irr::core::vector3df 		model::ACircuit::getCheckPointCenter(size_t checkPointID) const {
  return (_checkPoints[checkPointID].getMiddle());
}

/*
 * Collision Manager
 */

model::ACircuit::CollisionManager::CollisionManager(engine::RessourceManager &rm)
  : _device(*rm.getDevice()), _pwm(rm)
{}

model::ACircuit::CollisionManager::~CollisionManager() {}

bool					model::ACircuit::CollisionManager::inCollision(Car &f,
						    Car &s) {
  return (f.getCar()->getTransformedBoundingBox().intersectsWithBox(s.getCar()->getTransformedBoundingBox()));
}

void 					model::ACircuit::CollisionManager::update(std::vector<PlayerRef> &players) {
  checkPlayersCollision(players);
  checkCollisions();
  _pwm.update(players);
}

void 					model::ACircuit::CollisionManager::checkPlayersCollision(std::vector<PlayerRef> &players) {
  Car *first, *second;

  for (auto &p : players)
    for (auto &s : players) {
      first = &p.get().getCar();
      second = &s.get().getCar();
      if (first != second && inCollision(*first, *second)
	  && (first->getState() == Car::State::TURBO || second->getState() == Car::State::TURBO)
	  && !isKnown(*first, *second))
	  addCollision(*first, *second);
    }
}

bool 					model::ACircuit::CollisionManager::isKnown(model::Car &f, model::Car &s) {
  Collision	collision;

  for (auto &col : _collisions)
  {
    collision = col.getCol();
    if ((collision.first == f.getCar() && collision.second == s.getCar())
	|| (collision.first == s.getCar() && collision.second == f.getCar()))
      return (true);
  }
  return (false);
}

void 					model::ACircuit::CollisionManager::addCollision(model::Car &f, model::Car &s) {
  _collisions.push_back(CollisionHandler(Collision(f.getCar(), s.getCar()), 1));
  if (s.getState() == Car::State::TURBO) {
    this->takeDamage(f, s.getWeight() / 500);
  }
  else {
    this->takeDamage(s, f.getWeight() / 500);
  }

  // Bellow have been added
  irr::core::vector3df deplacment;

  deplacment.X = s.getPosition().X - f.getPosition().X;
  deplacment.Y = 20;
  deplacment.Z = s.getPosition().Z - f.getPosition().Z;
  deplacment /= 2;
  f.applyAcceleration(-deplacment / ((f.getWeight() / 100) + (s.getWeight() / 200)));
  s.applyAcceleration(deplacment / (s.getWeight() / 200 + (s.getWeight())));
}

void 					model::ACircuit::CollisionManager::initCollision(std::vector<PlayerRef> &players) {
  _pwm.grabAll();
  for (size_t id = 0; id < players.size(); id++)
    for (size_t i = 0; i < players.size(); i++)
      if (id != i)
	linkCars(players[id].get().getCar(), players[i].get().getCar());
}

void 					model::ACircuit::CollisionManager::linkCars(model::Car &f, model::Car &s) {
  irr::scene::IAnimatedMeshSceneNode *node = s.getCar();
  irr::scene::ISceneNodeAnimator *anim =
          _device.getSceneManager()->createCollisionResponseAnimator(
                  f.getSelect(), node, s.getCar()->getBoundingBox().MaxEdge * s.getCar()->getScale() - s.getCar()->getBoundingBox().getCenter(),
                  irr::core::vector3df(0, 0, 0));

  node->addAnimator(anim);
  anim->drop();
}

void 					model::ACircuit::CollisionManager::checkCollisions(void) {
  for (auto it = _collisions.begin(); it != _collisions.end(); ++it)
    if (it->isEnd()) {
      _collisions.erase(it);
      it = _collisions.begin() - 1;
    }
}

void 					model::ACircuit::CollisionManager::takeDamage(model::Car &car, unsigned int damage) {
  unsigned int life = car.getLife();

  if (static_cast<int>(life - damage) >= 0)
    car.setLife(life - damage);
  else
    car.setLife(0);
}

model::PowerUpManager 	&model::ACircuit::CollisionManager::getPUManager(void) {
  return (_pwm);
}
