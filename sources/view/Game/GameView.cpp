/*
** GameView.cpp for cpp_indie_studio in /home/vianney/cpp_indie_studio/sources/view/Game/GameView.cpp
**
** Made by Vianney DOLEANS
** Login   <vianney.doleans@epitech.eu>
**
** Started on  Sat Jun 17 15:17:34 2017 Vianney DOLEANS
** Last update Sat Jun 17 15:17:34 2017 Vianney DOLEANS
*/

#include	"ACircuit.hpp"
#include 	"GameView.hpp"

void view::GameView::stop()
{
  std::string name;
  int		i;

  i = 0;
  name = "Player1";
  for (unsigned int i = 1; (_mm->isHere(name) == true); i++)
  {
    if (i <= 2)
      _mm->getModel<model::Player>(name)->getCar().drop();
    name = "Player" + std::to_string(i + 1);
  }
  name = "Player1";
  for (unsigned int i = 1; (_mm->isHere(name) == true); i++)
  {
    if (i <= 2)
      _mm->getModel<model::Player>(name)->getCar().drop();
    name = "Player" + std::to_string(i + 1);
  }
  _mm->getModel<model::ACircuit>("Circuit")->drop();
  _score->remove();
  for (auto it = _cameraView.begin(); it != _cameraView.end(); ++it)
  {
    _cameraView[i]->remove();
    i++;
  }
  _cameraView.clear();
  irr::scene::ICameraSceneNode *newCamera = _rm->getDevice()->getSceneManager()->addCameraSceneNode(0, irr::core::vector3df(0, 0, 0), irr::core::vector3df(0, 0, 0));
  resolutionX = _rm->getDevice()->getVideoDriver()->getScreenSize().Width;
  resolutionY = _rm->getDevice()->getVideoDriver()->getScreenSize().Height;
  removeCamera();
  _rm->getDevice()->getSceneManager()->setActiveCamera(newCamera);
  _rm->getDevice()->getVideoDriver()->setViewPort(irr::core::rect<irr::s32>(0, 0, resolutionX, resolutionY));
  _rm->getDevice()->getSceneManager()->drawAll();
  removeLight(0);
}

view::GameView::GameView(core::ModelManager *mm, engine::RessourceManager *rm)
: AView(mm, rm)
{
}

view::GameView::~GameView()
{
}

void view::GameView::begin()
{
  _score =_rm->getDevice()->getSceneManager()->addCameraSceneNode(0, irr::core::vector3df(10000,0,0), irr::core::vector3df(0,0,0));
  addLight(irr::core::vector3df(0.0f, 400.0f, 0.0f), irr::video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 100000.0f);
}

#include <iostream>

void view::GameView::SplittingCamera()
{
  model::ACircuit *circuit = _mm->getModel<model::ACircuit>("Circuit");
  std::string name = "Player1";
  resolutionY = _rm->getDevice()->getVideoDriver()->getScreenSize().Height;
  resolutionX = _rm->getDevice()->getVideoDriver()->getScreenSize().Width;

  for (unsigned int i = 1; (_mm->isHere(name) == true); i++)
  {
    if (i <= 2)
      SplittingOneCamera(_mm->getModel<model::Player>(name), i - 1);
    name = "Player" + std::to_string(i + 1);
  }
  moveCameraStatic(circuit->getCameraPosition(), irr::core::vector3df(0,0,0));
  _camera->setFarValue(20000);
  _rm->getDevice()->getSceneManager()->setActiveCamera(_camera);
  _rm->getDevice()->getVideoDriver()->setViewPort(irr::core::rect<irr::s32>(resolutionX / 2, resolutionY / 2, resolutionX, resolutionY));
  _rm->getDevice()->getSceneManager()->drawAll();
  _score->setFarValue(20000);
  _rm->getDevice()->getSceneManager()->setActiveCamera(_score);
  _rm->getDevice()->getVideoDriver()->setViewPort(irr::core::rect<irr::s32>(0, resolutionY / 2, resolutionX / 2, resolutionY));
  _rm->getDevice()->getSceneManager()->drawAll();
}

void view::GameView::SplittingOneCamera(model::Player *player, int nb)
{
  model::ACircuit *circuit = _mm->getModel<model::ACircuit>("Circuit");
  const double cameraOffset = 600 * circuit->getPlayerScale();

  irr::core::vector3df pos = player->getPosition();

  resolutionY = _rm->getDevice()->getVideoDriver()->getScreenSize().Height;
  resolutionX = _rm->getDevice()->getVideoDriver()->getScreenSize().Width;
  if (nb <= 2)
    {
      _rm->getDevice()->getSceneManager()->setActiveCamera(_cameraView[nb]);
      _cameraView[nb]->setTarget(pos);
      pos.Y += cameraOffset;
      pos.X += cameraOffset / 2;
      pos.Z += cameraOffset / 2;
      _cameraView[nb]->setPosition(pos);
    }
  if (nb == 0)
    _rm->getDevice()->getVideoDriver()->setViewPort(irr::core::rect<irr::s32>(0, 0, resolutionX/2, resolutionY/2));
  if (nb == 1)
    _rm->getDevice()->getVideoDriver()->setViewPort(irr::core::rect<irr::s32>(resolutionX/2, 0, resolutionX, resolutionY/2));
  _rm->getDevice()->getSceneManager()->drawAll();
}
void view::GameView::initSplittingCamera()
{
  std::string name;

  name = "Player1";
  for (unsigned int i = 1; (_mm->isHere(name) == true); i++)
  {
    if (i <= 2)
    _cameraView.push_back(_rm->getDevice()->getSceneManager()->addCameraSceneNode(0, irr::core::vector3df(0,0,0), irr::core::vector3df(0,0,0)));
    name = "Player" + std::to_string(i + 1);
  }
}

void view::GameView::displayLap(std::vector<model::Player*> players)
{
  std::string lap;

  for (unsigned int i = 0; i < players.size(); i++)
  {
    lap = "Player" + std::to_string(i + 1) + " : " + std::to_string(players[i]->getLap()) + " Laps";
    drawText(lap, irr::core::rect<irr::s32>(100, 20 + i * 100, 300, 60), irr::video::SColor(255, 0, 100, 100));
  }
}

void view::GameView::drawTime(model::Timer *time)
{
  std::string lap = "Time : " + std::to_string(time->getElapsedTime());
  drawText(lap, irr::core::rect<irr::s32>(800, 20, 300, 60), irr::video::SColor(255, 0, 100, 100));
}
