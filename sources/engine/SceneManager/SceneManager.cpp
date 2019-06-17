//
// SceneManager.cpp for indie_studio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/SceneManager
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Sat May	20 13:43:49 2017 Guillaume Bouxin
// Last update	Sat May	20 13:43:49 2017 Guillaume Bouxin
//

#include <SplashScreen/SplashScreen.hpp>
#include "UIOptions.hpp"
#include "Basic.hpp"
#include "BlueBird.hpp"
#include "SceneManager.hpp"
#include "SelectCarMenu.hpp"
#include "Game.hpp"
#include "ACircuit.hpp"

engine::SceneManager::SceneManager(int width, int height, core::MyEventReceiver *receiver) 
: _rm(*irr::createDevice(irr::video::EDT_OPENGL,irr::core::dimension2d<irr::u32>(width, height),16, false, false, false, receiver))
{
	this->_device = this->_rm.getDevice();
	this->_smgr = this->_device->getSceneManager();
	this->_driver = this->_device->getVideoDriver();
	this->_receiver = receiver;

	this->_controllerList = {
	  {"SplashScreen", (std::make_shared<controller::SplashScreen>
	    (&this->_modelManager, &this->_rm, this->_receiver,
	     &(this->_system))) },
		{"UIMenu", (std::make_shared<controller::UIMenu>
		  (&this->_modelManager, &this->_rm, this->_receiver,
		   &(this->_system))) },
		{"UIOptions", (std::make_shared<controller::UIOptions>
		  (&this->_modelManager, &this->_rm, this->_receiver,
		   &(this->_system))) },
		{"SelectCarMenu",     (std::make_shared<controller::SelectCarMenu>(
			&this->_modelManager, &this->_rm, this->_receiver,
			&(this->_system)))},
		{"Game", (std::make_shared<controller::Game>(
			&this->_modelManager, &this->_rm, this->_receiver, &(this->_system)))},
		{"SelectCircuitMenu", (std::make_shared<controller::SelectCircuitMenu>(
			&this->_modelManager, &this->_rm, this->_receiver,
			&(this->_system)))},
		{"Result", (std::make_shared<controller::Result>(
			&this->_modelManager, &this->_rm, this->_receiver,
			&(this->_system)))}
	};
}

engine::SceneManager::~SceneManager()
{
}

void engine::SceneManager::executionThread()
{
	int index = 0;
	std::string controller_name = "SplashScreen";
	std::string return_value;

	while (1)
	{
		std::cout << "Controller: " << controller_name << std::endl;
		return_value = this->launchController(controller_name);
		if (return_value.empty())
			break;
		else
		{
			index++;
			controller_name = return_value;
		}
	}
	this->_device->drop();
}

std::string engine::SceneManager::launchController(const std::string &controller_name)
{
	if (this->_controllerList.at(controller_name)->run() == controller::NEXT)
		return (this->_controllerList.at(controller_name)->getNext());
	else
		return ("");
}

irr::scene::ISceneManager *engine::SceneManager::getSceneManager()
{
	return (this->_smgr);
}

irr::video::IVideoDriver *engine::SceneManager::getDriver()
{
	return (this->_driver);
}

irr::IrrlichtDevice *engine::SceneManager::getDevice()
{
	return (this->_device);
}

core::ModelManager &engine::SceneManager::getModelManager()
{
	return (this->_modelManager);
}

engine::RessourceManager &engine::SceneManager::getRessourceManager()
{
	return (this->_rm);
}