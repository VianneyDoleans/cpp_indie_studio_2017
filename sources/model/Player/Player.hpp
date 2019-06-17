//
// Player.hpp for cpp_indie_studio in /home/vianney/cpp_indie_studio/sources/core/Player
// 
// Made by Vianney
// Login   <vianney.doleans@epitech.eu>
// 
// Started on  Mon May 22 13:07:29 2017 Vianney
// Last update Mon Jun  5 18:38:20 2017 Vianney
//

#ifndef CPP_INDIE_STUDIO_PLAYER_HPP
#define CPP_INDIE_STUDIO_PLAYER_HPP

#include				"Timer.hpp"
#include                        	"Car.hpp"

namespace				model
{

  class					Player : public AModel
  {

    enum class				State
    {
      ALIVE,
      FREEZE,
      DEAD
    };

  protected:

    State				_state;
    std::string				_name;
    Car					&_car;
    size_t				_currentCheckPointID;
    size_t				_ranking;
    size_t				_lap;
    double				_time;
    double				_bestLap;
    double				_lastLap;
    model::Timer			_timeBoost;

  public:

    Player(const std::string  &name, Car &car);
    ~Player();

  public:

    /**
     * @brief Make alive
     */

    void				respawn();

    /**
     * @brief Dead
     */

    bool				die(void);

    // GETTERS

    Car					&getCar();
    const std::string			&getName() const;
    const irr::core::vector3df		&getPosition(void) const;
    size_t				getRanking() const;
    size_t				getCurrentCheckPointID() const;
    size_t				getLap();
    double				getTime() const;
    double				getBestLap();
    double				getlastLap();
    model::Timer			&getTimeBoost();

    // SETTERS

    void				setCar(Car &car);
    void				setPosition(const irr::core::vector3df &pos);
    void				setRanking(size_t ranking);
    void				setCurrentCheckPointID(size_t checkPoint);
    void				setLap(size_t lap);
    void				setTime(double time);
    void				setBestLap(double time);
    void				setlastLap(double time);

    /**
     * @brief Grab this model, now it appear on the screen !
     */

    virtual void			grab(void) override;

    /**
     * @brief Drop this model, it isn't on the screen !
     */

    virtual void			drop(void) override;

  };
}


#endif //CPP_INDIE_STUDIO_PLAYER_HPP
