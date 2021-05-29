#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

//Scheduler

#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;
// int main(){
//     string cProcess;
//     string command;
//     cout << "Enter the name of the process  that you would wish to end" << endl;
//     cin >> cProcess;
//     command = "taskkill /IM " + cProcess + " /F "+ "/t"; // or something like that
//     system(command.c_str());
//     return 0;
// }

class Task {
    
}; 

int main()
{

    //initialize time
    auto start = system_clock::now();
    // Some computation here
    auto end = system_clock::now();

    duration<double> elapsed_seconds = end - start;
    time_t end_time = system_clock::to_time_t(end);
    string cProcess;
    string command;
    cout << "Enter the name of the process  that you would wish to end" << endl;
    cin >> cProcess;

    while (1){ //if time is equal to set time exit out of loop, otherwise wait
        auto start = system_clock::now();
        // Some computation here
        auto end = system_clock::now();

        duration<double> elapsed_seconds = end - start;
        time_t end_time = system_clock::to_time_t(end);
        //cout << ctime(&end_time) << "\n";

        if ((strcmp(ctime(&end_time), "Fri May 28 15:37:00 2021\n")) == 0){ // Need to make the comparison, to a changeable variable set by user.
            command = "taskkill /IM " + cProcess + " /F " + "/t"; 
            system(command.c_str()); //Kill process at designated time. 
            return 0;
        }
    }

    return 0;
}