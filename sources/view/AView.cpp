//
// Created by vianney on 14/06/17.
//


#include "AView.hpp"

core::ModelManager *view::AView::getModelManager() const
{
  return (this->_mm);
}

view::AView::~AView()
{
}

view::AView::AView(core::ModelManager *mm, engine::RessourceManager *rm)
: _mm(mm), _rm(rm), _type(NONE), _camera(nullptr)
{

}

void view::AView::moveCameraStatic(irr::core::vector3df position, irr::core::vector3df rotation)
{
    if (_type == STATIC || _type == NONE)
    {
        if (_camera == nullptr)
        {
            _camera = _rm->getDevice()->getSceneManager()->addCameraSceneNode(0, position, rotation);
        }
        else
        {
            _camera->setPosition(position);
            _camera->setRotation(rotation);
        }
        _rm->getDevice()->getVideoDriver()->setViewPort(irr::core::rect<irr::s32>(0, 0, _rm->getDevice()->getVideoDriver()->getScreenSize().Width,
          _rm->getDevice()->getVideoDriver()->getScreenSize().Height));
        _camera->setFarValue(20000);
        _type = STATIC;
    }
}

void view::AView::removeCamera()
{
    if (_camera != nullptr)
    {
        _camera->remove();
        _camera = nullptr;
        _type = NONE;
    }
    _type = NONE;
}

void view::AView::moveCameraFps(float speed, float speedJump, irr::core::vector3df position, irr::core::vector3df rotation)
{
    irr::SKeyMap keyMap[5];

    keyMap[0].Action = irr::EKA_MOVE_FORWARD;
    keyMap[0].KeyCode = irr::KEY_KEY_Z;
    keyMap[1].Action = irr::EKA_MOVE_BACKWARD;
    keyMap[1].KeyCode = irr::KEY_KEY_S;
    keyMap[2].Action = irr::EKA_STRAFE_LEFT;
    keyMap[2].KeyCode = irr::KEY_KEY_Q;
    keyMap[3].Action = irr::EKA_STRAFE_RIGHT;
    keyMap[3].KeyCode = irr::KEY_KEY_D;
    keyMap[4].Action = irr::EKA_JUMP_UP;
    keyMap[4].KeyCode = irr::KEY_SPACE;
    if (_type == MOVE || _type == NONE)
    {
        if (_camera == nullptr)
        {
            _camera = _rm->getDevice()->getSceneManager()->addCameraSceneNodeFPS(0,100.0f, speed, -1, keyMap, 5, false, speedJump);
        }
        _camera->setPosition(position);
        _camera->setRotation(rotation);
        _type = MOVE;
        _rm->getDevice()->getVideoDriver()->setViewPort(irr::core::rect<irr::s32>(0, 0, _rm->getDevice()->getVideoDriver()->getScreenSize().Width,
          _rm->getDevice()->getVideoDriver()->getScreenSize().Height));
        _camera->setFarValue(20000);
    }
}


void                        view::AView::addLight(irr::core::vector3df position, irr::video::SColorf color, float radius)
{
    _light.push_back(_rm->getDevice()->getSceneManager()->
        addLightSceneNode(0, position, color, radius));
}

irr::scene::ILightSceneNode *view::AView::getLight(int nb)
{
    int     i;

    i = 0;
    for (auto it : _light)
    {
        if (i == nb)
            return (_light[i]);
        ++i;
        ++it;
    }
    return (nullptr);
}

void view::AView::removeLight(int nb)
{
    int     i;

    i  = 0;
    for (auto it : _light)
    {
        if (i == nb)
        {
            _light[i]->remove();
            _light.erase(_light.begin() + i);
        }
        ++it;
        ++i;
    }
}

void view::AView::drawScene()
{
    this->_rm->getDevice()->getSceneManager()->drawAll();
    this->_rm->getDevice()->getGUIEnvironment()->drawAll();
    this->_rm->getDevice()->getVideoDriver()->endScene();
}

void view::AView::drawText(const std::string &text, const irr::core::rect<irr::s32> &rectangle, irr::video::SColor color, bool alignCenter, bool bigSize)
{
  irr::gui::IGUIFont	*font;

  if (bigSize)
    font = _rm->getDevice()->getGUIEnvironment()->getFont("./ressources/Fonts/big.xml");
else
    font = _rm->getDevice()->getGUIEnvironment()->getFont("./ressources/Fonts/little.xml");
if (font)
    font->draw(text.c_str(), rectangle, color, alignCenter);
}

