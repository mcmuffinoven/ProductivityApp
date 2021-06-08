#pragma once

//wxWidget Headers
#include <wx/wx.h>
#include <wx/combobox.h>
#include <wx/string.h>

//Other Headers 
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <thread>

#include <fstream>
#include <sstream>

using namespace std; 

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:

	//Define variables to be used. 
	wxComboBox* dropdown = nullptr; 

	wxTextCtrl* tc1 = nullptr; 
	wxTextCtrl* tc2 = nullptr;
	wxTextCtrl* tc3 = nullptr; 



	wxListBox* list = nullptr;
	wxBoxSizer* sizer = nullptr;

	int nFieldWidth = 10;
	int nFieldHeight = 10;
	//wxButton** btn;

	//int* nField = nullptr;
	//bool bFirstClick = true;

	//wxArrayString execute(const std::string& command);
	void OnButtonClicked(wxCommandEvent& evt);
	
	
	wxDECLARE_EVENT_TABLE();
};

