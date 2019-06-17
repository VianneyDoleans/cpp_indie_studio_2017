/*
** UIMenu.hpp for cpp_indie_studio in /home/charles/Documents/C++/cpp_indie_studio/sources/controller/UIMenu/UIMenu.hpp
**
** Made by Charles des Pommare
** Login   <charles.des-pommare@epitech.eu>
**
** Started on  Tue Jun 13 17:13:39 2017 Charles des Pommare
** Last update Tue Jun 13 17:13:40 2017 Charles des Pommare
*/

#ifndef CPP_INDIE_STUDIO_UIMENU_HPP
#define CPP_INDIE_STUDIO_UIMENU_HPP

#include						"UIMenuView.hpp"
#include						"RessourceManager.hpp"
#include						"MRessource.hpp"
#include						"AController.hpp"
#include						"UIButton.hpp"

# define BLUE_BACKGROUND				("ressources/Menu/button.png")
# define ORANGE_BACKGROUND				("ressources/Menu/selected-button.png")

namespace						controller {

  enum 							type {

    PLAY,
    OPTIONS,
    QUIT

  };

  using 						ButtonType = std::pair<model::UIButton *, type>;

  class 						UIMenu : public AController {

  public:

    enum 						order {

      STOP,
      NEXT,
      DO_NOTHING

    };

    using 						KeyFunction = order	(UIMenu::*)();

    using 						KeyHandler = std::pair<irr::EKEY_CODE , KeyFunction>;

  private:
    std::vector<controller::ButtonType> 		buttonTab;
    type						currentButton;
    std::vector<KeyHandler> 				keyboard;
    view::UIMenuView					_view;
    irr::core::position2d<irr::s32>			cursor;
    engine::MRessource 					*sound;
    irr::scene::ISceneNode				*node;
    irr::scene::ISceneNodeAnimator			*animator;

  public:

    UIMenu(core::ModelManager *manager, engine::RessourceManager *ressources,
	   core::MyEventReceiver *event, core::System *system);

    ~UIMenu();

    /**
     * @brief Launch the menu
     * @return enum state (NEXT, STOP)
     */
    virtual state 					run() override;

    /**
     * @brief Select a button and show it with an arrow
     * @param button
     */
    void						selectButton(model::UIButton *button);

    /**
     * @brief Find key given in parameter
     * @param key
     * @return
     */
    order 						findKey(irr::EKEY_CODE key);

    /**
     * @brief return position of current arrow of selection
     * @return position2d
     */
    const irr::core::position2d<irr::s32>		&getCursor() const;

    controller::UIMenu::order				downKey();
    controller::UIMenu::order				upKey();
    controller::UIMenu::order				returnKey();
  };
}
#endif //CPP_INDIE_STUDIO_UIMENU_HPP
