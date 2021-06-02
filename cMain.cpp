#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001, OnButtonClicked) //Link ID to a specific function 
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Game of Life", wxPoint(30,30), wxSize(800, 1000) ) {
	//m_btn1 = new wxButton(this, 10001, "Click me", wxPoint(10, 10), wxSize(150, 50));
	//m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 70), wxSize(300, 30));
	//m_list1 = new wxListBox(this, wxID_ANY, wxPoint(10, 110), wxSize(300, 300));
	/*
	wxPanel* panel = new wxPanel(this, -1);

	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);

	wxStaticText* st1 = new wxStaticText(panel, wxID_ANY,wxT("Process Name"));
	wxStaticText* st2 = new wxStaticText(panel, wxID_ANY, wxT("Set Time"));

	hbox1->Add(st1, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);
	hbox1->Add(st2, 1, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 20);

	vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);
	vbox->Add(-1, 10);

	wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);
	wxTextCtrl* tc1 = new wxTextCtrl(panel, wxID_ANY, wxT(""),wxPoint(-1, -1), wxSize(-1, -1));
	wxTextCtrl* tc2 = new wxTextCtrl(panel, wxID_ANY, wxT(""),wxPoint(-1, -1), wxSize(-1, -1));
	wxTextCtrl* tc3 = new wxTextCtrl(panel, wxID_ANY, wxT(""),wxPoint(-1, -1), wxSize(-1, -1));

	hbox2->Add(tc1, 5, wxEXPAND | wxRIGHT, 20);
	hbox2->Add(tc2, 1, wxEXPAND | wxRIGHT, 20);
	hbox2->Add(tc3, 1, wxEXPAND | wxRIGHT, 20);

	vbox->Add(hbox2, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);



	panel->SetSizer(vbox);
	*/

	//wxPanel* leftpanel = new wxPanel(this, -1);
	//wxPanel* rightpanel = new wxPanel(this, -1);
	//wxPanel* panel = new wxPanel(this, -1);

	//leftpanel->SetBackgroundColour(wxColor(100, 100, 200));
	//rightpanel->SetBackgroundColour(wxColor(100, 200, 100));

	//wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* hbox1 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* vbox1 = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* vbox2 = new wxBoxSizer(wxVERTICAL);

	hbox1->Add(vbox1, 1, wxEXPAND | wxALL, 10 ); 
	hbox1->Add(vbox2, 1, wxEXPAND | wxALL, 10);

	wxStaticText* st1 = new wxStaticText(this, wxID_ANY, wxT("Process Name"));
	wxStaticText* st2 = new wxStaticText(this, wxID_ANY, wxT("Set Time"));

	vbox1->Add(st1, 0, wxEXPAND | wxALL, 10); 
	vbox2->Add(st2, 0, wxEXPAND | wxALL, 10);

	wxTextCtrl* tc1 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1));
	wxTextCtrl* tc2 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1));
	wxTextCtrl* tc3 = new wxTextCtrl(this, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1));
	wxBoxSizer* hbox2 = new wxBoxSizer(wxHORIZONTAL);

	vbox1->Add(tc1, 0, wxEXPAND);

	hbox2->Add(tc2, 0, wxEXPAND | wxRIGHT, 10);
	hbox2->Add(tc3, 0, wxEXPAND);

	vbox2->Add(hbox2, 0, wxEXPAND);



	this->SetSizer(hbox1);
/*	
	wxColour col1, col2, col3;
	col1.Set(wxT("#d46911"));
	col2.Set(wxT("#30b828"));
	col3.Set(wxT("#de1058"));
	wxPanel* panel = new wxPanel(this, wxID_ANY,wxDefaultPosition, wxSize(200,100));
	panel->SetBackgroundColour(col1);

	wxPanel* panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	wxPanel* panel3 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 100));
	panel2->SetBackgroundColour(col2);
	panel3->SetBackgroundColour(col3);

	sizer->Add(panel, 1, wxEXPAND | wxALL, 20);
	sizer->Add(panel2, 1, wxEXPAND | wxALL, 20);
	sizer->Add(panel3, 1, wxEXPAND | wxALL, 20);

	this->SetSizerAndFit(sizer); */

}

cMain::~cMain() {
	//delete[]btn; //Delete pointer of array to buttons to prevent memory leak 
}

void cMain::OnButtonClicked(wxCommandEvent& evt) {
	evt.Skip(); //Event has been handeled. 
}