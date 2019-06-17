/*
** UIOptionsView.hpp for cpp_indie_studio in /home/charles/Documents/C++/cpp_indie_studio/sources/view/UIOptions/UIOptionsView.hpp
**
** Made by Charles des Pommare
** Login   <charles.des-pommare@epitech.eu>
**
** Started on  Sat Jun 17 15:55:05 2017 Charles des Pommare
** Last update Sat Jun 17 15:55:05 2017 Charles des Pommare
*/

#ifndef CPP_INDIE_STUDIO_UIOPTIONSVIEW_HPP
#define CPP_INDIE_STUDIO_UIOPTIONSVIEW_HPP

#include "AView.hpp"

namespace	view
{

  class UIOptionsView : public AView {

  public:

    UIOptionsView(core::ModelManager *, engine::RessourceManager *);

    virtual ~UIOptionsView() {};

    virtual void	begin();

    virtual void	stop();

    void		drawTextOptions();

    void		drawSelections(unsigned int _volume, bool _split, unsigned int _ia, unsigned int _players);

    void		dispArrow(irr::video::ITexture *tex, const irr::core::position2d<irr::s32> &pos, irr::u32 time,
				  irr::core::rect<irr::s32> imp1, irr::core::rect<irr::s32> imp2);

  };

}

#endif //CPP_INDIE_STUDIO_UIOPTIONSVIEW_HPP
