/*
** ModelManager.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/core/ModelManager/ModelManager.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sat May 20 14:17:10 2017 Montagne Valentin
** Last update Sat May 20 14:17:10 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_MODELMANAGER_HPP
#define CPP_INDIE_STUDIO_MODELMANAGER_HPP

#include							<map>
#include							<string>
#include							<memory>
#include                            <irrlicht.h>
#include                            "AModel.hpp"

namespace 							core {

  class 							ModelManager {

    std::map<std::string, std::shared_ptr<model::AModel>>	_models;

  public:

    ModelManager();
    ~ModelManager();

    /**
     * @brief get Model from the ModelManager
     */

    /*
     * Exemple : model::test *t = ModelManager.getModel<model::test>(core::test(params));
     */

    template <typename T>
    T								*getModel(const std::string &name, const T &m)
    {
      _models.insert({name, std::make_shared<T>(m)});
      return (static_cast<T *>(_models[name].get()));
    }

    template <typename T>
    T								*getModel(const std::string &name)
    {
      return (static_cast<T *>(_models[name].get()));
    }

    /**
     * @brief check if key name is in the map
     * @param name
     * @return bool
     */

    bool							isHere(const std::string &name);

    /**
     * @brief remove Model from ModelManager
     * @param name
     */

    void							removeModel(const std::string &name);

  };

}

#endif //CPP_INDIE_STUDIO_MODELMANAGER_HPP
