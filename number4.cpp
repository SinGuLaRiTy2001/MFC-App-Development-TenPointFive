// number4.cpp : implementation file
//

#include "stdafx.h"
#include "Legend.h"
#include "number4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
#endif

/////////////////////////////////////////////////////////////////////////////
// number4 dialog


number4::number4(CWnd* pParent /*=NULL*/)
	: CDialog(number4::IDD, pParent)
{
	//{{AFX_DATA_INIT(number4)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void number4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(number4)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(number4, CDialog)
	//{{AFX_MSG_MAP(number4)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// number4 message handlers
