/*
** Height.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Circuit/Height/Height.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat Jun 17 10:06:13 2017 Montagne Valentin
** Last update Sat Jun 17 10:06:13 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_HEIGHT_HPP
#define CPP_INDIE_STUDIO_HEIGHT_HPP

#include				"RessourceManager.hpp"
#include				"ACircuit.hpp"

#define					CAMERAPOSITION_HEIGHT (irr::core::vector3df(0, 6000, 0))
#define					MESHPATH_HEIGHT ("ressources/course/Kinoko.obj")

namespace				model {

  class 				Height : public ACircuit {

    engine::RessourceManager		&_rm;
    irr::scene::ILightSceneNode		*_light;

  public:

    Height(engine::RessourceManager &rm);
    virtual ~Height() override;

    /**
     * @brief Grab this model, now he appear on the screen !
     */

    virtual void				grab(void) override;

    /**
     * @brief Drop this model, he isn't on the screen !
     */

    virtual void				drop(void) override;

  };
}

#endif //CPP_INDIE_STUDIO_HEIGHT_HPP