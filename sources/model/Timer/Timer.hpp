/*
** Timer.hpp for cpp_indie_studio in /home/montag-v/rendu/Game/cpp_indie_studio/sources/model/Timer/Timer.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 16 09:41:22 2017 Montagne Valentin
** Last update Fri Jun 16 09:41:22 2017 Montagne Valentin
*/

#ifndef CPP_INDIE_STUDIO_TIMER_HPP
#define CPP_INDIE_STUDIO_TIMER_HPP

#include 						<chrono>
#include 						"AModel.hpp"

namespace 						model {

  class 						Timer : public AModel {

    std::chrono::high_resolution_clock::time_point	_start;
    double						_elapsdedTime;
    bool						_isRunning;

  public:

    Timer();
    ~Timer();

    void						start(void);
    void						pause(void);
    void            stop(void);
    double					getElapsedTime(void) const;
    bool					run();
    void 						resetTimer();

    virtual void					grab(void) override;
    virtual void					drop(void) override;

  };

}

#endif //CPP_INDIE_STUDIO_TIMER_HPP
