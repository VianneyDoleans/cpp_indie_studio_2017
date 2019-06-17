/*
** UIOptions.cpp for cpp_indie_studio in /home/charles/Documents/C++/cpp_indie_studio/sources/view/UIOptions.cpp
**
** Made by Charles des Pommare
** Login   <charles.des-pommare@epitech.eu>
**
** Started on  Sat Jun 17 15:45:09 2017 Charles des Pommare
** Last update Sat Jun 17 15:45:09 2017 Charles des Pommare
*/

#include "UIOptions.hpp"

controller::UIOptions::order			controller::UIOptions::leftKey() {
  switch (this->currentButton)
  {
    case VOLUME:
      if (this->_volume > 0)
	this->_volume -= 10;
      _system->setVolume(this->_volume);
      break;
    case SPLIT:
      this->_split = !this->_split;
      _system->setModeCamera(this->_split);
      break;
    case AI:
      if (this->_laps > 1)
	this->_laps--;
      _system->setNbrLap(this->_laps);
      break;
    case PLAYERS:
      if (this->_players > 1)
	this->_players--;
      _system->setNbrPlayer(this->_players);
      break;
  }
  return (controller::UIOptions::DO_NOTHING);
}

controller::UIOptions::order			controller::UIOptions::rightKey() {
  switch (this->currentButton)
  {
    case VOLUME:
      if (this->_volume < 100)
	this->_volume += 10;
      _system->setVolume(this->_volume);
      break;
    case SPLIT:
      this->_split = !this->_split;
      _system->setModeCamera(this->_split);
      break;
    case AI:
      if (this->_laps < 20)
	this->_laps++;
      _system->setNbrLap(this->_laps);
      break;
    case PLAYERS:
      if (this->_players < 2)
	this->_players++;
      _system->setNbrPlayer(this->_players);
      break;
  }
  return (controller::UIOptions::DO_NOTHING);
}

controller::UIOptions::order			controller::UIOptions::escapeKey() {
  return (controller::UIOptions::NEXT);
}

controller::UIOptions::order			controller::UIOptions::downKey() {
  for (unsigned int i = 0; i < this->buttonTab.size(); i++) {
    if (this->buttonTab[i] == this->currentButton && this->buttonTab[i] != PLAYERS) {
      this->currentButton = this->buttonTab[i + 1];
      this->cursor.Y = this->cursor.Y + 200;
      break;
    }
  }
  return (controller::UIOptions::DO_NOTHING);
}

controller::UIOptions::order			controller::UIOptions::upKey() {
  for (unsigned int i = 0; i < this->buttonTab.size(); i++) {
    if (this->buttonTab[i] == this->currentButton && this->buttonTab[i] != VOLUME) {
      this->currentButton = this->buttonTab[i - 1];
      this->cursor.Y = this->cursor.Y - 200;
      break;
    }
  }
  return (controller::UIOptions::DO_NOTHING);
}

controller::UIOptions::UIOptions(core::ModelManager *manager, engine::RessourceManager *ressources,
				 core::MyEventReceiver *event, core::System *system)
: AController(manager, ressources, event, system), _view(manager, ressources)
{
  this->keyboard.push_back(KeyHandler(irr::KEY_RIGHT, &UIOptions::rightKey));
  this->keyboard.push_back(KeyHandler(irr::KEY_LEFT, &UIOptions::leftKey));
  this->keyboard.push_back(KeyHandler(irr::KEY_DOWN, &UIOptions::downKey));
  this->keyboard.push_back(KeyHandler(irr::KEY_UP, &UIOptions::upKey));
  this->keyboard.push_back(KeyHandler(irr::KEY_ESCAPE, &UIOptions::escapeKey));
  this->_volume = _system->getVolume();
  this->_laps = _system->getNbrLap();
  this->_split = _system->getModeCamera();
  this->_players = _system->getNbrPlayer();
  this->buttonTab.push_back(VOLUME);
  this->buttonTab.push_back(SPLIT);
  this->buttonTab.push_back(AI);
  this->buttonTab.push_back(PLAYERS);
  this->cursor = irr::core::position2d<irr::s32>(360,190);
  irr::scene::IAnimatedMesh			*mesh =  this->_device->getSceneManager()->getMesh("ressources/Circuit/Menu/Wii_Coconut_Mall.obj");
  this->animator = this->_smgr->createFlyStraightAnimator({0, 0, -100}, {0, 0, 200}, 12000, true, true);
  this->node = this->_device->getSceneManager()->addOctreeSceneNode(mesh, nullptr);
  this->node->setVisible(false);
}

const irr::core::position2d<irr::s32>		&controller::UIOptions::getCursor() const {
  return (this->cursor);
}

controller::UIOptions::order			controller::UIOptions::findKey(irr::EKEY_CODE key) {
  controller::UIOptions::order 			order;

  for (auto &it : this->keyboard) {
    if (it.first == key)
    {
      order = (this->*it.second)();
      return (order);
    }
  }
  return (DO_NOTHING);
}

controller::state		controller::UIOptions::run() {

  this->_view.begin();

  irr::video::ITexture				*tex =  this->_driver->getTexture("ressources/Menu/play-button.png");
  irr::u32					time = this->_device->getTimer()->getTime();
  irr::core::rect<irr::s32> 			imp1(0,0,95,100);
  irr::core::rect<irr::s32> 			imp2(0,0,0,0);
  const irr::core::position2d<irr::s32>		&pos = this->getCursor();

  this->node->setVisible(true);
  this->currentButton = VOLUME;
  this->cursor = irr::core::position2d<irr::s32>(360, 190);
  this->_smgr->addCameraSceneNode()->setPosition(irr::core::vector3df(1899.7, 239.585, 1554.22));

  node->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
  node->setMaterialType(irr::video::EMT_SOLID);
  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);

  node->addAnimator(animator);
  this->_smgr->getActiveCamera()->setFarValue(100000);

  this->node->setVisible(true);
  while (this->_device->run())
  {
    for (auto &it : this->keyboard)
    {
      if (this->_event->IsKeyPressed(it.first))
      {
	switch (findKey(it.first))
	{
	  case NEXT:
	    this->_next = "UIMenu";
	    this->_event->startEventProcess();
	    node->setVisible(false);
	    this->_view.stop();
	    return (controller::NEXT);
	  case STOP:
	    node->setVisible(false);
	    this->_event->startEventProcess();
	    this->_view.stop();
	    this->_ressources->getRessource<engine::MRessource>("ressources/Theme.ogg", engine::RessourceManager::RType::SOUND)->stop();
	    return (controller::STOP);
	  default:
	    break;
	}
      }
    }

    this->_event->startEventProcess();
    this->_driver->beginScene(true, true, irr::video::SColor(255, 200, 200, 200));
    time = this->_device->getTimer()->getTime();
    this->_smgr->drawAll();

    this->_view.dispArrow(tex, pos, time, imp1, imp2);

    this->_ressources->getDevice()->getGUIEnvironment()->drawAll();
    this->_view.drawSelections(this->_volume, this->_split, this->_laps, this->_players);
    this->_view.drawTextOptions();
    this->_driver->endScene();
  }
  this->_next = "SelectCarMenu";
  return (controller::NEXT);
}

controller::UIOptions::~UIOptions() {
  this->animator->drop();
}