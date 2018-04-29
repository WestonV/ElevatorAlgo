#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <unordered_map>
#include <list>
#include <string.h>
using namespace std;

int main() {
    cout<<"You have decided to take the elevator.\nEnter the total number of floors, the starting floor, goal floor, the upward floor increment, and the downward floor increment, in that order:\n";
    int totalFloors, goalFloor, startingFloor, upFloors, downFloors = 0;

    //read in the input from command line
    cin>> totalFloors>> startingFloor>>goalFloor>>upFloors>>downFloors;

    if(startingFloor < 1){
        cout<<"Your starting floor must be greater than zero.\n";
    }
    if(startingFloor > totalFloors){
        cout<<"Your starting floor cannot be greater than the total number of floors.\n";
    }
    if(totalFloors>100 || totalFloors<goalFloor){
        cout<<"Your total number of floors must be less than 100 and greater than the goal floor.\n";
    }
    if(upFloors<0){
        cout<<"Your upward floor increment must greater than or equal to zero.\n";
    }
    if(downFloors>100){
        cout<<"Your downward floor increment must not exceed 100.\n";
    }

    return 0;
}