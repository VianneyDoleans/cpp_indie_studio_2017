//
// SelectCarMenuView.cpp for SelectCarMenuView in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/view/SelectCarMenu
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Wed Jun	14 17:29:22 2017 Guillaume Bouxin
// Last update	Wed Jun	14 17:29:22 2017 Guillaume Bouxin
//

#include <iostream>
#include "SelectCarMenuView.hpp"

view::SelectCarMenuView::SelectCarMenuView(core::ModelManager *mm, engine::RessourceManager *rm)
: AView(mm, rm)
{
	this->checkOrCreateModel("CarMenu1", model::BlueBird(*this->_rm));
	this->checkOrCreateModel("CarMenu2", model::Bruno(*this->_rm));
	this->checkOrCreateModel("CarMenu3", model::SunnyGo(*this->_rm));
	this->checkOrCreateModel("CarMenu4", model::Sinder(*this->_rm));
	this->checkOrCreateModel("CarMenu5", model::Mitraille(*this->_rm));
}

view::SelectCarMenuView::~SelectCarMenuView()
{
}

void view::SelectCarMenuView::stop()
{
	this->_mm->getModel<model::BlueBird>("CarMenu1")->drop();
	this->_mm->getModel<model::Bruno>("CarMenu2")->drop();
	this->_mm->getModel<model::SunnyGo>("CarMenu3")->drop();
	this->_mm->getModel<model::Sinder>("CarMenu4")->drop();
	this->_mm->getModel<model::Mitraille>("CarMenu5")->drop();
}

void view::SelectCarMenuView::begin()
{
	this->_mm->getModel<model::BlueBird>("CarMenu1")->grab();
	this->_mm->getModel<model::BlueBird>("CarMenu1")->setPosition(irr::core::vector3df(0,0,0));
	this->_mm->getModel<model::Bruno>("CarMenu2")->grab();
	this->_mm->getModel<model::Bruno>("CarMenu2")->setPosition(irr::core::vector3df(0,0,0));
	this->_mm->getModel<model::SunnyGo>("CarMenu3")->grab();
	this->_mm->getModel<model::SunnyGo>("CarMenu3")->setPosition(irr::core::vector3df(0,0,0));
	this->_mm->getModel<model::Sinder>("CarMenu4")->grab();
	this->_mm->getModel<model::Sinder>("CarMenu4")->setPosition(irr::core::vector3df(0,0,0));
	this->_mm->getModel<model::Mitraille>("CarMenu5")->grab();
	this->_mm->getModel<model::Mitraille>("CarMenu5")->setPosition(irr::core::vector3df(0,0,0));
}
