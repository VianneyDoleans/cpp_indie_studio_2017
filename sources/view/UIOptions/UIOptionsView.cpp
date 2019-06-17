/*
** UIOptionsView.cpp for cpp_indie_studio in /home/charles/Documents/C++/cpp_indie_studio/sources/view/UIOptions/UIOptionsView.cpp
**
** Made by Charles des Pommare
** Login   <charles.des-pommare@epitech.eu>
**
** Started on  Sat Jun 17 15:55:08 2017 Charles des Pommare
** Last update Sat Jun 17 15:55:09 2017 Charles des Pommare
*/

#include "UIOptionsView.hpp"

view::UIOptionsView::UIOptionsView(core::ModelManager *model, engine::RessourceManager *ressources)
  : AView(model, ressources)
{
}

void	view::UIOptionsView::begin() {
}

void	view::UIOptionsView::drawTextOptions() {
  this->drawText("Volume", irr::core::rect<irr::s32>(500, 215, 100, 100), irr::video::SColor(255, 255, 255, 255));
  this->drawText("Split", irr::core::rect<irr::s32>(500, 415, 100, 100), irr::video::SColor(255, 255, 255, 255));
  this->drawText("Laps", irr::core::rect<irr::s32>(500, 615, 100, 100), irr::video::SColor(255, 255, 255, 255));
  this->drawText("Players", irr::core::rect<irr::s32>(500, 815, 100, 100), irr::video::SColor(255, 255, 255, 255));
}

void	view::UIOptionsView::drawSelections(unsigned int _volume, bool _split, unsigned int _laps, unsigned int _players) {
  this->drawText(std::to_string(_volume), irr::core::rect<irr::s32>(1000, 215, 100, 100), irr::video::SColor(255, 255, 255, 255));
  if (_split)
    this->drawText("Enable", irr::core::rect<irr::s32>(1000, 415, 100, 100), irr::video::SColor(255, 255, 255, 255));
  else
    this->drawText("Disable", irr::core::rect<irr::s32>(1000, 415, 100, 100), irr::video::SColor(255, 255, 255, 255));
  this->drawText(std::to_string(_laps), irr::core::rect<irr::s32>(1000, 615, 100, 100), irr::video::SColor(255, 255, 255, 255));
  this->drawText(std::to_string(_players), irr::core::rect<irr::s32>(1000, 815, 100, 100), irr::video::SColor(255, 255, 255, 255));
}

void	view::UIOptionsView::dispArrow(irr::video::ITexture *tex, const irr::core::position2d<irr::s32> &pos, irr::u32 time,
					   irr::core::rect<irr::s32> imp1, irr::core::rect<irr::s32> imp2) {
  this->_rm->getDevice()->getVideoDriver()->enableMaterial2D();
  this->_rm->getDevice()->getVideoDriver()->draw2DImage(tex,
			     pos, (time/400 % 2) ? imp1 : imp2, 0, irr::video::SColor(255,255,255,255), true);
  this->_rm->getDevice()->getVideoDriver()->enableMaterial2D(false);
}

void	view::UIOptionsView::stop() {

}