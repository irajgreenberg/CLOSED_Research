/*! \
 * File:   Nematode.h
 * Author: Ira Greenberg
 *
 * Created on July 18, 2013, 1:55 PM
 * Copyright (c) 2013 Ira Greenberg. All rights reserved.
 */

#ifndef NEMATODE_H
#define	NEMATODE_H

#include "Tube.h"

namespace proto {

    class Nematode: public GraphicsCore {
    public:
        /*!
         * Default Constructor */
        Nematode();
 
        Nematode(const Vector3& pos, const Vector3& rot, const Dimension3f& size,
                const Color4f& col4, const Tube& tube);

        virtual ~Nematode();

    private:
        Tube tube;
        
        void init();

    };

}

#endif	/* NEMATODE_H */

