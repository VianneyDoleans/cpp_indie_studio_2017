/*
** UIOptions.hpp for cpp_indie_studio in /home/charles/Documents/C++/cpp_indie_studio/sources/view/UIOptions.hpp
**
** Made by Charles des Pommare
** Login   <charles.des-pommare@epitech.eu>
**
** Started on  Sat Jun 17 15:45:05 2017 Charles des Pommare
** Last update Sat Jun 17 15:45:05 2017 Charles des Pommare
*/

#ifndef CPP_INDIE_STUDIO_UIOPTIONS_HPP
#define CPP_INDIE_STUDIO_UIOPTIONS_HPP

#include	"AController.hpp"
#include	"UIOptionsView.hpp"
#include	"MRessource.hpp"

namespace	controller
{

  enum	opt {
    VOLUME,
    SPLIT,
    AI,
    PLAYERS
  };

  class UIOptions : public AController
  {

  public:
    enum order {
      STOP,
      NEXT,
      DO_NOTHING
    };

    typedef order                (UIOptions::*KeyFunction)();

    using KeyHandler = std::pair<irr::EKEY_CODE , KeyFunction>;

  private:
    view::UIOptionsView			_view;
    std::vector<KeyHandler> 		keyboard;
    irr::core::position2d<irr::s32>	cursor;
    opt					currentButton;
    std::vector<opt>			buttonTab;
    engine::MRessource			*sound;
    irr::scene::ISceneNode 		*node;
    irr::scene::ISceneNodeAnimator	*animator;
    unsigned int			_volume;
    bool				_split;
    unsigned int			_laps;
    unsigned int			_players;

  public:
    UIOptions(core::ModelManager *manager, engine::RessourceManager *ressources,
	      core::MyEventReceiver *event, core::System *system);
    ~UIOptions();

    virtual state	run() override;

    controller::UIOptions::order			findKey(irr::EKEY_CODE key);

    const irr::core::position2d<irr::s32>		&getCursor() const;

    controller::UIOptions::order			downKey();
    controller::UIOptions::order			upKey();
    controller::UIOptions::order			leftKey();
    controller::UIOptions::order			rightKey();
    controller::UIOptions::order			escapeKey();
  };

}

#endif //CPP_INDIE_STUDIO_UIOPTIONS_HPP
