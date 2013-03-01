/*!  \brief Tuple3: Templated Tuple
 Tuple3.h
 Protobyte_iig001
 
 
 Created by Ira on 9/5/12.
 Copyright (c) 2012 __MyCompanyName__. All rights reserved.
 
 \ingroup common
 This class is templated to allow for varied single collection types
 This class is part of the group common (update)
 \sa NO LINK
 */

#ifndef Protobyte_iig001_Tuple3_h
#define Protobyte_iig001_Tuple3_h


template <class T>
class Tuple3 {
    
public:
    T elem0, elem1, elem2;
    T elems[3];
    
    
    Tuple3(T elem0 = 0, T elem1 = 0, T elem2 = 0):
    elem0(elem0), elem1(elem1), elem2(elem2) {
        
    }
    
};

#endif
