//
// SelectCircuitMenuView.hpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/view/SelectCircuitMenu
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Thu Jun	15 18:59:20 2017 Guillaume Bouxin
// Last update	Thu Jun	15 18:59:20 2017 Guillaume Bouxin
//

#ifndef SELECTCIRCUITMENUVIEW_HPP
# define SELECTCIRCUITMENUVIEW_HPP

#include    "AView.hpp"
#include    "Basic.hpp"
#include 	"Height.hpp"
#include 	"MRessource.hpp"

namespace view
{
	class SelectCircuitMenuView : public AView
	{
	public:
		SelectCircuitMenuView(core::ModelManager *, engine::RessourceManager *);

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
		
		virtual ~SelectCircuitMenuView();
		
		virtual void    stop();
		virtual void	begin();
	};
}

#endif