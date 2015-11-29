//
//  node.cpp
//  Robotic_graph_creator
//
//  Created by Burak Yeşilyurt on 29/11/15.
//  Copyright © 2015 Burak Yeşilyurt. All rights reserved.
//

#include "Node.hpp"
#include <iostream>

using namespace std;

Node::Node(int number, bool isOccuppied)
{
    left = NULL;
    right = NULL;
    up = NULL;
    down = NULL;
    this->number = number;
    this->isOccuppied = isOccuppied;
    
}
