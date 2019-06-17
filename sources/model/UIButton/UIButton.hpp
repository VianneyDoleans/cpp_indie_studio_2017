/*
** UIButton.hpp for cpp_indie_studio in /home/charles/Documents/C++/cpp_indie_studio/sources/model/UIButton/UIButton.hpp
**
** Made by Charles des Pommare
** Login   <charles.des-pommare@epitech.eu>
**
** Started on  Tue Jun 06 19:30:38 2017 Charles des Pommare
** Last update Tue Jun 06 19:30:38 2017 Charles des Pommare
*/

#ifndef CPP_INDIE_STUDIO_UIBUTTON_HPP
#define CPP_INDIE_STUDIO_UIBUTTON_HPP

#include	<vector>
#include	"RessourceManager.hpp"
#include	"AModel.hpp"

namespace	model {

  using Position =  std::pair<unsigned int, unsigned int>;

  class		UIButton : public model::AModel
  {
    engine::RessourceManager		*_ressources;
    irr::gui::IGUIButton		*button;

  public:
    UIButton(const Position &pos,
	     const Position &size,
	     const wchar_t *text,
	     engine::RessourceManager *Manager);
    ~UIButton();
    UIButton	&operator=(const UIButton &);

    /**
     * @brief return the gui button type
     * @return IGUIButton
     */
    irr::gui::IGUIButton	*getButton() const;

    /**
     * @brief Set the font of the button with a .xml
     * @param _font_xml
     */

    void			setFont(const std::string &_font_xml);

    /**
     * @brief Set the background of the button
     * @param _background
     */

    void			setBackground(const std::string &_background);

    /**
     * @brief Set the background of the button when pressed
     * @param _background
     */

    void			setPressedBackground(const std::string &_background);

    /**
    * @brief Grab this model, now he appear on the screen !
    */

    virtual void		grab(void) override;

    /**
     * @brief Drop this model, he isn't on the screen !
     */

    virtual void		drop(void) override;

  };
}

#endif //CPP_INDIE_STUDIO_UIBUTTON_HPP
