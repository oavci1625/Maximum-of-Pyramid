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

PyramidNode* PyramidNode::getLeftChildPtr(){
    return leftChildPtr;
};
PyramidNode* PyramidNode::getRightChildPtr(){
    return rightChildPtr;
};

void PyramidNode::setLeftChildPtr(PyramidNode* left){
    leftChildPtr = left;
};
void PyramidNode::setRightChildPtr(PyramidNode* right){
    rightChildPtr = right;
};