/*
** Ressource.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/engine/Ressource.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri May 19 16:54:33 2017 Montagne Valentin
** Last update Fri May 19 16:54:33 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_RESSOURCE_HPP
#define CPP_INDIE_STUDIO_RESSOURCE_HPP

#include			<string>
#include 			<memory>
#include 			<SFML/Audio.hpp>
#include            <irrlicht.h>
#include 			"IRessouce.hpp"

namespace 			engine {

  using 			MESH = irr::scene::IAnimatedMesh *;
  using 			TEX = irr::video::ITexture *;
  using 			FONT = irr::gui::IGUIFont *;

  template <typename T>
  class				Ressource : public IRessource
  {

    std::string			_path;
    T				_src;

  public:

    Ressource(const std::string &path, T r)
      : _path(path), _src(r) {};
    virtual ~Ressource() {};

    /**
     * @brief get a reference of a ressource
     */

    T				get(void) const
    {
      return (_src);
    }

    virtual const std::string 	&getPath(void) const override
    {
      return (_path);
    }

  };

}

#endif /* !CPP_INDIE_STUDIO_RESSOURCE_HPP */
