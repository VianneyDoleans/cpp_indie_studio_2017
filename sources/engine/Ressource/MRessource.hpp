/*
** NCRessource.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/engine/Ressource/NCRessource.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Tue Jun 06 19:02:27 2017 Montagne Valentin
** Last update Tue Jun 06 19:02:27 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_NCRESSOURCE_HPP
#define CPP_INDIE_STUDIO_NCRESSOURCE_HPP


#include			<string>
#include 			<memory>
#include 			<SFML/Audio.hpp>
#include            <irrlicht.h>
#include 			"IRessouce.hpp"

namespace 			engine {

  class				MRessource : public IRessource
  {

    std::string			_path;
    sf::Music 			_src;

  public:

    MRessource(const std::string &path);
    MRessource(const MRessource &other);
    virtual ~MRessource();

    /**
     * @brief Play sound
     * @param volume
     */

    void			play(unsigned int volume);

    /**
     * @brief Stop sound
     */

    void			stop(void);

    sf::Music		&get(void);

    virtual const std::string 	&getPath(void) const override;

  };

}

#endif /* !CPP_INDIE_STUDIO_NCRESSOURCE_HPP */
