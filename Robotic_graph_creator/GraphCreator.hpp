//
//  GraphCreator.hpp
//  Robotic_graph_creator
//
//  Created by Burak Yeşilyurt on 28/11/15.
//  Copyright © 2015 Burak Yeşilyurt. All rights reserved.
//

#ifndef GraphCreator_hpp
#define GraphCreator_hpp

#include <stdio.h>
#include "Node.hpp"
#include "pgm.h"

class GraphCreator{
private:
    int patternSize;
    int height,width;
    Node** data;
    void makeRelations();
   int makeGroup(int,int,RGB_INT (&array)[800][800]);
public:
    GraphCreator(int);
    void GroupImageWithPattern(PGMstructure& image);
    ~GraphCreator();
};

#endif /* GraphCreator_hpp */
