/*
** Model.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/core/Model.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat May 20 13:38:42 2017 Montagne Valentin
** Last update Sat May 20 13:38:42 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_MODEL_HPP
#define CPP_INDIE_STUDIO_MODEL_HPP

#include			<string>

#define				LIGHT	(true)

namespace			model {

  class 			AModel {

    std::string			_type;

  public:

    AModel(const std::string &type);
    virtual ~AModel();

    /**
     * get type of this model
     * @return const std::string &
     */

    const std::string 		&getType(void) const;

    /**
     * @brief Grab this model, now he appear on the screen !
     */

    virtual void		grab(void) = 0;

    /**
     * @brief Drop this model, he isn't on the screen !
     */

    virtual void		drop(void) = 0;

  };

}

#endif //CPP_INDIE_STUDIO_MODEL_HPP
