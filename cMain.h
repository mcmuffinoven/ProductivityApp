#pragma once

#define _CRT_SECURE_NO_WARNINGS
//Project Header Files
#include "Task.h"

//wxWidget Headers
#include <wx/wx.h>
#include <wx/combobox.h>
#include <wx/string.h>
#include <wx/timer.h>

//Other Headers 
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <thread>
#include <Windows.h>
#include <fstream>
#include <sstream>

using namespace std; 

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

private: 
	static const int timerInterval = 500; //500ms
	static const int buttonEventID = 101; 
	static const int timerEventID = 100; 
public:

	//Define wx objects to be used
	wxComboBox* process_dropdown = nullptr; 

	wxTextCtrl* tc1 = nullptr; 
	wxTextCtrl* tc_day = nullptr; 
	wxTextCtrl* tc_hr = nullptr;
	wxTextCtrl* tc_min = nullptr; 

	wxListBox* scheduled_task_list = nullptr;
	wxBoxSizer* sizer = nullptr;

	wxTimer* timer = new wxTimer(this, timerEventID);
	
//Class methods 
public: 
	void checkTime();
	void submitTaskButton(wxCommandEvent& evt);
	void OnTimer(wxTimerEvent& wxEVT_TIMER);
	wxArrayString getProcesses(const std::string& command);
	wxDECLARE_EVENT_TABLE();
};

