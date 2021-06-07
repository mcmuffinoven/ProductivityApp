#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <thread> 

//Scheduler header files
#include <chrono>
#include <ctime>

using namespace std;


class Task {
public:
    string processName;
    string killTime;

    //Task constructor
    Task(string Name, string Time) {
        processName = Name;
        killTime = Time;
    }

    //Print variables, for debug
    void identify() {
        cout << processName + " " + killTime << endl;
    }

    //If we want to edit the time. 
    void SetTime(string time) {
        killTime = time;
    }
};
