/*
** UIMenuView.hpp for cpp_indie_studio in /home/charles/Documents/C++/cpp_indie_studio/sources/view/UIMenu/UIMenuView.hpp
**
** Made by Charles des Pommare
** Login   <charles.des-pommare@epitech.eu>
**
** Started on  Thu Jun 15 17:52:46 2017 Charles des Pommare
** Last update Thu Jun 15 17:52:46 2017 Charles des Pommare
*/


#ifndef CPP_INDIE_STUDIO_UIMENUVIEW_HPP
#define CPP_INDIE_STUDIO_UIMENUVIEW_HPP

#include "AView.hpp"

namespace	view
{
  class UIMenuView : public AView
  {

  public:
    UIMenuView(core::ModelManager *model, engine::RessourceManager *ressources);

    virtual	~UIMenuView() {};

    /**
     * @brief check or create a model
     */
    template <typename T>
    void checkOrCreateModel(const std::string &name, const T &t)
    {
      if (this->_mm->isHere(name))
	this->_mm->getModel<T>(name)->grab();
      else
	this->_mm->getModel<T>(name, t)->grab();
    }

    /**
     * @brief show the menu
     */
    virtual void	begin();

    void		dispArrow(irr::video::ITexture *tex, const irr::core::position2d<irr::s32> &pos, irr::u32 time,
				  irr::core::rect<irr::s32> imp1, irr::core::rect<irr::s32> imp2);

    /**
     * @brief hide the menu
     */
    virtual void	stop();

  };
}

#endif //CPP_INDIE_STUDIO_UIMENUVIEW_HPP
