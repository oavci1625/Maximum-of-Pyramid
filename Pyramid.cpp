/*
* Title: Pyramid
* Author: Onuralp Avci
* Description: Pyramid is the class which keeps root of the pyramid which is the first node
* Also it has two more integer properties which are level and count
* Level is the height of the new node to be added and the count is the index of this node for this level
*/

#include "Pyramid.h"

Pyramid::Pyramid(){
    root = NULL;
    level = 1;
    count = 1;
}

Pyramid::~Pyramid(){
    destroyTree();
}


//recursive add function
bool Pyramid::add(const int newEntry){
    // Position of insertion found; insert after leaf
    if (root == NULL) { 
        root = new PyramidNode(newEntry, NULL, NULL);
        level = 2;
        count = 1;
        return true;
    }
    
    //If item is added to the start of the level
    else if(count == 1){
        PyramidNode* newItem = new PyramidNode(newEntry, NULL, NULL);
        PyramidNode* parentNodePtr = getNodeWithLevelCount(level-1, 1);
        parentNodePtr->setLeftChildPtr(newItem);
        count++;
        return true;
    }

    //If item is added to the end of the level
    else if(level == count){
        PyramidNode* newItem = new PyramidNode(newEntry, NULL, NULL);
        PyramidNode* parentNodePtr = getNodeWithLevelCount(level-1, level-1);
        parentNodePtr->setRightChildPtr(newItem);
        level++;
        count = 1;
        return true;
    }
    //If item is added in between the level and it is going to have two parents
    else if(count > 1 && count < level){
        PyramidNode* newItem = new PyramidNode(newEntry, NULL, NULL);
        PyramidNode* leftParentNodePtr = getNodeWithLevelCount(level-1, count-1);
        leftParentNodePtr->setRightChildPtr(newItem);
        PyramidNode* rightParentNodePtr = getNodeWithLevelCount(level-1, count);
        rightParentNodePtr->setLeftChildPtr(newItem);
        count++;
        return true;
    }
    else
        return false;
}


PyramidNode* Pyramid::getNodeWithLevelCount(int level, int count){
    PyramidNode* tempRoot = root;
    while(count != 1){
        tempRoot = tempRoot->getRightChildPtr();
        count --;
        level--;
    }

    while( level != 1){
        tempRoot = tempRoot->getLeftChildPtr();
        level--;
    }
    return tempRoot;
};

void Pyramid::printNodeWithLevelCount(int level, int count){
    PyramidNode* tempRoot = root;
    while(count != 1){
        tempRoot = tempRoot->getRightChildPtr();
        count --;
        level--;
    }

    while( level != 1){
        tempRoot = tempRoot->getLeftChildPtr();
        level--;
    }
    std::cout << std::setfill('0') << std::setw(3) << tempRoot->item;
};

void Pyramid::printAll(){
    for (int i = 1; i < level; i++){
        for (int j = 1; j < i+1; j++){
            printNodeWithLevelCount(i,j);
            cout<<' ';
        }
        cout<<endl;
    }
};

int Pyramid::getSumHelper(PyramidNode* subPyramid){
    //if tree is empty
    if(subPyramid == NULL)
        return 0;
    //if the end of the pyramid is reached
    else if(subPyramid->getLeftChildPtr()==NULL && subPyramid->getRightChildPtr() ==NULL)
        return subPyramid->item;
    //if both children are prime numbers
    else if(isPrime(subPyramid->getLeftChildPtr()->item) && isPrime(subPyramid->getRightChildPtr()->item))
        return subPyramid->item;
    //if only left child is prime
    else if( isPrime(subPyramid->getLeftChildPtr()->item))
        return subPyramid->item + getSumHelper(subPyramid->getRightChildPtr());
    //if only right child is prime
    else if( isPrime(subPyramid->getRightChildPtr()->item))
        return subPyramid->item + getSumHelper(subPyramid->getLeftChildPtr());
    //if both children are non-prime
    else
        return subPyramid->item + max( getSumHelper(subPyramid->getLeftChildPtr()), getSumHelper(subPyramid->getRightChildPtr()) );
};
//This method finds the maximum possible sum of the path in the pyramid. It only goes through non prime numbers
int Pyramid::getSum(){
    return getSumHelper(root);
};

bool Pyramid::isPrime(int number){
    bool prime = true;
    for (int i = 2; i <= number / 2; i++)
    {
        if( number % i == 0)
            prime = false;
    }
    return prime;
};

void Pyramid::createPyramidFromArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        add(arr[i]);
    }
};


void Pyramid::deleteWithLevelCount(int level, int count){
    PyramidNode* tempRoot = root;
    while(count != 1){
        tempRoot = tempRoot->getRightChildPtr();
        count --;
        level--;
    }

    while( level != 1){
        tempRoot = tempRoot->getLeftChildPtr();
        level--;
    }
    delete tempRoot;
};
void Pyramid::destroyTree(){
    for (int i = level-1; i > 0; i--){
        for (int j = 1; j < i+1; j++){
            deleteWithLevelCount(i,j);
        }
    }
};