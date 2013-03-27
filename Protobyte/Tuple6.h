/*!  \brief Tuple6: Templated Tuple
 Tuple6.h
 Protobyte Library
 
 
 Created on 3/27/13.
 Copyright (c) 2012 Ira Greenberg. All rights reserved.
 
 \ingroup common
 This class is templated to allow for varied single collection types
 This class is part of the group common (update)
 \sa NO LINK
 */

#ifndef Protobyte_Library_Tuple6_h
#define Protobyte_Library_Tuple6_h


template <class T>
class Tuple6 {
    
public:
    T elem0, elem1, elem2, elem3, elem4, elem5;
    T elems[6];
    
    
    Tuple6(T elem0 = 0, T elem1 = 0, T elem2 = 0, T elem3 = 0, T elem4 = 0, T elem5 = 0):
    elem0(elem0), elem1(elem1), elem2(elem2), elem3(elem3), elem4(elem4), elem5(elem5) {
        
    }
    
};

#endif
