//
// Created by vianney on 15/06/17.
//

#ifndef CPP_INDIE_STUDIO_GAMEVIEW_HPP
#define CPP_INDIE_STUDIO_GAMEVIEW_HPP

//#define resolutionX 1920
//#define resolutionY 1080

#include	"AView.hpp"
#include	"Player.hpp"
#include	"Timer.hpp"

namespace  view
{
    class GameView : public view::AView
    {
    public:
      std::vector<irr::scene::ICameraSceneNode*> _cameraView;
      irr::scene::ICameraSceneNode		*_score;
      size_t					resolutionX;
      size_t					resolutionY;

    public:
        GameView(core::ModelManager *mm, engine::RessourceManager *rm);
        virtual ~GameView();

      void		displayLap(std::vector<model::Player*> players);
      void		initSplittingCamera();
      void		SplittingOneCamera(model::Player *player, int nb);
      void		SplittingCamera();
      void		drawTime(model::Timer *time);
      virtual void	begin();
      virtual void    	stop();
    };
}

#endif //CPP_INDIE_STUDIO_GAMEVIEW_HPP
