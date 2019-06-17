/*
** Bomb.hpp for cpp_indie_studio in /home/antoine/TEK2/INDIE_STUDIO/cpp_indie_studio/sources/model/PowerUp/Bomb.hpp
**
** Made by Antoine CAFFIER
** Login   <antoine.caffier@epitech.eu>
**
** Started on  Sun Jun 18 16:31:53 2017 Antoine CAFFIER
** Last update Sun Jun 18 16:31:53 2017 Antoine CAFFIER
*/

#ifndef CPP_INDIE_STUDIO_BOMB_HPP
#define CPP_INDIE_STUDIO_BOMB_HPP

#include "APowerUp.hpp"
#include "RessourceManager.hpp"

namespace model
{
  class Bomb : public APowerUp
  {
    irr::IrrlichtDevice *_device;

  public:
    Bomb(engine::RessourceManager &rm);

    ~Bomb();

    virtual void unlockPowerup(model::Player &player) override;

    virtual void grab(void);

    virtual void drop(void);
  };
}


#endif //CPP_INDIE_STUDIO_BOMB_HPP
