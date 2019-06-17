/*
** APowerUp.hpp for cpp_indie_studio in /home/antoine/TEK2/INDIE_STUDIO/cpp_indie_studio/sources/model/APowerUp/APowerUp.hpp
**
** Made by Antoine CAFFIER
** Login   <antoine.caffier@epitech.eu>
**
** Started on  Thu Jun 15 19:17:26 2017 Antoine CAFFIER
** Last update Thu Jun 15 19:17:33 2017 Antoine CAFFIER
*/

#ifndef CPP_INDIE_STUDIO_APOWERUP_HPP
#define CPP_INDIE_STUDIO_APOWERUP_HPP

#include "AModel.hpp"
#include "Player.hpp"
#include "Timer.hpp"

namespace		model
{

  class 		APowerUp : public AModel
  {

  public:

    enum class		State
    {

      ACTIVE,
      NOT

    };

  protected:

    irr::scene::IAnimatedMeshSceneNode  	*_node;
    model::Timer				_timer;
    State					_state;

  public:

    APowerUp();
    virtual ~APowerUp();

  public:

    // GETTERS

    irr::scene::IAnimatedMeshSceneNode		*getNode(void) const;

    model::Timer				&getTimer(void);

    State					getState(void) const;

    // SETTERS

    void					setState(State state);

    // METHODS

    void					rotate();

    bool					isActive(void) const;

    virtual void				unlockPowerup(model::Player &player) = 0;

    virtual void				grab(void) = 0;

    virtual void				drop(void) = 0;
  };
}

#endif //CPP_INDIE_STUDIO_APOWERUP_HPP
