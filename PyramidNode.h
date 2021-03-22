/*
* Title: Pyramid Node
* Author: Onuralp Avci
* Description: Pyramid node is each item in a pyramid which has an integer value and also left and right children
*/
#ifndef PYRAMIDNODE_H
#define PYRAMIDNODE_H

#include <iostream>
using namespace std;

typedef int PyramidItemType;

class PyramidNode
{
    private:
        PyramidNode();
        ~PyramidNode();
        PyramidNode( const PyramidItemType &nodeItem, PyramidNode* left, PyramidNode* right );

        PyramidItemType item;
        PyramidNode* leftChildPtr;
        PyramidNode* rightChildPtr;
        friend class Pyramid;
    public:
        PyramidNode* getLeftChildPtr();
        PyramidNode* getRightChildPtr();
        void setLeftChildPtr(PyramidNode* left);
        void setRightChildPtr(PyramidNode* right);
};

#endif // PYRAMIDNODE_H