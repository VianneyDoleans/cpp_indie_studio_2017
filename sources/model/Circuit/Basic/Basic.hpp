/*
** Basic.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Circuit/Basic/Basic.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 08 20:45:36 2017 Montagne Valentin
** Last update Thu Jun 08 20:45:36 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_BASIC_HPP
#define CPP_INDIE_STUDIO_BASIC_HPP

#include                        		"ACircuit.hpp"

#define						CAMERAPOSITION_BASIC (irr::core::vector3df(0, 1000, 0))
#define						MESHPATH_BASIC	("ressources/Circuit/Basic/basic.obj")

namespace					model {

  class 					Basic : public ACircuit {

    engine::RessourceManager			&_rm;

  public:

    Basic(engine::RessourceManager &rm);
    virtual ~Basic() override;

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

#endif //CPP_INDIE_STUDIO_BASIC_HPP
