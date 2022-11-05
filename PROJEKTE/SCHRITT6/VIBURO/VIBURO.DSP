# Microsoft Developer Studio Project File - Name="ViBuro" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ViBuro - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VIBURO.MAK".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VIBURO.MAK" CFG="ViBuro - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ViBuro - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ViBuro - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ViBuro - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "c:\tmp"
# PROP Intermediate_Dir "c:\tmp"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "ViBuro - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "c:\tmp\schritt6"
# PROP Intermediate_Dir "c:\tmp\schritt6"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386

!ENDIF 

# Begin Target

# Name "ViBuro - Win32 Release"
# Name "ViBuro - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\ArbeitsTag.cpp
# End Source File
# Begin Source File

SOURCE=.\Arbeitszeitlist.cpp
# End Source File
# Begin Source File

SOURCE=.\Arbeitszeitlist.h
# End Source File
# Begin Source File

SOURCE=.\AufgabeView.cpp
# End Source File
# Begin Source File

SOURCE=.\BerichtView.cpp
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Datum.cpp
# End Source File
# Begin Source File

SOURCE=.\EdDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\Freimitb.cpp
# End Source File
# Begin Source File

SOURCE=.\Leiter.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Mitarb.cpp
# End Source File
# Begin Source File

SOURCE=.\NewDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\Option.cpp
# End Source File
# Begin Source File

SOURCE=.\Person.cpp
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\SetParam.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StunEingab.cpp
# End Source File
# Begin Source File

SOURCE=.\ViBuro.cpp
# End Source File
# Begin Source File

SOURCE=.\hlp\ViBuro.hpj

!IF  "$(CFG)" == "ViBuro - Win32 Release"

# Begin Custom Build - Making help file...
OutDir=c:\tmp
ProjDir=.
TargetName=VIBURO
InputPath=.\hlp\ViBuro.hpj

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	"$(ProjDir)\makehelp.bat"

# End Custom Build

!ELSEIF  "$(CFG)" == "ViBuro - Win32 Debug"

# Begin Custom Build - Making help file...
OutDir=c:\tmp\schritt6
ProjDir=.
TargetName=VIBURO
InputPath=.\hlp\ViBuro.hpj

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	"$(ProjDir)\makehelp.bat"

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ViBuro.rc
# End Source File
# Begin Source File

SOURCE=.\ViBuroDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\Waechter.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\Arbeitstag.h
# End Source File
# Begin Source File

SOURCE=.\Aufgabeview.h
# End Source File
# Begin Source File

SOURCE=.\Berichtview.h
# End Source File
# Begin Source File

SOURCE=.\Childfrm.h
# End Source File
# Begin Source File

SOURCE=.\Datum.h
# End Source File
# Begin Source File

SOURCE=.\Eddoc.h
# End Source File
# Begin Source File

SOURCE=.\Freimitb.h
# End Source File
# Begin Source File

SOURCE=.\Leiter.h
# End Source File
# Begin Source File

SOURCE=.\Mainfrm.h
# End Source File
# Begin Source File

SOURCE=.\Mitarb.h
# End Source File
# Begin Source File

SOURCE=.\Newdialog.h
# End Source File
# Begin Source File

SOURCE=.\Option.h
# End Source File
# Begin Source File

SOURCE=.\Person.h
# End Source File
# Begin Source File

SOURCE=.\SetParam.h
# End Source File
# Begin Source File

SOURCE=.\Stdafx.h
# End Source File
# Begin Source File

SOURCE=.\Stuneingab.h
# End Source File
# Begin Source File

SOURCE=.\Viburo.h
# End Source File
# Begin Source File

SOURCE=.\Viburodoc.h
# End Source File
# Begin Source File

SOURCE=.\Waechter.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\mainfram.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ViBuro.ico
# End Source File
# Begin Source File

SOURCE=.\res\ViBuro.rc2
# End Source File
# Begin Source File

SOURCE=.\res\ViBuroDoc.ico
# End Source File
# End Group
# End Target
# End Project
# Section ViBuro : {335F1903-AE2F-11CF-91A0-0000E8A54B33}
# 	0:12:Waechter.cpp:D:\Projects\Vis_cpp\vcpp\Schritt4\ViBuro\Waechter.cpp
# 	0:10:Waechter.h:D:\Projects\Vis_cpp\vcpp\Schritt4\ViBuro\Waechter.h
# 	1:12:IDD_WAECHTER:102
# 	2:16:Resource Include:resource.h
# 	2:12:IDD_WAECHTER:IDD_WAECHTER
# 	2:12:Waechter.cpp:Waechter.cpp
# 	2:10:ENUM: enum:enum
# 	2:16:CLASS: CWaechter:CWaechter
# 	2:19:Application Include:ViBuro.h
# 	2:10:Waechter.h:Waechter.h
# End Section
