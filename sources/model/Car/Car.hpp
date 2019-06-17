//
// Car.hpp for cpp_indie_studio in /home/vianney/cpp_indie_studio/sources/core/Car
// 
// Made by Vianney
// Login   <vianney.doleans@epitech.eu>
// 
// Started on  Mon May 22 14:00:31 2017 Vianney
// Last update Mon Jun  5 18:40:03 2017 Vianney
//

#ifndef CPP_INDIE_STUDIO_CAR_HPP
#define CPP_INDIE_STUDIO_CAR_HPP

#include                    <irrlicht.h>
#include                    "AModel.hpp"
#include					"AAccelerable.hpp"

namespace					model
{

  class						Car : public AModel, public AAccelerable
  {

  public:

    enum class					State
    {

      ALIVE,
      BROKEN,
      TURBO
    };

  protected:

    State					_state;
    unsigned int				_weight;
    unsigned int       	       			_life;
    unsigned int				_currentLife;
    unsigned int				_maxSpeed;
    int						_speed;
    unsigned int				_turbo;
    irr::scene::IAnimatedMeshSceneNode		*_car;
    irr::scene::ITriangleSelector		*_select;
    irr::core::vector3df			_direction;
    float					_rotation;
    std::string					_name;

  public:

    Car();
    ~Car();

  public:

    /**
     * @brief get the direction of the car.
     */

    const irr::core::vector3df			&getDirection(void) const;

    /**
     *  @brief set the direction of the car
     */

    void					setDirection(const irr::core::vector3df &direction);

    /**
     * @brief move the position of the car.
     */

    void					move(float deltaTime = 1);

    /**
     * @brief set the rotation of the car.
     */

    void					setRotation(const float angle);

    /**
     * @brief set the rotation of the car.
     */

    const float					&getRotation(void) const;

    /**
     * @brief get the position of the car. (Use IAnimatedMeshSceneNode position)
     */

    const irr::core::vector3df			&getPosition(void) const;

    /**
     * @brief get Weight of the car.
     */

    unsigned int				getWeight(void) const;

    /**
     * @brief get the current Life of the car.
     */

    unsigned int				getLife(void) const;

    /**
     * @brief get the max life of the car.
     */

    unsigned int				getLifeMax(void) const;

    /**
     * @brief get the current speed of the car.
     */

    double					getSpeed(void) const;

    /**
     * @brief get the max speed.
     */

    unsigned int				getMaxSpeed(void) const;

    /**
     * @brief get the Irrlicht Scene Node.
     */

    irr::scene::IAnimatedMeshSceneNode		*getCar(void) const;

    /**
     * @brief get the turbo of the car.
     */

    unsigned int				getTurbo(void) const;

    /**
     * @brief get State
     * @return state
     */

    State					getState(void) const;

    /**
     * @brief Get directionnal vector
     * @return vector3df
     */

    irr::core::vector3df			getDirectionnal(void) const;

    /**
     * @brief get TriangleSelector of Irrlicht
     * @return ITriangleSelector *
     */

    irr::scene::ITriangleSelector		*getSelect(void) const;

    /**
     * @brief      Gets the name.
     *
     * @return     The name.
     */
    const std::string &getName() const;

  public:

    /**
     * @brief set the position of the car.
     */

    void					setPosition(const irr::core::vector3df &position);

    /**
     * @brief set the state of the car
     */

    void					setState(State state);

    /**
     * @brief set the Weight of the car, It influences on the life, speed of the car.
     */

    void					setWeight(unsigned int weight);

    /**
     * @brief set the current life of the car.
     */

    void					setLife(unsigned int life);

    /**
     * @brief set the current speed of the car.
     */

    void					setSpeed(int speed);

    /**
     * @brief      Sets the name.
     *
     * @param[in]  name  The name
     */
    void                    setName(const std::string &name);


    /**
     * @brief Accelerate the car according to it's direction, weight, speed, ...
     * @param speed
     */

    void					accelerate(float speed = 1);

    /**
     * @brief Decelerate the car according to it's direction, weight, speed, ...
     * @param speed
     */

    void					decelerate(float speed = 1);

    /**
     * @brief Apply break to the car
     */

    void					breakSpeed();

    /**
     * @brief set the mesh of the car.
     */

    void					setCar(irr::scene::IAnimatedMeshSceneNode *car);

    /**
     * @brief set turbo of the car.
     */

    void					setTurbo(unsigned int turbo);

    /**
     * @brief Grab this model, now he appear on the screen !
     */

    virtual void				grab(void) override;

    /**
     * @brief Drop this model, he isn't on the screen !
     */

    virtual void				drop(void) override;

  };

};

std::ostream					&operator<<(std::ostream &os, model::Car &car);

#endif //CPP_INDIE_STUDIO_CAR_HPP
