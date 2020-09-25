  #ifndef __BASE_H // Make sure to only declare these classes once
  #define __BASE_H

  class MainApp: public wxApp // MainApp is the class for our application
  { // MainApp just acts as a container for the window,
  public: virtual bool OnInit();
  };

  class MainFrame: public wxFrame // MainFrame is the class for our window,
  { // It contains the window and all objects in it
  public:
    MainFrame( const wxString& title, const wxPoint& pos, const wxSize& size );
	wxStaticText *t1tle;
    wxTextCtrl *widthorig;
	wxTextCtrl *heightorig;
	wxTextCtrl *widthnew;
	wxTextCtrl *heightnew;
	wxButton *calculate;
    wxMenuBar *MainMenu;
    void Quit(wxCommandEvent& event);
	void multiply(wxCommandEvent& event);

    DECLARE_EVENT_TABLE()
  };

  enum
  {
	BUTTON_calculate,
    MENU_Quit
  };

  #endif