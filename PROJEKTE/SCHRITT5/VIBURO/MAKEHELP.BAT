@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by VIBURO.HPJ. >"hlp\ViBuro.hm"
echo. >>"hlp\ViBuro.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\ViBuro.hm"
c:\programme\devstudio\vc\bin\makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\ViBuro.hm"
echo. >>"hlp\ViBuro.hm"
echo // Prompts (IDP_*) >>"hlp\ViBuro.hm"
c:\programme\devstudio\vc\bin\makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\ViBuro.hm"
echo. >>"hlp\ViBuro.hm"
echo // Resources (IDR_*) >>"hlp\ViBuro.hm"
c:\programme\devstudio\vc\bin\makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\ViBuro.hm"
echo. >>"hlp\ViBuro.hm"
echo // Dialogs (IDD_*) >>"hlp\ViBuro.hm"
c:\programme\devstudio\vc\bin\makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\ViBuro.hm"
echo. >>"hlp\ViBuro.hm"
echo // Frame Controls (IDW_*) >>"hlp\ViBuro.hm"
c:\programme\devstudio\vc\bin\makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\ViBuro.hm"
REM -- Make help for Project VIBURO

echo Building Win32 Help files
start /wait c:\programme\devstudio\vc\bin\hcrtf -x hlp\ViBuro.hpj
echo.

copy hlp\ViBuro.hlp c:\tmp\schritt5\*.*
copy hlp\ViBuro.cnt c:\tmp\schritt5\*.*
copy Aufgaben.txt	c:\tmp\schritt5\*.*
copy Bericht.txt	c:\tmp\schritt5\*.*
echo.


