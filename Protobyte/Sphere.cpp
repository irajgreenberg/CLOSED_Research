/*! 
 * File:   Sphere.cpp
 * Author: Ira Greenberg
 * 
 * Created on April 25, 2013, 1:47 PM
 */

#include "Sphere.h"
using namespace proto;

Sphere::Sphere() {

}

Sphere::Sphere(const Vector3& pos, const Vector3& rot, const Dimension3f size,
        const Color4f col4, float textureScale, int spines, int spineNodes) :
GeomBase(pos, rot, size, col4, textureScale), spines(spines), spineNodes(spineNodes) {
    init();
}

Sphere::Sphere(const Vector3& pos, const Vector3& rot, const Dimension3f size,
        const Color4f col4, int spines, int spineNodes) :
GeomBase(pos, rot, size, col4), spines(spines), spineNodes(spineNodes) {
    init();
}

/*void Sphere::init() {
    calcVerts();
    calcInds();
    calcFaces();
    calcVertexNorms();
    calcPrimitives();
    fillDisplayLists();
}*/

void Sphere::calcVerts() {

    verts.resize((spineNodes - 2) * spines + 2);
    float x = 0, y = 0, z = 0;
    float tempX = 0, tempZ = 0;
    float theta = -M_PI / 2.0, phi = 0;
    int counter = 0;

    // always 1 more segment than points along spline
    for (int i = 0; i < spineNodes; i++) {
        // y rotation
        x = cos(theta) * (size.w / 2.0);
        y = sin(theta) * (size.w / 2.0);
        for (int j = 0; j < spines; j++) {

            // z rotation
            tempZ = cos(phi) * z - sin(phi) * x;
            tempX = sin(phi) * z + cos(phi) * x;
            // top vertex
            if (i == 0 && j == 0) {
                verts.at(counter++) = Vertex(Vector3(tempX, y, tempZ),
                        Color4f(col4.getR(), col4.getG(), col4.getB(), col4.getA()),
                        Tuple2f(tempX / (size.w / 2.0) / 2, tempZ / (size.w / 2.0) / 2));
                // body vertices
            } else if (i > 0 && i < spineNodes - 1) {
                verts.at(counter++) = Vertex(Vector3(tempX, y, tempZ),
                        Color4f(col4.getR(), col4.getG(), col4.getB(), col4.getA()),
                        Tuple2f(tempX / (size.w / 2.0) / 2, tempZ / (size.w / 2.0) / 2));
                // bottom vertex
            } else if (i == spineNodes - 1 && j == 0) {
                verts.at(counter++) = Vertex(Vector3(tempX, y, tempZ),
                        Color4f(col4.getR(), col4.getG(), col4.getB(), col4.getA()),
                        Tuple2f(tempX / (size.w / 2.0) / 2, tempZ / (size.w / 2.0) / 2));
            }
            phi -= M_PI * 2.0 / spines;
        }
        theta += M_PI / spineNodes;
    }
    std::cout << "counter = " << counter << std::endl;
}

/*Note: p = Pi
q as the angle  on X axis (0 <= q <= 2p)
f as the angle from the Z axis (0.0 <= f <= p).

X = R sin (f) * cos (q) = R sin (pv) * cos (2pu) where f/p = v (0.0 <= v <= 1.0)
Y = R sin (f) * sin (q) = R sin (pv) * sin (2pu) where q/2p = u (0.0 <= u <= 1.0))
Z = R cos (f) = R cos (pv)

u = [arccos ( X/R sin (pv) ) ] / 2p
v = f/p = arccos (Z/R) / p
 */

/*! 
 * Implementation Notes:
 * Verts packed 1 dimensionally as top PT = 0, body, bottom PT = size()-1
 * 
 * Created on April 25, 2013, 1:47 PM
 */
//  FIX NEED MORE FACES
void Sphere::calcInds() {
    int ctr = 0;
    Tuple3i t0;

    // body faces
    for (int i = 0; i < spineNodes; ++i) {
        for (int j = 0; j < spines; ++j) {
            //TOP
            if (i == 0 && j < spines - 1) {
                t0 = Tuple3i(0, j + 1, j + 2);
                inds.push_back(t0);
                std::cout << "top = " << t0 << std::endl;
                //TOP CLOSE
            } else if (i == 0 && j == spines - 1) {
                t0 = Tuple3i(0, j + 1, 1);
                inds.push_back(t0);
                std::cout << "top close = " << t0 << std::endl;
                // BODY
            } else if (i > 0 && i < spineNodes - 2 && j < spines - 1) { // HERE
                t0 = Tuple3i((i - 1) * spines + j + 1, i * spines + j + 1, (i - 1) * spines + j + 2);
                inds.push_back(t0);
                std::cout << "middle 1 = " << t0 << std::endl;

                t0 = Tuple3i((i - 1) * spines + j + 2, i * spines + j + 1, i * spines + j + 2);
                inds.push_back(t0);
                std::cout << "middle 2 = " << t0 << std::endl;
                // BODY CLOSE
            } else if (i > 0 && i < spineNodes - 2 && j == spines - 1) {
                t0 = Tuple3i((i - 1) * spines + j + 1, i * spines + j + 1, (i - 1) * spines + 1);
                inds.push_back(t0);
                std::cout << "middle 1 = " << t0 << std::endl;

                t0 = Tuple3i((i - 1) * spines + 1, i * spines + j + 1, i * spines + 1);
                inds.push_back(t0);
                std::cout << "middle 2 = " << t0 << std::endl;
                // BOTTOM
            } else if (i == spineNodes-1 && j < spines - 1) {
                t0 = Tuple3i(verts.size()-1, (i - 2) * spines + j + 2, (i - 2) * spines + j + 1);
                inds.push_back(t0);
                std::cout << "bottom = " << t0 << std::endl;
                //BOTTOM CLOSE
            } else if (i == spineNodes-1 && j == spines - 1) {
                t0 = Tuple3i(verts.size()-1,  (i - 2) * spines + 1, (i - 2) * spines + j + 1);
                inds.push_back(t0);
                std::cout << "bottom close = " << t0 << std::endl;
            }


        }
    }
    std::cout << "inds.size() = " << inds.size() << std::endl;
    std::cout << "ctr = " << ctr << std::endl;
}