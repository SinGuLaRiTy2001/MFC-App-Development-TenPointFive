#if !defined(AFX_NAME3_H__473C983C_18B0_4FAF_8578_F80DDBDE06F9__INCLUDED_)
#define AFX_NAME3_H__473C983C_18B0_4FAF_8578_F80DDBDE06F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Name3.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CName3 dialog

class CName3 : public CDialog
{
// Construction
public:
	CName3(CWnd* pParent = NULL);   // standard constructor
	CString name3a;//A玩家姓名
	CString name3b;//B玩家姓名
	CString name3c;//C玩家姓名

// Dialog Data
	//{{AFX_DATA(CName3)
	enum { IDD = IDD_NAME3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CName3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CName3)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAME3_H__473C983C_18B0_4FAF_8578_F80DDBDE06F9__INCLUDED_)
