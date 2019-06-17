//
// SunnyGo.hpp for SunnyGo in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/model/Car/SunnyGo
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Thu Jun	15 09:40:57 2017 Guillaume Bouxin
// Last update	Thu Jun	15 09:40:57 2017 Guillaume Bouxin
//

#ifndef CPP_INDIE_STUDIO_SUNNYGO_HPP
#define CPP_INDIE_STUDIO_SUNNYGO_HPP

#include			"RessourceManager.hpp"
#include			"Car.hpp"

#define				MESHPATH_SUNNYGO	("ressources/Car/SunnyGo/criminalboat.obj")

namespace 			model {

  class 			SunnyGo : public Car {

    engine::RessourceManager	&_rm;

  public:

    SunnyGo(engine::RessourceManager &rm);
    ~SunnyGo();
  };

}

#endif