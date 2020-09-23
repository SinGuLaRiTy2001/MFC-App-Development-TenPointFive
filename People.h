#if !defined(AFX_PEOPLE_H__4A2B43C9_94F1_40BA_89D8_61087B28A84C__INCLUDED_)
#define AFX_PEOPLE_H__4A2B43C9_94F1_40BA_89D8_61087B28A84C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "player.h"
// People.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPeople dialog

class CPeople : public CDialog
{
// Construction
public:
	CPeople(CWnd* pParent = NULL);   // standard constructor
	int control;//控制游戏人数是否已经选择，游戏能否开始的变量
	int Player;//记录选择人数
	player playe[4];
/*	player playe3[3];
	player playe4[4];
*/
// Dialog Data
	//{{AFX_DATA(CPeople)
	enum { IDD = IDD_PEOPLE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPeople)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPeople)
	afx_msg void OnTwo();
	afx_msg void OnThree();
	afx_msg void OnFour();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PEOPLE_H__4A2B43C9_94F1_40BA_89D8_61087B28A84C__INCLUDED_)
