/*
** UIMenuView.cpp for cpp_indie_studio in /home/charles/Documents/C++/cpp_indie_studio/sources/view/UIMenu/UIMenuView.cpp
**
** Made by Charles des Pommare
** Login   <charles.des-pommare@epitech.eu>
**
** Started on  Thu Jun 15 17:52:40 2017 Charles des Pommare
** Last update Thu Jun 15 17:52:40 2017 Charles des Pommare
*/

#include	"UIButton.hpp"
#include	"UIMenuView.hpp"

view::UIMenuView::UIMenuView(core::ModelManager *model, engine::RessourceManager *ressources)
  : AView(model, ressources)
{
  this->checkOrCreateModel("Play", model::UIButton(model::Position(200, 200), model::Position(600, 300), L"PLAY", ressources));
  this->checkOrCreateModel("Options", model::UIButton(model::Position(200, 400), model::Position(600, 500), L"OPTIONS", ressources));
  this->checkOrCreateModel("Quit", model::UIButton(model::Position(200, 600), model::Position(600, 700), L"QUIT", ressources));
  this->stop();
}

void		view::UIMenuView::begin() {
  this->_mm->getModel<model::UIButton>("Play")->grab();
  this->_mm->getModel<model::UIButton>("Options")->grab();
  this->_mm->getModel<model::UIButton>("Quit")->grab();
}

void		view::UIMenuView::dispArrow(irr::video::ITexture *tex, const irr::core::position2d<irr::s32> &pos, irr::u32 time,
						irr::core::rect<irr::s32> imp1, irr::core::rect<irr::s32> imp2) {
  this->_rm->getDevice()->getVideoDriver()->enableMaterial2D();
  this->_rm->getDevice()->getVideoDriver()->draw2DImage(tex,
			     pos, (time/400 % 2) ? imp1 : imp2, 0, irr::video::SColor(255,255,255,255), true);
  this->_rm->getDevice()->getVideoDriver()->enableMaterial2D(false);
}

void		view::UIMenuView::stop() {
  this->_mm->getModel<model::UIButton>("Play")->drop();
  this->_mm->getModel<model::UIButton>("Options")->drop();
  this->_mm->getModel<model::UIButton>("Quit")->drop();
}