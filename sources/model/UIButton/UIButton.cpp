/*
** UIButton.cpp for cpp_indie_studio in /home/charles/Documents/C++/cpp_indie_studio/sources/model/UIButton/UIButton.cpp
**
** Made by Charles des Pommare
** Login   <charles.des-pommare@epitech.eu>
**
** Started on  Tue Jun 06 19:30:32 2017 Charles des Pommare
** Last update Tue Jun 06 19:30:32 2017 Charles des Pommare
*/

#include	<irrlicht.h>
#include	<utility>
#include	"UIButton.hpp"

model::UIButton::UIButton(const Position &pos, const Position &size,
			  const wchar_t *text, engine::RessourceManager *Manager)
  : AModel("UIButton"), _ressources(Manager)
{
  irr::gui::IGUIEnvironment	*env = this->_ressources->getDevice()->getGUIEnvironment();
  this->button = env->addButton(irr::core::rect<irr::s32>(pos.first, pos.second, size.first, size.second), 0, 0,
				text);
}

void		model::UIButton::setFont(const std::string &_font_xml) {
  irr::gui::IGUIFont	*font =	this->_ressources->getDevice()->getGUIEnvironment()->getFont(_font_xml.c_str());
  irr::gui::IGUISkin		*skin = this->_ressources->getDevice()->getGUIEnvironment()->getSkin();

  skin->setFont(font);
  skin->setColor(irr::gui::EGDC_BUTTON_TEXT, irr::video::SColor(220,255,255,255));
  this->button->setOverrideFont(font);
}

void		model::UIButton::setBackground(const std::string &_background) {
  irr::video::ITexture		*image = this->_ressources->getRessource<engine::Ressource<engine::TEX >>
    (_background, engine::RessourceManager::RType::TEXTURE)->get();

  this->button->setImage(image);
}

void		model::UIButton::setPressedBackground(const std::string &_background) {
  irr::video::ITexture		*image = this->_ressources->getRessource<engine::Ressource<engine::TEX>>
    (_background, engine::RessourceManager::RType::TEXTURE)->get();

  this->button->setPressedImage(image);
}

void		model::UIButton::grab(void) {
  this->button->setVisible(true);
}

void		model::UIButton::drop(void) {
  this->button->setVisible(false);
}

irr::gui::IGUIButton		*model::UIButton::getButton() const {
  return (this->button);
}

model::UIButton::~UIButton() {
}

model::UIButton&	model::UIButton::operator=(const UIButton &) {
  return (*this);
}