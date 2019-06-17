//
// EventReceiver.hpp for indie_studio in /home/guillaume/Documents/rendu/cpp_indie_studio
// 
// Made by Guillaume Bouxin
// Login	 <guillaume@epitech.net>
// 
// Started on	Sat May	20 09:49:25 2017 Guillaume Bouxin
// Last update	Sat May	20 09:49:25 2017 Guillaume Bouxin
//

#ifndef EVENTRECEIVER_HPP
# define EVENTRECEIVER_HPP

namespace                           core {

    class MyEventReceiver : public irr::IEventReceiver
    {
        enum keyStatesENUM {UP, DOWN, PRESSED, RELEASED};
    private:
        keyStatesENUM Key[irr::KEY_KEY_CODES_COUNT];
    public:
        virtual bool OnEvent(const irr::SEvent& event)
        {
            if (event.EventType == irr::EET_KEY_INPUT_EVENT)
            {
                if (event.KeyInput.PressedDown == true)
                {
                    if (Key[event.KeyInput.Key] != DOWN)
                    {
                        Key[event.KeyInput.Key] = PRESSED;
                    }
                    else
                    {
                        Key[event.KeyInput.Key] = DOWN;
                    }
                }
                else
                {
                    if (Key[event.KeyInput.Key] != UP)
                    {
                        Key[event.KeyInput.Key] = RELEASED;
                    }
                }
            }

            return false;
        }

        virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const
        {
            if (Key[keyCode] == DOWN || Key[keyCode] == PRESSED)
                return (true);
            return (false);
        }

        virtual bool IsKeyPressed(irr::EKEY_CODE keyCode) const
        {
            if (Key[keyCode] == PRESSED)
            {
                return (true);
            }
            return (false);
        }

        void startEventProcess()
        {
            for (int i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
            {
                if (Key[i] == RELEASED)
                {
                    Key[i] = UP;
                }
                if (Key[i] == PRESSED)
                {
                    Key[i] = DOWN;
                }
            }
        }

        MyEventReceiver()
        {
            for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
                Key[i] = UP;
        }
    };
}

#endif