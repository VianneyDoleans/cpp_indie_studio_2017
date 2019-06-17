/*
** CollisionHandler.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Collision/CollisionHandler.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 15 13:41:05 2017 Montagne Valentin
** Last update Thu Jun 15 13:41:05 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_COLLISIONHANDLER_HPP
#define CPP_INDIE_STUDIO_COLLISIONHANDLER_HPP

#include						<irrlicht.h>
#include						<chrono>
#include						"Timer.hpp"
#include						"AModel.hpp"

namespace 						model {

  using							Collision =
  std::pair<irr::scene::ISceneNode *, irr::scene::ISceneNode *>;

  class 						CollisionHandler : public AModel {

    Collision						_col;
    Timer						_timer;
    double						_timeout;

  public:

    CollisionHandler(Collision col, double timout = 1);
    ~CollisionHandler();

    double						getTimeout(void) const;

    const Timer						getTimer(void) const;

    const Collision 					&getCol(void) const;

    bool						isEnd(void) const;

    virtual void					grab(void) override;

    virtual void					drop(void) override;

  };

}

#endif //CPP_INDIE_STUDIO_COLLISIONHANDLER_HPP
