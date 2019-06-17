//
// ResultView.cpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/view/Result
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Sat Jun	17 15:05:34 2017 Guillaume Bouxin
// Last update	Sat Jun	17 15:05:34 2017 Guillaume Bouxin
//

#include "ResultView.hpp"

view::ResultView::ResultView(core::ModelManager *mm, engine::RessourceManager *rm)
: AView(mm, rm)
{
}

view::ResultView::~ResultView()
{
}

void view::ResultView::stop()
{
	this->removeCamera();
}

void view::ResultView::begin()
{
}

void view::ResultView::drawDamier()
{
	irr::video::ITexture* images = this->_rm->getDevice()->getVideoDriver()->getTexture("ressources/Result/flags.png");

	this->_rm->getDevice()->getVideoDriver()->enableMaterial2D();
	this->_rm->getDevice()->getVideoDriver()->draw2DImage(images, irr::core::position2d<irr::s32>(750,50),
		irr::core::rect<irr::s32>(0,0,400,202), 0,
		irr::video::SColor(255,255,255,255), true);
	this->_rm->getDevice()->getVideoDriver()->enableMaterial2D(false);
}

void view::ResultView::writeTitle()
{
	this->drawText("Pos", irr::core::rect<irr::s32>(300, 350, 100, 20), irr::video::SColor(255, 0, 10, 10), true, false);
	this->drawText("Player Name", irr::core::rect<irr::s32>(400, 350, 600, 60), irr::video::SColor(255, 0, 10, 10), true, false);
	this->drawText("Car Name", irr::core::rect<irr::s32>(1000, 350, 600, 60), irr::video::SColor(255, 0, 10, 10), true, false);
	this->drawText("Best Time", irr::core::rect<irr::s32>(1600, 350, 600, 60), irr::video::SColor(255, 0, 10, 10), true, false);
	this->drawText("Total Time", irr::core::rect<irr::s32>(2200, 350, 600, 60), irr::video::SColor(255, 0, 10, 10), true, false);
	this->drawText("Lap", irr::core::rect<irr::s32>(2800, 350, 600, 60), irr::video::SColor(255, 0, 10, 10), true, false);
}

void view::ResultView::writePlayer(model::Player *player, int place, int y)
{
	this->drawText(std::to_string(place), irr::core::rect<irr::s32>(300, y, 100, 20), irr::video::SColor(255, 200, 100, 100), true, false);
	this->drawText(player->getName(), irr::core::rect<irr::s32>(400, y, 600, 60), irr::video::SColor(255, 200, 100, 100), true, false);
	this->drawText(player->getCar().getName(), irr::core::rect<irr::s32>(1000, y, 600, 600), irr::video::SColor(255, 200, 100, 100), true, false);
	if (player->getLap() == 1)
		this->drawText(std::to_string(player->getTime()), irr::core::rect<irr::s32>(1600, y, 600, 60), irr::video::SColor(255, 200, 100, 100), true, false);
	else
		this->drawText(std::to_string(player->getBestLap()), irr::core::rect<irr::s32>(1600, y, 600, 60), irr::video::SColor(255, 200, 100, 100), true, false);
	this->drawText(std::to_string(player->getTime()), irr::core::rect<irr::s32>(2200, y, 600, 60), irr::video::SColor(255, 200, 100, 100), true, false);
	this->drawText(std::to_string(player->getLap()), irr::core::rect<irr::s32>(2800, y, 600, 60), irr::video::SColor(255, 200, 100, 100), true, false);
}