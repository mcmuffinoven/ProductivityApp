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
using namespace chrono;

class Task {
public:
    string processName;
    string killTime_day;
    string killTime_hr;
    string killTime_min;

    //Task constructor
    Task(string Name, string Time_day, string Time_hr, string Time_min) {
        processName = Name;
        killTime_day = Time_day; 
        killTime_hr = Time_hr;
        killTime_min = Time_min; 
    }

    //Print variables, for debug
    void identify() {
        cout << processName + " " + killTime_day + killTime_hr + killTime_min + "\n";
    }

    //If we want to edit the time. 
    /*
    void SetTime(string time) {
        killTime = time;
    }*/
};
