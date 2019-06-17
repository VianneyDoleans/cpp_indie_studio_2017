//
// AController.hpp for cpp_indie_studio in /home/vianney/cpp_indie_studio/sources/controller
// 
// Made by Vianney
// Login   <vianney.doleans@epitech.eu>
// 
// Started on  Wed Jun  7 19:10:36 2017 Vianney
// Last update Mon Jun 12 15:53:04 2017 Vianney
//

#ifndef CPP_INDIE_STUDIO_ICONTROLLER_HPP
#define CPP_INDIE_STUDIO_ICONTROLLER_HPP

#include		<string>
#include        <irrlicht.h>
#include		"ModelManager.hpp"
#include		"RessourceManager.hpp"
#include		"EventReceiver.hpp"
#include		"AView.hpp"
#include		"System.hpp"

namespace		controller
{
  enum state
  {
    STOP,
    NEXT
  };

  class			AController
  {

  protected:
    core::ModelManager		    *_manager;
    engine::RessourceManager	*_ressources;
    core::MyEventReceiver	    *_event;
    irr::IrrlichtDevice       *_device;
    irr::scene::ISceneManager *_smgr;
    irr::video::IVideoDriver  *_driver;
    std::string			          _next;
      core::System              *_system;
//    view::AView                 _view;

  public:
    AController(core::ModelManager *manager, engine::RessourceManager *ressources, core::MyEventReceiver *event, core::System *system);
    virtual ~AController() = 0;

  public:
    virtual state			run() = 0;

    const std::string &getNext() const;
  };
}

#endif //CPP_INDIE_STUDIO_ACONTROLLER_HPP
