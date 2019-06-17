/*
** CarEffects.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Car/CarEffects.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 07 17:16:18 2017 Montagne Valentin
** Last update Wed Jun 07 17:16:18 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_CAREFFECTS_HPP
#define CPP_INDIE_STUDIO_CAREFFECTS_HPP

#include					"Car.hpp"

namespace 					model {

  class 					CarEffects {

    irr::IrrlichtDevice 			&_device;
    Car						&_car;
    irr::scene::IParticleSystemSceneNode	*_fire;
    irr::scene::IParticleSystemSceneNode	*_smoke;
    irr::scene::ITriangleSelector		*_selector;

    void					updateFire(void);
    void					updateSmoke(void);

  public:

    CarEffects(irr::IrrlichtDevice &device, Car &car);
    ~CarEffects();

    /**
     * @brief Call update to react if a car is low life
     */

    void					update(void);

    void					stop(void);

  };

}


#endif //CPP_INDIE_STUDIO_CAREFFECTS_HPP
