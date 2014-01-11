/*!  \brief  ProtoUtility2.cpp: 
 Utility class, all static functions, includes i/o
 ProtoUtility2.cpp
 Protobyte Library v02
 
 Created by Ira on 9/14/13.
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
 This class is part of the group common (update)
 \sa NO LINK
 */

#include "ProtoUtility.h"

using namespace ijg;


// static function implementations

std::string ProtoUtility::getBuildPath(){
    
    // 1. ensure path is to resources directory
    char cCurrentPath[FILENAME_MAX];
    
    if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
    {
        std::cout << "error loading from relative directory" << std::endl;
        //return errno;
    }
    // NOTE - make workspace project relative instead of using default derivedData path in Library
    //std::cout << "cCurrentPath = " << cCurrentPath << std::endl;
    cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
    std::string cp = cCurrentPath; //cast char[] to string
    
    return cp;
}

// get string from file (char* URL input)
std::string ProtoUtility::load(const char* data) {
    std::ifstream file(data);
    std::string line, block;
    if (file.is_open()) {
        
        while (!file.eof()) {
            std::getline(file, line);
            block.append(line);
            block.append(std::string("\n"));
        }
        file.close();
        return block;
    } else {
        std::cout << "Unable to open file";
    }
    // never reached - added to squelch ide warning
    return 0;
}





// get string from file (string URL input)
const std::string ProtoUtility::load(std::string data){
    const char *charData = data.c_str();
    return load(charData);
}

// loads image data in .raw format
void ProtoUtility::load(const std::string& url, int w, int h, unsigned char* data) {
    
    FILE * file;
    
    // open texture data
    file = fopen(url.c_str(), "rb");
    if (file == NULL) std::cout << "no file data";
    
    // read texture data
    fread(data, w * h * 3, 1, file);
    fclose(file);
    
}



