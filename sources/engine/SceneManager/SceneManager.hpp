//
// SceneManager.hpp for SceneManager in /home/guillaume/Documents/rendu/cpp_indie_studio/sources/SceneManager
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Sat May	20 12:01:21 2017 Guillaume Bouxin
// Last update	Sat May	20 12:01:21 2017 Guillaume Bouxin
//

#ifndef SCENEMANAGER_H_
# define SCENEMANAGER_H_

#include            <irrlicht.h>
#include			"ModelManager.hpp"
#include    		"RessourceManager.hpp"
#include 			"EventReceiver.hpp"
#include			"Game.hpp"
#include			"Result.hpp"
#include 			"SelectCarMenu.hpp"
#include 			"SelectCircuitMenu.hpp"
#include 			"UIMenu.hpp"
#include			"System.hpp"
#include 			<memory>

namespace 									engine
{
	class 									SceneManager
	{

	private:

	  irr::IrrlichtDevice							*_device;
	  irr::scene::ISceneManager						*_smgr;
	  irr::video::IVideoDriver						*_driver;
	  irr::gui::IGUIEnvironment						*_env;
	  core::ModelManager							_modelManager;
	  engine::RessourceManager						_rm;
	  core::MyEventReceiver							*_receiver;
	  core::System									_system;
	  std::map<std::string, std::shared_ptr<controller::AController>> 	_controllerList;

	public:

		/**
		* @brief      Renderer scene manager
		*/

		SceneManager(int, int, core::MyEventReceiver *);
	       ~SceneManager();

		/**
		 * @brief      Principal function witch make the exection of program
		 */
		void executionThread();

		/**
		 * @brief      Launch the controller
		 *
		 * @param[in]  index  The index
		 *
		 * @return     Return the name of next controller, empty = quit
		 */
		std::string launchController(const std::string &);

		/**
		 * @brief      Gets the scene manager.
		 *
		 * @return     The scene manager.
		 */
		irr::scene::ISceneManager *getSceneManager();

		/**
		 * @brief      Gets the driver.
		 *
		 * @return     The driver.
		 */
		irr::video::IVideoDriver *getDriver();

		/**
		 * @brief      Gets the device.
		 *
		 * @return     The device.
		 */
		irr::IrrlichtDevice *getDevice();

		/**
		 * @brief      Gets the model manager.
		 *
		 * @return     The model manager.
		 */
		core::ModelManager &getModelManager();

		/**
		 * @brief      Gets the ressource.
		 *
		 * @return     The ressource.
		 */
		engine::RessourceManager &getRessourceManager();


	};
}

#endif