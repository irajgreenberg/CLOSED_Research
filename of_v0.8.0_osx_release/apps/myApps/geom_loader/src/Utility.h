/*!  \brief  ProtoUtility.h: 
 Utility class, all static functions, includes i/o
 // Common ProtoUtlity::load(data) interface
 ProtoShader.h
 Protobyte Library v02
 
 Created by Ira on 7/23/13.
 Copyright (c) 2013 Ira Greenberg. All rights reserved.
 
 Library Usage:
 This work is licensed under the Creative Commons
 Attribution-NonCommercial-ShareAlike 3.0 Unported License.
 To view a copy of this license, visit
 http://creativecommons.org/licenses/by-nc-sa/3.0/
 or send a letter to Creative Commons,
 444 Castro Street, Suite 900,
 Mountain View, California, 94041, USA.
 
 This notice must be retained any source distribution.
 
 \ingroup common
 This class is templated to allow for varied single collection types
 This class is part of the group common (update)
 \sa NO LINK
 */

#ifndef PROTO_UTILITY_H
#define	PROTO_UTILITY_H

#include <string>
#include <iostream>
#include <fstream>

// for image path to file
#include <unistd.h>
#define GetCurrentDir getcwd

namespace ijg {

    class ProtoUtility {
    public:

        static std::string getBuildPath();
        
        /** string handling **/
        // load char*
        static std::string load(const char* data);
        
        // load string
        static const std::string load(std::string str);
        
        
        /** image handling **/
        // loads image data in .raw format
        static void load(const std::string& url, int w, int h, unsigned char* data);

    private:
        // prevent construction
        ProtoUtility();

    };

}

#endif	/* UTILITY_H */

