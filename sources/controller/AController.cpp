/*
** AController.cpp for cpp_indie_studio in /home/vianney/cpp_indie_studio/sources/controller/AController.cpp
**
** Made by Vianney Doleans
** Login   <vianney.doleans@epitech.eu>
**
** Started on  Mon Jun 12 16:13:28 2017 Vianney Doleans
** Last update Mon Jun 12 16:14:03 2017 Vianney Doleans
*/

#include "AController.hpp"

controller::AController::AController(core::ModelManager *manager, engine::RessourceManager *ressources, core::MyEventReceiver *event, core::System *system)
:_manager(manager), _ressources(ressources), _event(event), 
_device(ressources->getDevice()), _smgr(ressources->getDevice()->getSceneManager()), _driver(ressources->getDevice()->getVideoDriver()), _system(system)//, _view(renderer, manager, ressources)
{
}

controller::AController::~AController()
{
}

const std::string &controller::AController::getNext() const
{
	return (this->_next);
}
