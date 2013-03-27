/* 
 * File:   Tree.cpp
 * Author: ira
 * 
 * Created on March 27, 2013, 11:51 AM
 */

#include "Tree.h"

Tree::Tree() {
}

Tree::Tree(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4) :
GeomBase(pos, rot, size, col4) {
    sproutLimit = 5;
    subBranchCount = Tuple2<int>(2, 2);
    branchDetail = 10;
}

Tree::Tree(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4,
        int sproutLimit, const Tuple2<int>& subBranchCount, int branchDetail) :
GeomBase(pos, rot, size, col4), sproutLimit(sproutLimit), subBranchCount(subBranchCount), 
        branchDetail(branchDetail) {

}

Tree::~Tree() {
}


void Tree::calcVerts(){
    
}


void Tree::calcInds(){
    
}