//
//  GraphCreator.cpp
//  Robotic_graph_creator
//
//  Created by Burak Yeşilyurt on 28/11/15.
//  Copyright © 2015 Burak Yeşilyurt. All rights reserved.
//

#include "GraphCreator.hpp"
#include <iostream>
#include "Node.hpp"
using namespace std;

GraphCreator::GraphCreator(int patternSize)
{
    this->patternSize = patternSize;
    
    
}
 void GraphCreator::GroupImageWithPattern(PGMstructure& image)
{
    this->width = (image.width/patternSize)+1;
    this->height = (image.height/patternSize)+1;
    
    data = new Node*[height];
    for(int i =0;i<height;i++)
    {
        data[i] = new Node[width];
    }
    
    for(int i =0; i<height; i++)
    {
        for(int j =0; j<width; j++)
        {
            int returnedval =makeGroup(i,j,image.data);
            bool isOccupied =false;
            if(returnedval==0)
                isOccupied = true;
            Node node(((i*width)+j),isOccupied);

            
            data[i][j] = node;
        }
    }
    makeRelations();
}

int GraphCreator::makeGroup(int i, int j, RGB_INT (&array)[800][800] )
{
    for(int a=0;a <patternSize ;a++)
    {
        
        for(int b=0;b<patternSize;b++)
        {
            /*
             I omitted other options which are blue and green, the reason is that if pgm is B/W image file, all value will be either 255 or 0;
             */
           if( array[i*patternSize +a][j*patternSize+b].red == 0) // means this black
           {
               return 0;
           }
        }
    }
    return 255;
}

void GraphCreator::makeRelations(){
    for(int i=0; i<height;i++)
    {
        for (int j=0; j<width; j++) {
            if(i != height-1)
                data[i][j].setDown(&(data[i+1][j]));
            if(i != 0)
                data[i][j].setUp(&(data[i-1][j]));
            if(j != (width-1))
                data[i][j].setRight(&(data[i][j+1]));
            if(j != 0)
                data[i][j].setLeft(&(data[i][j-1]));
                
                
        }
    }
}

GraphCreator::~GraphCreator(){
    for(int i=0;i<height;i++)
    {
        delete [] data[i];
    }
}