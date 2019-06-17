/*
** AView.hpp for cpp_indie_studio in /home/vianney/cpp_indie_studio/sources/engine/View/AView.hpp
**
** Made by Vianney Doleans
** Login   <vianney.doleans@epitech.eu>
**
** Started on  Wed Jun 14 13:42:45 2017 Vianney Doleans
** Last update Wed Jun 14 13:42:45 2017 Vianney Doleans
*/

#ifndef CPP_INDIE_STUDIO_AVIEW_HPP
#define CPP_INDIE_STUDIO_AVIEW_HPP

#include	"RessourceManager.hpp"
#include	"ModelManager.hpp"
#include    <irrlicht.h>

namespace view
{
  class AView
  {
  public:
    enum typeCamera
    {
      STATIC,
      MOVE,
      NONE
    };
  protected:
    core::ModelManager              *_mm;
    engine::RessourceManager      *_rm;
    typeCamera                    _type;
    irr::scene::ICameraSceneNode *_camera;
    std::vector<irr::scene::ILightSceneNode*> _light;
    irr::gui::IGUIFont*	_myText;

  public:
    AView(core::ModelManager *mm, engine::RessourceManager *rm);
    virtual ~AView() = 0;

  public:
    virtual void		begin() = 0;
    virtual void                 stop() = 0;
    void                        moveCameraStatic(irr::core::vector3df position, irr::core::vector3df rotation);
    void                        moveCameraFps(float speed, float speedJump, irr::core::vector3df position, irr::core::vector3df rotation);
    void                        removeCamera();

    void                        addLight(irr::core::vector3df position, irr::video::SColorf color, float radius);
    irr::scene::ILightSceneNode *getLight(int nb);
    void                          removeLight(int nb);
    void			                 drawScene();
    void			                 drawText(const std::string &text, const irr::core::rect<irr::s32> &rectangle, irr::video::SColor color, bool alignCenter = false, bool bigSize = true);

    core::ModelManager	*getModelManager() const;
  };
}

#endif //CPP_INDIE_STUDIO_AVIEW_HPP
