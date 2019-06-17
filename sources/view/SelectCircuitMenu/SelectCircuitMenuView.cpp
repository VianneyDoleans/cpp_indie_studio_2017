//
// SelectCircuitMenuView.cpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/view/SelectCircuitMenu
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Thu Jun	15 19:00:15 2017 Guillaume Bouxin
// Last update	Thu Jun	15 19:00:15 2017 Guillaume Bouxin
//

#include "SelectCircuitMenuView.hpp"

view::SelectCircuitMenuView::SelectCircuitMenuView(core::ModelManager *mm, engine::RessourceManager *rm)
: AView(mm, rm)
{
	this->checkOrCreateModel("CircuitMenu1", model::Basic(*this->_rm));
	this->checkOrCreateModel("CircuitMenu2", model::Height(*this->_rm));
	this->_mm->getModel<model::Basic>("CircuitMenu1")->getCircuit()->setScale(irr::core::vector3df(80.f, 80.f, 80.f));
	this->_mm->getModel<model::Height>("CircuitMenu2")->getCircuit()->setScale(irr::core::vector3df(4.f, 4.f, 4.f));
}

view::SelectCircuitMenuView::~SelectCircuitMenuView()
{
}

void view::SelectCircuitMenuView::stop()
{
	this->_mm->getModel<model::Basic>("CircuitMenu1")->drop();
	this->_mm->getModel<model::Height>("CircuitMenu2")->drop();
}

void view::SelectCircuitMenuView::begin()
{
	this->_mm->getModel<model::Basic>("CircuitMenu1")->grab();
	this->_mm->getModel<model::Basic>("CircuitMenu1")->setPosition(irr::core::vector3df(0,-150,0));
	this->_mm->getModel<model::Height>("CircuitMenu2")->grab();
	this->_mm->getModel<model::Height>("CircuitMenu2")->setPosition(irr::core::vector3df(0,-200,-500));
};