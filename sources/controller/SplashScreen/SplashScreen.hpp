/*
** SplashScreen.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/controller/SplashScreen/SplashScreen.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sun Jun 18 16:13:39 2017 Montagne Valentin
** Last update Sun Jun 18 16:13:39 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_SPLASHSCREEN_HPP
#define CPP_INDIE_STUDIO_SPLASHSCREEN_HPP

#include					"SplashScreenView.hpp"
#include					"AController.hpp"

namespace 					controller {

  class 					SplashScreen : public AController {

  private:

    view::SplashScreenView 			_view;

  public:

    /**
     * @brief      Result of game
     *
     * @param      manager     The manager
     * @param      ressources  The ressources
     * @param      renderer    The renderer
     * @param      event       The event
     */

    SplashScreen(core::ModelManager *manager, engine::RessourceManager *ressources, core::MyEventReceiver *event,
		 core::System *system);

    ~SplashScreen();

    virtual state run();

  };

}

#endif //CPP_INDIE_STUDIO_SPLASHSCREEN_HPP
