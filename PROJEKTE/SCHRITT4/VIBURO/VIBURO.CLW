; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStunEingab
LastTemplate=CEditView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ViBuro.h"
LastPage=0

ClassCount=10
Class1=CViBuroApp
Class2=CViBuroDoc
Class3=CStunEingab
Class4=CMainFrame
Class7=CWaechter

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_VIBUROTYPE
Resource3=IDD_WAECHTER
Class5=CAboutDlg
Class6=CChildFrame
Resource4=IDR_MAINFRAME
Class8=CEdDoc
Class9=CAufgabenView
Class10=CBerichtView
Resource5=IDD_MAIN

[CLS:CViBuroApp]
Type=0
HeaderFile=ViBuro.h
ImplementationFile=ViBuro.cpp
Filter=N

[CLS:CViBuroDoc]
Type=0
HeaderFile=ViBuroDoc.h
ImplementationFile=ViBuroDoc.cpp
Filter=N

[CLS:CStunEingab]
Type=0
HeaderFile=StunEingab.h
ImplementationFile=StunEingab.cpp
Filter=D
LastObject=ID_ARBEIT_Aufgaben
BaseClass=CFormView
VirtualFilter=VWC

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CMDIFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M

[CLS:CAboutDlg]
Type=0
HeaderFile=ViBuro.cpp
ImplementationFile=ViBuro.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_HELP_FINDER
Command9=ID_APP_ABOUT
CommandCount=9

[MNU:IDR_VIBUROTYPE]
Type=1
Class=CStunEingab
Command1=ID_FILE_CLOSE
Command2=ID_FILE_SAVE
Command3=ID_FILE_SAVE_AS
Command4=ID_FILE_PRINT
Command5=ID_FILE_PRINT_PREVIEW
Command6=ID_FILE_PRINT_SETUP
Command7=ID_FILE_MRU_FILE1
Command8=ID_APP_EXIT
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_ARBEIT_Aufgaben
Command16=ID_ARBEIT_BERICHT
Command17=ID_ARBEIT_EINSTELLUNGEN
Command18=ID_WINDOW_NEW
Command19=ID_WINDOW_CASCADE
Command20=ID_WINDOW_TILE_HORZ
Command21=ID_WINDOW_ARRANGE
Command22=ID_HELP_FINDER
Command23=ID_APP_ABOUT
CommandCount=23

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_CONTEXT_HELP
Command16=ID_HELP
CommandCount=16

[DLG:IDD_MAIN]
Type=1
ControlCount=32
Control1=IDC_SPIN_STUN,msctls_updown32,1342308450
Control2=IDC_STUN,edit,1350631424
Control3=IDC_SPIN_MIN,msctls_updown32,1342177378
Control4=IDC_MIN,edit,1350762496
Control5=IDC_SLIDER,msctls_trackbar32,1342242832
Control6=IDC_ADD,button,1342242816
Control7=IDC_DEL,button,1342242816
Control8=IDC_ANZEIG_JA,button,1342373897
Control9=IDC_ANZEIG_NEIN,button,1342177289
Control10=IDC_SPIN_TAG,msctls_updown32,1342308450
Control11=IDC_TAG,edit,1350631424
Control12=IDC_MONAT,combobox,1342242819
Control13=IDC_JAHR,edit,1350631552
Control14=IDC_STATIC,button,1342177287
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STUN_SUM,edit,1350568064
Control26=IDC_STATIC,static,1342308352
Control27=IDC_GEHALT,edit,1350568064
Control28=IDC_STATIC124,button,1342177287
Control29=IDC_STATIC,button,1342177287
Control30=IDC_STATIC,button,1342177287
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352

[DLG:IDD_WAECHTER]
Type=1
Class=CWaechter
ControlCount=7
Control1=IDC_PASSWORD,edit,1350631592
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_HILFE,button,1342242816
Control5=IDC_NAME,edit,1350631552
Control6=IDC_STATIC,static,1342177280
Control7=IDC_STATIC,static,1342177280

[CLS:CWaechter]
Type=0
HeaderFile=Waechter.h
ImplementationFile=Waechter.cpp
BaseClass=CDialog

[CLS:CEdDoc]
Type=0
HeaderFile=EdDoc.h
ImplementationFile=EdDoc.cpp
BaseClass=CDocument
Filter=N
LastObject=CEdDoc
VirtualFilter=DC

[CLS:CAufgabenView]
Type=0
HeaderFile=AufgabenView.h
ImplementationFile=AufgabenView.cpp
BaseClass=CEditView
Filter=C
LastObject=CAufgabenView
VirtualFilter=VWC

[CLS:CBerichtView]
Type=0
HeaderFile=BerichtView.h
ImplementationFile=BerichtView.cpp
BaseClass=CEditView
Filter=C
LastObject=CBerichtView
VirtualFilter=VWC

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_SAVE
Command2=ID_EDIT_CUT
Command3=ID_EDIT_COPY
Command4=ID_EDIT_PASTE
Command5=ID_FILE_PRINT
Command6=IDM_Aufgaben
Command7=IDM_BERICHT
Command8=ID_APP_ABOUT
Command9=ID_CONTEXT_HELP
Command10=ID_APP_EXIT
CommandCount=10

