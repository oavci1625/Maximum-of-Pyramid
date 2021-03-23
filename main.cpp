/*
* Title: Pyramid
* Author: Onuralp Avci
* Description: Pyramid is the class which keeps root of the pyramid which is the first node
* Also it has two more integer properties which are level and count
* Level is the height of the new node to be added and the count is the index of this node for this level
*/

#include "Pyramid.h"

int main(){
    int arr[] = {215, 193, 124, 117, 237, 442, 218, 935, 347, 235, 320, 804, 522, 417, 345, 229, 601, 723, 835, 133, 124, 248, 202, 277, 433, 207, 263, 257, 359, 464, 504, 528, 516, 716, 871, 182, 
    461, 441, 426, 656, 863, 560, 380, 171, 923, 381, 348, 573, 533, 447, 632, 387, 176, 975, 449, 223, 711, 445, 645, 245, 543, 931, 532, 937, 541, 444, 330, 131, 333, 928, 377, 733, 17, 778, 839, 168, 
    197, 197, 131, 171, 522, 137, 217, 224, 291, 413, 528, 520, 227, 229, 928, 223, 626, 34, 683, 839, 53, 627, 310, 713, 999, 629, 817, 410, 121, 924, 622, 911, 233, 325, 139, 721, 218, 253, 223,
    107, 233, 230, 124, 233};
    int size = 120;
    Pyramid pyramid;
    pyramid.createPyramidFromArray(arr, size);
    
    pyramid.printAll();
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"Maximum sum of the path of numbers which are not prime is "<<pyramid.getSum()<<endl;
}
