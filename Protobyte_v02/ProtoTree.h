/*! \brief Class to generate simple tree forms
 * Author: Ira Greenberg
 *
 * Created on March 27, 2013, 11:51 AM
 */


#ifndef TREE_H
#define	TREE_H


#include <iostream>
#include "GeomBase.h"
#include "Tuple2.h"
//#include "Tuple6.h"
#include "Spline3.h"

namespace proto {

    class Tree : public GeomBase {
    public:
        friend std::ostream& operator<<(std::ostream& out, const Tree& tree);


        /*!
         * Default Constructor */
        Tree();

        /*!
         * Constructor */
        Tree(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4);

        /*!
         * Constructor */
        Tree(const Vector3& pos, const Vector3& rot, const Dimension3<float> size, const Color4<float> col4,
                int sproutLimit, const Tuple2<int>& subBranchCount, int branchDetail);

        /*!
         * Destructor */
        virtual ~Tree();

        /*!
         * Declared pure virtual in GeomBase base class
         * and must be implemented in all derived classes.
         * 
         * Generates all vertices.*/
        void calcVerts();

        /*!
         * Recursive function constructs tree.
         * \params pos Position of new branch
         * \params len Length of new branch*/
        void buildTree(const Vector3& pos, float len);

        /*!
         * Declared pure virtual in GeomBase base class
         * and must be implemented in all derived classes: 
         * 
         * Generates indices to group vertices to triangle faces.*/
        void calcInds();

        /* Begin setters/getters, inlined below class */
        void setSproutTaperJitter(Tuple2<float> sproutTaperJitter);
        Tuple2<float> getSproutTaperJitter() const;
        void setSproutTaper(float sproutTaper);
        float getSproutTaper() const;
        //void setBranchJitter(Tuple6<float> branchJitter);
        //Tuple6<float> getBranchJitter() const;
        void setBranchRadialJitter(Tuple2<float> branchRadialJitter);
        Tuple2<float> getBranchRadialJitter() const;
        void setTreeSplinePath(std::vector<Spline3> treeSplinePath);
        std::vector<Spline3> getTreeSplinePath() const;
        void setBranchDetail(int branchDetail);
        int getBranchDetail() const;
        void setSubBranchCount(Tuple2<int> subBranchCount);
        Tuple2<int> getSubBranchCount() const;
        void setSproutLimit(int sproutLimit);
        int getSproutLimit() const;
        void setBranchAttenuatorJitter(Tuple2<float> branchAttenuatorJitter);
        Tuple2<float> getBranchAttenuatorJitter() const;
        void setBranchAttenuator(float branchAttenuator);
        float getBranchAttenuator() const;


    private:
        /*! Overall sprouting limit of tree
         * Default = 5 */
        int sproutLimit;

        /*! Max/Min branch count per each new sprout.
         * Default = 3 */
        Tuple2<int> subBranchCount;

        /*! Number of points describing branches
         * Default = 10 */
        int branchDetail;

        /*! Vector of splines describing overall tree structure*/
        std::vector<Spline3> treeSplinePath;

        /*! Max/Min factors to randomly perturb branch radii */
        Tuple2<float> branchRadialJitter;

        /*! Max/Min factors to randomly perturb overall branch geometry */
        //Tuple6<float> branchJitter;

        /*! Factor tapering successive sprouts */
        float sproutTaper;

        /*! Max/Min factors to randomly perturb sprout taper */
        Tuple2<float> sproutTaperJitter;

        /*! Factor attenuating successive branches */
        float branchAttenuator;

        /*! Max/Min factors to randomly perturb branch attenuations */
        Tuple2<float> branchAttenuatorJitter;

    };

    /* inlined getters and setters */
    inline void Tree::setSproutTaperJitter(Tuple2<float> sproutTaperJitter) {
        this->sproutTaperJitter = sproutTaperJitter;
    }

    inline Tuple2<float> Tree::getSproutTaperJitter() const {
        return sproutTaperJitter;
    }

    inline void Tree::setSproutTaper(float sproutTaper) {
        this->sproutTaper = sproutTaper;
    }

    inline float Tree::getSproutTaper() const {
        return sproutTaper;
    }

    /*inline void Tree::setBranchJitter(Tuple6<float> branchJitter) {
        this->branchJitter = branchJitter;
    }

    inline Tuple6<float> Tree::getBranchJitter() const {
        return branchJitter;
    }*/

    inline void Tree::setBranchRadialJitter(Tuple2<float> branchRadialJitter) {
        this->branchRadialJitter = branchRadialJitter;
    }

    inline Tuple2<float> Tree::getBranchRadialJitter() const {
        return branchRadialJitter;
    }

    inline void Tree::setTreeSplinePath(std::vector<Spline3> treeSplinePath) {
        this->treeSplinePath = treeSplinePath;
    }

    inline std::vector<Spline3> Tree::getTreeSplinePath() const {
        return treeSplinePath;
    }

    inline void Tree::setBranchDetail(int branchDetail) {
        this->branchDetail = branchDetail;
    }

    inline int Tree::getBranchDetail() const {
        return branchDetail;
    }

    inline void Tree::setSubBranchCount(Tuple2<int> subBranchCount) {
        this->subBranchCount = subBranchCount;
    }

    inline Tuple2<int> Tree::getSubBranchCount() const {
        return subBranchCount;
    }

    inline void Tree::setSproutLimit(int sproutLimit) {
        this->sproutLimit = sproutLimit;
    }

    inline int Tree::getSproutLimit() const {
        return sproutLimit;
    }

    inline void Tree::setBranchAttenuatorJitter(Tuple2<float> branchAttenuatorJitter) {
        this->branchAttenuatorJitter = branchAttenuatorJitter;
    }

    inline Tuple2<float> Tree::getBranchAttenuatorJitter() const {
        return branchAttenuatorJitter;
    }

    inline void Tree::setBranchAttenuator(float branchAttenuator) {
        this->branchAttenuator = branchAttenuator;
    }

    inline float Tree::getBranchAttenuator() const {
        return branchAttenuator;
    }

#endif	/* TREE_H */
}