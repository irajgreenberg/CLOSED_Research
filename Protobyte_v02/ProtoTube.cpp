//
//  ProtoTube.cpp
//  Protobyte_iig001
//
//  Created by Ira on 10/17/12.
//
//

#include "ProtoTube.h"
#include "ProtoBlock.h"



namespace ijg {

    float breathTheta = 0.0;

    std::ostream& operator<<(std::ostream& out, const ProtoTube& tube) {
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

using namespace ijg;

// default cstr

ProtoTube::ProtoTube() {
    std::cout << "ProtoTube CSTR default" << std::endl;
}

// overloaded cstr 1

ProtoTube::ProtoTube(const ProtoSpline3& path, float radius, int crossSectionDetail, bool isClosed) :
ProtoGeom3(Vec3f(0, 0, 0), Vec3f(0, 0, 0), ProtoDimension3f(1, 1, 1), ProtoColor4f(.5, .5, .5, 1.0)), path(path), radius(radius), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 1" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
        col4s.push_back(col4);
    }






    // set default live states on
//    setIsSlithering(1);
//    setIsBreathing(1);
    init();
}

/*!
 * Constructor 02
 * with TransformFunction object*/
ProtoTube::ProtoTube(const ProtoSpline3& path, float radius, int crossSectionDetail, const ProtoTransformFunction& transFuncObj, bool isClosed) :
ProtoGeom3(Vec3f(0, 0, 0), Vec3f(0, 0, 0), ProtoDimension3f(1, 1, 1), ProtoColor4f(.5, .5, .5, 1.0)), path(path), radius(radius), crossSectionDetail(crossSectionDetail), transFuncObj(transFuncObj), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 2" << std::endl;
    setIsTransformFunction(true);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
        col4s.push_back(col4);
    }
    // set default live states on
//    setIsSlithering(1);
//    setIsBreathing(1);
    init();
}

// Constructor 03

ProtoTube::ProtoTube(const ProtoSpline3& path, std::vector<float>& radii, int crossSectionDetail, const ProtoTransformFunction& transFuncObj, bool isClosed) :
ProtoGeom3(Vec3f(0, 0, 0), Vec3f(0, 0, 0), ProtoDimension3f(1, 1, 1), ProtoColor4f(.5, .5, .5, 1.0)), path(path), radii(radii), crossSectionDetail(crossSectionDetail), transFuncObj(transFuncObj), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 3" << std::endl;
    setIsTransformFunction(true);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    for (int i = 0; i < path.getVertsLength(); i++) {
        //radii.push_back(radius);
        col4s.push_back(col4);
    }
    // set default live states on
//    setIsSlithering(1);
//    setIsBreathing(1);
    init();
}

/*!
 * Constructor 04
 * varied thickness*/
ProtoTube::ProtoTube(const ProtoSpline3& path, std::vector<float>& radii, int crossSectionDetail, bool isClosed) :
ProtoGeom3(Vec3f(0, 0, 0), Vec3f(0, 0, 0), ProtoDimension3f(1, 1, 1), ProtoColor4f(.5, .5, .5, 1.0)), path(path), radii(radii), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 4" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    for (int i = 0; i < path.getVertsLength(); i++) {
        col4s.push_back(col4);
    }
    // set default live states on
//    setIsSlithering(1);
//    setIsBreathing(1);
    init();
}

/*!
 * Constructor 05
 * varied color*/
ProtoTube::ProtoTube(const std::vector<ProtoColor4f>& col4s, const ProtoSpline3& path, float radius, int crossSectionDetail, bool isClosed) :
ProtoGeom3(Vec3f(0, 0, 0), Vec3f(0, 0, 0), ProtoDimension3f(1, 1, 1), col4s), path(path), radius(radius), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 5" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
    }
    // set default live states on
//    setIsSlithering(1);
//    setIsBreathing(1);
    init();
}

/*!
 * Constructor 06
 * varied color and TransformFunction object*/
ProtoTube::ProtoTube(const std::vector<ProtoColor4f>& col4s, const ProtoSpline3& path, float radius, int crossSectionDetail, const ProtoTransformFunction& transFuncObj, bool isClosed) :
ProtoGeom3(Vec3f(0, 0, 0), Vec3f(0, 0, 0), ProtoDimension3f(1, 1, 1), col4s), path(path), radius(radius), crossSectionDetail(crossSectionDetail), transFuncObj(transFuncObj), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 6" << std::endl;
    setIsTransformFunction(true);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
    }
    // set default live states on
//    setIsSlithering(1);
//    setIsBreathing(1);
    init();
}

/*!
 * Constructor 07
 * varied thickness and color */
ProtoTube::ProtoTube(const std::vector< ProtoColor4f >& col4s, const ProtoSpline3& path, std::vector<float>& radii, int crossSectionDetail, bool isClosed) :
ProtoGeom3(Vec3f(0, 0, 0), Vec3f(0, 0, 0), ProtoDimension3f(1, 1, 1), col4s), path(path), radii(radii), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 7" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    // set default live states on
//    setIsSlithering(1);
//    setIsBreathing(1);
    init();
}

/*!
 * Constructor 08
 * All */
ProtoTube::ProtoTube(const Vec3f& pos, const Vec3f& rot, const ProtoDimension3f& size, const ProtoColor4f& col4, const ProtoSpline3& path, float radius, int crossSectionDetail, bool isClosed) :
ProtoGeom3(pos, rot, size, col4), path(path), radius(radius), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 8" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
        col4s.push_back(col4);
    }
    // set default live states on
//    setIsSlithering(1);
//    setIsBreathing(1);
    init();
}

/*!
 * Constructor 09
 * varied thickness */
ProtoTube::ProtoTube(const Vec3f& pos, const Vec3f& rot, const ProtoDimension3f& size, const ProtoColor4f& col4, const ProtoSpline3& path, std::vector<float>& radii, int crossSectionDetail, bool isClosed) : // varied thickness
ProtoGeom3(pos, rot, size, col4), path(path), radii(radii), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 9" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    for (int i = 0; i < path.getVertsLength(); i++) {
        col4s.push_back(col4);
    }
    // set default live states on
//    setIsSlithering(1);
//    setIsBreathing(1);
    init();
}

/*!
 * Constructor 10
 * varied color */
ProtoTube::ProtoTube(const Vec3f& pos, const Vec3f& rot, const ProtoDimension3f& size,
        const std::vector<ProtoColor4f>& col4s, const ProtoSpline3& path, float radius, int crossSectionDetail, bool isClosed) : // varied color
ProtoGeom3(pos, rot, size, col4s), path(path), radius(radius), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 10" << std::endl;
    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
    }
    // set default live states on
//    setIsSlithering(1);
//    setIsBreathing(1);
    init();
}

/*!
 * Constructor 11
 * varied thickness and color */
ProtoTube::ProtoTube(const Vec3f& pos, const Vec3f& rot, const ProtoDimension3f& size,
        const std::vector<ProtoColor4f>& col4s, const ProtoSpline3& path, std::vector<float>& radii,
        int crossSectionDetail, bool isClosed) : // varied thickness & color
ProtoGeom3(pos, rot, size, col4s), path(path), radii(radii), crossSectionDetail(crossSectionDetail), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 11" << std::endl;

    // no transform function
    setIsTransformFunction(false);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    // set default live states on
//    setIsSlithering(1);
//    setIsBreathing(1);
    init();
}

/*!
 * Constructor 12
 * All with TransformFunction obj*/
ProtoTube::ProtoTube(const Vec3f& pos, const Vec3f& rot, const ProtoDimension3f& size, const ProtoColor4f& col4, const ProtoSpline3& path, float radius, int crossSectionDetail, const ProtoTransformFunction& transFuncObj, bool isClosed) : ProtoGeom3(pos, rot, size, col4), path(path), radius(radius), crossSectionDetail(crossSectionDetail), transFuncObj(transFuncObj), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 12" << std::endl;
    setIsTransformFunction(true);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
        col4s.push_back(col4);
    }
    // set default live states on
    //setIsSlithering(1);
    //setIsBreathing(1);
    init();
}

/*!
 * Constructor 13
 * all with varied color and TransformFunction obj */
ProtoTube::ProtoTube(const Vec3f& pos, const Vec3f& rot, const ProtoDimension3f& size, const std::vector<ProtoColor4f>& col4s, const ProtoSpline3& path, float radius, int crossSectionDetail, const ProtoTransformFunction& transFuncObj, bool isClosed) : ProtoGeom3(pos, rot, size, col4s), path(path), radius(radius), crossSectionDetail(crossSectionDetail), transFuncObj(transFuncObj), isClosed(isClosed) {

    std::cout << "ProtoTube CSTR 13" << std::endl;
    setIsTransformFunction(true);
    perturbation.x = perturbation.y = perturbation.z = 0.0;

    for (int i = 0; i < path.getVertsLength(); i++) {
        radii.push_back(radius);
    }
    // set default live states on
   // setIsSlithering(1);
   // setIsBreathing(1);
    init();
}

ProtoTube::~ProtoTube() {
    std::cout << "in ProtoTube destructor" << std::endl;
}

// overrides method in base class

void ProtoTube::calcVerts() {
    // NOTE: ff and vecs are not the same size
    ff = path.getFrenetFrames();
    std::vector<Vec3f> vecs = path.getVerts();
    frenetFrameLength = static_cast<int>(ff.size());
    //std::cout << ff.size() << std::endl;

    // prepare verts vector
    verts.clear();
    verts.resize(frenetFrameLength * crossSectionDetail + 2);

    // top and bottom vec to enable tube caps
    Vec3f topCapVec, bottomCapVec;
    // std::cout << "frenetFrameLength = " << frenetFrameLength << std::endl;


    //float step = 0;
    Vec3f step_xyz, randomStep_xyz;
    float randomStep_x = 0.0;
    float randomStep_y = 0.0;
    float x = 0.0, y = 0.0;
    float phi = 0.0;

    //one additional convenience position vector for VerletProtoSpline
    std::vector<Vec3f> vProtoSplineVecs;


    for (int i = 0; i < frenetFrameLength; i++) {

        // calculate cross-section vertices
        float theta = ProtoMath::PI / 4;

        // only calculate if necessary
        if (getIsTransformFunction()) {
            //std::cout << "in random getTransformed section" << std::endl;
            step_xyz.x = (transFuncObj.getVectorRange().elem1.x - transFuncObj.getVectorRange().elem0.x) / frenetFrameLength;
            step_xyz.y = (transFuncObj.getVectorRange().elem1.y - transFuncObj.getVectorRange().elem0.y) / frenetFrameLength;

            randomStep_x = ProtoMath::random(transFuncObj.getVectorRange().elem0.x, transFuncObj.getVectorRange().elem1.x);
            randomStep_y = ProtoMath::random(transFuncObj.getVectorRange().elem0.y, transFuncObj.getVectorRange().elem1.y);

        }


        vProtoSplineVecs.push_back(vecs.at(i));

        for (int j = 0; j < crossSectionDetail; j++) {

            // customize tube based on transform function
            if (getIsTransformFunction()) {

                switch (transFuncObj.getFunctionType()) {
                    case ProtoTransformFunction::LINEAR:
                        //step_xyz.x = (transFuncObj.getVectorRange().elem1.x - transFuncObj.getVectorRange().elem0.x) / frenetFrameLength;
                        //step_xyz.y = (transFuncObj.getVectorRange().elem1.y - transFuncObj.getVectorRange().elem0.y) / frenetFrameLength;
                        x = cos(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.x + step_xyz.x * i + ProtoMath::random(-perturbation.x, perturbation.x));
                        y = sin(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.y + step_xyz.y * i + ProtoMath::random(-perturbation.y, perturbation.y));
                        break;
                    case ProtoTransformFunction::LINEAR_INVERSE:
                        //step_xyz.x = (transFuncObj.getVectorRange().elem1.x - transFuncObj.getVectorRange().elem0.x) / frenetFrameLength;
                        //step_xyz.y = (transFuncObj.getVectorRange().elem1.y - transFuncObj.getVectorRange().elem0.y) / frenetFrameLength;
                        x = cos(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem1.x - step_xyz.x * i + ProtoMath::random(-perturbation.x, perturbation.x));
                        y = sin(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem1.y - step_xyz.y * i + ProtoMath::random(-perturbation.y, perturbation.y));
                        break;
                    case ProtoTransformFunction::SINUSOIDAL:
                        //step = fabs(sin(phi) * (transFuncObj.getScalerRange().elem1 - transFuncObj.getScalerRange().elem0));
                        step_xyz.x = fabs(sin(phi) * (transFuncObj.getVectorRange().elem1.x - transFuncObj.getVectorRange().elem0.x));
                        step_xyz.y = fabs(sin(phi) * (transFuncObj.getVectorRange().elem1.y - transFuncObj.getVectorRange().elem0.y));
                        //std::cout << "phi = " << phi << std::endl;
                        x = cos(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.x + step_xyz.x + ProtoMath::random(-perturbation.x, perturbation.x));
                        y = sin(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.y + step_xyz.y + ProtoMath::random(-perturbation.y, perturbation.y));

                        break;
                    case ProtoTransformFunction::SINUSOIDAL_INVERSE:
                        //step = fabs(sin(phi) * (transFuncObj.getScalerRange().elem1 - transFuncObj.getScalerRange().elem0));
                        step_xyz.x = fabs(sin(ProtoMath::HALF_PI - phi) * (transFuncObj.getVectorRange().elem1.x - transFuncObj.getVectorRange().elem0.x));
                        step_xyz.y = fabs(sin(ProtoMath::HALF_PI - phi) * (transFuncObj.getVectorRange().elem1.y - transFuncObj.getVectorRange().elem0.y));
                        //std::cout << "phi = " << phi << std::endl;
                        x = cos(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.x + step_xyz.x + ProtoMath::random(-perturbation.x, perturbation.x));
                        y = sin(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.y + step_xyz.y + ProtoMath::random(-perturbation.y, perturbation.y));

                        break;
                        //                    case TransformFunction::SINUSOIDAL_TRANSFORM_RANDOM:
                        //                        x = cos(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.x + randomStep_x);
                        //                        y = sin(theta) * radii.at(i) * (transFuncObj.getVectorRange().elem0.y + randomStep_y);
                        //                        break;
                        //default:
                };

                // no transform function
            } else {
                x = cos(theta) * (radii.at(i) + ProtoMath::random(-perturbation.x, perturbation.x));
                y = sin(theta) * (radii.at(i) + ProtoMath::random(-perturbation.y, perturbation.y));
            }

            // calculate cross section shape
            // TO DO: add param for ribbon asymmetry (radius per axis)
            //float x = cos(theta) * radii.at(i) * step*i; //*10;
            //float y = sin(theta) * radii.at(i) * step*i;
            // std::cout << "radii.at(" << i << ") = " << radii.at(i) << std::endl;


            float z = ProtoMath::random(-perturbation.z, perturbation.z);
            theta += ProtoMath::PI * 2 / crossSectionDetail;

            // transform to Frenet frame of reference
            float px = vecs.at(i + 1).x + x * ff.at(i).getN().x + y * ff.at(i).getB().x;
            float py = vecs.at(i + 1).y + x * ff.at(i).getN().y + y * ff.at(i).getB().y;
            float pz = vecs.at(i + 1).z + x * ff.at(i).getN().z + y * ff.at(i).getB().z;
            // std::cout <<"ff[i].getB() = " << ff[i].getB() << std::endl;

            //             std::cout << "vecs.at(i + 1) = " << vecs.at(i + 1) << std::endl;
            //             std::cout << " ff.at(i).getN() = " <<  ff.at(i).getN() << std::endl;
            //             std::cout << "ff.at(i).getB() = " << ff.at(i).getB() << std::endl;
            //             std::cout << "Vec3f(px, py, pz).at(" << i << ") = " << Vec3f(px, py, pz) << std::endl;
            verts.at(i * crossSectionDetail + j) = ProtoVertex3(Vec3f(px, py, pz), col4s.at(i));
            //std::cout << "Vec3f(px, py, pz).at(" << i << ") = " << Vec3f(px, py, pz) << std::endl;
            
            //std::cout << "perturbation = " << perturbation << std::endl;


            // get centroid of top and bottom cross-section for caps
            if (i == 0)
                topCapVec += Vec3f(px, py, pz);
            else if (i == ff.size() - 1)
                bottomCapVec += Vec3f(px, py, pz);

        }

        // only calculate if necessary
        if (getIsTransformFunction()) {
            phi += ProtoMath::PI / frenetFrameLength * transFuncObj.getPeriodCount();
        }
    }

    // finish getting top and bottom cap centroid vecs.
    topCapVec /= crossSectionDetail;
    bottomCapVec /= crossSectionDetail;

    // add cap centroids to verts.
    verts.at(verts.size() - 2) = ProtoVertex3(topCapVec, col4s.at(0));
    verts.at(verts.size() - 1) = ProtoVertex3(bottomCapVec, col4s.at(frenetFrameLength - 1));



    // calculate all cross-section centroids - used by transforamtions such as breath()
    std::vector<Vec3f> centerPts(frenetFrameLength);
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
        crossSectionCentroids.at(i) = Vec3f(cx, cy, cz);

    }


    // setup VerletSystem. Perhaps this should be st via a flag to avoid wasted memory use
    //    verletSys = VerletSys(crossSectionCentroids, .5);
    //    verletSys.start();
    //    verletSys.nudge(Vec3f(ProtoMath::random(-.002, .002), 0, 0), 10);


    // TESTING ONLY !!!!!
    /*vBalls.reserve(4);
    vSticks.reserve(6);
    // testingVerts.reserve(frenetFrameLength);
    //for (int i = 0; i < 100; i++) {
    vBalls.push_back(Vec3f(.1, .1, 0));
    vBalls.push_back(Vec3f(-.1, .1, 0));
    vBalls.push_back(Vec3f(-.1, -.1, 0));
    vBalls.push_back(Vec3f(.1, -.1, 0));
    //}

    vSticks.push_back(VerletStick(&vBalls[0], &vBalls[1], .01));
    vSticks.push_back(VerletStick(&vBalls[1], &vBalls[2], .01));
    vSticks.push_back(VerletStick(&vBalls[2], &vBalls[3], .01));
    vSticks.push_back(VerletStick(&vBalls[3], &vBalls[0], .01));
    vSticks.push_back(VerletStick(&vBalls[0], &vBalls[2], .01));
    vSticks.push_back(VerletStick(&vBalls[1], &vBalls[3], .01));
    vBalls.at(0).pos += Vec3f(.0005, .0005, .0005);*/

    //    vbs[0] = VerletBall(Vec3f(.1, .1, 0));
    //    vbs[1] = VerletBall(Vec3f(-.1, .1, 0));
    //    vbs[2] = VerletBall(Vec3f(-.1, -.1, 0));
    //    vbs[3] = VerletBall(Vec3f(.1, -.1, 0));
    //
    //
    //    vss[0] = VerletStick(&vbs[0], &vbs[1], .01);
    //    vss[1] = VerletStick(&vbs[1], &vbs[2], .01);
    //    vss[2] = VerletStick(&vbs[2], &vbs[3], .01);
    //    vss[3] = VerletStick(&vbs[3], &vbs[0], .01);
    //    vss[4] = VerletStick(&vbs[0], &vbs[2], .01);
    //    vss[5] = VerletStick(&vbs[1], &vbs[3], .01);
    //    vbs[0].pos += .001;

    //const std::vector<Vec3f>& vecs, float tension
//    vSpine = VerletSpine(vProtoSplineVecs, .1, VerletSpine::BOTH);
//    for (int i = 1; i < vProtoSplineVecs.size() - 1; ++i) {
//        if (i % 12 == 0) {
//            vSpine.nudge(Vec3f(ProtoMath::random(-.02, .02), ProtoMath::random(-.02, .02), ProtoMath::random(-.02, .02)), i);
//        }
//    }

    //vSpine.start();
    
}

void ProtoTube::calcInds() {

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
                        inds.push_back(ProtoTuple3<int>(i2, i0, static_cast<int>(verts.size()) - 2));
                    }

                    // tube body
                    inds.push_back(ProtoTuple3<int>(i0, i2, i3));
                    inds.push_back(ProtoTuple3<int>(i0, i3, i1));

                    // close tube
                } else {

                    // top cap
                    if (i == 0 && isClosed) {
                        inds.push_back(ProtoTuple3<int>(i5, i0, static_cast<int>(verts.size()) - 2));
                    }

                    // tube body
                    inds.push_back(ProtoTuple3<int>(i0, i5, i7));
                    inds.push_back(ProtoTuple3<int>(i0, i7, i1));
                }
            } else if (i == frenetFrameLength - 1 && isClosed) {
                // close bottom cap
                if (j < crossSectionDetail - 1) {
                    inds.push_back(ProtoTuple3<int>(i0, i2, static_cast<int>(verts.size()) - 1));
                } else {
                    inds.push_back(ProtoTuple3<int>(i0, i5, static_cast<int>(verts.size()) - 1));
                }
            }
        }
    }
}

// Example that animates FPO data
// uses: glBindBuffer(data), glBufferSubData(), glBindBuffer(0)

void ProtoTube::rotateY() {
//    glBindBuffer(GL_ARRAY_BUFFER, vboID);
//    float t = ProtoMath::PI / 360.0;
//    for (int i = 0; i < interleavedPrims.size(); i += 12) {
//        float x = 0;
//        //float y = 0;
//        float z = 0;
//        float nx = 0;
//        //float ny = 0;
//        float nz = 0;
//
//        // verts
//        z = cos(t) * interleavedPrims.at(i + 2) - sin(t) * interleavedPrims.at(i);
//        x = sin(t) * interleavedPrims.at(i + 2) + cos(t) * interleavedPrims.at(i);
//        interleavedPrims.at(i + 2) = z;
//        interleavedPrims.at(i) = x;
//
//        //vnorms
//        nz = cos(t) * interleavedPrims.at(i + 5) - sin(t) * interleavedPrims.at(i + 3);
//        nx = sin(t) * interleavedPrims.at(i + 5) + cos(t) * interleavedPrims.at(i + 3);
//        interleavedPrims.at(i + 5) = nz;
//        interleavedPrims.at(i + 3) = nx;
//
//    }
//    int vertsDataSize = sizeof (float) *interleavedPrims.size();
//    glBufferSubData(GL_ARRAY_BUFFER, 0, vertsDataSize, &interleavedPrims[0]); // upload the data
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

