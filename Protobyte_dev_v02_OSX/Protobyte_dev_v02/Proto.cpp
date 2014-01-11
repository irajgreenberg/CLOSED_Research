//
//  ProtoHome.cpp
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/26/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "ProtoHome.h"


void Proto::initSFMLInit(){
    
    sf::ContextSettings settings;
    settings.depthBits = 32;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    
    // create the window
    window = sf::Window(sf::VideoMode(1400, 700), "Protobyte World Development", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    
    //    std::cout << window.getSize().x  << std::endl;
    //    std::cout << window.getSize().y  << std::endl;
    
    
    //window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width/2-window.getSize().x/2, sf::VideoMode::getDesktopMode().height/2+window.getSize().y/2));
    
    //window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width/2.0-window.getSize().x/2.0, -sf::VideoMode::getDesktopMode().height));
    window.setPosition(sf::Vector2i(0,0));
    
    // load resources, initialize the OpenGL states, ...
    
    settings = window.getSettings();
    
    //    std::cout << "depth bits:" << settings.depthBits << std::endl;
    //    std::cout << "stencil bits:" << settings.stencilBits << std::endl;
    //    std::cout << "antialiasing level:" << settings.antialiasingLevel << std::endl;
    //    std::cout << "version:" << settings.majorVersion << "." << settings.minorVersion << std::endl;
    
    // Implementation defined by derived implemention
    init();
    
}

void Proto::initSFMLRun(){
    // run the main loop
    bool running = true;
    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.mouseButton.button == sf::Mouse::Left) {
                //std::cout << "in mouse event" << std::endl;
                // toroid3->setColor(ProtoColor4f(.2, .9, .1, 1.0));
            }
            
            if (event.type == sf::Event::Closed)
            {
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                //glViewport(0, 0, event.size.width/4.0, event.size.height/4.0);
                world.updateCanvasSize(event.size.width, event.size.height);
                
                //                    std::cout << event.size.width  << std::endl;
                //                    std::cout << event.size.height  << std::endl;
            }else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Escape) {
                    running = false;
                    window.close();
                }
            }
        }
        
        
        // clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // draw...
        world.run();
        //glTranslatef(0,0,-.1);
        //spline.display();
        
        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }
    
    
}

void run(){
    
}