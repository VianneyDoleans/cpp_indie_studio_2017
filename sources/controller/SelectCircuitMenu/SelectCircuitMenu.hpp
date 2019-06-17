//
// SelectCircuitMenu.hpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/controller/SelectCircuitMenu
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Thu Jun	15 18:54:35 2017 Guillaume Bouxin
// Last update	Thu Jun	15 18:54:35 2017 Guillaume Bouxin
//

#ifndef CPP_INDIE_STUDIO_SELECTCIRCUITMENU_HPP
#define CPP_INDIE_STUDIO_SELECTCIRCUITMENU_HPP

#include	<chrono>
#include	"SelectCircuitMenuView.hpp"
#include	"AController.hpp"
#include 	"Basic.hpp"
#include 	"Height.hpp"

namespace   controller
{
	class SelectCircuitMenu : public AController
	{
	private:
		enum type_circuit {
			BASIC,
			HEIGHT
		};
		view::SelectCircuitMenuView       	_view;
		std::vector<std::pair<model::ACircuit *, type_circuit>>   	_circuitList;
		int                           		_vitesseMove;
	public:
		SelectCircuitMenu(core::ModelManager *manager, engine::RessourceManager *rcs, core::MyEventReceiver *event, core::System *system);
		virtual ~SelectCircuitMenu();

		virtual state           run();

        /**
         * @brief      Creates a new circuit.
         */
		void createNewCircuit(type_circuit type_circuit);
		/**
		 * @brief      Rotate the circuit
		 *
		 * @param[in]  index  The index
		 */
		void rotateCircuit(int index);

		/**
		 * @brief      Init the circuit
		 */
		void initCircuit();

		/**
		 * @brief      Change circuit
		 *
		 * @param      <unnamed>  { parameter_description }
		 */
		void changeCircuit(int &, int);

		/**
		 * @brief      Go to left
		 *
		 * @param[in]  <unnamed>  { parameter_description }
		 */
		void goLeft(int);

		/**
		 * @brief      Go to right
		 *
		 * @param[in]  <unnamed>  { parameter_description }
		 */
		void goRight(int);

		void 							quit();

	};
}


#endif