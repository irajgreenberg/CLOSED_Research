
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>
#include "../../Protobyte_v02/ProtoMath.h"
#include "../../Protobyte_v02/ProtoWorld.h"
#include "../../Protobyte_v02/ProtoVector2.h"
#include "../../Protobyte_v02/ProtoVector3.h"
#include "../../Protobyte_v02/ProtoToroid.h"
#include "../../Protobyte_v02/ProtoSpline3.h"
#include "../../Protobyte_v02/ProtoTube.h"
#include "../../Protobyte_v02/ProtoLight.h"


#include <memory>

using namespace ijg;

int main(int argc, char const** argv)
{
    sf::ContextSettings settings;
    settings.depthBits = 32;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;

    // create the window
    sf::Window window(sf::VideoMode(1400, 700), "Protobyte World Development", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);

    
    // release resources...
    return EXIT_SUCCESS;
}
