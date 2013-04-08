/* 
 * File:   Utility.h
 * Author: 33993405
 *
 * Created on April 3, 2013, 5:29 PM
 */

#ifndef UTILITY_H
#define	UTILITY_H

#include <iostream>
#include <fstream>

namespace proto {

    class Utility {
    public:

        Utility() {
        }

        static std::string getStringFromURL(const char* URL) {
            std::ifstream file(URL);
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
        }

    private:

    };

}

#endif	/* UTILITY_H */

