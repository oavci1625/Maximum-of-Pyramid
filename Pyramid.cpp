/*
* Title: Pyramid
* Author: Onuralp Avci
* Description: Pyramid is the class which keeps the root of the pyramid which is the first node
* Also it has two more integer properties which are level and index
* Level is the current level of the pyramid where the new node will be added 
* and the index is the index of this node for this level
*/

#include "Pyramid.h"

//Initially there is no node, so root is null. The first item to be added will in in level 1 of the pyramid and its index in this level will be 1
Pyramid::Pyramid(){
    root = NULL;
    level = 1;
    index = 1;
}

//Desctructor of the pyramid which deletes all nodes
Pyramid::~Pyramid(){
    destroyPyramid();
}


//recursive add function
bool Pyramid::add(const int newEntry){
    //If pyramid is empty it adds the first node and sets the root
    if (root == NULL) { 
        root = new PyramidNode(newEntry, NULL, NULL);
        level = 2;
        index = 1;
        return true;
    }
    
    //If item is added to the first index of the level where it is going to be added
    else if(index == 1){
        PyramidNode* newItem = new PyramidNode(newEntry, NULL, NULL);
        PyramidNode* parentNodePtr = getNodeWithLevelCount(level-1, 1);
        parentNodePtr->setLeftChildPtr(newItem);
        index++;
        return true;
    }

    //If item is added to the end of the level where it is going to be added
    else if(level == index){
        PyramidNode* newItem = new PyramidNode(newEntry, NULL, NULL);
        PyramidNode* parentNodePtr = getNodeWithLevelCount(level-1, level-1);
        parentNodePtr->setRightChildPtr(newItem);
        level++;
        index = 1;
        return true;
    }
    //If item is added in between the level and it is going to have two parents
    else if(index > 1 && index < level){
        PyramidNode* newItem = new PyramidNode(newEntry, NULL, NULL);
        PyramidNode* leftParentNodePtr = getNodeWithLevelCount(level-1, index-1);
        leftParentNodePtr->setRightChildPtr(newItem);
        PyramidNode* rightParentNodePtr = getNodeWithLevelCount(level-1, index);
        rightParentNodePtr->setLeftChildPtr(newItem);
        index++;
        return true;
    }
    //If there is a mistake it returns false
    else
        return false;
}


//This method returns the pointer of the node which is at the 'index'th position of the level of the pyramid 
PyramidNode* Pyramid::getNodeWithLevelCount(int level, int index){
    PyramidNode* tempRoot = root;
    //Until their position in the level is the same, pointer moves to the right child
    while(index != 1){
        tempRoot = tempRoot->getRightChildPtr();
        index --;
        level--;
    }

    //At this point tempRoot has the same index with the target node, and it will move down until its level is same with target node
    while( level != 1){
        tempRoot = tempRoot->getLeftChildPtr();
        level--;
    }
    return tempRoot;
};

//This method is used for printing the item in the node which is at the 'index'th position of the level of the pyramid 
void Pyramid::printNodeWithLevelCount(int level, int index){
    //This method prints the items with 0 extension, as it is shown in the task form like this
    std::cout << std::setfill('0') << std::setw(3) << getNodeWithLevelCount(level,index)->item;
};

//This method prints all the pyramid from top to bottom (from level 1 to level n)
void Pyramid::printAll(){
    for (int i = 1; i < level; i++){
        for (int j = 1; j < i+1; j++){
            printNodeWithLevelCount(i,j);
            cout<<' ';
        }
        cout<<endl;
    }
};

//This function finds the maximum possible sum of the path in the pyramid. It only goes through non prime numbers
int Pyramid::getSum(){
    return getSumHelper(root);
};

//This function recursively considers every possible path which does not pass through a non-prime number
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

//This function is for checking if a number is prime or not. If it is prime it returns true. Else it returns false
bool Pyramid::isPrime(int number){
    bool prime = true;
    for (int i = 2; i <= number / 2; i++)
    {
        if( number % i == 0)
            prime = false;
    }
    return prime;
};

//This function adds every item in an array to the pyramid
void Pyramid::createPyramidFromArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        add(arr[i]);
    }
};

//This function deletes a specific node from the pyramid
//It is important to not to delete an item which has a left or a right child because it will cause memory leak
//For this reason this function is private and it is only used in the right way in destroyPyramid() function which is also private
void Pyramid::deleteWithLevelCount(int level, int index){
    delete getNodeWithLevelCount(level, index);
};

//This function deletes all the nodes in the pyramid starting from bottom to top
//As it starts from the bottom it does not cause any memory leak
void Pyramid::destroyPyramid(){
    for (int i = level-1; i > 0; i--){
        for (int j = 1; j < i+1; j++){
            deleteWithLevelCount(i,j);
        }
    }
};