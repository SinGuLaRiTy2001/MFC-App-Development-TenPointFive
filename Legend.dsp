# Microsoft Developer Studio Project File - Name="Legend" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Legend - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Legend.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Legend.mak" CFG="Legend - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Legend - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Legend - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Legend - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Legend - Win32 Release"
# Name "Legend - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Card.cpp

!IF  "$(CFG)" == "Legend - Win32 Release"

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Legend.cpp

!IF  "$(CFG)" == "Legend - Win32 Release"

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Legend.rc
# End Source File
# Begin Source File

SOURCE=.\LegendDoc.cpp

!IF  "$(CFG)" == "Legend - Win32 Release"

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\LegendView.cpp

!IF  "$(CFG)" == "Legend - Win32 Release"

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "Legend - Win32 Release"

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Managers.cpp

!IF  "$(CFG)" == "Legend - Win32 Release"

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Name2.cpp

!IF  "$(CFG)" == "Legend - Win32 Release"

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Name3.cpp

!IF  "$(CFG)" == "Legend - Win32 Release"

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Name4.cpp

!IF  "$(CFG)" == "Legend - Win32 Release"

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\People.cpp

!IF  "$(CFG)" == "Legend - Win32 Release"

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\player.cpp

!IF  "$(CFG)" == "Legend - Win32 Release"

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Sign.cpp

!IF  "$(CFG)" == "Legend - Win32 Release"

!ELSEIF  "$(CFG)" == "Legend - Win32 Debug"

# SUBTRACT CPP /YX /Yc /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Card.h
# End Source File
# Begin Source File

SOURCE=.\Legend.h
# End Source File
# Begin Source File

SOURCE=.\LegendDoc.h
# End Source File
# Begin Source File

SOURCE=.\LegendView.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Managers.h
# End Source File
# Begin Source File

SOURCE=.\Name2.h
# End Source File
# Begin Source File

SOURCE=.\Name3.h
# End Source File
# Begin Source File

SOURCE=.\Name4.h
# End Source File
# Begin Source File

SOURCE=.\People.h
# End Source File
# Begin Source File

SOURCE=.\player.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Sign.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\background.bmp
# End Source File
# Begin Source File

SOURCE=.\res\card.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cl1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cl10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cl2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cl3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cl4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cl5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cl6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cl7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cl8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cl9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\clj.bmp
# End Source File
# Begin Source File

SOURCE=.\res\clq.bmp
# End Source File
# Begin Source File

SOURCE=.\res\clz.bmp
# End Source File
# Begin Source File

SOURCE=.\res\di1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\di10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\di2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\di3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\di4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\di5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\di6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\di7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\di8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\di9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dij.bmp
# End Source File
# Begin Source File

SOURCE=.\res\diq.bmp
# End Source File
# Begin Source File

SOURCE=.\res\diz.bmp
# End Source File
# Begin Source File

SOURCE=.\res\he1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\he10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\he2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\he3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\he4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\he5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\he6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\he7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\he8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\he9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hej.bmp
# End Source File
# Begin Source File

SOURCE=.\res\heq.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hez.bmp
# End Source File
# Begin Source File

SOURCE=.\res\IDB_P1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\IDB_P3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\IDB_P5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\IDB_P6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\IDB_P7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Legend.ico
# End Source File
# Begin Source File

SOURCE=.\res\Legend.rc2
# End Source File
# Begin Source File

SOURCE=.\res\LegendDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\rank.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rule.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sp1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sp10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sp2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sp3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sp4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sp5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sp6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sp7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sp8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sp9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\spj.bmp
# End Source File
# Begin Source File

SOURCE=.\res\spq.bmp
# End Source File
# Begin Source File

SOURCE=.\res\spz.bmp
# End Source File
# Begin Source File

SOURCE=.\res\start.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=".\res\±³¾°.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\ï¿½ï¿½ï¿½ï¿½.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\BGM2.wav
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
