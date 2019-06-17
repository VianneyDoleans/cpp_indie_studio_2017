//
// Created by vianney on 15/06/17.
//

#ifndef CPP_INDIE_STUDIO_SYSTEM_HPP
#define CPP_INDIE_STUDIO_SYSTEM_HPP

#include				<string>
#include				<exception>
#include 				"Timer.hpp"

namespace core
{

  class                                 LoadError : public std::exception
  {

  public:

    LoadError(std::string const &message);

    std::string const 			getMessage() const;
    virtual ~LoadError() 		throw() {};
    const char				*what() const throw() { return (_message.c_str()); };

  private:

    std::string   			_message;

  };

  class System
    {
    private:
        unsigned int		_nbrPlayer;
        unsigned int		_nbrLap;
      	unsigned int		_modeCamera;
        unsigned int		_volume;
        model::Timer		*_timer;

    public:
        System();
        ~System();

    public:
        unsigned int getNbrPlayer() const;
        unsigned int getNbrLap() const;
    	unsigned int getModeCamera() const;
        unsigned int getVolume() const;
    	model::Timer *getTimer() const;

    public:
        void setNbrPlayer(unsigned int nb);
        void setNbrLap(unsigned int nb);
    	void setModeCamera(unsigned int mode);
        void setVolume(unsigned int volume);
    	void setTimer(model::Timer *timer);
    };
}

#endif //CPP_INDIE_STUDIO_SYSTEM_HPP
