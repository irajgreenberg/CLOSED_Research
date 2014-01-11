/* 
 * File:   Helix.cpp
 * Author: ira
 * 
 * Created on April 30, 2013, 8:46 AM
 */

#include "Helix.h"


using namespace proto;

Helix::Helix() {
}

/*!
 * Constructor */
Helix::Helix(int strandCount, float helixRadius, int strandControlPtCount, int strandInterpolatedPtDetail, int strandPeriods,
        int strandCrossSectionPointCount, float strandRadius, bool isStrandTubeClosed) : GraphicsCore(Vector3(0, 0, 0), Vector3(0, 0, 0), Dimension3f(1, 1, 1), Color4f(1, .6, .5, 1.0)),
strandCount(strandCount), helixRadius(helixRadius), strandControlPtCount(strandControlPtCount), strandInterpolatedPtDetail(strandInterpolatedPtDetail), strandPeriods(strandPeriods),
strandCrossSectionPointCount(strandCrossSectionPointCount), strandRadius(strandRadius), isStrandTubeClosed(isStrandTubeClosed) {

    // init perturbation fields
    periodJitter = 0.0;
    nodeJitter = Vector3(0.0, 0.0, 0.0);
    tubeJitter = 0.0;

    init();

}

/*!
 * Constructor */
Helix::Helix(const Vector3& pos, const Vector3& rot, const Dimension3f size, const Color4f col4,
        int strandCount, float helixRadius, int strandControlPtCount, int strandInterpolatedPtDetail, int strandPeriods, int strandCrossSectionPointCount, float strandRadius, bool isStrandTubeClosed) :
GraphicsCore(pos, rot, size, col4), strandCount(strandCount), helixRadius(helixRadius), strandControlPtCount(strandControlPtCount), strandInterpolatedPtDetail(strandInterpolatedPtDetail), strandPeriods(strandPeriods),
strandCrossSectionPointCount(strandCrossSectionPointCount), strandRadius(strandRadius), isStrandTubeClosed(isStrandTubeClosed) {

    // init perturbation fields
    periodJitter = 0.0;
    nodeJitter = Vector3(0.0, 0.0, 0.0);
    tubeJitter = 0.0;

    init();


}

void Helix::init() {

    if (splines.size() > 0) {
        splines.clear();
    }

    if (tubes.size() > 0) {
        tubes.clear();
    }
    splines.resize(strandCount);
    tubes.resize(strandCount);

    float helixHt = 1.0;
    float theta = 0.0, thetaSpd = 0.0;
    float smoothness = .5;

    std::vector<float> strandRadii;

    for (int i = 0; i < strandCount; ++i) {
        // start at random position around y-axis
        theta = Math::TWO_PI / strandCount*i;
        std::vector<Vector3> cps;
        float x = 0.0, y = -helixHt / 2.0, z = 0.0;
        cps.resize(strandControlPtCount);
        
        thetaSpd  = Math::TWO_PI/strandControlPtCount*(strandPeriods+Math::random(-periodJitter, periodJitter));

        if (strandRadii.size() > 0) {
            strandRadii.clear();
        }

        // create varied radii
        if (isVariedRadii) {
            strandRadii.resize((strandControlPtCount - 1) * strandInterpolatedPtDetail + strandControlPtCount);
            float step = (variedRadii.elem1 - variedRadii.elem0) / (strandRadii.size());
            //            std::cout << "variedRadii.elem0= " << variedRadii.elem0 << std::endl;
            //            std::cout << "variedRadii.elem1= " << variedRadii.elem1 << std::endl;
            //            std::cout << "variedRadii.elem2= " << variedRadii.elem2<< std::endl;
            float theta = 0.0;
            float val = 0.0;
            for (int j = 0; j < strandRadii.size(); ++j) {
                switch (static_cast<int> (variedRadii.elem2)) {
                    case LINEAR:
                        strandRadii.at(j) = variedRadii.elem0 + step*j;
                        //std::cout << "strandRadii.at(j) = " << strandRadii.at(j)<< std::endl;
                        break;
                    case LINEAR_INVERSE:
                        strandRadii.at(j) = variedRadii.elem1 - step*j;
                        break;
                    case SINUSOIDAL:
                        val = variedRadii.elem0 + sin(theta)*(variedRadii.elem1 - variedRadii.elem0);
                        strandRadii.at(j) = val;
                        //std::cout << "theta = " << theta*180.0/Math::PI << std::endl;
                        theta += Math::PI / strandRadii.size();
                        break;
                    case SINUSOIDAL_2:
                        val = variedRadii.elem0 + fabs(sin(theta)*(variedRadii.elem1 - variedRadii.elem0));
                        strandRadii.at(j) = val;
                        theta += Math::TWO_PI / strandRadii.size();
                        break;
                    case SINUSOIDAL_3:
                        val = variedRadii.elem0 + fabs(sin(theta)*(variedRadii.elem1 - variedRadii.elem0));
                        strandRadii.at(j) = val;
                        theta += Math::THREE_PI / strandRadii.size();
                        break;
                    case SINUSOIDAL_4:
                        val = variedRadii.elem0 + fabs(sin(theta)*(variedRadii.elem1 - variedRadii.elem0));
                        strandRadii.at(j) = val;
                        theta += Math::TWO_PI * 2 / strandRadii.size();
                        break;
                    case SINUSOIDAL_5:
                        val = variedRadii.elem0 + fabs(sin(theta)*(variedRadii.elem1 - variedRadii.elem0));
                        strandRadii.at(j) = val;
                        theta += Math::PI * 5 / strandRadii.size();
                        break;
                    case SINUSOIDAL_RAND_5:
                        val = variedRadii.elem0 + fabs(sin(theta)*(variedRadii.elem1 - variedRadii.elem0));
                        strandRadii.at(j) = val;
                        theta += Math::PI * Math::random(1, 5) / strandRadii.size();
                        break;
                    case SINUSOIDAL_RAND_10:
                        val = variedRadii.elem0 + fabs(sin(theta)*(variedRadii.elem1 - variedRadii.elem0));
                        strandRadii.at(j) = val;
                        theta += Math::PI * Math::random(1, 10) / strandRadii.size();
                        break;
                    case SINUSOIDAL_RAND_15:
                        val = variedRadii.elem0 + fabs(sin(theta)*(variedRadii.elem1 - variedRadii.elem0));
                        strandRadii.at(j) = val;
                        theta += Math::PI * Math::random(1, 15) / strandRadii.size();
                        break;
                    case SINUSOIDAL_RAND_20:
                        val = variedRadii.elem0 + fabs(sin(theta)*(variedRadii.elem1 - variedRadii.elem0));
                        strandRadii.at(j) = val;
                        theta += Math::PI * Math::random(1, 20) / strandRadii.size();
                        break;
                    case SINUSOIDAL_RAND_25:
                        val = variedRadii.elem0 + fabs(sin(theta)*(variedRadii.elem1 - variedRadii.elem0));
                        strandRadii.at(j) = val;
                        theta += Math::PI * Math::random(1, 25) / strandRadii.size();
                        break;
                    case SINUSOIDAL_RAND_30:
                        val = variedRadii.elem0 + fabs(sin(theta)*(variedRadii.elem1 - variedRadii.elem0));
                        strandRadii.at(j) = val;
                        theta += Math::PI * Math::random(1, 30) / strandRadii.size();
                        break;
                    case SINUSOIDAL_RAND_35:
                        val = variedRadii.elem0 + fabs(sin(theta)*(variedRadii.elem1 - variedRadii.elem0));
                        strandRadii.at(j) = val;
                        theta += Math::PI * Math::random(1, 25) / strandRadii.size();
                        break;
                    case SINUSOIDAL_RAND_40:
                        val = variedRadii.elem0 + fabs(sin(theta)*(variedRadii.elem1 - variedRadii.elem0));
                        strandRadii.at(j) = val;
                        theta += Math::PI * Math::random(1, 40) / strandRadii.size();
                        break;



                }

            }
        }


        for (int j = 0; j < strandControlPtCount; ++j) {
            //std::cout << "Math::random(-nodeJitter.z, nodeJitter.z) = " << Math::random(-nodeJitter.z, nodeJitter.z) << std::endl;
            z = cos(theta) * (helixRadius + Math::random(-nodeJitter.z, nodeJitter.z));
            x = sin(theta) * (helixRadius + Math::random(-nodeJitter.x, nodeJitter.x));
            y += helixHt / (strandControlPtCount + Math::random(-nodeJitter.y, nodeJitter.y)); 
            cps.at(j) = Vector3(x, y, z);
           // std::cout << "cps.at(j)" << cps.at(j) << std::endl;
            theta += thetaSpd;
        }
        splines.at(i) = Spline3(cps, strandInterpolatedPtDetail, true, smoothness);
        if (isVariedRadii) {
            if (isStrandTubeClosed) {
                tubes.at(i) = Tube(pos, rot, size, col4, splines.at(i), strandRadii, strandCrossSectionPointCount, true);
            } else {
                tubes.at(i) = Tube(pos, rot, size, col4, splines.at(i), strandRadii, strandCrossSectionPointCount, false);
            }
            // use straight strandRadius
        } else {
            if (isStrandTubeClosed) {
                tubes.at(i) = Tube(pos, rot, size, col4, splines.at(i), strandRadius, strandCrossSectionPointCount, true);
            } else {
                tubes.at(i) = Tube(pos, rot, size, col4, splines.at(i), strandRadius, strandCrossSectionPointCount, false);
            }
        }

    }
   // tubes.at(0).exportSTL();

}

void Helix::display(GeomBase::displayMode mode, GeomBase::renderMode render, float pointSize) {

    for (int i = 0; i < tubes.size(); ++i) {
        tubes.at(i).display(mode, render, pointSize);
    }

}


