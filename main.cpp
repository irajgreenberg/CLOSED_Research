#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>
#include "Protobyte/Toroid.h"
#include "Protobyte/Matrix4.h"
#include <iomanip>




/**********************************
 *           matrices             *
 *********************************/
GLfloat modelViewMatrix[16];
GLfloat projectionMatrix[16];
void printMatrices();

/**********************************
 *             VIEW               *
 *********************************/
void setView(double fovY, double aspect, double zNear, double zFar);

/**********************************
 *           LIGHTING             *
 *********************************/
// Light01
GLfloat light01_ambient[] = {0.3, 0.3, 0.3, 1.0};
GLfloat light01_diffuse[] = {.6, .6, .8, 1.0};
GLfloat light01_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light01_position[] = {1.0, 1.0, 1.0, 0.0};

//materials
GLfloat light01_mat_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light01_mat_shininess[] = {128.0}; // max 128

void setLights();
void initGL();

int main() {
    // create the window
    sf::Window window(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    initGL();

    setLights();

    // about GL internal matrices
    // GL_MODELVIEW matrix is for position of camera - inverse of object transformations
    // GL_PROJECTIOIN matrix may be thought of as lens component of camera - 3d to 2d mapping


    // make projection matrix active
    glMatrixMode(GL_PROJECTION);
    // set projection matrix to identity
    glLoadIdentity();
    // update projection matrix with perspective values
    setView(75.0, window.getSize().x / (float) window.getSize().y, 1, 800);



    // make Modelview matrix active
    glMatrixMode(GL_MODELVIEW); // reload modelview matrix
    //set ModelView Matrix to identity
    glLoadIdentity();
    //glTranslatef(20, 20, 220);

    // print out current state of MODELVIEW and PROJECTION matrices
    printMatrices();

    Toroid toroid(Vector3(0, 0, -250), Vector3(100, 180, 0),
            Dimension3<float>(50, 50, 50), Color4<float>(0.7, 0.2, 0.1, .85), 56, 56, .5);

    Toroid toroid2(Vector3(0, 0, -350), Vector3(100, 125, -240),
            Dimension3<float>(30, 30, 30), Color4<float>(0.5, 0.5, 0.7, 1.0), 56, 56, .3);
    
    Toroid toroid3(Vector3(0, 0, -100), Vector3(270, 125, -240),
            Dimension3<float>(10, 10, 10), Color4<float>(0.7, 0.5, 0.7, 1.0), 24, 24, .8);




    // run the main loop
    bool running = true;
    while (running) {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // end the program
                running = false;
            } else if (event.type == sf::Event::Resized) {

                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        // clear buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);



        /*
         * // manually set modelview matrix
        // as example             
        static float rotX = 0;
        static float rotY = 0;
        static float rotZ = 0;

        float newM[16];
        newM[0] = cos(rotY) * cos(rotZ);
        newM[1] = cos(rotY) * sin(rotZ);
        newM[2] = -sin(rotY);
        newM[3] = 0;

        newM[4] = -cos(rotX) * sin(rotZ) + sin(rotX) * sin(rotY) * cos(rotZ);
        newM[5] = cos(rotX) * cos(rotZ) + sin(rotX) * sin(rotY) * sin(rotZ);
        newM[6] = sin(rotX) * cos(rotY);
        newM[7] = 0;

        newM[8] = sin(rotX) * sin(rotZ) + cos(rotX) * sin(rotY) * cos(rotZ);
        newM[9] = -sin(rotX) * cos(rotZ) + cos(rotX) * sin(rotY) * sin(rotZ);
        newM[10] = cos(rotX) * cos(rotY);
        newM[11] = 0;

        newM[12] = 0;
        newM[13] = 0;
        newM[14] = 0;
        newM[15] = 1;
        rotX += M_PI / 180 * 3.2;
        rotY += M_PI / 180 * 1.2;
        rotZ += M_PI / 180 * 2.2;

        //glLoadMatrixf(newM); // update modelview // turned this off
         */

        toroid2.display(GeomBase::VERTEX_ARRAY_INTERLEAVED); // draw opaque first 
        toroid.display(GeomBase::VERTEX_BUFFER_OBJECT);
        toroid3.display(GeomBase::DISPLAY_LIST);


        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // release resources...

    return 0;
}

// function from nehe.gamedev.net (http://nehe.gamedev.net/article/replacement_for_gluperspective/21002/)

void setView(double fovY, double aspect, double zNear, double zFar) {
    const double pi = 3.1415926535897932384626433832795;
    double fW, fH;
    //Formula below corrected by Carsten Jurenz: 
    //fH = tan( (fovY / 2) / 180 * pi ) * zNear reduces to
    fH = tan(fovY / 360 * pi) * zNear;
    fW = fH * aspect;
    glFrustum(-fW, fW, -fH, fH, zNear, zFar);
    //gluPerspective(fovY, aspect, zNear, zFar);
}

void setLights() {
    // light 01
    glMaterialfv(GL_FRONT, GL_SPECULAR, light01_mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, light01_mat_shininess);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light01_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light01_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light01_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light01_position);


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void initGL() {
    glFrontFace(GL_CCW); // default
    glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);
    //glDisable(GL_CULL_FACE);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH); // smooth by default
    //glShadeModel(GL_FLAT); 
    glEnable(GL_COLOR_MATERIAL); // incorporates per vertex color with lights
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_RESCALE_NORMAL); //  good for uniform scaling

    glClearColor(.1, .1, .2, 0); // background color
    glClearStencil(0); // clear stencil buffer
    glClearDepth(1.0f); // 0 is near, 1 is far
    glDepthFunc(GL_LEQUAL);

}

void printMatrices() {

    glGetFloatv(GL_MODELVIEW_MATRIX, modelViewMatrix);
    std::cout << "size of modelViewMatrix = " << sizeof (modelViewMatrix) << std::endl;
    transpose(modelViewMatrix);
    std::cout << "\n  ==================GL_MODELVIEW MATRIX==================" << "\n";
    for (int i = 0; i < 16; i++) {
        if (i % 4 == 0 && i != 0) {
            std::cout << " |  \n |  ";
        }
        if (i == 0) {
            std::cout << " |  ";
        }
        std::cout << std::setw(12) << modelViewMatrix[i] << " ";
        if (i == 15) {
            std::cout << " |  ";
        }
    }
    std::cout << "\n  =======================================================" << "\n";


    glGetFloatv(GL_PROJECTION_MATRIX, projectionMatrix);
    //inverse(projectionMatrix);
    std::cout << "\n  ==================GL_PROJECTION MATRIX=================" << "\n";
    for (int i = 0; i < 16; i++) {
        if (i % 4 == 0 && i != 0) {
            std::cout << " |  \n |  ";
        }
        if (i == 0) {
            std::cout << " |  ";
        }
        std::cout << std::setw(12) << projectionMatrix[i] << " ";
        if (i == 15) {
            std::cout << " |  ";
        }
    }
    std::cout << "\n  =======================================================" << "\n";
}