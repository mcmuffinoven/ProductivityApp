//Project Header Files
#include "cMain.h"
#include "Task.h"

#define _CRT_SECURE_NO_WARNINGS


wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	//Button Event
	EVT_BUTTON(buttonEventID, submitTaskButton) //Link ID to a specific function

	//Timer Event
	EVT_TIMER(timerEventID, cMain::OnTimer)  
wxEND_EVENT_TABLE()

//Create vector of Tasks
vector<Task*> TaskList; 

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Productivity App", wxPoint(30,30), wxSize(800, 500) ) {
	
	//Call function to get current running processes
	wxArrayString tasks; 
	tasks = getProcesses("tasklist"); 

	//Initialize and setup 500ms timer
	timer->SetOwner(this, timerEventID);
	this->Connect(timer->GetId(), wxEVT_TIMER, wxTimerEventHandler(cMain::OnTimer), NULL, this);

	//Start periodic 500ms timer to check task deadline
	timer->Start(timerInterval); 

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

	//Dropdown menu to display current running processes
	process_dropdown = new wxComboBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, tasks, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
	
	//Create text boxes for user input
	
	tc_day = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Day
	tc_hr = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Hr
	tc_min = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Min

	//Create horizontal sizer to add the timer text boxes. 
	wxBoxSizer* righthbox1 = new wxBoxSizer(wxHORIZONTAL);

	//Add process name text box to leftvbox
	leftvbox->Add(process_dropdown, 0, wxEXPAND);

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

	//Create list menu of scheduled tasks
	scheduled_task_list = new wxListBox(this, wxID_ANY, wxPoint(-1, -1), wxSize(-1, -1)); //Scheduled Task, NEED TO REPLACE WITH TEXT BOX LATER TO SHOW SCHEDULED TASKS 
	
	//Create text boxes for user inpt
	wxTextCtrl* tc_work = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Work time
	wxTextCtrl* tc_rest = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Rest time

	//Add the scheduled tasks box to the leftvbox
	leftvbox->Add(scheduled_task_list, 1, wxEXPAND);

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
	wxButton* btn1 = new wxButton(this, buttonEventID, wxT("Submit Task"));

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

	//Set font of wx objects 
	process_dropdown->SetFont(font); 
	tc_day->SetFont(font);
	tc_hr->SetFont(font);
	tc_min->SetFont(font);
	tc_work->SetFont(font);
	tc_rest->SetFont(font);

	//Button Font
	btn1->SetFont(font);

	//Text Font
	st1->SetFont(font);
	st2->SetFont(font);
	st3->SetFont(font);
	st4->SetFont(font);
	st5->SetFont(font);

	//List Font
	scheduled_task_list->SetFont(font); 

}

cMain::~cMain() {
	if (timer->IsRunning())
	{
		timer->Stop();
	}
}

//Function to handle user submiting a task
void cMain::submitTaskButton(wxCommandEvent& evt) {

	string processName; 
	string killTime_day; 
	string killTime_hr; 
	string killTime_min;

	//Update scheduled tasks according to user input when submit button is pressed
	processName = process_dropdown->GetValue(); 
	killTime_day = tc_day->GetValue(); 
	killTime_hr = tc_hr->GetValue(); 
	killTime_min = tc_min->GetValue();

	//Update wxList object with processName 
	scheduled_task_list->AppendString(processName);

	//Create a new task object and push into tasklist vector
	TaskList.push_back(new Task(processName, killTime_day, killTime_hr, killTime_min)); 

	//Event has been handeled. 
	evt.Skip(); 
}

//Function to get current running processes
wxArrayString cMain::getProcesses(const std::string& command)
{
	//Output system command outputs to temp.txt
	wxArrayString tasks; 
	system((command + " > temp.txt").c_str());

	std::ifstream ifs("temp.txt");
	std::string ret{ std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>() };

	ifs.close(); // must close the inout stream so the file can be cleaned up

	//Read file and parse first column 
	vector<string> names;
	ifstream infile("temp.txt");

	//If file is not read return error 
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

	//Push process names to tasks wxarraystring
	for (string s : names) {
		wxString processes(s);
		tasks.Add(processes);
	}

	//Return arraystring to be pushed into wx dropdown menu
	return tasks;
}

//Timer event to call checkTime function
void cMain::OnTimer(wxTimerEvent& wxEVT_TIMER){
	checkTime();
}
//Time Checking 
void cMain::checkTime() {

	//Command Variables
	string cProcess;
	string command;

	//Timer Variables
	time_t now;
	struct tm *killTime;
	double seconds;

	 //Iterate Through Task Vector
	if (!TaskList.empty()) {
		for (int i = 0; i < TaskList.size(); i++) {
			time(&now);
			killTime = localtime(&now);
			cProcess = TaskList[i]->processName;
			//Set time of scheduler to scheduled time of task.
			killTime->tm_hour = stoi(TaskList[i]->killTime_hr); killTime->tm_min = stoi(TaskList[i]->killTime_min); killTime->tm_sec = 0;
			killTime->tm_mday = stoi(TaskList[i]->killTime_day);

			seconds = difftime(now, mktime(killTime));

			if (seconds >= 0) { // Need to make the comparison, to a changeable variable set by user.
				command = "taskkill /IM " + cProcess + " /F " + "/t";
				system(command.c_str()); //Kill process at designated time.

				wxString listString(cProcess.c_str(), wxConvUTF8);
				scheduled_task_list->Delete(scheduled_task_list->FindString(listString));
				//Remove ith task from beginning 
				TaskList.erase(TaskList.begin() + i);
				return;
			}
		}
	}
}
