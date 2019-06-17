//
// Result.hpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/controller/Result
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Sat Jun	17 14:42:31 2017 Guillaume Bouxin
// Last update	Sat Jun	17 14:42:31 2017 Guillaume Bouxin
//

#ifndef CPP_INDIE_STUDIO_RESULT_HPP
#define CPP_INDIE_STUDIO_RESULT_HPP

#include	"ResultView.hpp"
#include	"RessourceManager.hpp"
#include	"AController.hpp"
#include	"ModelManager.hpp"
#include	"Player.hpp"
#include 	"MRessource.hpp"

namespace	controller {

	class Result : public AController 
	{
	private:

		view::ResultView       			_view;
		std::vector<model::Player *> 	_players;
		int 							_xPos;
		int 							_xEspace;

	public:

        /**
         * @brief      Result of game
         *
         * @param      manager     The manager
         * @param      ressources  The ressources
         * @param      renderer    The renderer
         * @param      event       The event
         */
		Result(core::ModelManager *manager, engine::RessourceManager *ressources, core::MyEventReceiver *event, core::System *system);
		~Result();

		virtual state run();

		void getAllPlayer();

		void writeResult();

		void deletePlayer();
	};

}

#endif