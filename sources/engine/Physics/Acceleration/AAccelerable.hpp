#ifndef CPP_INDIE_STUDIO_AACCELERABLE_HPP
#define CPP_INDIE_STUDIO_AACCELERABLE_HPP

#include        <irrlicht.h>

class AAccelerable {

private:
  unsigned int			_speedVelocity;
  irr::core::vector3df		_acceleration;

public:
  AAccelerable(unsigned int speedVelocity = 0);
  AAccelerable(const AAccelerable &aAccelerable);
  virtual ~AAccelerable();

  void				applyFriction(double deltaTime, irr::core::vector3df direction, unsigned int weight);

  // GETTERS
  unsigned int			speedVelocity() const;
  const irr::core::vector3df	&acceleration() const;
  double			speed() const;

  // SETTERS
  void				speedVelocity(const unsigned int speedVelocity);
  void				acceleration(const irr::core::vector3df &acceleration);
  void				applyAcceleration(const irr::core::vector3df &acceleration);

  AAccelerable			&operator=(const AAccelerable &aAccelerable);
};


#endif //CPP_INDIE_STUDIO_AACCELERABLE_HPP
