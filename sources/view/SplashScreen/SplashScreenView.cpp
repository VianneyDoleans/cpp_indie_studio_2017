/*
** SplashScreenView.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/view/SplashScreen/SplashScreenView.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sun Jun 18 16:23:32 2017 Montagne Valentin
** Last update Sun Jun 18 16:23:32 2017 Montagne Valentin
*/

#include <netinet/in.h>
#include "SplashScreenView.hpp"

view::SplashScreenView::SplashScreenView(core::ModelManager *manager,
					 engine::RessourceManager *ressourceManager)
  : AView(manager, ressourceManager)
{}

view::SplashScreenView::~SplashScreenView() {}

void view::SplashScreenView::stop() {

}

void view::SplashScreenView::begin() {

}

void view::SplashScreenView::drawImg(irr::u32 alpha) {
  irr::video::ITexture* images = this->_rm->getDevice()->getVideoDriver()->getTexture("ressources/Derby.png");

  this->_rm->getDevice()->getVideoDriver()->enableMaterial2D();
  this->_rm->getDevice()->getVideoDriver()->draw2DImage(images, irr::core::position2d<irr::s32>(0,0),
							irr::core::rect<irr::s32>(0,0,1920,1080), 0,
							irr::video::SColor(alpha,255,255,255), true);
  this->_rm->getDevice()->getVideoDriver()->enableMaterial2D(false);
}
