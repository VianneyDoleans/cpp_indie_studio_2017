cmake_minimum_required(VERSION 3.6)
project(cpp_indie_studio)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        install/irrlicht-1.8.4/include
        sources/controller
        sources/controller/Game
        sources/controller/SelectCarMenu
        sources/controller/UIMenu
        sources/controller/UIOptions
        sources/controller/Result
        sources/controller/SelectCircuitMenu
        soures/controller/SplashScreen
        sources/core
        sources/core/ModelManager
        sources/core/System
        sources/engine
        sources/engine/Ressource
        sources/engine/RessourceManager
        sources/engine/SceneManager
        sources/engine/Physics/Acceleration
        sources/model/AModel
        sources/model/Car
        sources/model/Car/Mitraille
        sources/model/Car/BlueBird
        sources/model/Car/Bruno
        sources/model/Car/Sinder
        sources/model/Car/SunnyGo
        sources/model/Circuit
        sources/model/Circuit/Basic
        sources/model/Circuit/Height
        sources/model/UIButton
        sources/model/Player
        sources/model/Collision
        sources/model/Timer
        sources/model/APowerUp
        sources/model/PowerUp
        sources/model/PowerUpManager
        sources/view
        sources/view/Game
        sources/view/Result
        sources/view/SelectCarMenu
        sources/view/SelectCircuitMenu
        sources/view/UIOptions
        sources/view/UIMenu
        sources/view/SplashScreen)
find_library(IRRLICHT NAMES Irrlicht PATH install/irrlicht-1.8.4/lib/Linux)

link_libraries(${IRRLICHT} GL sfml-audio sfml-system)

set(SOURCE_FILES
        sources/main.cpp
        sources/controller/Game/Game.cpp
        sources/controller/Result/Result.cpp
        sources/controller/SelectCarMenu/SelectCarMenu.cpp
        sources/controller/UIMenu/UIMenu.cpp
        sources/controller/AController.cpp
        sources/controller/SplashScreen/SplashScreen.cpp
        sources/controller/UIOptions/UIOptions.cpp
        sources/controller/SelectCircuitMenu/SelectCircuitMenu.cpp
        sources/core/ModelManager/ModelManager.cpp
        sources/core/System/System.cpp
        sources/engine/RessourceManager/RessourceManager.cpp
        sources/engine/SceneManager/SceneManager.cpp
        sources/engine/Physics/Acceleration/AAccelerable.cpp
        sources/engine/Ressource/MRessource.cpp
        sources/model/AModel/AModel.cpp
        sources/model/Car/BlueBird/BlueBird.cpp
        sources/model/Car/Bruno/Bruno.cpp
        sources/model/Car/Mitraille/Mitraille.cpp
        sources/model/Car/Car.cpp
        sources/model/Car/CarEffects.cpp
        sources/model/Circuit/Basic/Basic.cpp
        sources/model/Circuit/ACircuit.cpp
        sources/model/Player/Player.cpp
        sources/model/UIButton/UIButton.cpp
        sources/model/PowerUpManager/PowerUpManager.cpp
        sources/model/Car/Sinder/Sinder.cpp
        sources/model/Car/SunnyGo/SunnyGo.cpp
        sources/model/Collision/CollisionHandler.cpp
        sources/model/Timer/Timer.cpp
        sources/model/Circuit/Height/Height.cpp
        sources/model/AI/AI.cpp
        sources/model/APowerUp/APowerUp.cpp
        sources/model/PowerUp/Boost.cpp
        sources/model/PowerUp/Bomb.cpp
        sources/model/PowerUp/Reparation.cpp
        sources/view/Game/GameView.cpp
        sources/view/SplashScreen/SplashScreenView.cpp
        sources/view/Result/ResultView.cpp
        sources/view/SelectCarMenu/SelectCarMenuView.cpp
        sources/view/AView.cpp
        sources/view/UIMenu/UIMenuView.cpp
        sources/view/UIOptions/UIOptionsView.cpp
        sources/view/SelectCircuitMenu/SelectCircuitMenuView.cpp)


add_executable(cpp_indie_studio ${SOURCE_FILES})