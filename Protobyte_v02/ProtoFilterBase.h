/*! \File:   FilterBase.h
 * Base non-shader filtering class for 
 * image and vertex manipulation
 * Author: Ira Greenberg
 *
 * Created on April 11, 2013, 9:11 AM
 */

#ifndef FILTERBASE_H
#define	FILTERBASE_H

#include <vector>

namespace proto {

    class FilterBase {
    public:

        /*!
         * Default Constructor */
        FilterBase();

        /*!
         * Constructor 
         * \params data data to filter
         * \params w width of data
         * \params h height of data*/
        FilterBase(unsigned char*& data, int w, int h);
        
        /*!
         * Constructor 
         * \params data data to filter
         * \params w width of data
         * \params h height of data
         * \std::vector<int> kernal */
        FilterBase(unsigned char*& data, int w, int h, const std::vector<int>& kernal);

        /*!
         * Constructor 
         * \params data data to filter
         * \params w width of data
         * \params h height of data
         * \params filterType specify built-in filter
         * \params kernalDepth size of kernal matrix*/
        FilterBase(unsigned char*& data, int w, int h, int filterType, int kernalDepth);


        /*!
         * Default Virtual Constructor */
        virtual ~FilterBase();


        /*!
         * Filter constants for pre-builts */
        static int const BLUR = 0;
        static int const SHARPEN = 1;
        static int const EMBOSS = 2;
        static int const EDGES = 3;
        static int const MOTION_BLUR = 4;


    protected:
        unsigned char* data;
        int w, h;
        int filterType;
        int kernalDepth;
        std::vector<int> kernal;

        /*!
         * Multiplies data by filter. 
         * This function is declared pure virtual and 
         * must be implemented in a derived class */
        virtual void mult() = 0;
        
    };
}

#endif	/* FILTERBASE_H */

