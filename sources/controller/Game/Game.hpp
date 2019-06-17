/*
** Game.hpp for cpp_indie_studio in /home/vianney/cpp_indie_studio/sources/controller/Game/Game.hpp
**
** Made by Vianney Doleans
** Login   <vianney.doleans@epitech.eu>
**
** Started on  Wed Jun 14 15:22:23 2017 Vianney Doleans
** Last update Wed Jun 14 15:22:23 2017 Vianney Doleans
*/

#ifndef CPP_INDIE_STUDIO_GAME_HPP
#define CPP_INDIE_STUDIO_GAME_HPP

#include    <chrono>
#include    <functional>
#include	"GameView.hpp"
#include	"Player.hpp"
#include	"AController.hpp"
#include	"Basic.hpp"
#include	"BlueBird.hpp"
#include	"CarEffects.hpp"
#include	"Sinder.hpp"
#include    "MRessource.hpp"
#include    "RessourceManager.hpp"
//#include	"AI.hpp"

#define PLAYER2LEFT     irr::KEY_LEFT
#define PLAYER2UP       irr::KEY_UP
#define PLAYER2RIGHT	irr::KEY_RIGHT
#define PLAYER2DOWN     irr::KEY_DOWN
#define PLAYER2BREAK	irr::KEY_RSHIFT
#define PLAYER2TURBO	irr::KEY_KEY_M
#define PLAYER1LEFT     irr::KEY_KEY_Q
#define PLAYER1UP       irr::KEY_KEY_Z
#define PLAYER1RIGHT	irr::KEY_KEY_D
#define PLAYER1DOWN     irr::KEY_KEY_S
#define PLAYER1BREAK	irr::KEY_KEY_E
#define PLAYER1TURBO	irr::KEY_KEY_A
#define PAUSE           irr::KEY_RETURN
#define QUIT_GAME       irr::KEY_ESCAPE

namespace   controller
{
    class Game : public AController
    {
        using KeyHandler = std::pair<irr::EKEY_CODE, std::function<void()>>;

    protected:
        view::GameView			        _view;
        std::vector<model::Player*>	    _player;
        model::ACircuit			        *_circuit;
        std::vector<KeyHandler>		    _keyboard;
        std::vector<KeyHandler>		    _keyboardPressed;
        std::vector<model::CarEffects>	_eff;
        bool                            _run;
        engine::MRessource              *_sound_engine;
        engine::MRessource              *_sound_die;
        engine::MRessource              *_sound_bell;

  public:
    Game(core::ModelManager *manager, engine::RessourceManager *rcs, core::MyEventReceiver *event, core::System *system);
    virtual ~Game();

    void			createKey(irr::EKEY_CODE left, irr::EKEY_CODE right, irr::EKEY_CODE down, irr::EKEY_CODE up, irr::EKEY_CODE break_key, irr::EKEY_CODE boost_key, int nb);

    public:
    virtual state	run();
    void			init();
    void			findKey(irr::EKEY_CODE key) const;
    void			downKey(int nb);
    void			upKey(int nb);
    void			leftKey(int nb);
    void			rightKey(int nb);
    void			breakKey(int nb);
    void			grabPlayers(void);
    void			movePlayers(void);
    void			checkEvents(void);
    void			updateEffects(void);
    void			updateTimePLayer(void);
    void			checkCheckpointPlayers();
    bool			checkEndGame();
    void			removeCarEffects();
    void			checkDie();
    void			pause();
    void			quit();
    void			createKeyPressed();
    void			findKeyPressed(irr::EKEY_CODE key) const;
    void			checkEventsPressed();
    void			boostKey(int nb);
    void			updateBoost();
    };
}


#endif //CPP_INDIE_STUDIO_GAME_HPP

