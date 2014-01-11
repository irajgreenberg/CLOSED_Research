/* 
 * File:   utilityFunctions.h
 * Author: Ira Greenberg
 *
 * Created on April 16, 2013, 9:31 AM
 */

#ifndef UTILITYFUNCTIONS_H
#define	UTILITYFUNCTIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

namespace proto {

    void loadRaw(const std::string& url, int w, int h, unsigned char* data) {

      
        FILE * file;

        // open texture data
        file = fopen(url.c_str(), "rb");
        if (file == NULL) std::cout << "no file data";

        // read texture data
        fread(data, w * h * 3, 1, file);
        fclose(file);

    }
}

#endif	/* UTILITYFUNCTIONS_H */

