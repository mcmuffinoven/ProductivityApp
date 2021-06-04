#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001, OnButtonClicked) //Link ID to a specific function 
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Productivity App", wxPoint(30,30), wxSize(800, 500) ) {
	
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
	wxStaticText* st2 = new wxStaticText(this, wxID_ANY, wxT("Set Time"));

	//Add text to each side of the GUI
	leftvbox->Add(st1, 0, wxEXPAND | wxTOP | wxRIGHT, 10);
	rightvbox->Add(st2, 0, wxEXPAND | wxTOP | wxRIGHT, 10);

	//Create text boxes for user input
	tc1 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Process Name
	wxTextCtrl* tc2 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Hr
	wxTextCtrl* tc3 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Min

	//Create horizontal sizer to add the timer text boxes. 
	wxBoxSizer* righthbox1 = new wxBoxSizer(wxHORIZONTAL);

	//Add process name text box to leftvbox
	leftvbox->Add(tc1, 0, wxEXPAND);

	//Add the two text boxes into a horizontal sizer
	righthbox1->Add(tc2, 0, wxEXPAND | wxRIGHT, 10);
	righthbox1->Add(tc3, 0, wxEXPAND);

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

	//Create text boxes for user input
	list = new wxListBox(this, wxID_ANY, wxPoint(-1, -1), wxSize(-1, -1)); //Scheduled Task, NEED TO REPLACE WITH TEXT BOX LATER TO SHOW SCHEDULED TASKS 
	wxTextCtrl* tc5 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Work time
	wxTextCtrl* tc6 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1)); //Set Rest time

	//Add the scheduled tasks box to the leftvbox
	leftvbox->Add(list, 1, wxEXPAND);

	//Create horizontal sizer to add the Work/Rest time textbox
	wxBoxSizer* righthbox3 = new wxBoxSizer(wxHORIZONTAL);

	//Add the work rest time textbox
	righthbox3->Add(tc5, 0, wxEXPAND | wxRIGHT, 10);
	righthbox3->Add(tc6, 0, wxEXPAND);
	
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

	tc1->SetFont(font); 
	tc2->SetFont(font);
	tc3->SetFont(font);
	tc5->SetFont(font);
	tc6->SetFont(font);
	btn1->SetFont(font);

	st1->SetFont(font);
	st2->SetFont(font);
	st3->SetFont(font);
	st4->SetFont(font);
	st5->SetFont(font);
}

cMain::~cMain() {
	//delete[]btn; //Delete pointer of array to buttons to prevent memory leak 
}

void cMain::OnButtonClicked(wxCommandEvent& evt) {

	list->AppendString(tc1->GetValue());
	evt.Skip(); //Event has been handeled. 
}

/*
* virtual int wxListBox::FindString	(	const wxString & 	string,
bool 	caseSensitive = false 
)		const

if(task complete)
	list->Delete(findstring(process name))
*/