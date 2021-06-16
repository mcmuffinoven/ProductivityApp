#include "cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {
}

cApp::~cApp() {
}

//Startup function to launch GUI
bool cApp::OnInit()
{
	m_frame1 = new cMain();
	m_frame1->Show();

	return true;
}
