#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

queue<int> Q;
vector<int> visited(100000000);

int main() {

    cout<<"You are now in the elevator.\nEnter the total number of floors, the starting floor, goal floor, the upward floor increment, and the downward floor increment, in that order:\n";
    int totalFloors, goalFloor, startingFloor, upFloors, downFloors = 0;

            //read in the input from command line
    cin>> totalFloors>> startingFloor>>goalFloor>>upFloors>>downFloors;


    if (startingFloor == goalFloor) {
        cout << "No need to take stairs or elevator. Already on goal floor.\n";
    }
    //input is entered correctly
    else{

        visited[startingFloor] = 1;
        Q.push(startingFloor);
        while(!Q.empty()){
            int currentFloor = Q.front();
            Q.pop();

            if((currentFloor+upFloors) <= totalFloors && visited[currentFloor+upFloors] ==0){
                visited[currentFloor+upFloors] = visited[currentFloor] + 1;
                Q.push(currentFloor+upFloors);
            }

            if((currentFloor-downFloors) >= 1 && visited[currentFloor-downFloors] == 0){
                visited[currentFloor-downFloors] = visited[currentFloor+1];
                Q.push(currentFloor-downFloors);
            }
        }

    }

    if(visited[goalFloor]!=0){
        cout<<"\nThe minimum amount of button presses needed is..... "<<visited[goalFloor]-1<<"\n"<<"Thanks for taking the elevator!\n";
    }
    else{
        cout<<"\nSorry. You must use the stairs.\n";
    }




    return 0;
}