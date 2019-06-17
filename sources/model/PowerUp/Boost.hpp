/*
** Boost.hpp for cpp_indie_studio in /home/antoine/TEK2/INDIE_STUDIO/cpp_indie_studio/sources/model/PowerUp/Boost.hpp
**
** Made by Antoine CAFFIER
** Login   <antoine.caffier@epitech.eu>
**
** Started on  Thu Jun 15 19:17:18 2017 Antoine CAFFIER
** Last update Thu Jun 15 19:17:18 2017 Antoine CAFFIER
*/

#ifndef CPP_INDIE_STUDIO_BOOST_HPP
#define CPP_INDIE_STUDIO_BOOST_HPP

#define				TEXBOOST_PATH ("ressources/particle.bmp")

#include 			"APowerUp.hpp"
#include 			"RessourceManager.hpp"
#include 			"Timer.hpp"

namespace 			model {

  class 			Boost : public APowerUp
  {

    irr::IrrlichtDevice		*_device;

  public:
    Boost(engine::RessourceManager &rm);
    ~Boost();

    virtual void			unlockPowerup(model::Player &player) override;

    virtual void			grab(void);

    virtual void			drop(void);
  };
}

#endif //CPP_INDIE_STUDIO_BOOST_HPP
