# Microsoft Developer Studio Project File - Name="DJQGeoExe" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=DJQGeoExe - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DJQGeoExe.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DJQGeoExe.mak" CFG="DJQGeoExe - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DJQGeoExe - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "DJQGeoExe - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DJQGeoExe - Win32 Release"

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

!ELSEIF  "$(CFG)" == "DJQGeoExe - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /stack:0x100000 /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "DJQGeoExe - Win32 Release"
# Name "DJQGeoExe - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DDAline.cpp
# End Source File
# Begin Source File

SOURCE=.\DJQGeoExe.cpp
# End Source File
# Begin Source File

SOURCE=.\DJQGeoExe.rc
# End Source File
# Begin Source File

SOURCE=.\DJQGeoExeDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\DJQGeoExeView.cpp
# End Source File
# Begin Source File

SOURCE=.\GeoLayer.cpp
# End Source File
# Begin Source File

SOURCE=.\GeoPolyline.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Map1.cpp
# End Source File
# Begin Source File

SOURCE=.\Map2.cpp
# End Source File
# Begin Source File

SOURCE=.\Map3.cpp
# End Source File
# Begin Source File

SOURCE=.\Map4.cpp
# End Source File
# Begin Source File

SOURCE=.\Map5.cpp
# End Source File
# Begin Source File

SOURCE=.\Map6.cpp
# End Source File
# Begin Source File

SOURCE=.\MyClipLine.cpp
# End Source File
# Begin Source File

SOURCE=.\Myline.cpp
# End Source File
# Begin Source File

SOURCE=.\Mypolygon.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DDAline.h
# End Source File
# Begin Source File

SOURCE=.\DJQGeoExe.h
# End Source File
# Begin Source File

SOURCE=.\DJQGeoExeDoc.h
# End Source File
# Begin Source File

SOURCE=.\DJQGeoExeView.h
# End Source File
# Begin Source File

SOURCE=.\GeoLayer.h
# End Source File
# Begin Source File

SOURCE=.\GeoPolyline.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Map1.h
# End Source File
# Begin Source File

SOURCE=.\Map2.h
# End Source File
# Begin Source File

SOURCE=.\Map3.h
# End Source File
# Begin Source File

SOURCE=.\Map4.h
# End Source File
# Begin Source File

SOURCE=.\Map5.h
# End Source File
# Begin Source File

SOURCE=.\Map6.h
# End Source File
# Begin Source File

SOURCE=.\MyClipLine.h
# End Source File
# Begin Source File

SOURCE=.\Myline.h
# End Source File
# Begin Source File

SOURCE=.\Mypolygon.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\DJQGeoExe.ico
# End Source File
# Begin Source File

SOURCE=.\res\DJQGeoExe.rc2
# End Source File
# Begin Source File

SOURCE=.\res\DJQGeoExeDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
