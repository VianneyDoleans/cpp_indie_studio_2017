/*
** Reparation.hpp for cpp_indie_studio in /home/antoine/TEK2/INDIE_STUDIO/cpp_indie_studio/sources/model/PowerUp/Reparation.hpp
**
** Made by Antoine CAFFIER
** Login   <antoine.caffier@epitech.eu>
**
** Started on  Sun Jun 18 16:32:06 2017 Antoine CAFFIER
** Last update Sun Jun 18 16:32:09 2017 Antoine CAFFIER
*/

#ifndef CPP_INDIE_STUDIO_REPARATION_HPP
#define CPP_INDIE_STUDIO_REPARATION_HPP

#include <APowerUp.hpp>
#include "RessourceManager.hpp"

namespace 	model
{
  class Reparation : public APowerUp
  {
    irr::IrrlichtDevice		*_device;

  public:
    Reparation(engine::RessourceManager &rm);
    ~Reparation();

    virtual void		unlockPowerup(model::Player &player) override;

    virtual void		grab(void);

    virtual void		drop(void);
  };
}

#endif //CPP_INDIE_STUDIO_REPARATION_HPP
