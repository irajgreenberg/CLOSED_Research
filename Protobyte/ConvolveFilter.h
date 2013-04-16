/* 
 * File:   ConvolveFilter.h
 * Author: Ira Greenberg
 *
 * Created on April 12, 2013, 11:33 AM
 */

#ifndef CONVOLVEFILTER_H
#define	CONVOLVEFILTER_H

#include "FilterBase.h"
#include <vector>
#include "Matrix3.h"

namespace proto {

    class ConvolveFilter : public FilterBase {
    public:

        /*!
         * Default Constructor */
        ConvolveFilter();

        /*!
         * Constructor
         * Uses default box filter  (all 1's)
         * \params data data to filter
         * \params w width of data
         * \params h height of data*/
        ConvolveFilter(unsigned char*& data, int w, int h);
        
        /*!
         * Constructor 
         * \params data data to filter
         * \params w width of data
         * \params h height of data
         * \std::vector<int> kernal */
        ConvolveFilter(unsigned char*& data, int w, int h, std::vector<int> kernal);
        
        
        /*!
         * Constructor 
         * \params data data to filter
         * \params w width of data
         * \params h height of data
         * \params filterType specify built-in filter
         * \params kernalDepth size of kernal matrix*/
        ConvolveFilter(unsigned char*& data, int w, int h, int filterType, int kernalDepth);


    private:
        /*!
         * Multiplies data by filter. 
         * This function is declared pure virtual in
         * FilterBase and must be implemented here */
        void mult();

        Matrix3 mat3;

    };
}

#endif	/* CONVOLVEFILTER_H */

