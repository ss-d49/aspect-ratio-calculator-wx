  #include "wx/wxprec.h"
  #include "wx/wx.h"
  #include "includes/base.h"

  BEGIN_EVENT_TABLE ( MainFrame, wxFrame )
  EVT_MENU(MENU_Quit, MainFrame::Quit)
  EVT_BUTTON ( BUTTON_calculate, MainFrame::multiply ) // Tell the OS to run MainFrame::OnExit when
  END_EVENT_TABLE()

  IMPLEMENT_APP(MainApp) // Initializes the MainApp class and tells our program
  // to run it
  bool MainApp::OnInit()
  {
    // Create an instance of our frame, or window
    MainFrame *MainWin = new MainFrame(wxT("Aspect Ratio Calculator"), wxPoint(1,1),
    wxSize(530, 345)); // Create an instance of our frame, or window
    MainWin->Show(TRUE); // show the window
    SetTopWindow(MainWin);// and finally, set it as the main window

    return TRUE;
  }

  MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	 : wxFrame((wxFrame *) NULL, -1, title, pos, size)
  {
    CreateStatusBar(1);
    MainMenu = new wxMenuBar();
    wxMenu *FileMenu = new wxMenu();
    FileMenu->Append(MENU_Quit, wxT("&Quit"), wxT("Quit the editor"));
    MainMenu->Append(FileMenu, wxT("File"));
    SetMenuBar(MainMenu);
	wxPanel *panel = new wxPanel(this, -1);
	wxStaticText *heading = new wxStaticText(panel, -1, wxT("Aspect Ratio Calculator"), wxPoint(170, 20));
	heading->SetFont(wxFont (12, wxDEFAULT, wxNORMAL, wxBOLD));
    widthorig = new wxTextCtrl(panel, -1, wxT(""), wxPoint(45,70), wxSize(185, 30));
	heightorig = new wxTextCtrl(panel, -1, wxT(""), wxPoint(45,155), wxSize(185, 30));
	widthnew = new wxTextCtrl(panel, -1, wxT(""), wxPoint(285,70), wxSize(185, 30));
	heightnew = new wxTextCtrl(panel, -1, wxT(""), wxPoint(285,155), wxSize(185, 30));
	calculate = new wxButton(panel, BUTTON_calculate, wxT("Calculate"), wxPoint(220,215));
  }

  void MainFrame::Quit(wxCommandEvent& WXUNUSED(event))
  {
    Close(TRUE); // Tells the OS to quit running this process
  }

  void MainFrame::multiply(wxCommandEvent& WXUNUSED(event))
  {
	wxString widthorig_str = widthorig->GetValue();
	float widthorig_float;
	widthorig_float = wxAtof(widthorig_str);

	wxString heightorig_str = heightorig->GetValue();
	float heightorig_float;
	heightorig_float = wxAtof(heightorig_str);

	wxString heightnew_str = heightnew->GetValue();
	float heightnew_float;
	heightnew_float = wxAtof(heightnew_str);

	float out_float;
	out_float = (widthorig_float / heightorig_float) * heightnew_float;

	wxString out_str = wxString::Format(wxT("%f"),out_float);
	widthnew->SetValue(out_str);

  }
