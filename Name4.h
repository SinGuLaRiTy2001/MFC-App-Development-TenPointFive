#if !defined(AFX_NAME4_H__E10B84B5_2BFD_4C1A_9E40_A955BC2F3465__INCLUDED_)
#define AFX_NAME4_H__E10B84B5_2BFD_4C1A_9E40_A955BC2F3465__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Name4.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CName4 dialog

class CName4 : public CDialog
{
// Construction
public:
	CName4(CWnd* pParent = NULL);   // standard constructor
	CString name4a;//A玩家姓名
	CString name4b;//B玩家姓名
	CString name4c;//C玩家姓名
	CString name4d;//D玩家姓名


// Dialog Data
	//{{AFX_DATA(CName4)
	enum { IDD = IDD_NAME4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CName4)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CName4)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NAME4_H__E10B84B5_2BFD_4C1A_9E40_A955BC2F3465__INCLUDED_)
