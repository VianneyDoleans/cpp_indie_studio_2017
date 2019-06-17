/*
** RessourceManager.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/engine/RessourceManager.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri May 19 17:15:37 2017 Montagne Valentin
** Last update Fri May 19 17:15:37 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_RESSOURCEMANAGER_HPP
#define CPP_INDIE_STUDIO_RESSOURCEMANAGER_HPP

#include 					<vector>
#include 					<irrlicht.h>
#include                    "Ressource.hpp"

namespace					engine {

  class 					RessourceManager {

  public:

    enum class					RType
    { TEXTURE, FONT, MESH, SOUND };

  private:

    irr::IrrlichtDevice				&_device;
    irr::scene::ISceneManager			*_smgr;
    irr::video::IVideoDriver			*_driver;
    irr::gui::IGUIEnvironment			*_env;
    std::vector<std::shared_ptr<IRessource>>	_ressources;

    std::shared_ptr<IRessource>			createRessource(const std::string &path, RType &type);

    MESH					loadMesh(const std::string &path);
    TEX						loadTex(const std::string &path);
    FONT					loadFont(const std::string &path);

  public:

    RessourceManager(irr::IrrlichtDevice &d);
    ~RessourceManager();

    /**
     * @brief Adding (load) a ressource (Or get it if it's already load)
     * @param path (real path to the ressource)
     * @param type (Texture, font mesh..)
     * @return a valid ressource
     */
    template <typename T>
    T						*getRessource(const std::string &path,
								   engine::RessourceManager::RType type) {
      for (auto &r : _ressources)
	if (r->getPath() == path)
	  return (static_cast<T *>(r.get()));
      return (static_cast<T *>(createRessource(path, type).get()));
    }

    /**
     * @brief Remove a ressource
     * @param res
     */

    void					removeRessource(const IRessource &res);

    /**
     * @brief Get Irrlicht Device
     * @return irr::IrrlichtDevice *
     */

    irr::IrrlichtDevice				*getDevice(void) const;

  };

}

#endif //CPP_INDIE_STUDIO_RESSOURCEMANAGER_HPP
