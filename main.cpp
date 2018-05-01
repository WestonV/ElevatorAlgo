#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

queue<int> Q;
vector<int> visited(100000000);

int main() {
        //print statement explaining how to enter input
    cout<<"You are now in the elevator.\nEnter the total number of floors, the starting floor, goal floor, the upward floor increment, and the downward floor increment, in that order:\n";
    int totalFloors, goalFloor, startingFloor, upFloors, downFloors = 0;

        //read in the input from command line
    cin>> totalFloors>> startingFloor>>goalFloor>>upFloors>>downFloors;

        //on rare case that starting floor is the goal floor, print message and exit program
    if (startingFloor == goalFloor) {
        cout << "No need to take stairs or elevator. Already on goal floor.\n";
        return 0;
    }
        //input is entered correctly
    else{

        visited[startingFloor] = 1; //marking starting floor as visited
        Q.push(startingFloor);  //push starting floor onto queue
        while(!Q.empty()){  //while queue is not empty
            int currentFloor = Q.front();   //set the front of the queue to an int called currentFloor
            Q.pop();    //pop the node off the queue since it is stored in the currentFloor variable

            if((currentFloor+upFloors) <= totalFloors && visited[currentFloor+upFloors] ==0){ //if we can get to the currentFloor by pressing the upFloor button, and we haven't been to that floor before, run code
                visited[currentFloor+upFloors] = visited[currentFloor] + 1; //increment visited[currentFloor] by one, and set value equal to visited[currentFloor + upFloors]
                Q.push(currentFloor+upFloors); //push this node onto queue, which will now be at the front of the queue
            }

            if((currentFloor-downFloors) >= 1 && visited[currentFloor-downFloors] == 0){ //if current floor is accessable by pressing down button, and if we haven't been to that floor before, then run
                visited[currentFloor-downFloors] = visited[currentFloor]+1; //mark this new floor as visited
                Q.push(currentFloor-downFloors); //push this floor to front of queue
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