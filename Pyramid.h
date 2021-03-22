/*
* Title: Pyramid
* Author: Onuralp Avci
* Description: Pyramid is the class which keeps root of the pyramid which is the first node
* Also it has two more integer properties which are level and count
* Level is the height of the new node to be added and the count is the index of this node for this level
*/

#ifndef PYRAMID_H
#define PYRAMID_H

#include "PyramidNode.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Pyramid
{
private:
    PyramidNode* root;
    int level;
    int index;

    bool add(const int newEntry);
    PyramidNode* getNodeWithLevelCount(int level, int index);
    void printNodeWithLevelCount(int level, int index);
    bool isPrime(int number);
    int getSumHelper(PyramidNode* subPyramid);
    void deleteWithLevelCount(int level, int index);
    void destroyPyramid();

public:
    Pyramid();
    ~Pyramid();
    void createPyramidFromArray(int arr[], int size);
    void printAll();
    int getSum();
};

#endif // PYRAMID_H
