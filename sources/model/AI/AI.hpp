#ifndef CPP_INDIE_STUDIO_AI_HPP
#define CPP_INDIE_STUDIO_AI_HPP

#include "Player.hpp"

namespace model
{
  class AI : public Player {

  private:
    irr::core::vector3df	_target;

  public:
    AI(model::Car &car, unsigned int id = 0);
    virtual ~AI();

    void takeDecision();
    void dump() const;

    // GETTERS
    const irr::core::vector3df	&getTarget() const;

    // SETTERS
    void			setTarget(const irr::core::vector3df &target);
  };
}


#endif //CPP_INDIE_STUDIO_AI_HPP
