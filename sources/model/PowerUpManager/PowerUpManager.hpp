/*
** PowerUpManager.hpp for cpp_indie_studio in /home/antoine/TEK2/INDIE_STUDIO/cpp_indie_studio/sources/model/PowerUpManager/PowerUpManager.hpp
**
** Made by Antoine CAFFIER
** Login   <antoine.caffier@epitech.eu>
**
** Started on  Fri Jun 16 16:50:35 2017 Antoine CAFFIER
** Last update Fri Jun 16 16:50:35 2017 Antoine CAFFIER
*/

#ifndef CPP_INDIE_STUDIO_POWERUPMANAGER_HPP
#define CPP_INDIE_STUDIO_POWERUPMANAGER_HPP

#include				<vector>
#include				<memory>
#include				"RessourceManager.hpp"
#include 				"APowerUp.hpp"
#include				"Timer.hpp"

namespace 				model
{

  using 				PlayerRef = std::reference_wrapper<model::Player>;

  using PowerUps = std::shared_ptr<APowerUp>;

  class 				PowerUpManager
  {

    std::vector<PowerUps>		_pows;
    engine::RessourceManager		&_rm;
    irr::IrrlichtDevice			*_device;

  public:

    PowerUpManager(engine::RessourceManager &rm);
    ~PowerUpManager();

    template <typename T>
    T					*spawn(const irr::core::vector3df &pos)
    {
      _pows.push_back(std::make_shared<T>(_rm));
      _pows.back().get()->getNode()->setPosition(pos);
      return (static_cast<T *>(_pows.back().get()));
    }

    void				update(std::vector<PlayerRef> &playerList);

    bool				isTaking(const Car &car, const APowerUp &);

    bool				canRespawn(APowerUp &);

    void				grabAll(void);

    void				dropAll(void);

  };
}

#endif //CPP_INDIE_STUDIO_POWERUPMANAGER_HPP
