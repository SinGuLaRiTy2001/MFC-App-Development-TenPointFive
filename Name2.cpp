// Name2.cpp : implementation file
//

#include "stdafx.h"
#include "Legend.h"
#include "Name2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CName2 dialog


CName2::CName2(CWnd* pParent /*=NULL*/)
	: CDialog(CName2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CName2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CName2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CName2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Text (pDX, IDC_NAME2A, name2a);
	DDX_Text (pDX, IDC_NAME2B, name2b);

}


BEGIN_MESSAGE_MAP(CName2, CDialog)
	//{{AFX_MSG_MAP(CName2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CName2 message handlers

void CName2::OnOK() 
{
	// TODO: Add extra validation here
	//定义两个字符串数组
	char ch1[20];
	char ch2[20];
	GetDlgItem(IDC_NAME2A)->GetWindowText(ch1, 20);//得到文本
	GetDlgItem(IDC_NAME2B)->GetWindowText(ch2, 20);
	if(ch1[20]==NULL||ch2[20]==NULL){
		MessageBox("请填写玩家姓名！");
		return;
	}

	CDialog::OnOK();
}
