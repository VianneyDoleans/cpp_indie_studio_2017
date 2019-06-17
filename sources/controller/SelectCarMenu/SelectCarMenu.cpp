//
// SelectCarMenu.cpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/controller/SelectCarMenu
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Wed Jun	14 15:34:52 2017 Guillaume Bouxin
// Last update	Wed Jun	14 15:34:52 2017 Guillaume Bouxin
//

#include	"Player.hpp"
#include 	"SelectCarMenu.hpp"

controller::SelectCarMenu::SelectCarMenu(core::ModelManager *manager, engine::RessourceManager *ressources, core::MyEventReceiver *event, core::System *system)
: AController(manager, ressources, event, system), _view(manager, ressources)
{
	this->_vitesseMove = 40;
	irr::scene::IAnimatedMesh		*mesh =  this->_device->getSceneManager()->getMesh("ressources/Circuit/Menu/Wii_Coconut_Mall.obj");
	this->_node = this->_device->getSceneManager()->addOctreeSceneNode(mesh, nullptr);

	this->_node->setVisible(false);
	this->_node->setScale(irr::core::vector3df(1.f, 1.f, 1.f));
	this->_node->setPosition(irr::core::vector3df(-1600.f, -130.f, -1300.f));
	this->_node->setMaterialType(irr::video::EMT_SOLID);
	this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

controller::SelectCarMenu::~SelectCarMenu()
{
}

controller::state controller::SelectCarMenu::run() 
{
	this->_playerNb = 0;
	this->_aiNb = 0;
	size_t voiture = 0;
	bool isChangeQuit = false;
	bool isChangeCome = false;
	int direction = 0;
	irr::core::vector3df nodePosition;

	this->_view.begin();
	this->_node->setVisible(true);
	
	this->_carList.push_back(std::make_pair(this->_manager->getModel<model::BlueBird>("CarMenu1"), BLUEBIRD));
	this->_carList.push_back(std::make_pair(this->_manager->getModel<model::Bruno>("CarMenu2"), BRUNO));
	this->_carList.push_back(std::make_pair(this->_manager->getModel<model::SunnyGo>("CarMenu3"), SUNNYGO));
	this->_carList.push_back(std::make_pair(this->_manager->getModel<model::Sinder>("CarMenu4"), SINDER));
	this->_carList.push_back(std::make_pair(this->_manager->getModel<model::Mitraille>("CarMenu5"), MITRAILLE));

	this->_view.removeCamera();
	this->_view.moveCameraStatic(irr::core::vector3df(0, 50, 300), irr::core::vector3df(0,0,0));
	this->_view.addLight(irr::core::vector3df(0,100,300), irr::video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 100000.0f);

	engine::MRessource *sound_change = this->_ressources->getRessource<engine::MRessource>("ressources/Sound/change_menu.wav", engine::RessourceManager::RType::SOUND);
	engine::MRessource *sound_valide = this->_ressources->getRessource<engine::MRessource>("ressources/Sound/valide.wav", engine::RessourceManager::RType::SOUND);

	this->initCar();

    const double timeStep = 15; // 15 milliseconds == 58.8 FPS
	while (this->_device->run())
	{
        auto startTime = std::chrono::system_clock::now();

		nodePosition = this->_carList[voiture].first->getCar()->getPosition();
		if (isChangeQuit == true)
		{
			if (nodePosition.X < 300 && direction == 0)
				goLeft(voiture);
			else if (nodePosition.X > -300 && direction == 1)
				goRight(voiture);
			else
			{
				isChangeQuit = false;
				isChangeCome = true;
				changeCar(voiture, direction);
			}
		}
		else if (isChangeCome == true)
		{
			if (nodePosition.X < 0 && direction == 0)
				goLeft(voiture);
			else if (nodePosition.X > 0 && direction == 1)
				goRight(voiture);
			else
				isChangeCome = false;
		}
		else
		{
			if (this->_event->IsKeyDown(irr::KEY_LEFT))
			{
				sound_change->play(_system->getVolume());
				isChangeQuit = true;
				direction = 0;
			}
			else if (this->_event->IsKeyDown(irr::KEY_RIGHT))
			{
				sound_change->play(_system->getVolume());
				isChangeQuit = true;
				direction = 1;
			}
			else if (this->_event->IsKeyPressed(irr::KEY_RETURN))
			{
				sound_valide->play(_system->getVolume());
				if (this->createNewPlayer(this->selectCarType(this->_carList[voiture].second)))
				{
					this->quit();
					this->_next = "SelectCircuitMenu";
					return (NEXT);
				}
			}
			else if (this->_event->IsKeyPressed(irr::KEY_ESCAPE))
			{
				if (this->_playerNb == 0)
				{
					this->quit();
					this->_next = "UIMenu";
					return (NEXT);
				}
			}
		}
		this->_driver->beginScene(true, true, irr::video::SColor(255, 200, 200, 200));
		this->rotateCar(voiture);
		this->_ressources->getDevice()->getSceneManager()->drawAll();
		this->_ressources->getDevice()->getGUIEnvironment()->drawAll();
		this->_view.drawText(getPlayerName(true), irr::core::rect<irr::s32>(850, 20, 300, 60), irr::video::SColor(255, 255, 255, 255));
		this->_ressources->getDevice()->getVideoDriver()->endScene();
		this->_event->startEventProcess();

        // Framerate
        auto endTime = std::chrono::system_clock::now();

        if (std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() < timeStep)
        {
            this->_device->sleep(static_cast<irr::u32>(timeStep -
            std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()));
        }

	}
	return (STOP);
}

model::Car controller::SelectCarMenu::selectCarType(SelectCarMenu::CarType carType)
{
	switch (carType) {
		case BLUEBIRD:
		return (model::BlueBird(*this->_ressources));
		break;
		case BRUNO: 
		return (model::Bruno(*this->_ressources));
		break;
		case SUNNYGO:
		return (model::SunnyGo(*this->_ressources));
		break;
		case SINDER: 
		return (model::Sinder(*this->_ressources));
		break;
		case MITRAILLE: 
		return (model::Mitraille(*this->_ressources));
		break;
	}
	return (model::BlueBird(*this->_ressources));
}

void controller::SelectCarMenu::quit()
{
	this->_node->setVisible(false);
	this->_view.stop();
	this->_event->startEventProcess();
}

void controller::SelectCarMenu::rotateCar(size_t index)
{
	//Rotate of car
	irr::core::vector3df nodeRotation = this->_carList[index].first->getCar()->getRotation();
	nodeRotation.Y += 1;
	this->_carList[index].first->getCar()->setRotation(nodeRotation);
}

void controller::SelectCarMenu::initCar()
{
	for (std::vector<std::pair<model::Car *, CarType>>::iterator it = this->_carList.begin(); it != this->_carList.end(); it++)
	{
		(*it).first->getCar()->setVisible(false);
	}
	this->_carList[0].first->getCar()->setVisible(true);
}

void controller::SelectCarMenu::changeCar(size_t &index, int direction)
{
	this->_carList[index].first->getCar()->setVisible(false);
	if (direction == 0)
	{
		if (index < this->_carList.size() - 1)
			index += 1;
		else
			index = 0;
		this->_carList[index].first->setPosition(irr::core::vector3df(-300, 0, 0));
	}
	else
	{
		if (index > 0)
			index -= 1;
		else
			index = this->_carList.size() - 1;
		this->_carList[index].first->setPosition(irr::core::vector3df(300, 0, 0));
	}
	this->_carList[index].first->getCar()->setVisible(true);
}

void controller::SelectCarMenu::goRight(size_t index)
{
	this->_carList[index].first->setPosition(
		irr::core::vector3df(this->_carList[index].first->getPosition().X - this->_vitesseMove,
			this->_carList[index].first->getPosition().Y,
			this->_carList[index].first->getPosition().Z));
}

void controller::SelectCarMenu::goLeft(size_t index)
{
	this->_carList[index].first->setPosition(
		irr::core::vector3df(this->_carList[index].first->getPosition().X + this->_vitesseMove,
			this->_carList[index].first->getPosition().Y,
			this->_carList[index].first->getPosition().Z));
}

std::string controller::SelectCarMenu::getPlayerName(bool escape)
{
	std::string name;
	name += "Player";
	if (escape == true)
		name += " ";
	name += std::to_string(this->_playerNb + 1);
	return (name);
}