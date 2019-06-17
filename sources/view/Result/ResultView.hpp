//
// ResultView.hpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/view/Result
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Sat Jun	17 15:06:40 2017 Guillaume Bouxin
// Last update	Sat Jun	17 15:06:40 2017 Guillaume Bouxin
//

#ifndef RESULTVIEW_HPP
# define RESULTVIEW_HPP

#include	"Player.hpp"
#include    "AView.hpp"
#include    "System.hpp"

namespace view
{
	class ResultView : public AView
	{
	public:
		ResultView(core::ModelManager *, engine::RessourceManager *);
		
		virtual ~ResultView();

		virtual void    stop();

		virtual void	begin();

		void writeTitle();

		void drawDamier();

		void writePlayer(model::Player *, int place, int y);
	};
}

#endif