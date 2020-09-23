#if !defined(AFX_NAME2_H__641B3AC3_FEC0_4FA8_A589_6AD0DEB15517__INCLUDED_)
#define AFX_NAME2_H__641B3AC3_FEC0_4FA8_A589_6AD0DEB15517__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Name2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CName2 dialog

class CName2 : public CDialog
{
// Construction
public:
	CName2(CWnd* pParent = NULL);   // standard constructor
//两人对战
	CString name2a;//A玩家姓名
	CString name2b;//B玩家姓名

// Dialog Data
	//{{AFX_DATA(CName2)
	enum { IDD = IDD_NAME2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CName2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CName2)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAME2_H__641B3AC3_FEC0_4FA8_A589_6AD0DEB15517__INCLUDED_)
