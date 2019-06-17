//
// Bruno.hpp for indie_studio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/model/Car/Bruno
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Wed Jun	14 13:38:35 2017 Guillaume Bouxin
// Last update	Wed Jun	14 13:38:35 2017 Guillaume Bouxin
//

#ifndef CPP_INDIE_STUDIO_BRUNO_HPP
#define CPP_INDIE_STUDIO_BRUNO_HPP

#include			"RessourceManager.hpp"
#include			"Car.hpp"

#define				MESHPATH_BRUNO	("ressources/Car/Bruno/bruno_car.obj")

namespace 			model {

  class 			Bruno : public Car {

    engine::RessourceManager	&_rm;

  public:

    Bruno(engine::RessourceManager &rm);
    ~Bruno();
  };

}

#endif