//
//  ProtoPlasm.cpp
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "ProtoPlasm.h"

using namespace ijg;


ProtoPlasm::ProtoPlasm(ProtoBaseApp* baseApp):
baseApp(baseApp), appWidth(1024), appHeight(764), appTitle("Protobyte App")
{
    // instantiate world
    //world = std::unique_ptr<ProtoWorld>(new ProtoWorld(appWidth, appHeight));
    
    // init app and call init() and run() to activate functions in user derived class
    initSFMLInit();
    initSFMLRun();
}

ProtoPlasm:: ProtoPlasm(int appWidth, int appHeight, std::string appTitle, ProtoBaseApp* baseApp){
   // std::cout << " baseApp = " << baseApp << std::endl;
   // std::cout << " this->baseApp = " << this->baseApp << std::endl;
    this->baseApp = baseApp;
    this->appWidth = appWidth;
    this->appHeight = appHeight;
    this->appTitle = appTitle;
    
    
    
    // init app and call init() and run() to activate functions in user derived class
    initSFMLInit();
    initSFMLRun();
}


void ProtoPlasm::initSFMLInit(){
    sf::ContextSettings settings;
    settings.depthBits = 32;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    
    // create the window and GL context
    window = new sf::Window(sf::VideoMode(appWidth, appHeight), appTitle, sf::Style::Default, settings);
    window->setVerticalSyncEnabled(true);
    
    
    // World
    // instantiate world
    world = std::unique_ptr<ProtoWorld>(new ProtoWorld(appWidth, appHeight));
    world->setWorldView(ProtoWorld::SINGLE_VIEW);
    world->setWorldRotSpeed(Vec3f(1.3, 0, 0));
    
    std::unique_ptr<ijg::ProtoCamera> camera1(new ijg::ProtoCamera(Vec3f(0, 0, 4.9), Vec3f(0, 0, 0), ProtoBoundsf(0, 0,appWidth, appHeight)));
    std::unique_ptr<ijg::ProtoCamera> camera2(new ijg::ProtoCamera(Vec3f(0, 0, 4.9), Vec3f(0, 180, 0), ProtoBoundsf(0, 0,appWidth, appHeight)));
    std::unique_ptr<ijg::ProtoCamera> camera3(new ijg::ProtoCamera(Vec3f(0, 0, 4.9), Vec3f(-50, 30, 30), ProtoBoundsf(0, 0,appWidth, appHeight)));
    std::unique_ptr<ijg::ProtoCamera> camera4(new ijg::ProtoCamera(Vec3f(0, 0, 4.9), Vec3f(0, 124, 0), ProtoBoundsf(0, 0,appWidth, appHeight)));
    
    // Camera
    camera1->setProjection(75.0f, appWidth/appHeight, .1, 1000);
    camera2->setProjection(60.0f, appWidth/appHeight, .1, 1000);
    camera3->setProjection(110.0f, appWidth/appHeight, .1, 1000);
    camera4->setProjection(60.0f, appWidth/appHeight, .1, 1000);
    
//camera1->setViewPort(0, 0, window.getSize().x/2, window.getSize().y/2);
//    camera2->setViewPort(0, window.getSize().y/2, window.getSize().x/2, window.getSize().y/2);
//    camera3->setViewPort(window.getSize().x/2, window.getSize().y/2, window.getSize().x/2, window.getSize().y/2);
//    camera4->setViewPort(window.getSize().x/2, 0, window.getSize().x/2, window.getSize().y/2);
//
    world->add(std::move(camera1));
//    world->add(std::move(camera2));
//    world->add(std::move(camera3));
//    world->add(std::move(camera4));
    
   // camera1->setViewPort(0, 0, appWidth, appHeight);
   // world->add(std::move(camera1));

    // Lights
    // Light 1
    std::unique_ptr<ijg::ProtoLight> lt0_ptr = std::unique_ptr<ijg::ProtoLight>(new ProtoLight());
    lt0_ptr->setShininess(105.0);
    lt0_ptr->setDiffuse(ProtoColor4f(1.0, .5, 0, 1.0));
    lt0_ptr->setSpecular(ProtoColor4f(1.0, 1.0, 1.0, 1.0));
    lt0_ptr->setAmbient(ProtoColor4f(.4, .4, .4, 1.0));
    lt0_ptr->setPosition(Vec3f(0, 0, -2.0));
    world->add(std::move(lt0_ptr));
    
    // Light 2
    std::unique_ptr<ijg::ProtoLight> lt1_ptr = std::unique_ptr<ijg::ProtoLight>(new ProtoLight());
    lt1_ptr->setShininess(105.0);
    lt1_ptr->setDiffuse(ProtoColor4f(1.0, .5, 0, 1.0));
    lt1_ptr->setSpecular(ProtoColor4f(1.0, 1.0, 1.0, 1.0));
    lt1_ptr->setAmbient(ProtoColor4f(.4, .4, .4, 1.0));
    lt1_ptr->setPosition(Vec3f(-2, 2, 2.0));
    world->add(std::move(lt1_ptr));
    
    
    world->setLights();

    
    
    baseApp->setWorld(std::move(world));
    
    // Activate derived user class implementation.
    baseApp->init();
    }

void ProtoPlasm::initSFMLRun(){
    
    // Activate derived user class implementations of events:
    /*
     • run
     • mouse
     • keyboard
     */
    
    // clear screen
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // run the SFML main loop
    bool running = true;
    while (running)
    {
       //
        
        // Activate derived user class implementation.
        baseApp->runWorld();
        baseApp->run();
        
        
        // handle SFML events
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.mouseButton.button == sf::Mouse::Left) {
//                std::cout << "event.size = " << event.size.width << std::endl;
//                std::cout << "event.size = " << event.size.height << std::endl;
//                std::cout << "event.mouseButton.x = " << event.mouseButton.x << std::endl;
//                std::cout << "event.mouseButton.y = " << event.mouseButton.y << std::endl;
                
                // Activate derived user class implementation.
                baseApp->mousePressed();
            }
            
            if (event.type == sf::Event::Closed)
            {
                // Activate derived user class implementation.
                baseApp->onClosed();
                
                // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                //glViewport(0, 0, event.size.width/4.0, event.size.height/4.0);
                //world.updateCanvasSize(event.size.width, event.size.height);
                
                //                    std::cout << event.size.width  << std::endl;
                //                    std::cout << event.size.height  << std::endl;
            }else if (event.type == sf::Event::KeyPressed)
            {
                 // Activate derived user class implementation.
                baseApp->keyPressed();
                
                if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Escape) {
                    
                    running = false;
                    window->close();
                }
            }
        }
        
        // clear the buffers
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       
        
        // end the current frame (internally swaps the front and back buffers)
        window->display();
    }
    
    
}

