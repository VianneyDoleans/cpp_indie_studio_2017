//
// SelectCircuitMenu.cpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/controller/SelectCircuitMenu
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Thu Jun	15 18:54:51 2017 Guillaume Bouxin
// Last update	Thu Jun	15 18:54:51 2017 Guillaume Bouxin
//

#include "SelectCircuitMenu.hpp"

controller::SelectCircuitMenu::SelectCircuitMenu(core::ModelManager *manager, engine::RessourceManager *ressources,
	core::MyEventReceiver *event, core::System *system) : AController(manager, ressources, event, system),
_view(manager, ressources)
{
	this->_vitesseMove = 40;
	this->_view.stop();
}

controller::SelectCircuitMenu::~SelectCircuitMenu() {
}

controller::state controller::SelectCircuitMenu::run()
{
	int circuit = 0;
	bool isChangeQuit = false;
	bool isChangeCome = false;
	int direction = 0;
	irr::core::vector3df nodePosition;
	engine::MRessource *sound_change = this->_ressources->getRessource<engine::MRessource>("ressources/Sound/change_menu.wav", engine::RessourceManager::RType::SOUND);
	engine::MRessource *sound_valide = this->_ressources->getRessource<engine::MRessource>("ressources/Sound/valide.wav", engine::RessourceManager::RType::SOUND);

	this->_view.begin();

	this->_circuitList.push_back(std::make_pair(this->_manager->getModel<model::Basic>("CircuitMenu1"), BASIC));
	this->_circuitList.push_back(std::make_pair(this->_manager->getModel<model::Height>("CircuitMenu2"), HEIGHT));
	
	this->_view.removeCamera();
	this->_view.moveCameraStatic(irr::core::vector3df(0, 300, 500), irr::core::vector3df(0,0,0));
	this->_view.addLight(irr::core::vector3df(0,50,300), irr::video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 100000.0f);

	this->_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
	irr::scene::ISceneNode* skydome = this->_smgr->addSkyDomeSceneNode(this->_driver->getTexture("ressources/skydome.jpg"),16,8,0.95f,2.0f);
	this->_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

	this->initCircuit();

	const double timeStep = 17; // 17 milliseconds == 58.8 FPS
	while (this->_device->run())
	{
		auto startTime = std::chrono::system_clock::now();

		nodePosition = this->_circuitList[circuit].first->getPosition();
		if (isChangeQuit == true)
		{
			if (nodePosition.X < 300 && direction == 0)
				goLeft(circuit);
			else if (nodePosition.X > -300 && direction == 1)
				goRight(circuit);
			else
			{
				isChangeQuit = false;
				isChangeCome = true;
				changeCircuit(circuit, direction);
			}
		}
		else if (isChangeCome == true)
		{
			if (nodePosition.X < 0 && direction == 0)
				goLeft(circuit);
			else if (nodePosition.X > 0 && direction == 1)
				goRight(circuit);
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
				skydome->setVisible(false);
				sound_valide->play(_system->getVolume());
				this->createNewCircuit(this->_circuitList[circuit].second);
				this->quit();
				this->_next = "Game";
				return (NEXT);
			}
		}
		this->_ressources->getDevice()->getVideoDriver()->beginScene(true, true, irr::video::SColor(0,255,255,255));
		this->rotateCircuit(circuit);
		this->_view.drawScene();
		this->_event->startEventProcess();

		// Framerate
		auto endTime = std::chrono::system_clock::now();

		if (std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() < timeStep) {
			this->_device->sleep(static_cast<irr::u32>(timeStep - std::chrono::duration_cast<std::chrono::milliseconds>(
					endTime - startTime).count()));
		}
	}
	return (STOP);
}

void controller::SelectCircuitMenu::quit()
{
	this->_view.stop();
	this->_event->startEventProcess();
}

void controller::SelectCircuitMenu::createNewCircuit(SelectCircuitMenu::type_circuit type_circuit)
{
	switch (type_circuit) {
		case BASIC:
		this->_manager->getModel<model::Basic>("Circuit", model::Basic(*this->_ressources))->drop();
		break;
		case HEIGHT: 
		this->_manager->getModel<model::Height>("Circuit", model::Height(*this->_ressources))->drop();
		break;
	}
}

void controller::SelectCircuitMenu::rotateCircuit(int index)
{
	//Rotate of car
	irr::core::vector3df nodeRotation = this->_circuitList[index].first->getCircuit()->getRotation();
	nodeRotation.Y += 0.2;
	this->_circuitList[index].first->getCircuit()->setRotation(nodeRotation);
}

void controller::SelectCircuitMenu::initCircuit()
{
	for (std::vector<std::pair<model::ACircuit *, type_circuit>>::iterator it = this->_circuitList.begin() + 1; it != this->_circuitList.end(); it++)
	{
		(*it).first->getCircuit()->setVisible(false);
	}
	this->_circuitList[0].first->getCircuit()->setVisible(true);
}

void controller::SelectCircuitMenu::changeCircuit(int &index, int direction)
{
	this->_circuitList[index].first->getCircuit()->setVisible(false);
	if (direction == 0)
	{
		if (index < int(this->_circuitList.size() - 1))
			index += 1;
		else
			index = 0;
		this->_circuitList[index].first->setPosition(irr::core::vector3df(-300, 
			this->_circuitList[index].first->getPosition().Y,
			this->_circuitList[index].first->getPosition().Z));
	}
	else
	{
		if (index > 0)
			index -= 1;
		else
			index = this->_circuitList.size() - 1;
		this->_circuitList[index].first->setPosition(irr::core::vector3df(300, 
			this->_circuitList[index].first->getPosition().Y,
			this->_circuitList[index].first->getPosition().Z));
	}
	this->_circuitList[index].first->getCircuit()->setVisible(true);
}

void controller::SelectCircuitMenu::goRight(int index)
{
	this->_circuitList[index].first->setPosition(
		irr::core::vector3df(this->_circuitList[index].first->getPosition().X - this->_vitesseMove,
			this->_circuitList[index].first->getPosition().Y,
			this->_circuitList[index].first->getPosition().Z));
}

void controller::SelectCircuitMenu::goLeft(int index)
{
	this->_circuitList[index].first->setPosition(
		irr::core::vector3df(this->_circuitList[index].first->getPosition().X + this->_vitesseMove,
			this->_circuitList[index].first->getPosition().Y,
			this->_circuitList[index].first->getPosition().Z));
}