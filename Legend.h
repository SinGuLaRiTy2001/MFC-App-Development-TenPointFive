// Legend.h : main header file for the Legend application
//

#if !defined(AFX_Legend_H__CE44513B_7DE6_4C87_978E_4535C9A79F11__INCLUDED_)
#define AFX_Legend_H__CE44513B_7DE6_4C87_978E_4535C9A79F11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "mmsystem.h"
#pragma comment(lib,"Winmm.lib")

/////////////////////////////////////////////////////////////////////////////
// CMyLegendApp:
// See Legend.cpp for the implementation of this class
//

class CMyLegendApp : public CWinApp
{
public:
	CMyLegendApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyLegendApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyLegendApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_Legend_H__CE44513B_7DE6_4C87_978E_4535C9A79F11__INCLUDED_)
