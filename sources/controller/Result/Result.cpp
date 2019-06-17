//
// Result.cpp for IndieStudio in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/controller/Result
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Sat Jun	17 14:42:53 2017 Guillaume Bouxin
// Last update	Sat Jun	17 14:42:53 2017 Guillaume Bouxin
//

#include 	"Result.hpp"

bool comparePtrToNode(model::Player* a, model::Player* b) { return (a->getTime() < b->getTime()); }

controller::Result::Result(core::ModelManager *manager, engine::RessourceManager *ressources, core::MyEventReceiver *event, core::System *system)
: AController(manager, ressources, event, system), _view(manager, ressources)
{

}

controller::Result::~Result()
{
}

controller::state controller::Result::run() 
{
	this->_view.moveCameraStatic(irr::core::vector3df(0, 300, 300), irr::core::vector3df(0,0,0));
	this->_view.addLight(irr::core::vector3df(0,50,300), irr::video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 100000.0f);

	this->getAllPlayer();
	std::sort(this->_players.begin(), this->_players.end(), comparePtrToNode);
	engine::MRessource *sound_result = this->_ressources->getRessource<engine::MRessource>("ressources/Sound/result.wav", engine::RessourceManager::RType::SOUND);
	while (this->_device->run())
	{
		if (this->_event->IsKeyPressed(irr::KEY_RETURN))
		{
			sound_result->stop();
			this->_view.stop();
			this->deletePlayer();
			this->_manager->removeModel("Circuit");
			this->_system->getTimer()->stop();
			this->_next = "UIMenu";
			this->_event->startEventProcess();
			return (NEXT);
		}
		if (sound_result->get().getStatus() != sf::Music::Playing)
			sound_result->play(_system->getVolume());
		this->_ressources->getDevice()->getVideoDriver()->beginScene(true, true, irr::video::SColor(0,255,255,255));
		this->_view.drawDamier();
		this->_view.writeTitle();
		this->_view.drawText("Press enter to return in menu", irr::core::rect<irr::s32>(0, 800, 1920, 60), irr::video::SColor(255, 0, 10, 10), true, true);
		this->writeResult();
		this->_view.drawScene();
		this->_event->startEventProcess();
	}
	return (STOP);
}

void controller::Result::deletePlayer()
{
	int i = 1;
	for (std::vector<model::Player *>::iterator it = this->_players.begin(); it != this->_players.end(); ++it)
	{
		this->_manager->removeModel((*it)->getName());
		this->_manager->removeModel("Car" + std::to_string(i));
		i++;
	}
}

void controller::Result::writeResult()
{
	int y = 400;
	int place = 1;

	for (std::vector<model::Player *>::iterator it = this->_players.begin(); it != this->_players.end(); ++it)
	{
		this->_view.writePlayer(*it, place, y);
		y += 50;
		place++;
	}
}

void controller::Result::getAllPlayer()
{
	std::string name;
	name = "Player1";
	this->_players.clear();
	for (unsigned int i = 1; (this->_manager->isHere(name) == true); i++)
	{
		this->_players.push_back(this->_manager->getModel<model::Player>(name));
		name = "Player" + std::to_string(i + 1);
	}
}