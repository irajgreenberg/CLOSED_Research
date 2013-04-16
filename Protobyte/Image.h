/* 
 * File:   Image.h
 * Author: 33993405
 *
 * Created on April 14, 2013, 9:30 PM
 */

#ifndef IMAGE_H
#define	IMAGE_H

#include <string>
#include <vector>
#include "Color3.h"
#include "Color4.h"

namespace proto {

    class Image {
    public:
        Image();
        Image(int w, int h);

        void load(const std::string& url);
        


    private:
        std::vector< Color3<unsigned char> > pixels3;
        std::vector< Color4<unsigned char> > pixels4;

    };

}

#endif	/* IMAGE_H */

