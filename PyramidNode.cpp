/*
* Title: Pyramid Node
* Author: Onuralp Avci
* Description: Pyramid node is each item in a pyramid which has an integer value and also left and right children
*/
#include "PyramidNode.h"
#include <iostream>
using namespace std;

typedef int PyramidItemType;

PyramidNode::PyramidNode(){}
PyramidNode::~PyramidNode(){}

PyramidNode::PyramidNode( const PyramidItemType &nodeItem, PyramidNode* left, PyramidNode* right )
{
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
}

//Return the left child pointer of the node
PyramidNode* PyramidNode::getLeftChildPtr(){
    return leftChildPtr;
};
//Returns the right child pointer of the node
PyramidNode* PyramidNode::getRightChildPtr(){
    return rightChildPtr;
};

//It sets the left child pointer
void PyramidNode::setLeftChildPtr(PyramidNode* left){
    leftChildPtr = left;
};
//It sets the right child pointer
void PyramidNode::setRightChildPtr(PyramidNode* right){
    rightChildPtr = right;
};