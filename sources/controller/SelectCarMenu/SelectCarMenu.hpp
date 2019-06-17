//
// SelectCarController.hpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/controller/SelectCarMenu
//
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
//
// Started on	Wed Jun	14 15:32:48 2017 Guillaume Bouxin
// Last update	Wed Jun	14 15:32:48 2017 Guillaume Bouxin
//

#ifndef CPP_INDIE_STUDIO_SELECTCARMENU_HPP
#define CPP_INDIE_STUDIO_SELECTCARMENU_HPP

#include							<iostream>
#include							<chrono>
#include							"RessourceManager.hpp"
#include							"AController.hpp"
#include 							"BlueBird.hpp"
#include    						"Bruno.hpp"
#include    						"Sinder.hpp"
#include    						"SunnyGo.hpp"
#include    						"Mitraille.hpp"
#include							"ModelManager.hpp"
#include    						"SelectCarMenuView.hpp"
namespace							controller {

	class 							SelectCarMenu : public AController
	{

	private:

	  enum CarType {

	    BLUEBIRD,
	    BRUNO,
	    SUNNYGO,
	    SINDER,
	    MITRAILLE

	  };

	  view::SelectCarMenuView       			_view;
	  std::vector<std::pair<model::Car *, CarType>>    	_carList;
	  int                           			_vitesseMove;
	  unsigned int                           		_playerNb;
	  unsigned int                           		_aiNb;
	  irr::scene::ISceneNode 						*_node;

	public:

        /**
         * @brief      Menu to select the car
         *
         * @param      manager     The manager
         * @param      ressources  The ressources
         * @param      renderer    The renderer
         * @param      event       The event
         */
	SelectCarMenu(core::ModelManager *manager, engine::RessourceManager *ressources, core::MyEventReceiver *event, core::System *system);
	  ~SelectCarMenu();

        /**
         * @brief      Create selected car
         */
        template <typename T>
	void 							newCar(const std::string &carName, T t)
	{
	  this->_manager->getModel<T>(carName, t);
	  this->_manager->getModel<T>(carName)->drop();
	  std::cout << "Create car => " << this->_manager->getModel<T>(carName)->getName() << std::endl;
	}

        /**
         * @brief      Creates a new player.
         */
        template <typename K>
	bool 							createNewPlayer(K k)
	{
	  std::string carName = "Car";

	  carName += std::to_string(this->_playerNb + 1);
	  this->newCar(carName, k);
	  this->_manager->getModel<model::Player>(
	    getPlayerName(false),
	    model::Player(getPlayerName(false), *this->_manager->getModel<K>(carName))
	  );
	  std::cout << "Create player => " << getPlayerName(false) << std::endl;
	  this->_playerNb += 1;
	  return (this->_system->getNbrPlayer() == this->_playerNb);
	}

	        /**
		 * @brief      Get the car selected
		 *
		 * @param[in]  type_car  The type car
		 *
		 * @return     Return instance of car
		 */

		model::Car 					selectCarType(SelectCarMenu::CarType CarType);

        /**
         * @brief      Rotate the car
         *
         * @param[in]  index  The index
         */
		void 						rotateCar(size_t index);

        /**
         * @brief      Initialize visibility of a car
         */
		void 						initCar();

        /**
         * @brief      Change selection of a car
         *
         * @param[in]  <unnamed>  Index of car in vector
         */
		void 						changeCar(size_t &, int);

		/**
         * @brief      Got to the left
         *
         * @param[in]  <unnamed> index
         */
		void 						goLeft(size_t index);

		/**
         * @brief      Go to the right
         *
         * @param[in]  <unnamed>  index
         */
		void 						goRight(size_t index);

        /**
         * @brief      Gets the player name.
         *
         * @return     The player name.
         */
		std::string 					getPlayerName(bool);

		void 							quit();

		virtual state 					run();
	};

}

#endif
