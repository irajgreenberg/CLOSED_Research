/* 
 * File:   Tree.cpp
 * Author: ira
 * 
 * Created on March 27, 2013, 11:51 AM
 */

#include "Tree.h"

using namespace proto;

Tree::Tree() {
}

Tree::Tree(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4) :
GeomBase(pos, rot, size, col4) {
    sproutLimit = 5;
    subBranchCount = Tuple2<int>(3, 3);
    branchDetail = 10;
    
    init();
}

Tree::Tree(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4,
        int sproutLimit, const Tuple2<int>& subBranchCount, int branchDetail) :
GeomBase(pos, rot, size, col4), sproutLimit(sproutLimit), subBranchCount(subBranchCount), 
        branchDetail(branchDetail) {
    
    init();
}

Tree::~Tree() {
}


void Tree::calcVerts(){
    // draw from base at origin
    
    
}


void Tree::calcInds(){
    
}

void Tree::buildTree(const Vector3& pos, float len){
    treeSplinePath.push_back(Spline3());
    
}