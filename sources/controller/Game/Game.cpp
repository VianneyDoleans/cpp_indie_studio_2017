//
// Created by vianney on 14/06/17.
//

#include "Game.hpp"

void			controller::Game::downKey(int nb)
{
	std::string name = "Player" + std::to_string(nb);

  _player[nb - 1]->getCar().speedVelocity(15);
  _manager->getModel<model::Player>(name)->getCar().decelerate(2);
  if (_player[nb - 1]->getTimeBoost().run() == true) {
    _manager->getModel<model::Player>(name)->getCar().decelerate(10);
    _player[nb - 1]->getCar().speedVelocity(_player[nb - 1]->getCar().speedVelocity() + 10);
  }
}

void			controller::Game::upKey(int nb)
{
  std::string name = "Player" + std::to_string(nb);

  if (this->_sound_engine->get().getStatus() != sf::Music::Playing)
    this->_sound_engine->play(_system->getVolume());
  _manager->getModel<model::Player>(name)->getCar().speedVelocity(15);
    _manager->getModel<model::Player>(name)->getCar().accelerate(2);
  if (_manager->getModel<model::Player>(name)->getTimeBoost().run() == true) {
    _manager->getModel<model::Player>(name)->getCar().speedVelocity(_manager->getModel<model::Player>(name)->getCar().speedVelocity() + 10);
    _manager->getModel<model::Player>(name)->getCar().accelerate(10);
  }
}

void			controller::Game::leftKey(int nb)
{
	std::string name = "Player" + std::to_string(nb);
	model::Car	&car = _manager->getModel<model::Player>(name)->getCar();
	float		angle;

	angle = car.getRotation();
	angle -= 5 * (car.speed() / car.speedVelocity());
	car.setRotation(angle);
}

void			controller::Game::rightKey(int nb)
{
	std::string name = "Player" + std::to_string(nb);
	model::Car	&car = _manager->getModel<model::Player>(name)->getCar();
	float		angle;

	angle = car.getRotation();
	angle += 5 * (car.speed() / car.speedVelocity());
	car.setRotation(angle);
}

void controller::Game::breakKey(int nb) {
	std::string name = "Player" + std::to_string(nb);
	model::Car	&car = this->_manager->getModel<model::Player>(name)->getCar();

	car.breakSpeed();
}

void controller::Game::pause() {
	if (_system->getTimer()->run() == true) {
		_system->getTimer()->pause();
		_view.drawText("PAUSE", irr::core::rect<irr::s32>(400, 200, 300, 300), irr::video::SColor(255, 100, 100, 100));
		_view.drawScene();
	}
	else
		_system->getTimer()->start();
}

void			controller::Game::findKey(irr::EKEY_CODE key) const
{
	std::function<void()> funct;
	int			i;

	i = 0;
	for (auto it = _keyboard.begin(); it != _keyboard.end(); ++it)
	{
		if (it->first == key)
		{
			funct = it->second;
			funct();
		}
		++i;
	}
}

void			controller::Game::findKeyPressed(irr::EKEY_CODE key) const
{
	std::function<void()> funct;
	int			i;

	i = 0;
	for (auto it = _keyboardPressed.begin(); it != _keyboardPressed.end(); ++it)
	{
		if (it->first == key)
		{
			funct = it->second;
			funct();
		}
		++i;
	}
}

void			controller::Game::createKey(irr::EKEY_CODE left, irr::EKEY_CODE right, irr::EKEY_CODE down, irr::EKEY_CODE up, irr::EKEY_CODE break_code, irr::EKEY_CODE boost_code, int nb)
{
  std::function<void()> right_Key = [this, nb]() { rightKey(nb); };
  std::function<void()> left_Key = [this, nb]() { leftKey(nb); };
  std::function<void()> up_Key = [this, nb]() { upKey(nb); };
  std::function<void()> down_Key = [this, nb]() { downKey(nb); };
  std::function<void()> break_key = [this, nb]() { breakKey(nb); };
  std::function<void()> boost_Key = [this, nb]() { boostKey(nb - 1); };

  _keyboard.push_back(KeyHandler(down, down_Key));
  _keyboard.push_back(KeyHandler(up, up_Key));
  _keyboard.push_back(KeyHandler(right, right_Key));
  _keyboard.push_back(KeyHandler(left, left_Key));
  _keyboard.push_back(KeyHandler(break_code, break_key));
  _keyboard.push_back(KeyHandler(boost_code, boost_Key));
}

void			controller::Game::createKeyPressed()
{
	std::function<void()> Pause = [this]() { pause();};
	std::function<void()> Quit = [this]() { quit();};

	_keyboardPressed.push_back(KeyHandler(PAUSE, Pause));
	_keyboardPressed.push_back(KeyHandler(QUIT_GAME, Quit));
}

controller::Game::Game(core::ModelManager *manager, engine::RessourceManager *ressources,
	core::MyEventReceiver *event, core::System *system) : AController(manager, ressources, event, system), _view(manager, ressources)
{
	this->_sound_engine = this->_ressources->getRessource<engine::MRessource>("ressources/Sound/engine.wav", engine::RessourceManager::RType::SOUND);
	this->_sound_die = this->_ressources->getRessource<engine::MRessource>("ressources/Sound/explosion.wav", engine::RessourceManager::RType::SOUND);
	this->_sound_bell = this->_ressources->getRessource<engine::MRessource>("ressources/Sound/bell.wav", engine::RessourceManager::RType::SOUND);
}

void		controller::Game::init()
{
	std::string		name;

	_player.clear();
	_eff.clear();
	for (unsigned int i = 0; i < _system->getNbrPlayer(); i++)
	{
		name = "Player" + std::to_string(i + 1);
		_player.push_back(_manager->getModel<model::Player>(name));
	}
	for (unsigned int i = 0; i < _system->getNbrPlayer(); i++)
	{
		_eff.push_back({*_ressources->getDevice(), _player[i]->getCar()});
	}
	_system->setTimer(_manager->getModel<model::Timer>("Timer", model::Timer()));
	_system->getTimer()->start();
}

void controller::Game::grabPlayers(void) {
	for (auto &p : _player)
		p->grab();
}

void controller::Game::movePlayers(void) {
	for (auto &p : _player)
		p->getCar().move();
}

void controller::Game::checkEvents(void) {
	for (auto it = _keyboard.begin(); it != _keyboard.end(); ++it)
	{
		if (this->_event->IsKeyDown(it->first)) {
			findKey(it->first);
		}
	}
}

void controller::Game::checkEventsPressed()
{
	int		i;

	i = 0;
	for (auto it = _keyboardPressed.begin(); it != _keyboardPressed.end(); ++it)
	{
		if (this->_event->IsKeyPressed(it->first))
		{
			findKeyPressed(it->first);
			++i;
		}

	}
}

void controller::Game::updateEffects(void) {
	for (auto &e : _eff)
		e.update();
}

controller::state controller::Game::run()
{
	this->_keyboard.clear();
	this->_keyboardPressed.clear();
	createKeyPressed();
	createKey(PLAYER1LEFT, PLAYER1RIGHT, PLAYER1DOWN, PLAYER1UP, PLAYER1BREAK, PLAYER1TURBO, 1);
	if (_system->getNbrPlayer() > 1)
		createKey(PLAYER2LEFT, PLAYER2RIGHT, PLAYER2DOWN, PLAYER2UP, PLAYER2BREAK, PLAYER2TURBO, 2);

	_run = true;
	_circuit = _manager->getModel<model::ACircuit>("Circuit");
	_circuit->grab();
	init();
	grabPlayers();
	_view.begin();
	for (unsigned int i = 0; i < _system->getNbrPlayer(); i++)
	{
		_circuit->addPlayer(*_player[i]);
		_circuit->link(_player[i]->getCar().getCar());
		_circuit->toStart(_player[i]->getName());
	}
	_circuit->getColManager().initCollision(_circuit->getPlayers());
	if (_system->getModeCamera() == 1)
		_view.initSplittingCamera();
	else {
		_view.moveCameraStatic(_circuit->getCameraPosition(),
			irr::core::vector3df(0.0f, 0.0f, 0.0f));
	}

    const double timeStep = 6; // 6 milliseconds == 166.6 FPS
	while (_ressources->getDevice()->run())
	{
        auto startTime = std::chrono::system_clock::now();

		if (checkEndGame() == true || _run == false)
		{
			_next = "Result";
			_view.stop();
			_player.clear();
			removeCarEffects();
			_system->getTimer()->pause();
			return (NEXT);
		}
		// EVENT
		checkEventsPressed();
		// UPDATE
		if (_system->getTimer()->run() == true)
		{
			checkEvents();
			movePlayers();
			checkCheckpointPlayers();
			updateTimePLayer();
			checkDie();
			updateBoost();
			_circuit->getColManager().update(_circuit->getPlayers());
			// DISPLAY
			_ressources->getDevice()->getVideoDriver()->beginScene(true, true,
				irr::video::SColor(
					0, 255, 255,
					255));
			if (_system->getModeCamera() == 1)
				_view.SplittingCamera();
			_view.drawTime(_system->getTimer());
			_ressources->getDevice()->getVideoDriver()->beginScene(true, true,
				irr::video::SColor(
					0, 255, 255,
					255));
			updateEffects();
			if (_system->getModeCamera() == 1)
				_view.SplittingCamera();
			this->_ressources->getDevice()->getSceneManager()->drawAll();
			this->_ressources->getDevice()->getGUIEnvironment()->drawAll();
			_view.drawTime(_system->getTimer());
			this->_view.displayLap(_player);
			this->_ressources->getDevice()->getVideoDriver()->endScene();
			this->_event->startEventProcess();
		}
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

controller::Game::~Game()
{}

void controller::Game::checkCheckpointPlayers()
{
	for (unsigned int i = 0; i < _system->getNbrPlayer(); i++)
	{
		if (_player[i]->getLap() < _system->getNbrLap()) {
			if (_circuit->onCheckPoint(_player[i]->getCurrentCheckPointID(),
				*_player[i])) {
				_player[i]->setCurrentCheckPointID(
					_player[i]->getCurrentCheckPointID() + 1);
		}
		if (_player[i]->getCurrentCheckPointID() >
			_circuit->getCheckpointsCount())
		{
			if (_player[i]->getBestLap() > (_system->getTimer()->getElapsedTime() - _player[i]->getlastLap()) || _player[i]->getLap() == 0)
				_player[i]->setBestLap(_system->getTimer()->getElapsedTime() - _player[i]->getlastLap());
			_player[i]->setlastLap(_system->getTimer()->getElapsedTime());
			_player[i]->setCurrentCheckPointID(0);
			_player[i]->setLap(_player[i]->getLap() + 1);
			this->_sound_bell->play(_system->getVolume());
		}
	}


}
}

void controller::Game::updateTimePLayer(void)
{
	for (unsigned int i = 0; i < _system->getNbrPlayer(); i++)
	{
		if (_player[i]->getLap() < _system->getNbrLap())
			_player[i]->setTime(_system->getTimer()->getElapsedTime());
	}
}

bool controller::Game::checkEndGame()
{
	for (unsigned int i = 0; i < _system->getNbrPlayer(); i++)
	{
		if (_player[i]->getLap() < _system->getNbrLap())
			return (false);
	}
	return (true);
}

void controller::Game::removeCarEffects()
{
	for (auto &it : _eff)
		it.stop();
	_eff.clear();
}

void controller::Game::checkDie() {
	for (unsigned int i = 0; i < _system->getNbrPlayer(); i++) {
		if (_player[i]->die() == true || (_player[i]->getPosition().Y < 0))
		{
			if (this->_sound_die->get().getStatus() != sf::Music::Playing)
				this->_sound_die->play(_system->getVolume());
			_player[i]->respawn();
			_circuit->toStart(_player[i]->getName());
		}
	}
}

void controller::Game::quit() {
	_run = false;
}

void controller::Game::boostKey(int nb) {
  if (_player[nb]->getTimeBoost().run() == false) {
    if (_player[nb]->getCar().getTurbo() >= 30) {
      _player[nb]->getTimeBoost().start();
      _player[nb]->getCar().setTurbo(_player[nb]->getCar().getTurbo() - 30);
    }
  }
}

void controller::Game::updateBoost() {
  for (unsigned int i = 0; i < _system->getNbrPlayer(); i++)
  {
    if (_player[i]->getTimeBoost().run() == true && _player[i]->getTimeBoost().getElapsedTime() > 5) {
      _player[i]->getTimeBoost().stop();
    }
  }
}
