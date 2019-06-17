/*
** IRessouce.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/engine/IRessouce.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri May 19 18:52:55 2017 Montagne Valentin
** Last update Fri May 19 18:52:55 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_IRESSOUCE_HPP
#define CPP_INDIE_STUDIO_IRESSOUCE_HPP

namespace 				engine
{

  class					IRessource
  {

  public:

    virtual ~IRessource() {};

    virtual const std::string 		&getPath(void) const = 0;

  };

}

#endif /* !CPP_INDIE_STUDIO_IRESSOUCE_HPP */
