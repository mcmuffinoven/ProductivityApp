#pragma once

#define _CRT_SECURE_NO_WARNINGS
//Class Header Files
#include "cThread.h"
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
	static const int timerInterval = 1000; //1s

public:

	//Define variables to be used. 
	wxComboBox* dropdown = nullptr; 

	wxTextCtrl* tc1 = nullptr; 
	wxTextCtrl* tc_day = nullptr; 
	wxTextCtrl* tc_hr = nullptr;
	wxTextCtrl* tc_min = nullptr; 

	wxListBox* list = nullptr;
	wxBoxSizer* sizer = nullptr;

	wxTimer* timer = new wxTimer(this, 101);
	
	
	

public: 
	void checkTime();
	void OnButtonClicked(wxCommandEvent& evt);
	void OnTimer(wxTimerEvent& wxEVT_TIMER);
	wxArrayString execute(const std::string& command);
	wxDECLARE_EVENT_TABLE();
};

