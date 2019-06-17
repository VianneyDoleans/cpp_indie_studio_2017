/*
** SplashScreenView.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/view/SplashScreen/SplashScreenView.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sun Jun 18 16:23:27 2017 Montagne Valentin
** Last update Sun Jun 18 16:23:28 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_SPLASHSCREENVIEW_HPP
#define CPP_INDIE_STUDIO_SPLASHSCREENVIEW_HPP

#include				"AView.hpp"
#include				"ModelManager.hpp"
#include				"RessourceManager.hpp"

namespace 				view {

  class 				SplashScreenView : public AView {

  public:

    SplashScreenView(core::ModelManager *manager, engine::RessourceManager *ressourceManager);

    void				drawImg(irr::u32 alpha);

    virtual ~SplashScreenView();

    virtual void 			stop();

    virtual void 			begin();

  };

}


#endif //CPP_INDIE_STUDIO_SPLASHSCREENVIEW_HPP
