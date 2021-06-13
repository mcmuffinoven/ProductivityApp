#include "cMain.h"
#include "Task.h"
#include "cThread.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001, OnButtonClicked) //Link ID to a specific function

//Timer Event
EVT_TIMER(wxID_ANY, cMain::checkTime)  
wxEND_EVENT_TABLE()

//Create Vector of Tasks
vector<Task*> TaskList; 

wxArrayString execute(const std::string& command);

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Productivity App", wxPoint(30,30), wxSize(800, 500) ) {
	
	wxArrayString tasks; 
	tasks = execute("tasklist"); 

	//Start Periodic 1s Timer To Check Task Deadline
	timer->Start(timerInterval, false); 

	//Create horizontal sizer for entire GUI
	wxBoxSizer* fullhbox = new wxBoxSizer(wxHORIZONTAL);

	//Create vertical sizers for each coloumn of the GUI
	wxBoxSizer* leftvbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* rightvbox = new wxBoxSizer(wxVERTICAL);

	//Add the leftvbox first, then the right into the horizontal sizer, creating two divisions. 
	fullhbox->Add(leftvbox, 1, wxEXPAND | wxALL, 10 );
	fullhbox->Add(rightvbox, 1, wxEXPAND | wxALL, 10);

	//Create static text
	wxStaticText* st1 = new wxStaticText(this, wxID_ANY, wxT("Process Name"));
	wxStaticText* st2 = new wxStaticText(this, wxID_ANY, wxT("Set Time (Day, Hr, Min)"));

	//Add text to each side of the GUI
	leftvbox->Add(st1, 0, wxEXPAND | wxTOP | wxRIGHT, 10);
	rightvbox->Add(st2, 0, wxEXPAND | wxTOP | wxRIGHT, 10);

	//Create text boxes for user input

	dropdown = new wxComboBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, tasks, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	//tc1 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Process Name
	tc_day = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Day
	tc_hr = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Hr
	tc_min = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Min

	//Create horizontal sizer to add the timer text boxes. 
	wxBoxSizer* righthbox1 = new wxBoxSizer(wxHORIZONTAL);

	//Add process name text box to leftvbox
	leftvbox->Add(dropdown, 0, wxEXPAND);

	//Add the two text boxes into a horizontal sizer
	righthbox1->Add(tc_day, 0, wxEXPAND | wxRIGHT, 10);
	righthbox1->Add(tc_hr, 0, wxEXPAND | wxRIGHT, 10);
	righthbox1->Add(tc_min, 0, wxEXPAND);

	//Add the first horizontal sizer into rightvhox
	rightvbox->Add(righthbox1, 0, wxEXPAND);

	//Create static text
	wxStaticText* st3 = new wxStaticText(this, wxID_ANY, wxT("Scheduled Tasks"));
	wxStaticText* st4 = new wxStaticText(this, wxID_ANY, wxT("Work Time"));
	wxStaticText* st5 = new wxStaticText(this, wxID_ANY, wxT("Rest Time"));

	//Add text to each side of the GUI
	leftvbox->Add(st3, 0, wxEXPAND | wxTOP | wxRIGHT, 10);
	
	//Create horizontal sizer to add the Work/Rest time text
	wxBoxSizer* righthbox2 = new wxBoxSizer(wxHORIZONTAL);

	//Add the work/rest time text into the right horizontal sizer
	righthbox2->Add(st4, 1, wxEXPAND | wxTOP | wxRIGHT, 10);
	righthbox2->Add(st5, 2, wxEXPAND | wxTOP | wxRIGHT, 10);

	//Add the second horizontal sizer into the rightvbox
	rightvbox->Add(righthbox2, 0, wxEXPAND);

	//Create text boxes for user inpt
	list = new wxListBox(this, wxID_ANY, wxPoint(-1, -1), wxSize(-1, -1)); //Scheduled Task, NEED TO REPLACE WITH TEXT BOX LATER TO SHOW SCHEDULED TASKS 
	wxTextCtrl* tc_work = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Work time
	wxTextCtrl* tc_rest = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Rest time

	//Add the scheduled tasks box to the leftvbox
	leftvbox->Add(list, 1, wxEXPAND);

	//Create horizontal sizer to add the Work/Rest time textbox
	wxBoxSizer* righthbox3 = new wxBoxSizer(wxHORIZONTAL);

	//Add the work rest time textbox
	righthbox3->Add(tc_work, 0, wxEXPAND | wxRIGHT, 10);
	righthbox3->Add(tc_rest, 0, wxEXPAND);
	
	//Add horizontal sizer to rightvbox
	rightvbox->Add(righthbox3, 0, wxEXPAND);

	//Create a spacer sizer to fix a panel that stretches all the way, so the submit button appears at the very bottom of the GUI
	wxBoxSizer* spacerbox = new wxBoxSizer(wxHORIZONTAL);

	//Add panel into the spacer
	spacerbox->Add(new wxPanel(this, -1));

	//Add spacer into rightvbox
	rightvbox->Add(spacerbox, 1, wxEXPAND);

	//Add horizontal sizer for submit button
	wxBoxSizer* rightthbox4 = new wxBoxSizer(wxHORIZONTAL);
	
	//Create submit button
	wxButton* btn1 = new wxButton(this, 10001, wxT("Submit Task"));

	//Add button to horizontal sizer
	rightthbox4->Add(btn1, 0);
	
	//Add button to rightvhox
	rightvbox->Add(rightthbox4, 0, wxALIGN_RIGHT | wxRIGHT, 10);

	//Set the sizer of the GUI to fullhbox 
	this->SetSizer(fullhbox);

	//Center app popup
	Centre(); 

	//Create font class so we can set our text to this font
	wxFont font(14, wxFONTFAMILY_ROMAN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false); 

	dropdown->SetFont(font); 
	tc_day->SetFont(font);
	tc_hr->SetFont(font);
	tc_min->SetFont(font);
	tc_work->SetFont(font);
	tc_rest->SetFont(font);
	btn1->SetFont(font);

	st1->SetFont(font);
	st2->SetFont(font);
	st3->SetFont(font);
	st4->SetFont(font);
	st5->SetFont(font);

	list->SetFont(font); 
	//Wait for thread
	//thread_1.join();
}

cMain::~cMain() {
	//delete[]btn; //Delete pointer of array to buttons to prevent memory leak 
}

void cMain::OnButtonClicked(wxCommandEvent& evt) {

	string processName; 
	string killTime_day; 
	string killTime_hr; 
	string killTime_min;

	//Update scheduled tasks according to user input when submit button is pressed
	processName = dropdown->GetValue(); 
	killTime_day = tc_day->GetValue(); 
	killTime_hr = tc_hr->GetValue(); 
	killTime_min = tc_min->GetValue();

	list->AppendString(processName);

	TaskList.push_back(new Task(processName, killTime_day, killTime_hr, killTime_min)); //Create a new Task 

	evt.Skip(); //Event has been handeled. 
}


wxArrayString execute(const std::string& command)
{
	wxArrayString tasks; 
	system((command + " > temp.txt").c_str());

	std::ifstream ifs("temp.txt");
	std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };

	ifs.close(); // must close the inout stream so the file can be cleaned up

	vector<string> names;
	ifstream infile("temp.txt");


	if (!infile)
	{
		wxArrayString error;
		error.Add(wxT("error"));
		return error; 
	}
	string line, nm;
	while (getline(infile, line))
	{
		stringstream(line) >> nm;
		names.push_back(nm);
	}

	for (string s : names) {
		wxString mystring(s);
		tasks.Add(mystring); 
	}

	return tasks;
}


//Time Checking 

void checkTime() {

	//Command Variables
	string cProcess;
	string command;

	//Timer Variables
	time_t now;
	struct tm killTime;
	double seconds;

	while (1) { //if time is equal to set time exit out of loop, otherwise wait
		for (int i = 0; i < TaskList.size(); i++) {

			killTime = *localtime(&now);

			killTime.tm_hour = stoi(TaskList[i]->killTime_hr); killTime.tm_min = stoi(TaskList[i]->killTime_min); killTime.tm_sec = 0;
			killTime.tm_mday = stoi(TaskList[i]->killTime_day);

			TaskList[i]->identify();

			seconds = difftime(now, mktime(&killTime));

			if (seconds >= 0) { // Need to make the comparison, to a changeable variable set by user.
				command = "taskkill /IM " + cProcess + " /F " + "/t";
				system(command.c_str()); //Kill process at designated time. 
				break;
			}

			//check every second
			this_thread::sleep_for(1s);
		}
	}
}


/*
* virtual int wxListBox::FindString	(	const wxString & 	string,
bool 	caseSensitive = false 
)		const

if(task complete)
	list->Delete(findstring(process name))
*/