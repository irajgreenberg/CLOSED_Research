/*!  \brief Tuple2: Templated Tuple
 Tuple2.h
 Protobyte_iig001
 
 
 Created by Ira on 9/5/12.
 Copyright (c) 2012 __MyCompanyName__. All rights reserved.
 
 \ingroup common
 This class is templated to allow for varied single collection types
 This class is part of the group common (update)
 \sa NO LINK
 */

#ifndef Protobyte_iig001_Tuple2_h
#define Protobyte_iig001_Tuple2_h


template <class T>
class Tuple2 {
    
public:
    T elem0, elem1;
    T elems[2];
    
    
    Tuple2(T elem0 = 0, T elem1 = 0):
    elem0(elem0), elem1(elem1) {
        
    }
    
};

#endif
