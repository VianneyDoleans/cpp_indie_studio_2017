/*
** main.cpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/main.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu May 18 16:46:39 2017 Montagne Valentin
// Last update Sat Jun 17 14:30:15 2017 montag-v
*/

#include	<irrlicht.h>
#include	"BlueBird.hpp"
#include	"Bruno.hpp"
#include	"MRessource.hpp"
#include	"RessourceManager.hpp"
#include	"ModelManager.hpp"
#include	"SceneManager.hpp"
#include	"EventReceiver.hpp"
#include	"System.hpp"

int             main()
{
  core::MyEventReceiver       receiver;
  try {
    engine::SceneManager      SceneManager(1920, 1080, &receiver);

    SceneManager.executionThread();
  }
  catch (core::LoadError &e)
  {
    std::cout << "Couldn't launch the game" << std::endl;
    return (1);
  }
  return (0);
}
