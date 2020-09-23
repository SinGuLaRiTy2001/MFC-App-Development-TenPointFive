// Name3.cpp : implementation file
//

#include "stdafx.h"
#include "Legend.h"
#include "Name3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CName3 dialog


CName3::CName3(CWnd* pParent /*=NULL*/)
	: CDialog(CName3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CName3)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CName3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CName3)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Text (pDX, IDC_NAME3A, name3a);
	DDX_Text (pDX, IDC_NAME3B, name3b);
	DDX_Text (pDX, IDC_NAME3C, name3c);
}


BEGIN_MESSAGE_MAP(CName3, CDialog)
	//{{AFX_MSG_MAP(CName3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CName3 message handlers

void CName3::OnOK() 
{
	// TODO: Add extra validation here

	char ch1[20];
	char ch2[20];
	char ch3[20];
	GetDlgItem(IDC_NAME3A)->GetWindowText(ch1, 20);
	GetDlgItem(IDC_NAME3B)->GetWindowText(ch2, 20);
	GetDlgItem(IDC_NAME3C)->GetWindowText(ch3, 20);
	if(strlen(ch1)==0||strlen(ch2)==0||strlen(ch3)==0){
		MessageBox("ÇëÌîĞ´Íæ¼ÒĞÕÃû£¡");
		return;
	}
	CDialog::OnOK();
}

