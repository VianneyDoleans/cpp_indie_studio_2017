/*
** UIMenu.cpp for cpp_indie_studio in /home/charles/Documents/C++/cpp_indie_studio/sources/controller/UIMenu/UIMenu.cpp
**
** Made by Charles des Pommare
** Login   <charles.des-pommare@epitech.eu>
**
** Started on  Tue Jun 13 17:13:49 2017 Charles des Pommare
** Last update Tue Jun 13 17:13:50 2017 Charles des Pommare
*/

#include "UIMenu.hpp"

controller::UIMenu::order			controller::UIMenu::downKey() {
  controller::type 				oldType = this->currentButton;

  if (this->currentButton == this->buttonTab.begin()->second)
  {
    this->currentButton = controller::OPTIONS;
    this->cursor = irr::core::position2d<irr::s32>(85, 397);
    this->buttonTab[1].first->setBackground(ORANGE_BACKGROUND);
  }
  else if (this->currentButton == this->buttonTab[1].second)
  {
    this->currentButton = controller::QUIT;
    this->cursor = irr::core::position2d<irr::s32>(85, 597);
    this->buttonTab[2].first->setBackground(ORANGE_BACKGROUND);
  }
  else
    return (controller::UIMenu::DO_NOTHING);
  for (auto &it : this->buttonTab) {
    if (it.second == oldType)
      it.first->setBackground(BLUE_BACKGROUND);
  }
  return (controller::UIMenu::DO_NOTHING);
}

controller::UIMenu::order			controller::UIMenu::upKey() {
  controller::type 				oldType = this->currentButton;

  if (this->currentButton == this->buttonTab[1].second)
  {
    this->currentButton = controller::PLAY;
    this->cursor = irr::core::position2d<irr::s32>(85, 197);
    this->buttonTab.begin()->first->setBackground(ORANGE_BACKGROUND);
  }
  else if (this->currentButton == controller::QUIT)
  {
    this->currentButton = controller::OPTIONS;
    this->cursor = irr::core::position2d<irr::s32>(85, 397);
    this->buttonTab[1].first->setBackground(ORANGE_BACKGROUND);
  }
  else
    return (controller::UIMenu::DO_NOTHING);
  for (auto &it : this->buttonTab) {
    if (it.second == oldType)
      it.first->setBackground(BLUE_BACKGROUND);
  }
  return (controller::UIMenu::DO_NOTHING);
}

controller::UIMenu::order			controller::UIMenu::returnKey() {
  if (this->currentButton == controller::PLAY || this->currentButton == controller::OPTIONS)
    return (controller::UIMenu::NEXT);
  else
    return (controller::UIMenu::STOP);
}

controller::UIMenu::UIMenu(core::ModelManager *manager, engine::RessourceManager *ressources, core::MyEventReceiver *event, core::System *system)
  : AController(manager, ressources, event, system), _view(manager, ressources)
{
  this->keyboard.push_back(KeyHandler(irr::KEY_DOWN, &UIMenu::downKey));
  this->keyboard.push_back(KeyHandler(irr::KEY_UP, &UIMenu::upKey));
  this->keyboard.push_back(KeyHandler(irr::KEY_RETURN, &UIMenu::returnKey));
  this->cursor = irr::core::position2d<irr::s32>(85,197);
  this->sound = this->_ressources->getRessource<engine::MRessource>("ressources/Theme.ogg", engine::RessourceManager::RType::SOUND);
  this->animator =  this->_smgr->createFlyStraightAnimator({-100, 0, 0}, {200, 0, 0}, 12000, true, true);
  irr::scene::IAnimatedMesh		*mesh =  this->_device->getSceneManager()->getMesh("ressources/Circuit/Menu/Wii_Coconut_Mall.obj");
  this->node = this->_device->getSceneManager()->addOctreeSceneNode(mesh, nullptr);
  this->node->setVisible(false);
}

const irr::core::position2d<irr::s32>		&controller::UIMenu::getCursor() const {
  return (this->cursor);
}

controller::UIMenu::order			controller::UIMenu::findKey(irr::EKEY_CODE key) {
  controller::UIMenu::order 			order;

  for (auto &it : this->keyboard) {
    if (it.first == key)
    {
      order = (this->*it.second)();
      return (order);
    }
  }
  return (DO_NOTHING);
}

void			controller::UIMenu::selectButton(model::UIButton*)
{

}

controller::state	controller::UIMenu::run() {
  this->_view.begin();
  model::UIButton			*playButton = this->_manager->getModel<model::UIButton>("Play");
  model::UIButton			*optionsButton = this->_manager->getModel<model::UIButton>("Options");
  model::UIButton			*quitButton = this->_manager->getModel<model::UIButton>("Quit");
  irr::video::ITexture			*tex =  this->_driver->getTexture("ressources/Menu/play-button.png");
  irr::core::rect<irr::s32> 		imp1(0,0,95,100);
  irr::core::rect<irr::s32> 		imp2(0,0,0,0);
  irr::u32				time = this->_device->getTimer()->getTime();
  const irr::core::position2d<irr::s32>	&pos = this->getCursor();

  this->cursor = irr::core::position2d<irr::s32>(85, 197);
  this->buttonTab.push_back(controller::ButtonType(playButton ,controller::PLAY));
  this->buttonTab.push_back(controller::ButtonType(optionsButton ,controller::OPTIONS));
  this->buttonTab.push_back(controller::ButtonType(quitButton ,controller::QUIT));

  playButton->setFont("ressources/Fonts/Xolonium/FontMenu.xml");
  optionsButton->setFont("ressources/Fonts/Xolonium/FontMenu.xml");
  quitButton->setFont("ressources/Fonts/Xolonium/FontMenu.xml");

  playButton->setBackground(BLUE_BACKGROUND);
  optionsButton->setBackground(BLUE_BACKGROUND);
  quitButton->setBackground(BLUE_BACKGROUND);

  this->currentButton = controller::PLAY;
  playButton->setBackground(ORANGE_BACKGROUND);

  this->_smgr->addCameraSceneNode()->setPosition(irr::core::vector3df(-1306, 210.732, 2943));
  this->node->setVisible(true);

  node->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
  node->setMaterialType(irr::video::EMT_SOLID);
  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);

  node->addAnimator(animator);
  this->_smgr->getActiveCamera()->setFarValue(100000);

  while (this->_device->run())
  {
    if (sound->get().getStatus() != sf::Music::Playing)
      sound->play(_system->getVolume());
    for (auto &it : this->keyboard)
    {
      if (this->_event->IsKeyPressed(it.first))
      {
	switch (findKey(it.first))
	{
	  case NEXT:
	    if (this->currentButton == controller::OPTIONS)
	      this->_next = "UIOptions";
	    else
	      this->_next = "SelectCarMenu";
	    this->_event->startEventProcess();
	    node->setVisible(false);
	    this->_view.stop();
	    this->sound->stop();
	    return (controller::NEXT);
	  case STOP:
	    node->setVisible(false);
	    this->_event->startEventProcess();
	    this->_view.stop();
	    sound->stop();
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
    this->_driver->endScene();
  }
  return (controller::NEXT);
}

controller::UIMenu::~UIMenu() {
  this->animator->drop();
}