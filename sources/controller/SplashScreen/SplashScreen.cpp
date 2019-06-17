/*
** SplashScreen.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/controller/SplashScreen/SplashScreen.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sun Jun 18 16:13:43 2017 Montagne Valentin
** Last update Sun Jun 18 16:13:44 2017 Montagne Valentin
*/

#include		"MRessource.hpp"
#include 		"SplashScreen.hpp"

controller::SplashScreen::SplashScreen(core::ModelManager *manager,
				       engine::RessourceManager *ressources,
				       core::MyEventReceiver *event,
				       core::System *system)
  : AController(manager, ressources, event, system), _view(manager, ressources)
{}

controller::SplashScreen::~SplashScreen() {}

controller::state controller::SplashScreen::run() {
  model::Timer			timer;
  engine::MRessource		*music =
    _ressources->getRessource<engine::MRessource>("ressources/flûte.ogg", engine::RessourceManager::RType::SOUND);

  timer.start();
  music->play(100);
  _view.moveCameraStatic({0, 0, 0}, {0, 0, 0});
  _view.addLight({0, 0, 0}, irr::video::SColorf(1.f, 1.f, 1.f, 1.f), 360);
  while (_device->run())
  {
    if (timer.getElapsedTime() > 20 || this->_event->IsKeyPressed(irr::KEY_RETURN))
    {
      this->_view.stop();
      this->_next = "UIMenu";
      this->_event->startEventProcess();
      music->stop();
      return (NEXT);
    }
    this->_ressources->getDevice()->getVideoDriver()->beginScene(true, true, irr::video::SColor(0,255,255,255));
    _view.drawImg(static_cast<irr::u32>(timer.getElapsedTime() * 12.75));
    this->_view.drawScene();
    this->_event->startEventProcess();
  }
  return (STOP);
}
