//
// Sinder.hpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/model/Car/Sindir
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Thu Jun	15 11:21:08 2017 Guillaume Bouxin
// Last update	Thu Jun	15 11:21:08 2017 Guillaume Bouxin
//

#ifndef CPP_INDIE_STUDIO_SINDER_HPP
#define CPP_INDIE_STUDIO_SINDER_HPP

#include			"RessourceManager.hpp"
#include			"Car.hpp"

#define				MESHPATH_SINDER	("ressources/Car/Sinder/sinder_car.obj")

namespace 			model {

  class 			Sinder : public Car {

    engine::RessourceManager	&_rm;

  public:

    Sinder(engine::RessourceManager &rm);
    ~Sinder();
  };

}

#endif