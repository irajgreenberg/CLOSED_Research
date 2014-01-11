//
//  ProtoPlasm2.cpp
//  Protobyte_dev_v02
//
//  Created by iragreenberg on 9/27/13.
//  Copyright (c) 2013 Ira Greenberg. All rights reserved.
//

#include "ProtoPlasm2.h"

using namespace ijg;

// init static globals
int ProtoPlasm2::frameCount = 0;
int ProtoPlasm2::frameRate = 0;


ProtoPlasm2::ProtoPlasm2(ProtoBaseApp* baseApp):
baseApp(baseApp), appWidth(1024), appHeight(764), appTitle("Protobyte App")
{
    // instantiate world
    //world = std::unique_ptr<ProtoWorld>(new ProtoWorld(appWidth, appHeight));
    
    // init app and call init() and run() to activate functions in user defined BaseApp derived class
    initSFMLInit();
    initSFMLRun();
}

ProtoPlasm2:: ProtoPlasm2(int appWidth, int appHeight, std::string appTitle, ProtoBaseApp* baseApp):
appWidth(appWidth), appHeight(appHeight), appTitle(appTitle), baseApp(baseApp){
    // this->baseApp = baseApp;
    baseApp->setWidth(appWidth);
    baseApp->setHeight(appHeight);
    baseApp->setSize(Dim2i(appWidth, appHeight));
    
    // this->appWidth = appWidth;
    // this->appHeight = appHeight;
    // this->appTitle = appTitle;
    
    
    
    // Create GL context and call init() and run() to activate functions in user defined BaseApp derived class
    initSFMLInit();
    initSFMLRun();
}


void ProtoPlasm2::initSFMLInit(){
    sf::ContextSettings settings;
    settings.depthBits = 32;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 8;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    
    
    
    // create window and GL context
    window = new sf::Window(sf::VideoMode(appWidth, appHeight), appTitle, sf::Style::Default, settings);
    // set framerate to refresh rate, ~60fps
    window->setVerticalSyncEnabled(true);
    
    // set gl states
    glClearColor(0, 0, 0, 1.0f);
    glShadeModel(GL_SMOOTH);
    // enable specualrity on textures
    glLightModelf(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SEPARATE_SPECULAR_COLOR);
    glEnable(GL_LIGHTING);
    glFrontFace(GL_CCW); // default
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glDisable(GL_CULL_FACE);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    //glShadeModel(GL_FLAT); // option
    glEnable(GL_COLOR_MATERIAL); // incorporates per vertex color with lights
    
    // global ambinet unrelated to lights
    float globalAmbient[4] = {.2, .2, .2, 1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,  globalAmbient);
    
    // let glColor contorl diffues and ambient material values
    glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );
    
    //
    glEnable(GL_BLEND);
    //glBlendFunc(GL_DST_COLOR,GL_ZERO);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glBlendFunc(GL_DST_COLOR,GL_ZERO);
    //glBlendFunc (GL_ONE, GL_ONE);
    
    //glEnable(GL_ALPHA_TEST);
    //glAlphaFunc(GL_GREATER,0.0f);
    
    
    
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE); //  good for uniform scaling
    
    
    glClearStencil(0); // clear stencil buffer
    glClearDepth(1.0f); // 0 is near, 1 is far
    glDepthFunc(GL_LEQUAL);
    
    
    
    // World manages lighting and views (cameras)
    // instantiate singleton world
    world = std::unique_ptr<ProtoWorld>(new ProtoWorld(appWidth, appHeight));
    
    // set default single world view
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
    //    std::unique_ptr<ijg::ProtoLight> lt0_ptr = std::unique_ptr<ijg::ProtoLight>(new ProtoLight());
    //    lt0_ptr->setShininess(128.0);
    //    lt0_ptr->setDiffuse(ProtoColor4f(1.0, .5, 0, 1.0));
    //    lt0_ptr->setSpecular(ProtoColor4f(1.0, 1.0, 1.0, 1.0));
    //    lt0_ptr->setAmbient(ProtoColor4f(.4, .4, .4, 1.0));
    //    lt0_ptr->setPosition(Vec3f(0, 0, -2.0));
    //    world->add(std::move(lt0_ptr));
    //
    //    // Light 2
    //    std::unique_ptr<ijg::ProtoLight> lt1_ptr = std::unique_ptr<ijg::ProtoLight>(new ProtoLight());
    //    lt1_ptr->setShininess(128.0);
    //    lt1_ptr->setDiffuse(ProtoColor4f(1.0, .5, 0, 1.0));
    //    lt1_ptr->setSpecular(ProtoColor4f(1.0, 1.0, 1.0, 1.0));
    //    lt1_ptr->setAmbient(ProtoColor4f(.4, .4, .4, 1.0));
    //    lt1_ptr->setPosition(Vec3f(-2, 2, 2.0));
    //    world->add(std::move(lt1_ptr));
    //
    //
    //    world->setLights();
    
    
    
    // pass world to baseApp enabling user defined BaseApp derived class access
    // setWorld also initializes some baseApp states
    //std::cout << "world->fovAngle = " << world->fovAngle << std::endl;
    baseApp->setWorld(std::move(world));
    // std::cout << "baseApp->world->fovAngle = " << baseApp->world->fovAngle << std::endl;
    
    // Activate init function in user derived class.n.
    baseApp->init();
}

// activate animation thread and run() function in user defined BaseApp derived class
void ProtoPlasm2::initSFMLRun(){
    
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
    
    sf::Clock clock;
    
    while (running)
    {
        /*
         TO DO – fix timing issues with control for users:
         From: http://stackoverflow.com/questions/2182675/how-do-you-make-sure-the-speed-of-opengl-animation-is-consistent-on-different-ma
         This is the poor man's solution:
         
         FPS = 60.0;
         while (game_loop) {
         int t = getticks();
         if ((t - t_prev) > 1000/FPS)
         process_animation_tick();
         t_prev = t;
         }
         
         this is the better solution:
         
         GAME_SPEED = ...
         while (game_loop) {
         int t = getticks();
         process_animation((t - t_prev)*GAME_SPEED/1000.0);
         t_prev = t;
         }
         
         
         */
        
        ++frameCount;
        sf::Time elapsedT = clock.restart();
        frameRate = 1.0/elapsedT.asSeconds();
        //std::cout << "frameRate = "<< frameRate << std::endl;
        
        sf::Time elapsed = clock.getElapsedTime();
        if(frameCount%60==0){
            //std::cout << "clock running at 60 fps"<< std::endl;
        }
        
        //std::cout << " elapsed.asSeconds() = " <<  elapsed.asSeconds()<<std::endl;
        
        
        
        
        // Activate derived user class implementation.
        baseApp->runWorld();
        baseApp->run();
        
        
        // handle SFML events
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    //                    std::cout << "event.size = " << event.size.width << std::endl;
                    //                    std::cout << "event.size = " << event.size.height << std::endl;
                    //
                    //                    std::cout << "event.mouseButton.x = " << event.mouseButton.x << std::endl;
                    //                    std::cout << "event.mouseButton.y = " << event.mouseButton.y << std::endl;
                    //
                    // Activate derived user class implementation.
                    baseApp->mousePressed();
                }
            }
            
            else if (event.type == sf::Event::MouseMoved)
            {
                baseApp->mouseMoved(event.mouseMove.x,event.mouseMove.y);
            }
            
            else if (event.type == sf::Event::Closed)
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

