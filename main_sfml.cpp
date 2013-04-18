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
#include "Protobyte/Shader.h"
#include "Protobyte/Texture2.h"
#include "Protobyte/Block.h"
#include "Protobyte/GroundPlane.h"

#include "Protobyte/utilityFunctions.h"


using namespace proto;

/**********************************
 *           Window             *
 *********************************/
struct WindowValues {
    // constructor

    WindowValues() : x(0), y(0), w(1028), h(768),
    title("Protobyte Library .0001a"), fovAngle(65),
    nearClipPlane(.1f), farClipPlane(5000), running(true) {
    }
    //fields
    int x, y, w, h;
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
GLfloat light01_position[] = {1.0, 10.0, 1.0, 0.0};

//materials
GLfloat light01_mat_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light01_mat_shininess[] = {128}; // max 128

Toroid toroid;
Tube tube2;

// const std::string& textureURL, GLuint w, GLuint h, bool isWrap
Texture2 tex2;
Toroid toroid2;


Block block;

GroundPlane plane;
Texture2 texScape;

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



void setGeom() {
    tex2 = Texture2("resources/imgs/ship_plate.raw", 256, 256, true);
    //tex2 = Texture2("resources/imgs/white_texture.raw", 256, 256, true);

    //toroid = Toroid(Vector3(0, 0, 0), Vector3(100, 180, 0),
    //Dimension3<float>(30, 30, 30), Color4<float>(0.9, 0.1, 0.1, .75), 10, 10, .87, .22, tex2);



    texScape = Texture2("resources/imgs/graham.raw", 1024, 768, true);
    // filter texture image
    //unsigned char* data = new unsigned char[1024*768*3];
    // loadRaw("resources/imgs/graham.raw", 1024, 768, data);
    // texScape = Texture2(data, 1024, 768, true);

    sf::Image img;
    img.loadFromFile("imgs/graham.jpg");

    
    // test for color storage
    // better than bitwise ops
    typedef struct packed_int {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    } packed_int;

    typedef union {
        unsigned int i;
        packed_int col;
    } packed;
    
    packed c;
    c.i = 3232235881UL;
    
    printf("%d\n", c.col.r);
    std::cout << "c.col.r = " << int(c.col.r) << std::endl;
// end test



    //unsigned char* label = (unsigned char*) img.getPixelsPtr();

    //texScape = Texture2(label, 1024, 768, true);

    plane = GroundPlane(Vector3(0, 0, 0), Vector3(180, 0, 0),
            Dimension3<float>(150, 1, 150), Color4<float>(.3, .3, .3, 1.0), 64, 64, texScape);
    //delete [] data;
    // toroid2 = Toroid(Vector3(0, 0, -60), Vector3(100, 180, 0),
    // Dimension3<float>(30, 30, 30), Color4<float>(0.3, 0.3, 0.8, .85), 60, 60, .87, .22, tex);

    // test spline curve
    std::vector<Vector3> cps;
    int controlPts = 10;
    float x, y, z = 5;
    float t = 0;
    for (int i = 0; i < controlPts; i++) {
        //rand() % 100;  // v1 in the range 0 to 99
        x = -1 + rand() % 3; // (-5 to 5)
        y = -1 + rand() % 3; // (-5 to 5)
        z = -2 + rand() % 5; // (-5 to 5)
        //std::cout << "x = " << x << std::endl;
        //std::cout << "y = " << y << std::endl;
        //std::cout << "( " << x << ", " << y << ", " << z << " )" << std::endl;
        //x = cos(t)*2;
        //y = sin(t)*2;
        //z=0;
        cps.push_back(Vector3(x, y, z));
        t += M_PI * 2 / (controlPts);
    }

    int interpDetail = 2;
    float smoothness = .8;
    Spline3 spline(cps, interpDetail, false, smoothness);

    int totalSegCount = (controlPts - 1) * interpDetail + controlPts;
    std::vector<float> radii;
    radii.resize(totalSegCount);
    std::vector< Color4<float> > cols;
    cols.resize(totalSegCount);


    for (int i = 0; i < totalSegCount; i++) {
        // mult radii
        static double theta2 = 0.0;
        radii.at(i) = .15 + sin(theta2)*.09;
        //std::cout << " radii.at(i) = " << radii.at(i) << std::endl;
        theta2 += M_PI / 5.0;

        // mult colors
        static float r = 0.0, g = 0.0, b = 0.0, a = 1.0;
        static float nudger = 1.0 / totalSegCount;
        cols.at(i) = Color4<float>(r += nudger, g += nudger, b += nudger, a);
    }

    //Tube tube(Vector3(0, 0, -200), Vector3(0, 0, 0), Dimension3<float>(40, 40, 40), Color4<float>(0.7, 0.2, 0.3, 1.0), spline, radii, 24);
    //Tube tube(Vector3(0, 0, -200), Vector3(0, 0, 0), Dimension3<float>(40, 40, 40), cols, spline, radii, 24);

    // tube around toroid
    interpDetail = 3;
    smoothness = .55;
    std::vector<Vector3> cps2;
    int segs = 200/*400*/;


    //int loops = 4;
    cps2.resize(segs);
    float xx, yy, zz = .1;

    float tempX, tempZ;
    for (int i = 0; i < segs; i++) {
        static float theta = 0.0, phi = 0.0;
        xx = .8 - .02 + cos(theta)*.33;
        yy = sin(theta)*.31;
        theta += M_PI / 1.95;


        tempZ = cos(phi) * zz - sin(phi) * xx;
        tempX = sin(phi) * zz + cos(phi) * xx;
        cps2.at(i) = Vector3(tempX, yy, tempZ);

        //phi += (-2+rand() % 5)*M_PI/360;
        phi += M_PI / proto::Math::random(2.0, 50.0);
        // zz += .2 / segs;

    }

    totalSegCount = (segs - 1) * interpDetail + segs;
    radii.clear();
    radii.resize(totalSegCount);
    cols.clear();
    cols.resize(totalSegCount);

    for (int i = 0; i < totalSegCount; i++) {
        // mult radii
        static double theta2 = 0.0;
        radii.at(i) = .02 + sin(theta2)*.005;
        //std::cout << " radii.at(i) = " << radii.at(i) << std::endl;
        theta2 += M_PI / 5.0;

        // mult colors
        static float r = 0.0, g = 0.0, b = 0.0, a = 1.0;
        static float nudger = 1.0 / totalSegCount;
        cols.at(i) = Color4<float>(r += nudger, g += nudger, b += nudger, a);
    }

    Spline3 spline2(cps2, interpDetail, false, smoothness);
    //tube2 = Tube(Vector3(0, 0, 0), Vector3(100, 180, 0), Dimension3<float>(30, 30, 30), cols, spline2, radii, 18);

    //block = Block(Vector3(0, 0, -60), Vector3(100, 180, 0),
    //Dimension3<float>(20, 20, 20), Color4<float>(0.4, 0.3, 0.85, 1.0), tex2);
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
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glClearColor(.2, 1, 1, 1); // background color
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
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void draw() {
    // clear the buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // make modelview matrix active
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Define a viewing transformation
    gluLookAt(0, 0, -100, 0, 0, 0, 0, -1, 0);

    // use different lighting on the different geometry
    light01_diffuse[0] = 1.0;
    light01_diffuse[1] = 1.0;
    light01_diffuse[2] = 1.0;
    setLights();

    // shader.bind();

    /*
     // set uniform variables for shaders
    GLint loc1, loc2, loc3, loc4;
    float BrickColor[4] = {0.9, 0.3, 0.1, 1.0};
    float MortarColor[4] = {0.7, 0.7, 0.6, 1.0};
    float BrickSize[2] = {10.2, 8.1};
    float BrickPct[2] = {0.5, 0.5};

    loc1 = glGetUniformLocation(shader.shader_id, "BrickColor");
    
    glUniform4fv(loc1, 1, BrickColor);

    loc2 = glGetUniformLocation(shader.shader_id, "MotarColor");
    glUniform4fv(loc2, 1, MortarColor);

    loc3 = glGetUniformLocation(shader.shader_id, "BrickSize");
    glUniform2fv(loc3, 1, BrickSize);

    loc4 = glGetUniformLocation(shader.shader_id, "BrickPct");
    glUniform2fv(loc4, 1, BrickPct);
    
    std::cout << "loc1 = " << loc1 << std::endl;
    std::cout << "loc2 = " << loc2 << std::endl;
    std::cout << "loc3 = " << loc3 << std::endl;
    std::cout << "loc4 = " << loc4 << std::endl;
     */
    glPushMatrix();

    glTranslatef(transX, transY, transZ);
    glRotatef(liveRotX, 0, 1, 0);
    glRotatef(liveRotY, 1, 0, 0);


    glDisable(GL_TEXTURE_2D);
    shader.bind();
    //toroid.display(GeomBase::VERTEX_BUFFER_OBJECT, GeomBase::SURFACE);

    //tube2.display(GeomBase::VERTEX_BUFFER_OBJECT, GeomBase::SURFACE);
    shader.unbind();

    light01_diffuse[1] = .2;
    light01_diffuse[2] = .2;
    setLights();

    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    //   toroid.display(GeomBase::VERTEX_BUFFER_OBJECT, GeomBase::SURFACE);


    glShadeModel(GL_FLAT);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    //block.display(GeomBase::VERTEX_BUFFER_OBJECT, GeomBase::SURFACE);
    glShadeModel(GL_SMOOTH); // smooth by default

    plane.display(GeomBase::VERTEX_BUFFER_OBJECT, GeomBase::SURFACE);

    //shader.unbind();

    glPopMatrix();
    // required by glut
    //glutSwapBuffers();
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
