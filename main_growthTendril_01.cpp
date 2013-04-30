#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#ifdef  __APPLE__
#include <GLUT/glut.h>
#elif __linux
#include <GL/glew.h>
#include <GL/glut.h>
#elif defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#include <GL/glew.h>
#include <GL/glut.h>
#endif

// eventually go back to SFML
//#include <SFML/Window.hpp>
//#include <SFML/OpenGL.hpp>


#include <cmath>
#include <string>
#include <bitset>
#include "Protobyte/Toroid.h"
#include "Protobyte/Matrix4.h"
#include <iomanip>
#include "Protobyte/Spline3.h"
#include "Protobyte/Tube.h"
#include <ctime>
//#include <OpenGL.framework/headers/gl.h>
#include "Protobyte/Math.h"
#include "Protobyte/Color4.h"
#include "Protobyte/Shader.h"
#include "Protobyte/Texture2.h"
#include "Protobyte/Block.h"
#include "Protobyte/BlockGrid.h"
#include "Protobyte/GroundPlane.h"
#include "Protobyte/Sphere.h"

#include "Protobyte/utilityFunctions.h"


using namespace proto;

/**********************************
 *           Window             *
 *********************************/
struct WindowValues {
    // constructor

    WindowValues() : x(0), y(0), w(1400), h(1000), bgCol(0.0, 0.0, 0.0, 1.0),
    title("Protobyte Library .0001a"), fovAngle(65),
    nearClipPlane(.1f), farClipPlane(5000), running(true) {
    }
    //fields
    int x, y, w, h;
    Color4f bgCol;
    std::string title;
    float fovAngle;
    float nearClipPlane;
    float farClipPlane;
    bool running;
};
WindowValues win;


/**********************************
 *            Events              *
 *********************************/
//void glutMouseFunc(int button, int state, int x, int y);
bool isMouseDown = 0, isMouseUp = 1;
int mouseXIn, mouseXOut, mouseYIn, mouseYOut;
float liveRotX, liveRotY;
float worldRotX, worldRotY;
float mouseRotX, mouseRotY;
float transX, transY, transZ;


/**********************************
 *      animation and timer       *
 *********************************/
int interframeDelay = 5;
void animationLoop(int delay);


/**********************************
 *             VIEW               *
 *********************************/



/**********************************
 *             shaders               *
 *********************************/
static Shader shader;



/**********************************
 *           LIGHTING             *
 *********************************/
// Light01
GLfloat light01_ambient[] = {0.3, 0.1, 0.1, 1.0};
GLfloat light01_diffuse[] = {.85, .85, .85, 1.0};
GLfloat light01_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light01_position[] = {-20, 10, 5.0, 0.0};

//materials
GLfloat light01_mat_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light01_mat_shininess[] = {109}; // max 128

/**********************************
 *           Geometry             *
 *********************************/

Spline3 spline01;
Tube tube;





/**********************************
 *       FUNCTION PROTOTYPES      *
 *********************************/
void setGeom();
void setView(double fovY, double aspect, double zNear, double zFar);
void setLights();
void setShaders();
void init();
void initGL();
void resize();
void draw();

/**********************************
 *    END FUNCTION PROTOTYPES     *
 *********************************/



//============================================================================
// Set up Geometry objs
//============================================================================

void setGeom() {
    /*Spline3::Spline3(const std::vector<Vector3>& controlPts, int interpDetail, 
    bool isCurveClosed, float smoothness) :
    Curve3(controlPts, interpDetail, isCurveClosed), smoothness(smoothness) {
     */
    std::vector<Vector3> pts;
//    pts.push_back(Vector3(-40, -15, 0));
//    pts.push_back(Vector3(-10, -5, 0));
//    pts.push_back(Vector3(0, 0, 0));
//    pts.push_back(Vector3(5, -9, 0));
//    pts.push_back(Vector3(10, 5, 0));
//    pts.push_back(Vector3(40, 15, 0));
    
    int cpLen = 60;
    pts.resize(cpLen);
    for(int i=0; i<cpLen; ++i){
        pts.at(i) = Vector3(Math::random(-120, 120), Math::random(-120, 120), Math::random(-120, 120));
    }
    
    spline01 = Spline3(pts, 20, false, .5);
    //const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4f col4, const Spline3& path, float radius, int crossSectionDetail
    tube = Tube(Vector3(0,0,0), Vector3(0,0,0), Dimension3f(1, 1, 1), Color4f(.3, .6, .25, .9), spline01, 1, 24);


}

//============================================================================
// Set up views
//============================================================================
// function from nehe.gamedev.net (http://nehe.gamedev.net/article/replacement_for_gluperspective/21002/)

void setView(double fovAngle, double aspect, double nearClipPlane, double farClipPlane) {
    // set up a perspective projection matrix
    gluPerspective(fovAngle, aspect, nearClipPlane, farClipPlane);
}


//============================================================================
// Set up lights
//============================================================================

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


//============================================================================
// Set up shaders
//============================================================================

void setShaders() {
    const char* vert = "resources/shaders/singleLight.vert";
    const char* frag = "resources/shaders/singleLight.frag";

    shader.init(vert, frag);
}

void init() {

    initGL();
    setLights();
    srand(time(0)); // seed random, should only be called once
    setGeom();
    setShaders();

    std::cout << "glGetString(GL_VERSION) = " << glGetString(GL_VERSION) << std::endl;
}

void initGL() {

    // GLEW
#ifdef  __linux__ || _WIN32 || _WIN64
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        fprintf(stderr, "Error %s\n", glewGetErrorString(err));
        exit(1);
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

    if (GLEW_ARB_vertex_program)
        fprintf(stdout, "Status: ARB vertex programs available.\n");

    if (glewGetExtension("GL_ARB_fragment_program"))
        fprintf(stdout, "Status: ARB fragment programs available.\n");

    if (glewIsSupported("GL_VERSION_1_4  GL_ARB_point_sprite"))
        fprintf(stdout, "Status: ARB point sprites available.\n");

#endif


    // make projection matrix active
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // set the viewport
    glViewport(win.x, win.y, win.w, win.h);

    // update projection matrix with perspective values
    setView(win.fovAngle, win.w / win.h, win.nearClipPlane, win.farClipPlane);

    // make Modelview matrix active
    glMatrixMode(GL_MODELVIEW); // reload modelview matrix
    //set ModelView Matrix to identity
    glLoadIdentity();

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
    glEnable(GL_NORMALIZE); //  good for uniform scaling

    // texture
    glEnable(GL_TEXTURE_2D);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glClearColor(win.bgCol.getR(), win.bgCol.getG(), win.bgCol.getB(), win.bgCol.getA()); // background color
    glClearStencil(0); // clear stencil buffer
    glClearDepth(1.0f); // 0 is near, 1 is far
    glDepthFunc(GL_LEQUAL);
}

void resize() {
    // check all these settings eventually
    glViewport(0, 0, win.w, win.h);

    // make projection matrix active
    glMatrixMode(GL_PROJECTION);

    // set projection matrix to identity
    glLoadIdentity();

    // update projection matrix with perspective values
    setView(win.fovAngle, win.w / win.h, win.nearClipPlane, win.farClipPlane);


    // make Modelview matrix active
    glMatrixMode(GL_MODELVIEW);

    // set modelvioew matrix to identity
    glLoadIdentity();

    // Define a viewing transformation
    gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);
}

void draw() {
    // clear the buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // make modelview matrix active
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Define a viewing transformation
    //gluLookAt(0, 0, -15, 0, 0, 0, 0, -1, 0);

    // use different lighting on the different geometry
    light01_diffuse[0] = 1.0;
    light01_diffuse[1] = 1.0;
    light01_diffuse[2] = 1.0;
    setLights();


    glPushMatrix();
    gluLookAt(0, 0, 150, 0, 0, 0, 0, -1, 0);
    glTranslatef(transX, transY, transZ);
    glRotatef(liveRotX, 0, 1, 0);
    glRotatef(liveRotY, 1, 0, 0);

    // Rendering state utils
    //glDisable(GL_TEXTURE_2D);
    //shader.bind();
    //shader.unbind();
    //glEnable(GL_TEXTURE_2D);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    // glShadeModel(GL_FLAT);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    spline01.display();
    spline01.displayControlPts();
    spline01.displayInterpPts();
    tube.display(GeomBase::VERTEX_BUFFER_OBJECT, GeomBase::SURFACE);
    glPopMatrix();

}

int main() {
    // create the window
    sf::Window window(sf::VideoMode(win.w, win.h), win.title, sf::Style::Default, sf::ContextSettings(32));

    // sync refresh to monitor and avoid tearing
    window.setVerticalSyncEnabled(true);
    // OR (don't use both
    // window.setFramerateLimit(60);

    sf::Vector2i mousePos;

    // load resources, initialize the lib/OpenGL states, ...
    init();

    window.setKeyRepeatEnabled(true); // processes keypress holds

    // main event animation loop
    while (win.running) {
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {

            switch (event.type) {

                case sf::Event::Closed:
                    win.running = false;
                    window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {

                        isMouseDown = 1;
                        isMouseUp = 0;

                        worldRotX = liveRotX;
                        worldRotY = liveRotY;

                        // capture mouse press position relative to window
                        mousePos = sf::Mouse::getPosition(window);
                        mouseXIn = mousePos.x;
                        mouseYIn = mousePos.y;
                        break;

                    } else if (event.mouseButton.button == sf::Mouse::Right) {
                        //
                    }
                    break;

                case sf::Event::MouseButtonReleased:
                    isMouseDown = 0;
                    isMouseUp = 1;

                    // capture mouse release position
                    mousePos = sf::Mouse::getPosition(window);
                    mouseXOut = mousePos.x;
                    mouseYOut = mousePos.x;
                    break;

                case sf::Event::KeyPressed:
                    //switch (key) {
                    if (event.key.code == sf::Keyboard::X) {
                        transZ++;
                    } else if (event.key.code == sf::Keyboard::Z) {
                        transZ--;
                    } else if (event.key.code == sf::Keyboard::Q) {
                        win.running = false;
                        window.close();
                    } else if (event.key.code == sf::Keyboard::Escape) {
                        win.running = false;
                        window.close();
                    } else if (event.key.code == sf::Keyboard::Left) {
                        transX--;
                    } else if (event.key.code == sf::Keyboard::Right) {
                        transX++;
                    } else if (event.key.code == sf::Keyboard::Up) {
                        transY++;
                    } else if (event.key.code == sf::Keyboard::Down) {
                        transY--;
                    }
                    //}
                    break;

                case sf::Event::MouseMoved:
                    if (isMouseDown) {
                        mousePos = sf::Mouse::getPosition(window);
                        mouseRotX = mousePos.x - mouseXIn;
                        mouseRotY = mousePos.y - mouseYIn;

                        liveRotX = worldRotX + mouseRotX;
                        liveRotY = worldRotY + mouseRotY;
                    }

                    break;

                case sf::Event::MouseWheelMoved:
                    break;

                case sf::Event::KeyReleased:
                    break;

                case sf::Event::Resized:
                    resize();
                    break;

                case sf::Event::LostFocus:
                    break;

                case sf::Event::GainedFocus:
                    break;

                case sf::Event::TextEntered:
                    break;

                case sf::Event::MouseEntered:
                    break;

                case sf::Event::MouseLeft:
                    break;

                default:
                    break;
            }



        }

        draw();

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    // release resources...

    return 0;
}
