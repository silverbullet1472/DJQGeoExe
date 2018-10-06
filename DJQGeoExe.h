// DJQGeoExe.h : main header file for the DJQGEOEXE application
//

#if !defined(AFX_DJQGEOEXE_H__BD1BAE26_AC95_45B3_AE87_C6E0BF595832__INCLUDED_)
#define AFX_DJQGEOEXE_H__BD1BAE26_AC95_45B3_AE87_C6E0BF595832__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDJQGeoExeApp:
// See DJQGeoExe.cpp for the implementation of this class
//

class CDJQGeoExeApp : public CWinApp
{
public:
	CDJQGeoExeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDJQGeoExeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDJQGeoExeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DJQGEOEXE_H__BD1BAE26_AC95_45B3_AE87_C6E0BF595832__INCLUDED_)
