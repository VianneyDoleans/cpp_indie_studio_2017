/*
** BlueBird.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Car/BlueBird/BlueBird.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 07 11:22:47 2017 Montagne Valentin
** Last update Wed Jun 07 11:22:47 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_BLUEBIRD_HPP
#define CPP_INDIE_STUDIO_BLUEBIRD_HPP

#include			"RessourceManager.hpp"
#include			"Car.hpp"

#define				MESHPATH_BLUEBIRD	("ressources/Car/BlueBird/BlueBird.obj")

namespace 			model {

  class 			BlueBird : public Car {

    engine::RessourceManager	&_rm;

  public:

    BlueBird(engine::RessourceManager &rm);
    ~BlueBird();

  };

}

#endif //CPP_INDIE_STUDIO_BLUEBIRD_HPP
