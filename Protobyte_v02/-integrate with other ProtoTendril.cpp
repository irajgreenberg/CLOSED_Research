//
//  Tube.cpp
//  Protobyte_iig001
//
//  Created by Ira on 10/17/12.
//
//

#include "Tube.h"
#include "Block.h"

using namespace proto;

namespace proto {
    
    float breathTheta = 0.0;
    
    std::ostream& operator<<(std::ostream& out, const Tube& tube) {
        out << "\n\tpos = " << tube.pos << "\n" << ""
        "\trot = " << tube.rot << "\n" <<
        "\tsize = " << tube.size << "\n" <<
        "\tcol4 = " << tube.col4 << "\n" <<
        "\tradius = " << tube.radius << "\n" <<
        "\tcrossSectionDetail = " << tube.crossSectionDetail << "\n" <<
        "\tisClosed = " << tube.isClosed << "\n" <<
        "\tfrenetFrameLength = " << tube.frenetFrameLength << "\n" <<
        "\tspd = " << tube.spd << "\n" <<
        "\trotSpd = " << tube.rotSpd << "\n" <<
        "\tisTransformFunction = " << tube.isTransformFunction;
        
        return out;
    }
}

// default cstr

Tube::Tube() {
    std::cout << "Tube CSTR default" << std::endl;
}

// overloaded cstr 1

Tube::Tube(const Spline3& path, float radius, int crossSectionDetail, bool isClosed) :
GeomBase(Vector3(0, 0, 0), Vector3(0, 0, 0), Dimension3f(1, 1, 1), Color4f(.5, .5, .5, 1.0)), path(path), radius(radius), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 1" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
        col4s.push_back(col4);
    }
    
    
    
    
    
    
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

/*!
 * Constructor 02
 * with TransformFunction object*/
Tube::Tube(const Spline3& path, float radius, int crossSectionDetail, const TransformFunction& transFuncObj, bool isClosed) :
GeomBase(Vector3(0, 0, 0), Vector3(0, 0, 0), Dimension3f(1, 1, 1), Color4f(.5, .5, .5, 1.0)), path(path), radius(radius), crossSectionDetail(crossSectionDetail), transFuncObj(transFuncObj), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 2" << std::endl;
    setIsTransformFunction(true);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
        col4s.push_back(col4);
    }
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

// Constructor 03

Tube::Tube(const Spline3& path, std::vector<float>& radii, int crossSectionDetail, const TransformFunction& transFuncObj, bool isClosed) :
GeomBase(Vector3(0, 0, 0), Vector3(0, 0, 0), Dimension3f(1, 1, 1), Color4f(.5, .5, .5, 1.0)), path(path), radii(radii), crossSectionDetail(crossSectionDetail), transFuncObj(transFuncObj), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 3" << std::endl;
    setIsTransformFunction(true);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    for (int i = 0; i < path.getVertsLength(); i++) {
        //radii.push_back(radius);
        col4s.push_back(col4);
    }
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

/*!
 * Constructor 04
 * varied thickness*/
Tube::Tube(const Spline3& path, std::vector<float>& radii, int crossSectionDetail, bool isClosed) :
GeomBase(Vector3(0, 0, 0), Vector3(0, 0, 0), Dimension3f(1, 1, 1), Color4f(.5, .5, .5, 1.0)), path(path), radii(radii), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 4" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    for (int i = 0; i < path.getVertsLength(); i++) {
        col4s.push_back(col4);
    }
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

/*!
 * Constructor 05
 * varied color*/
Tube::Tube(const std::vector<Color4f>& col4s, const Spline3& path, float radius, int crossSectionDetail, bool isClosed) :
GeomBase(Vector3(0, 0, 0), Vector3(0, 0, 0), Dimension3f(1, 1, 1), col4s), path(path), radius(radius), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 5" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
    }
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

/*!
 * Constructor 06
 * varied color and TransformFunction object*/
Tube::Tube(const std::vector<Color4f>& col4s, const Spline3& path, float radius, int crossSectionDetail, const TransformFunction& transFuncObj, bool isClosed) :
GeomBase(Vector3(0, 0, 0), Vector3(0, 0, 0), Dimension3f(1, 1, 1), col4s), path(path), radius(radius), crossSectionDetail(crossSectionDetail), transFuncObj(transFuncObj), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 6" << std::endl;
    setIsTransformFunction(true);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
    }
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

/*!
 * Constructor 07
 * varied thickness and color */
Tube::Tube(const std::vector< Color4f >& col4s, const Spline3& path, std::vector<float>& radii, int crossSectionDetail, bool isClosed) :
GeomBase(Vector3(0, 0, 0), Vector3(0, 0, 0), Dimension3f(1, 1, 1), col4s), path(path), radii(radii), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 7" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

/*!
 * Constructor 08
 * All */
Tube::Tube(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, const Spline3& path, float radius, int crossSectionDetail, bool isClosed) :
GeomBase(pos, rot, size, col4), path(path), radius(radius), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 8" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
        col4s.push_back(col4);
    }
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

/*!
 * Constructor 09
 * varied thickness */
Tube::Tube(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, const Spline3& path, std::vector<float>& radii, int crossSectionDetail, bool isClosed) : // varied thickness
GeomBase(pos, rot, size, col4), path(path), radii(radii), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 9" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    for (int i = 0; i < path.getVertsLength(); i++) {
        col4s.push_back(col4);
    }
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

/*!
 * Constructor 10
 * varied color */
Tube::Tube(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
           const std::vector<Color4f>& col4s, const Spline3& path, float radius, int crossSectionDetail, bool isClosed) : // varied color
GeomBase(pos, rot, size, col4s), path(path), radius(radius), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 10" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
    }
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

/*!
 * Constructor 11
 * varied thickness and color */
Tube::Tube(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
           const std::vector<Color4f>& col4s, const Spline3& path, std::vector<float>& radii,
           int crossSectionDetail, bool isClosed) : // varied thickness & color
GeomBase(pos, rot, size, col4s), path(path), radii(radii), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 11" << std::endl;
    
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

/*!
 * Constructor 12
 * All with TransformFunction obj*/
Tube::Tube(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const Color4f& col4, const Spline3& path, float radius, int crossSectionDetail, const TransformFunction& transFuncObj, bool isClosed) : GeomBase(pos, rot, size, col4), path(path), radius(radius), crossSectionDetail(crossSectionDetail), transFuncObj(transFuncObj), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 12" << std::endl;
    setIsTransformFunction(true);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
        col4s.push_back(col4);
    }
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

/*!
 * Constructor 13
 * all with varied color and TransformFunction obj */
Tube::Tube(const Vector3& pos, const Vector3& rot, const Dimension3f& size, const std::vector<Color4f>& col4s, const Spline3& path, float radius, int crossSectionDetail, const TransformFunction& transFuncObj, bool isClosed) : GeomBase(pos, rot, size, col4s), path(path), radius(radius), crossSectionDetail(crossSectionDetail), transFuncObj(transFuncObj), isClosed(isClosed) {
    
    std::cout << "Tube CSTR 13" << std::endl;
    setIsTransformFunction(true);
    perturbation.x = perturbation.y = perturbation.z = 0.0;
    
    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
    }
    // set default live states on
    setIsSlithering(1);
    setIsBreathing(1);
    init();
}

Tube::~Tube() {
    std::cout << "in Tube destructor" << std::endl;
}

// overrides method in base class

void Tube::calcVerts() {
    // NOTE: ff and vecs are not the same size
    ff = path.getFrenetFrame();
    std::vector<Vector3> vecs = path.getVerts();
    frenetFrameLength = ff.size();
    //std::cout << ff.size() << std::endl;
    
    // prepare verts vector
    verts.clear();
    verts.resize(frenetFrameLength * crossSectionDetail + 2);
    
    // top and bottom vec to enable tube caps
    Vector3 topCapVec, bottomCapVec;
    // std::cout << "frenetFrameLength = " << frenetFrameLength << std::endl;
    
    
    float step = 0;
    Vector3 step_xyz, randomStep_xyz;
    float randomStep_x = 0.0;
    float randomStep_y = 0.0;
    float x = 0.0, y = 0.0;
    float phi = 0.0;
    
    //one additional convenience position vector for VerletSpline
    std::vector<Vector3> vSplineVecs;
    
    
    for (int i = 0; i < frenetFrameLength; i++) {
        
        // calculate cross-section vertices
        float theta = Math::PI / 4;
        
        // only calculate if necessary
        if (getIsTransformFunction()) {
            
            step_xyz.x = (transFuncObj.getVectorRange().elem1.x - transFuncObj.getVectorRange().elem0.x) / frenetFrameLength;
            step_xyz.y = (transFuncObj.getVectorRange().elem1.y - transFuncObj.getVectorRange().elem0.y) / frenetFrameLength;
            
            randomStep_x = Math::random(transFuncObj.getVectorRange().elem0.x, transFuncObj.getVectorRange().elem1.x);
            randomStep_y = Math::random(transFuncObj.getVectorRange().elem0.y, transFuncObj.getVectorRange().elem1.y);
            
        }
        
        
        vSplineVecs.push_back(vecs.at(i));
        
        for (int j = 0; j < crossSectionDetail; j++) {
            
            // customize tube based on transform function
            if (getIsTransformFunction()) {
                
                switch (transFuncObj.getFunctionType()) {
                    case TransformFunction::LINEAR:
                        //step_xyz.x = (transFuncObj.getVectorRange().elem1.x - transFuncObj.getVectorRange().elem0.x) / frenetFrameLength;
                        //step_xyz.y = (transFuncObj.getVectorRange().elem1.y - transFuncObj.getVectorRange().elem0.y) / frenetFrameLength;
                        x = cos(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.x + step_xyz.x * i + Math::random(-perturbation.x, perturbation.x));
                        y = sin(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.y + step_xyz.y * i + Math::random(-perturbation.y, perturbation.y));
                        break;
                    case TransformFunction::LINEAR_INVERSE:
                        //step_xyz.x = (transFuncObj.getVectorRange().elem1.x - transFuncObj.getVectorRange().elem0.x) / frenetFrameLength;
                        //step_xyz.y = (transFuncObj.getVectorRange().elem1.y - transFuncObj.getVectorRange().elem0.y) / frenetFrameLength;
                        x = cos(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem1.x - step_xyz.x * i + Math::random(-perturbation.x, perturbation.x));
                        y = sin(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem1.y - step_xyz.y * i + Math::random(-perturbation.y, perturbation.y));
                        break;
                    case TransformFunction::SINUSOIDAL:
                        //step = fabs(sin(phi) * (transFuncObj.getScalerRange().elem1 - transFuncObj.getScalerRange().elem0));
                        step_xyz.x = fabs(sin(phi) * (transFuncObj.getVectorRange().elem1.x - transFuncObj.getVectorRange().elem0.x));
                        step_xyz.y = fabs(sin(phi) * (transFuncObj.getVectorRange().elem1.y - transFuncObj.getVectorRange().elem0.y));
                        //std::cout << "phi = " << phi << std::endl;
                        x = cos(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.x + step_xyz.x + Math::random(-perturbation.x, perturbation.x));
                        y = sin(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.y + step_xyz.y + Math::random(-perturbation.y, perturbation.y));
                        
                        break;
                    case TransformFunction::SINUSOIDAL_INVERSE:
                        //step = fabs(sin(phi) * (transFuncObj.getScalerRange().elem1 - transFuncObj.getScalerRange().elem0));
                        step_xyz.x = fabs(sin(Math::HALF_PI - phi) * (transFuncObj.getVectorRange().elem1.x - transFuncObj.getVectorRange().elem0.x));
                        step_xyz.y = fabs(sin(Math::HALF_PI - phi) * (transFuncObj.getVectorRange().elem1.y - transFuncObj.getVectorRange().elem0.y));
                        //std::cout << "phi = " << phi << std::endl;
                        x = cos(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.x + step_xyz.x + Math::random(-perturbation.x, perturbation.x));
                        y = sin(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.y + step_xyz.y + Math::random(-perturbation.y, perturbation.y));
                        
                        break;
                        //                    case TransformFunction::SINUSOIDAL_TRANSFORM_RANDOM:
                        //                        x = cos(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.x + randomStep_x);
                        //                        y = sin(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.y + randomStep_y);
                        //                        break;
                        //default:
                };
                
                // no transform function
            } else {
                x = cos(theta) * (radii.at(i) + Math::random(-perturbation.x, perturbation.x));
                y = sin(theta) * (radii.at(i) + Math::random(-perturbation.y, perturbation.y));
            }
            
            // calculate cross section shape
            // TO DO: add param for ribbon asymmetry (radius per axis)
            //float x = cos(theta) * radii.at(i) * step*i; //*10;
            //float y = sin(theta) * radii.at(i) * step*i;
            // std::cout << "radii.at(" << i << ") = " << radii.at(i) << std::endl;
            
            
            float z = Math::random(-perturbation.z, perturbation.z);
            theta += M_PI * 2 / crossSectionDetail;
            
            // transform to Frenet frame of reference
            float px = vecs.at(i + 1).x + x * ff.at(i).getN().x + y * ff.at(i).getB().x;
            float py = vecs.at(i + 1).y + x * ff.at(i).getN().y + y * ff.at(i).getB().y;
            float pz = vecs.at(i + 1).z + x * ff.at(i).getN().z + y * ff.at(i).getB().z;
            // std::cout <<"ff[i].getB() = " << ff[i].getB() << std::endl;
            
            //             std::cout << "vecs.at(i + 1) = " << vecs.at(i + 1) << std::endl;
            //             std::cout << " ff.at(i).getN() = " <<  ff.at(i).getN() << std::endl;
            //             std::cout << "ff.at(i).getB() = " << ff.at(i).getB() << std::endl;
            //             std::cout << "Vector3(px, py, pz).at(" << i << ") = " << Vector3(px, py, pz) << std::endl;
            verts.at(i * crossSectionDetail + j) = Vertex(Vector3(px, py, pz), col4s.at(i));
            
            
            // get centroid of top and bottom cross-section for caps
            if (i == 0)
                topCapVec += Vector3(px, py, pz);
            else if (i == ff.size() - 1)
                bottomCapVec += Vector3(px, py, pz);
            
        }
        
        // only calculate if necessary
        if (getIsTransformFunction()) {
            phi += Math::PI / frenetFrameLength * transFuncObj.getPeriodCount();
        }
    }
    
    // finish getting top and bottom cap centroid vecs.
    topCapVec /= crossSectionDetail;
    bottomCapVec /= crossSectionDetail;
    
    // add cap centroids to verts.
    verts.at(verts.size() - 2) = Vertex(topCapVec, col4s.at(0));
    verts.at(verts.size() - 1) = Vertex(bottomCapVec, col4s.at(frenetFrameLength - 1));
    
    
    
    // calculate all cross-section centroids - used by transforamtions such as breath()
    std::vector<Vector3> centerPts(frenetFrameLength);
    crossSectionCentroids.resize(frenetFrameLength);
    
    
    // std::cout << "crossSectionDetail = " << crossSectionDetail << std::endl;
    
    for (int i = 0; i < frenetFrameLength; i++) {
        float cx = 0, cy = 0, cz = 0;
        for (int j = 0; j < crossSectionDetail; j++) {
            cx += verts.at(i * crossSectionDetail + j).pos.x;
            cy += verts.at(i * crossSectionDetail + j).pos.y;
            cz += verts.at(i * crossSectionDetail + j).pos.z;
            //            std::cout << "cx = " << cx << std::endl;
            //            std::cout << "cy = " << cy << std::endl;
            //            std::cout << "cz = " << cz << std::endl;
        }
        cx /= crossSectionDetail;
        cy /= crossSectionDetail;
        cz /= crossSectionDetail;
        crossSectionCentroids.at(i) = Vector3(cx, cy, cz);
        
    }
    
    
    // setup VerletSystem. Perhaps this should be st via a flag to avoid wasted memory use
    //    verletSys = VerletSys(crossSectionCentroids, .5);
    //    verletSys.start();
    //    verletSys.nudge(Vector3(Math::random(-.002, .002), 0, 0), 10);
    
    
    // TESTING ONLY !!!!!
    /*vBalls.reserve(4);
     vSticks.reserve(6);
     // testingVerts.reserve(frenetFrameLength);
     //for (int i = 0; i < 100; i++) {
     vBalls.push_back(Vector3(.1, .1, 0));
     vBalls.push_back(Vector3(-.1, .1, 0));
     vBalls.push_back(Vector3(-.1, -.1, 0));
     vBalls.push_back(Vector3(.1, -.1, 0));
     //}
     
     vSticks.push_back(VerletStick(&vBalls[0], &vBalls[1], .01));
     vSticks.push_back(VerletStick(&vBalls[1], &vBalls[2], .01));
     vSticks.push_back(VerletStick(&vBalls[2], &vBalls[3], .01));
     vSticks.push_back(VerletStick(&vBalls[3], &vBalls[0], .01));
     vSticks.push_back(VerletStick(&vBalls[0], &vBalls[2], .01));
     vSticks.push_back(VerletStick(&vBalls[1], &vBalls[3], .01));
     vBalls.at(0).pos += Vector3(.0005, .0005, .0005);*/
    
    //    vbs[0] = VerletBall(Vector3(.1, .1, 0));
    //    vbs[1] = VerletBall(Vector3(-.1, .1, 0));
    //    vbs[2] = VerletBall(Vector3(-.1, -.1, 0));
    //    vbs[3] = VerletBall(Vector3(.1, -.1, 0));
    //
    //
    //    vss[0] = VerletStick(&vbs[0], &vbs[1], .01);
    //    vss[1] = VerletStick(&vbs[1], &vbs[2], .01);
    //    vss[2] = VerletStick(&vbs[2], &vbs[3], .01);
    //    vss[3] = VerletStick(&vbs[3], &vbs[0], .01);
    //    vss[4] = VerletStick(&vbs[0], &vbs[2], .01);
    //    vss[5] = VerletStick(&vbs[1], &vbs[3], .01);
    //    vbs[0].pos += .001;
    
    //const std::vector<Vector3>& vecs, float tension
    vSpine = VerletSpine(vSplineVecs, .1, VerletSpine::BOTH);
    for (int i = 1; i < vSplineVecs.size() - 1; ++i) {
        if (i % 12 == 0) {
            vSpine.nudge(Vector3(Math::random(-.02, .02), Math::random(-.02, .02), Math::random(-.02, .02)), i);
        }
    }
    
    //vSpine.start();
    
}

void Tube::calcInds() {
    
    // indices
    for (int i = 0; i < frenetFrameLength; i++) {
        for (int j = 0; j < crossSectionDetail; j++) {
            
            int i0 = i * crossSectionDetail + j;
            int i1 = (i + 1) * crossSectionDetail + j;
            int i2 = i * crossSectionDetail + j + 1;
            int i3 = (i + 1) * crossSectionDetail + j + 1;
            int i4 = j;
            int i5 = i*crossSectionDetail;
            int i6 = crossSectionDetail + j + 1;
            int i7 = (i + 1) * crossSectionDetail;
            int i8 = j + 1;
            
            
            if (i < frenetFrameLength - 1) {
                if (j < crossSectionDetail - 1) {
                    
                    // top cap
                    if (i == 0 && isClosed) {
                        inds.push_back(Tuple3<int>(i2, i0, verts.size() - 2));
                    }
                    
                    // tube body
                    inds.push_back(Tuple3<int>(i0, i2, i3));
                    inds.push_back(Tuple3<int>(i0, i3, i1));
                    
                    // close tube
                } else {
                    
                    // top cap
                    if (i == 0 && isClosed) {
                        inds.push_back(Tuple3<int>(i5, i0, verts.size() - 2));
                    }
                    
                    // tube body
                    inds.push_back(Tuple3<int>(i0, i5, i7));
                    inds.push_back(Tuple3<int>(i0, i7, i1));
                }
            } else if (i == frenetFrameLength - 1 && isClosed) {
                // close bottom cap
                if (j < crossSectionDetail - 1) {
                    inds.push_back(Tuple3<int>(i0, i2, verts.size() - 1));
                } else {
                    inds.push_back(Tuple3<int>(i0, i5, verts.size() - 1));
                }
            }
        }
    }
}

// Example that animates FPO data
// uses: glBindBuffer(data), glBufferSubData(), glBindBuffer(0)

void Tube::rotateY() {
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    float t = Math::PI / 360.0;
    for (int i = 0; i < interleavedPrims.size(); i += 12) {
        float x = 0;
        //float y = 0;
        float z = 0;
        float nx = 0;
        //float ny = 0;
        float nz = 0;
        
        /*z' = z*cos q - x*sin q
         x' = z*sin q + x*cos q
         */
        // verts
        z = cos(t) * interleavedPrims.at(i + 2) - sin(t) * interleavedPrims.at(i);
        x = sin(t) * interleavedPrims.at(i + 2) + cos(t) * interleavedPrims.at(i);
        interleavedPrims.at(i + 2) = z;
        interleavedPrims.at(i) = x;
        
        //vnorms
        nz = cos(t) * interleavedPrims.at(i + 5) - sin(t) * interleavedPrims.at(i + 3);
        nx = sin(t) * interleavedPrims.at(i + 5) + cos(t) * interleavedPrims.at(i + 3);
        interleavedPrims.at(i + 5) = nz;
        interleavedPrims.at(i + 3) = nx;
        
    }
    int vertsDataSize = sizeof (float) *interleavedPrims.size();
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertsDataSize, &interleavedPrims[0]); // upload the data
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/* TEST ONLY */
//void Tube::verlet() {
//    // VERLET TESTING ONLY
//    // Draw vballs for testing purposes
//    vbs[0].pos += Math::random(-.002, .002);
//    glBegin(GL_QUADS);
//    for (int i = 0; i < 4; i++) {
//        glVertex3f(vbs[i].pos.x, vbs[i].pos.y, vbs[i].pos.z);
//    }
//
//
//    for (int i = 0; i < 4; ++i) {
//        vbs[i].verlet();
//    }
//
//    for (int i = 0; i < 6; ++i) {
//        vss[i].constrainLen();
//    }
//    glEnd();
//    // END TESTING
//
//}

/***********************************************************
 * Functions below animate VBO data using glBufferSubData()
 **********************************************************/

//void Tube::breath() {
//
//
//
//    // we're going to update data in VBO, woo-hoo!
//    glBindBuffer(GL_ARRAY_BUFFER, vboID);
//
//    for (int i = 0; i < frenetFrameLength; i++) {
//        for (int j = 0; j < crossSectionDetail; j++) {
//
//            // get each vector (delta) between each cross-section vertex and cross-section centroid making up tube
//            Vector3 deltaVec = (verts.at(i * crossSectionDetail + j).pos - crossSectionCentroids.at(i));
//            Vector3 biasVec = verts.at(i * crossSectionDetail + j).pos;
//            float dst = 1.0 / biasVec.mag()*.04;
//
//            deltaVec.normalize();
//            deltaVec *= .13 * dst;
//            //std::cout << "deltaVec = " << deltaVec << std::endl;
//            // sin wave with each pts relative pos (to (0,0,0) as wave amplitude.
//            float sx = fabs(sin(breathTheta)) * deltaVec.x;
//            float sy = fabs(sin(breathTheta)) * deltaVec.y;
//            float sz = fabs(sin(breathTheta)) * deltaVec.z;
//            int index = crossSectionDetail * 12 * i + 12 * j;
//            interleavedPrims.at(index) = verts.at(i * crossSectionDetail + j).pos.x + sx;
//            interleavedPrims.at(index + 1) = verts.at(i * crossSectionDetail + j).pos.y + sy;
//            interleavedPrims.at(index + 2) = verts.at(i * crossSectionDetail + j).pos.z + sz;
//
//            //std::cout << i << " tube x = " << interleavedPrims.at(crossSectionDetail * 12 * i + 12 * j) << std::endl;
//            //std::cout << "s = " << s << std::endl;
//
//            //vnorms
//            /*nz = cos(t) * interleavedPrims.at(i + 5) - sin(t) * interleavedPrims.at(i + 3);
//            nx = sin(t) * interleavedPrims.at(i + 5) + cos(t) * interleavedPrims.at(i + 3);
//            interleavedPrims.at(i + 5) = nz;
//            interleavedPrims.at(i + 3) = nx;*/
//        }
//
//    }
//    breathTheta += Math::PI / 180.0 * 1.25;
//
//    int vertsDataSize = sizeof (float) *interleavedPrims.size();
//    glBufferSubData(GL_ARRAY_BUFFER, 0, vertsDataSize, &interleavedPrims[0]); // upload the data
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//
//
//}
//
//void Tube::wave() {
//    static float theta3 = 0.0;
//    static int frameCount = 0;
//    frameCount++;
//    vSpine.run();
//    if (frameCount == 2) {
//        //vSpine.nudge(Vector3(.002, 0, 0 ), 0);
//        // std::cout << "balls.at(0)->getPos() = " << vSpine.getBalls().at(0)->getPos() << std::endl;
//    }
//    //vSpine.nudge(Vector3(sin(theta3)*.0002, sin(theta3)*.0002, sin(-theta3)*.0002), 5);
//    //vSpine.nudge(Vector3(cos(theta3)*.0002, cos(theta3)*.0002, cos(-theta3)*.0002), 15);
//    //vSpine.nudge(Vector3(sin(theta3)*.0002, sin(theta3)*.0002, sin(-theta3)*.0002), 25);
//    //vSpine.nudge(
//
//    //    //verletSys.nudge(Vector3(Math::random(-.002, .002), 0, 0), 10);
//    //
//    //    //std::vector<VerletBall> balls = verletSys.getBalls();
//    //    //verletSys.run();
//    //    //std::cout << "balls.at(0).getPos() = " << verletSys.getBalls().at(0).getPos() << std::endl;
//    glBindBuffer(GL_ARRAY_BUFFER, vboID);
//
//    for (int i = 0; i < frenetFrameLength; i++) {
//        //vSpine.nudge(Vector3(Math::random(-.0002, .0002), Math::random(-.0002, .0002), Math::random(-.0002, .0002)), i);
//
//        //balls.at(i * crossSectionDetail + j)->pos.y += sin(theta3)*.01;
//        //vSpine.nudge(Vector3(sin(theta3)*.01, 0, 0));
//
//        Vector3 shift = vSpine.getBalls().at(i)->getPos();
//        for (int j = 0; j < crossSectionDetail; j++) {
//
//
//
//            int index = crossSectionDetail * 12 * i + 12 * j;
//
//
//            interleavedPrims.at(index) = verts.at(i * crossSectionDetail + j).pos.x + vSpine.getBalls().at(i)->pos.x; // shift.x;
//            interleavedPrims.at(index + 1) = verts.at(i * crossSectionDetail + j).pos.y + vSpine.getBalls().at(i)->pos.y; // shift.y;
//            interleavedPrims.at(index + 2) = verts.at(i * crossSectionDetail + j).pos.z + vSpine.getBalls().at(i)->pos.z; // shift.z;
//
//        }
//        //shift *= .1;
//
//
//    }
//    theta3 += Math::PI / 180;
//
//    int vertsDataSize = sizeof (float) *interleavedPrims.size();
//    glBufferSubData(GL_ARRAY_BUFFER, 0, vertsDataSize, &interleavedPrims[0]); // upload the data
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//
//    //    for (int i = 0; i < vBalls.size(); i++) {
//    //
//    //
//    //        vBalls.at(i).verlet();
//    //
//    //        if (i > 0) {
//    //            vSticks.at(i - 1).constrainLen();
//    //        }
//    //    }
//
//}

void Tube::live() {
    
    
    // we're going to update data in VBO, woo-hoo!
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    
    float breathX = 0.0;
    float breathY = 0.0;
    float breathZ = 0.0;
    
    static float slitherTheta = 0.0; // not used
    static int frameCount = 0;
    frameCount++;
    vSpine.run(); // start Verleting
    
    
    for (int i = 0; i < frenetFrameLength; i++) {
        Vector3 shift = vSpine.getBalls().at(i)->getPos();
        for (int j = 0; j < crossSectionDetail; j++) {
            
            
            if (isBreathing) {
                // get each vector (delta) between each cross-section vertex and cross-section centroid making up tube
                Vector3 deltaVec = (verts.at(i * crossSectionDetail + j).pos - crossSectionCentroids.at(i));
                Vector3 biasVec = verts.at(i * crossSectionDetail + j).pos;
                float dst = 1.0 / biasVec.mag()*.04;
                
                deltaVec.normalize();
                deltaVec *= .13 * dst;
                //std::cout << "deltaVec = " << deltaVec << std::endl;
                // sin wave with each pts relative pos (to (0,0,0) as wave amplitude.
                breathX = fabs(sin(breathTheta)) * deltaVec.x;
                breathY = fabs(sin(breathTheta)) * deltaVec.y;
                breathZ = fabs(sin(breathTheta)) * deltaVec.z;
                
            }
            
            int index = crossSectionDetail * 12 * i + 12 * j;
            if (isSlithering) {
                interleavedPrims.at(index) = verts.at(i * crossSectionDetail + j).pos.x + vSpine.getBalls().at(i)->pos.x + breathX; // shift.x;
                interleavedPrims.at(index + 1) = verts.at(i * crossSectionDetail + j).pos.y + vSpine.getBalls().at(i)->pos.y + breathY; // shift.y;
                interleavedPrims.at(index + 2) = verts.at(i * crossSectionDetail + j).pos.z + vSpine.getBalls().at(i)->pos.z + breathZ; // shift.z;
            } else {
                int index = crossSectionDetail * 12 * i + 12 * j;
                interleavedPrims.at(index) = verts.at(i * crossSectionDetail + j).pos.x + breathX;
                interleavedPrims.at(index + 1) = verts.at(i * crossSectionDetail + j).pos.y + breathY;
                interleavedPrims.at(index + 2) = verts.at(i * crossSectionDetail + j).pos.z + breathZ;
                
            }
            
        }
        
    }
    breathTheta += Math::PI / 180.0 * 1.25;
    slitherTheta += Math::PI / 180; // not used
    
    int vertsDataSize = sizeof (float) *interleavedPrims.size();
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertsDataSize, &interleavedPrims[0]); // upload the data
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}