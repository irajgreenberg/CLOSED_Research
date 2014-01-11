#ifdef _WIN32
#include <GL/glew.h>
#endif

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>


#ifndef __Protobyte_dev_v02__ProtoHome__
#define __Protobyte_dev_v02__ProtoHome__

#include <iostream>

class Proto {

public:
    virtual void init(){}
    virtual void run(){}
    
    private :
    sf::Window window;
    void initSFMLInit();
    void initSFMLRun();
};

#endif /* defined(__Protobyte_dev_v02__ProtoHome__) */
