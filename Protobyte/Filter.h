/*! \File:   Filter.h
 * Base non-shader class for image and vertex filtering
 * Author: ira
 *
 * Created on April 11, 2013, 9:11 AM
 */

#ifndef FILTER_H
#define	FILTER_H

class Filter {
public:

    /*!
     * Default Constructor */
    Filter();

    /*!
     * Constructor 
     * \params data data to filter
     * \params w width of data
     * \params h height of data*/
    Filter(unsigned char*& data, int w, int h);

    /*!
     * Multiplies data by filter. 
     * This function is declared pure virtual and 
     * must be implemented in a derived class */
    virtual void mult() = 0;

    /*!
     * Default Virtual Constructor */
    virtual ~Filter();

private:
    unsigned char* filteredData;
    int w, h;

};

#endif	/* FILTER_H */

