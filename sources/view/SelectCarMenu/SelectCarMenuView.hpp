//
// SelectCarMenuView.hpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/view/SelectCarMenu
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Wed Jun	14 17:29:43 2017 Guillaume Bouxin
// Last update	Wed Jun	14 17:29:43 2017 Guillaume Bouxin
//

#ifndef SELECTCARMENUVIEW_HPP
# define SELECTCARMENUVIEW_HPP

#include 	"BlueBird.hpp"
#include    "Bruno.hpp"
#include    "Sinder.hpp"
#include    "SunnyGo.hpp"
#include   	"Mitraille.hpp"
#include    "AView.hpp"
#include 	"MRessource.hpp"

namespace view
{
	class SelectCarMenuView : public AView
	{
	public:
		SelectCarMenuView(core::ModelManager *, engine::RessourceManager *);

		/**
		 * @brief      Check or create a model
		 */
		template <typename T>
		void checkOrCreateModel(const std::string &name, T t)
		{
			if (this->_mm->isHere(name))
				this->_mm->getModel<T>(name)->grab();
			else
				this->_mm->getModel<T>(name, t)->grab();
		}
		
		virtual ~SelectCarMenuView();

		virtual void    stop();

		virtual void	begin();
	};
}

#endif