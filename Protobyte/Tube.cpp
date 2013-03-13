//
//  Tube.cpp
//  Protobyte_iig001
//
//  Created by Ira on 10/17/12.
//
//

#include "Tube.h"

//using namespace ijg;

std::ostream& operator<<(std::ostream& out, const Tube& tube) {
    out << "No Information to report at the moment";
    return out;
}

Tube::Tube(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4, const Spline3& path, float radii[], int crossSectionDetail) : // varied thickness
GeomBase(pos, rot, size, col4), path(path), crossSectionDetail(crossSectionDetail) {
    for (int i = 0; i < path.getVertsLength(); i++) {
        this->radii.push_back(radii[i]);
    }
    init();
}

Tube::Tube(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4, const Spline3& path, float radius, int crossSectionDetail) :
GeomBase(pos, rot, size, col4), path(path), radius(radius), crossSectionDetail(crossSectionDetail) {
    float t = 0;
    for (int i = 0; i < path.getVertsLength(); i++) {
        // ******** don't leave like this ********
        // testing varying radii
        //this->radii.push_back(.5+abs(cos(t+=PI/15))*radius*15);
        this->radii.push_back(radius);
    }
    init();
}

// overrides method in base class

void Tube::calcVerts() {
    // IMPORTANT: ff and vecs NEED to be the same size
    std::vector<FrenetFrame> ff = path.getFrenetFrame(); 
    std::vector<Vector3> vecs = path.getVerts();
    //std::cout << ff.size() << std::endl;

    for (int i = 0; i < ff.size(); i++) {

        // calculate cross-section vertices
        float theta = 0;
        for (int j = 0; j < crossSectionDetail; j++) {
            //float x = cos(th)*(radii[i] + ofRandom(-5, 5)); //bumpy
            //float y = sin(th)*(radii[i] + ofRandom(-5, 5)); //bumpy

            // calculate cross section shape
            float x = cos(theta) * radii[i];
            float y = sin(theta) * radii[i];

            float z = 0;
            theta += M_PI * 2 / crossSectionDetail;

            // transform to Frenet frame of reference
            float px = vecs.at(i+1).x + x * ff.at(i).getN().x + y * ff.at(i).getB().x;
            float py = vecs.at(i+1).y + x * ff.at(i).getN().y + y * ff.at(i).getB().y;
            float pz = vecs.at(i+1).z + x * ff.at(i).getN().z + y * ff.at(i).getB().z;
           // std::cout <<"ff[i].getB() = " << ff[i].getB() << std::endl;
            
            verts.push_back(Vertex(Vector3(px, py, pz), col4));

        }
    }
}



void Tube::calcInds() {
    std::cout << "color.r = " << col4.getR() << std::endl;
    std::cout << "color.g = " << col4.getG() << std::endl;
    std::cout << "color.b = " << col4.getB() << std::endl;
    std::cout << "color.a = " << col4.getA() << std::endl;

    int frameCount = path.getFrenetFrame().size();
    int crossSectionCount = path.getVertsLength();
    // indices
    for (int i = 0; i < frameCount-2/*ringCount*/; i++) {
        for (int j = 0; j < crossSectionDetail/*ringDetail*/; j++) {

            int i0 = i * crossSectionDetail + j;
            int i1 = (i + 1) * crossSectionDetail + j;
            int i2 = i * crossSectionDetail + j + 1;
            int i3 = (i + 1) * crossSectionDetail + j + 1;
            int i4 = j;
            int i5 = i*crossSectionDetail;
            int i6 = crossSectionDetail + j + 1;
            int i7 = (i + 1) * crossSectionDetail;
            int i8 = j + 1;

            if (i < crossSectionCount - 1) {
                if (j < crossSectionDetail - 1) {
                    inds.push_back(Tuple3<int>(i0, i2, i3));
                    inds.push_back(Tuple3<int>(i0, i3, i1));

                } else {
                    // j+1 = 0
                    inds.push_back(Tuple3<int>(i0, i5, i7));
                    inds.push_back(Tuple3<int>(i0, i7, i1));
                }
            } else {
                if (j < crossSectionDetail - 1) {
                    //i+1 = 0
                    inds.push_back(Tuple3<int>(i0, i2, i8));
                    inds.push_back(Tuple3<int>(i0, i8, i4));

                } else {
                    //i+1 =0, j+1 = 0
                    //inds.push_back( Tuple3<int>(i0, i5, 0) );
                    //inds.push_back( Tuple3<int>(i0, 0, i4) );
                }
            }
        }
    }


}

const Spline3& Tube::getPath() const {
    return path;
}