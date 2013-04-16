/* 
 * File:   ConvolveFilter.cpp
 * Author: ira
 * 
 * Created on April 12, 2013, 11:33 AM
 */

#include "ConvolveFilter.h"

using namespace proto;

ConvolveFilter::ConvolveFilter() {
}

// uses default box filter
ConvolveFilter::ConvolveFilter(unsigned char*& data, int w, int h) :
FilterBase(data, w, h) {
    float m[9] = {1, 1, 1, 1, 0, 1, 1, 1, 1};
    mat3 = Matrix3(m);
}

ConvolveFilter::ConvolveFilter(unsigned char*& data, int w, int h, std::vector<int> kernal) :
FilterBase(data, w, h, kernal) {

}

ConvolveFilter::ConvolveFilter(unsigned char*& data, int w, int h, int filterType, int kernalDepth):
   FilterBase(data, w, h, filterType, kernalDepth) {
}

void ConvolveFilter::mult() {

    // convolve filter

    const int _w = w;
    const int _h = h;

    // temp 2d arr of image data
    unsigned char data2D [_w][_h];
    unsigned char result2D [_w][_h];


    for (int i = 0; i < _w; ++i) {
        for (int j = 0; j < _h; ++j) {
            data2D[i][j] = data[i * _h + j];

        }

    }

    unsigned char c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0;
    for (int i = 0; i < _w; i++) {
        for (int j = 0; j < _h; j++) {

            /********
             c0 c1 c2
             c7    c3
             c6 c5 c4 
             ********/
            c0 = data2D[i - 1][j - 3];
            c1 = data2D[i - 1][j];
            c2 = data2D[i - 1][j + 3];
            c3 = data2D[i][j + 3];
            c4 = data2D[i + 1][j + 3];
            c5 = data2D[i + 1][j];
            c6 = data2D[i + 1][j - 3];
            c7 = data2D[i][j - 3];
            // not at left or top or right or bottom edges
            if (i > 0 && i < _w - 3 && j > 2 && j < _h - 3) {
                result2D[i][j] = (data2D[i][j] + c0 + c1 + c2 + c3 + c4 + c5 + c6 + c7) / 9;
            }

        }

    }

}

