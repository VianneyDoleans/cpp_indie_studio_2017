//
// Mitraille.hpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/model/Car/Mitraille
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Sat Jun	17 14:23:56 2017 Guillaume Bouxin
// Last update	Sat Jun	17 14:23:56 2017 Guillaume Bouxin
//

#ifndef CPP_INDIE_STUDIO_MITRAILLE_HPP
#define CPP_INDIE_STUDIO_MITRAILLE_HPP

#include			"RessourceManager.hpp"
#include			"Car.hpp"

#define				MESHPATH_MITRAILLE ("ressources/Car/Mitraille/Cheapy.obj")

namespace 			model {

  class 			Mitraille : public Car {

    engine::RessourceManager	&_rm;

  public:

    Mitraille(engine::RessourceManager &rm);
    ~Mitraille();
  };

}

#endif