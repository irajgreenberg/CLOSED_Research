
#ifdef __APPLE__
#include "glut/glut.h"
#else
#include <GL/glut.h>
#endif

#include <cmath>
#include "Protobyte/Toroid.h"
#include "Protobyte/Matrix4.h"
#include <iomanip>
#include "Protobyte/Spline3.h"
#include "Protobyte/Tube.h"
#include <ctime>
#include "Protobyte/Math.h"
#include "Protobyte/Shader.h"

/**********************************
 *           Window             *
 *********************************/

struct glutWindow {
    int x;
    int y;
    int w;
    int h;
    char* title;
    float fovAngle;
    float nearClipPlane;
    float farClipPlane;
};
glutWindow win;


/**********************************
 *      animation and timer       *
 *********************************/
int interframeDelay = 15;
void animationLoop(int delay);


/**********************************
 *             VIEW               *
 *********************************/
void setView(double fovY, double aspect, double zNear, double zFar);


/**********************************
 *             shaders               *
 *********************************/

static Shader shader;
void setShaders();


/**********************************
 *           LIGHTING             *
 *********************************/
// Light01
GLfloat light01_ambient[] = {0.0, 0.0, 0.0, 1.0};
GLfloat light01_diffuse[] = {.7, .2, .2, 1.0};
GLfloat light01_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light01_position[] = {1.0, 10.0, 1.0, 0.0};

//materials
GLfloat light01_mat_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light01_mat_shininess[] = {128}; // max 128

void setLights();

void initGL();
void setGeom();

Toroid toroid;
Tube tube2;

void setGeom() {
    toroid = Toroid(Vector3(0, 0, -60), Vector3(100, 180, 0),
            Dimension3<float>(30, 30, 30), Color4<float>(0.3, 0.3, 0.8, .2), 60, 60, .87, .22);

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
    int segs = 100/*400*/;


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
    tube2 = Tube(Vector3(0, 0, -60), Vector3(100, 180, 0), Dimension3<float>(30, 30, 30), cols, spline2, radii, 12);
}

void init() {
    
    
    initGL();
    setLights();
    srand(time(0)); // seed random, should only be called once
    setGeom();
    setShaders();
}

void initGL() {

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

    glClearColor(.2, 1, 1, 1); // background color
    glClearStencil(0); // clear stencil buffer
    glClearDepth(1.0f); // 0 is near, 1 is far
    glDepthFunc(GL_LEQUAL);
}


// Called every time a window is resized to resize the projection matrix

void reshape(int w, int h) {

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


// animation loop

void display() {
    // clear buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // make modelview matrix active
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Define a viewing transformation
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    // use different lighting on the different geometry
    light01_diffuse[0] = 1.0;
    light01_diffuse[1] = 1.0;
    light01_diffuse[2] = 1.0;
    setLights();
   
    shader.bind();
   // tube2.display(GeomBase::VERTEX_BUFFER_OBJECT, GeomBase::SURFACE);
   
    light01_diffuse[1] = .2;
    light01_diffuse[2] = .2;
    setLights();
    toroid.display(GeomBase::VERTEX_BUFFER_OBJECT, GeomBase::SURFACE);
    shader.unbind();
    
    // required by glut
    glutSwapBuffers();
}

int main(int argc, char **argv) {

     // set window values
    win.x = 0;
    win.y = 0;
    win.w = 1280;
    win.h = 800;
    win.title = "Protobyte Glut Project";
    win.fovAngle = 65;
    win.nearClipPlane = .1f;
    win.farClipPlane = 50000.0f;
    
    // set up GLUT

    glutInit(&argc, argv); // Initializes glut

    // Sets up a double buffer with RGBA components and a depth component
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    // Sets the window position to the upper left
    glutInitWindowPosition(win.x, win.y);

    // Sets the window size to 512*512 square pixels
    glutInitWindowSize(win.w, win.h);


    // Creates a window using internal glut functionality
    glutCreateWindow(win.title);

    // passes reshape and display functions to the OpenGL machine for callback
    glutReshapeFunc(reshape);
    glutDisplayFunc(display); //call display
    glutTimerFunc(interframeDelay, animationLoop, 0); // start animation

    init();

    // Starts the program.
    glutMainLoop();

    // release any resources...

    return 0;
}


// animation based on internal timer
void animationLoop(int delay) 
{
   glutPostRedisplay();
   glutTimerFunc(delay, animationLoop, 0);
   return;
}



// function from nehe.gamedev.net (http://nehe.gamedev.net/article/replacement_for_gluperspective/21002/)

void setView(double fovAngle, double aspect, double nearClipPlane, double farClipPlane) {
    // set up a perspective projection matrix
    gluPerspective(fovAngle, aspect, nearClipPlane, farClipPlane);
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


//============================================================================
// Set up shaders
//============================================================================

void setShaders() {
    const char* vert = "resources/shaders/phong_shader.vert";
    const char* frag = "resources/shaders/phong_shader.frag";

    shader.init(vert, frag);
}
