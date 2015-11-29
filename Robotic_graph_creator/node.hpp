//
//  node.hpp
//  Robotic_graph_creator
//
//  Created by Burak Yeşilyurt on 29/11/15.
//  Copyright © 2015 Burak Yeşilyurt. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

class Node
{
private:
    int number;
    Node *left,*right,*up,*down;
    bool isOccuppied;
    
public:
    Node(int,bool);
    Node(){number =0;isOccuppied=true;};
    int getNumber(){return number;}
    Node* getLeft(){return left;}
    Node* getRight(){return right;}
    Node* getUp(){return up;}
    Node* getDown(){return down;}
    void  setLeft(Node* left){this->left = left;}
    void  setRight(Node* right){this->right = right;}
    void  setUp(Node* up){this->up = up;}
    void  setDown(Node* down){this->down = down;}


    
};


#endif /* node_hpp */
