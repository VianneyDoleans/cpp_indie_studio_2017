/*
** Circuit.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Circuit/Circuit.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 08 10:02:53 2017 Montagne Valentin
** Last update Thu Jun 08 10:02:53 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_CIRCUIT_HPP
#define CPP_INDIE_STUDIO_CIRCUIT_HPP

#include 					"PowerUpManager.hpp"
#include					"CollisionHandler.hpp"
#include 					"RessourceManager.hpp"
#include                                        "AModel.hpp"
#include					"Player.hpp"

#define						GRAVITY	(irr::core::vector3df(0, -10, 0))

namespace					model {

  using 					PlayerRef = std::reference_wrapper<model::Player>;

  class 					ACircuit : public AModel {

  public:

    /**
     * @brief Collision Manager
     */

    class					CollisionManager {

      irr::IrrlichtDevice			&_device;
      std::vector<CollisionHandler>		_collisions;
      PowerUpManager				_pwm;

      /**
       * @brief Adding a collision in the collision history
       * @param f
       * @param s
       */

      void					addCollision(Car &f, Car &s);

      /**
       * @bref Check all the players collision
       * @param players
       */

      void					checkPlayersCollision(std::vector<PlayerRef> &players);

      /**
       * @bref Check if collisions in the collisions history are outdated
       */

      void					checkCollisions(void);

    public:

      CollisionManager(engine::RessourceManager &rm);
      ~CollisionManager();

      /**
       * @brief init Collision, need to put all the player on the map before
       */

      void					initCollision(std::vector<PlayerRef> &players);

      /**
       * @brief Link two cars
       * @param f
       * @param s
       */

      void					linkCars(Car &f, Car &s);

      /**
       * @brief check if two scene node are in collision
       * @param f first
       * @param s second
       * @return bool
       */

      bool					inCollision(Car &f, Car &s);

      bool					isKnown(Car &f, Car &s);

      void					update(std::vector<PlayerRef> &players);

      void					takeDamage(Car &car, unsigned int damage);

      PowerUpManager				&getPUManager(void);

    };

    /**
     * End Collision Manager
     */

  protected:
    
    irr::IrrlichtDevice				&_device;
    irr::core::vector3df			_camPos;
    double					_playerScale;
    std::vector<PlayerRef>			_players;
    std::vector<irr::core::vector3df>		_startPos;
    std::vector<irr::core::line3df>		_checkPoints;
    irr::scene::IAnimatedMesh			&_mesh;
    irr::scene::IMeshSceneNode			*_node;
    irr::scene::ITriangleSelector		*_selector;
    CollisionManager				_colman;

  public:

    ACircuit(engine::RessourceManager &rm, irr::core::vector3df camPos,
	    irr::scene::IAnimatedMesh &mesh);
    virtual ~ACircuit();

    /**
     * @brief Add a player to the circuit
     * @param player
     */

    void					addPlayer(Player &player);

    /**
     * @brief Change the position of the player to the start of the circuit
     * @param playerName
     */

    virtual void				toStart(const std::string &playerName);

    /**
     * @brief Remove a playe from this circuit
     * @param player
     */

    void					removePlayer(Player &player);

    /**
     * @brief Link an object to the circuit
     * @param node
     */

    void					link(irr::scene::ISceneNode *node);

    /**
     * @brief get the Irrlicht Circuit
     * @return
     */

    irr::scene::IMeshSceneNode			*getCircuit(void) const;

    /**
     * @brief Get the position of the Circuit
     * @return const irr::core::vector3df
     */

    const irr::core::vector3df			&getPosition(void) const;

    std::vector<PlayerRef>			&getPlayers(void);

    const irr::core::vector3df			&getCameraPosition(void) const;

    double					getPlayerScale(void) const;

    const irr::core::line3df			&getCheckPoint(size_t checkPointID) const;

    const irr::core::vector3df			getCheckPointCenter(size_t checkPointID) const;

    size_t					getCheckpointsCount(void) const;

    /**
     * @brief Set a new position of this circuit
     * @param pos
     */

    void					setPosition(const irr::core::vector3df &pos);

    /**
     * @brief check if the player is on a checkpoint
     * @param p
     * @return bool
     */

    CollisionManager				&getColManager(void);

    bool					onCheckPoint(size_t checkPointID, Player &p);

  };

}

#endif //CPP_INDIE_STUDIO_CIRCUIT_HPP
