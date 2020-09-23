// Name4.cpp : implementation file
//

#include "stdafx.h"
#include "Legend.h"
#include "Name4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CName4 dialog


CName4::CName4(CWnd* pParent /*=NULL*/)
	: CDialog(CName4::IDD, pParent)
{
	//{{AFX_DATA_INIT(CName4)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CName4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CName4)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Text (pDX, IDC_NAME4A, name4a);
	DDX_Text (pDX, IDC_NAME4B, name4b);
	DDX_Text (pDX, IDC_NAME4C, name4c);
	DDX_Text (pDX, IDC_NAME4D, name4d);//数据的代入

}


BEGIN_MESSAGE_MAP(CName4, CDialog)
	//{{AFX_MSG_MAP(CName4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CName4 message handlers

void CName4::OnOK() 
{
	// TODO: Add extra validation here
	char ch1[20];
	char ch2[20];
	char ch3[20];
	char ch4[20];
	GetDlgItem(IDC_NAME4A)->GetWindowText(ch1, 20);
	GetDlgItem(IDC_NAME4B)->GetWindowText(ch2, 20);
	GetDlgItem(IDC_NAME4C)->GetWindowText(ch3, 20);
	GetDlgItem(IDC_NAME4D)->GetWindowText(ch4, 20);
	if(strlen(ch1)==0||strlen(ch2)==0||strlen(ch3)==0||strlen(ch4)==0){
		MessageBox("请填写玩家姓名！");
		return;
	}

	
	CDialog::OnOK();
}

