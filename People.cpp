// People.cpp : implementation file
//

#include "stdafx.h"
#include "Legend.h"
#include "People.h"
#include "player.h"
#include "Name2.h"
#include "Name3.h"
#include "Name4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPeople dialog


CPeople::CPeople(CWnd* pParent /*=NULL*/)
	: CDialog(CPeople::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPeople)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPeople::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPeople)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPeople, CDialog)
	//{{AFX_MSG_MAP(CPeople)
	ON_BN_CLICKED(IDC_TWO, OnTwo)
	ON_BN_CLICKED(IDC_THREE, OnThree)
	ON_BN_CLICKED(IDC_FOUR, OnFour)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPeople message handlers

void CPeople::OnTwo() 
{
	// TODO: Add your control notification handler code here
	control=1;	Player=2;
}

void CPeople::OnThree() 
{
	// TODO: Add your control notification handler code here
 	control=1;	Player=3;
}

void CPeople::OnFour() 
{
	// TODO: Add your control notification handler code here
 	control=1;	Player=4;
}

void CPeople::OnOK() 
{
	// TODO: Add extra validation here
	if(control==1)//按num即人数确定弹出对话框
	{
		switch(Player)
		{
		case 2: {CName2 dlg;  dlg.DoModal(); 
			playe[0].name=dlg.name2a ; 
			playe[1].name=dlg.name2b;
			//if(playe[0].name=="文简")playe[0].Power=10;
			char a[20];
			char b[20];
			memcpy(a,dlg.name2a,dlg.name2a.GetLength());//用CString转成char
			memcpy(b,dlg.name2b,dlg.name2b.GetLength());//用CString转成char
			for(int i=19;i>=0;i--){
				if(a[i]=='u'&&a[i-1]=='l'&&a[i-2]=='p')
					playe[0].Power=10;
			}
			for(int j=19;j>=0;j--){
				if(a[j]=='b'&&a[j-1]=='u'&&a[j-2]=='s')
					playe[0].Power=-10;
			}
			for(int m=19;m>=0;m--){
				if(b[m]=='u'&&b[m-1]=='l'&&b[m-2]=='p')
					playe[1].Power=10;
			}
			for(int n=19;n>=0;n--){
				if(b[n]=='b'&&b[n-1]=='u'&&b[n-2]=='s')
					playe[1].Power=-10;
			}
			break;}         //传玩家名字
		case 3: {CName3 dlg;   dlg.DoModal();
			playe[0].name=dlg.name3a ;
			playe[1].name=dlg.name3b ;
			playe[2].name=dlg.name3c ; 
			char a[20];
			char b[20];
			char c[20];
			memcpy(a,dlg.name3a,dlg.name3a.GetLength());//用CString转成char
			memcpy(b,dlg.name3b,dlg.name3b.GetLength());//用CString转成char
			memcpy(c,dlg.name3c,dlg.name3c.GetLength());//用CString转成char
			for(int i=19;i>=0;i--){
				if(a[i]=='u'&&a[i-1]=='l'&&a[i-2]=='p')
					playe[0].Power=10;
			}
			for(int j=19;j>=0;j--){
				if(a[j]=='b'&&a[j-1]=='u'&&a[j-2]=='s')
					playe[0].Power=-10;
			}
			for(int m=19;m>=0;m--){
				if(b[m]=='u'&&b[m-1]=='l'&&b[m-2]=='p')
					playe[1].Power=10;
			}
			for(int n=19;n>=0;n--){
				if(b[n]=='b'&&b[n-1]=='u'&&b[n-2]=='s')
					playe[1].Power=-10;
			}
			for(int p=19;p>=0;p--){
				if(c[p]=='u'&&c[p-1]=='l'&&c[p-2]=='p')
					playe[2].Power=10;
			}
			for(int q=19;q>=0;q--){
				if(c[q]=='b'&&c[q-1]=='u'&&c[q-2]=='s')
					playe[2].Power=-10;
			}
			break;}         //传玩家名字
		case 4: {CName4 dlg;    dlg.DoModal();  
			playe[0].name=dlg.name4a ;
			playe[1].name=dlg.name4b ;
			playe[2].name=dlg.name4c ; 
			playe[3].name=dlg.name4d ; 
			char a[20];
			char b[20];
			char c[20];
			char d[20];
			memcpy(a,dlg.name4a,dlg.name4a.GetLength());//用CString转成char
			memcpy(b,dlg.name4b,dlg.name4b.GetLength());//用CString转成char
			memcpy(c,dlg.name4c,dlg.name4c.GetLength());//用CString转成char
			memcpy(d,dlg.name4d,dlg.name4d.GetLength());//用CString转成char
			for(int i=19;i>=0;i--){
				if(a[i]=='u'&&a[i-1]=='l'&&a[i-2]=='p')
					playe[0].Power=10;
			}
			for(int j=19;j>=0;j--){
				if(a[j]=='b'&&a[j-1]=='u'&&a[j-2]=='s')
					playe[0].Power=-10;
			}
			for(int m=19;m>=0;m--){
				if(b[m]=='u'&&b[m-1]=='l'&&b[m-2]=='p')
					playe[1].Power=10;
			}
			for(int n=19;n>=0;n--){
				if(b[n]=='b'&&b[n-1]=='u'&&b[n-2]=='s')
					playe[1].Power=-10;
			}
			for(int p=19;p>=0;p--){
				if(c[p]=='u'&&c[p-1]=='l'&&c[p-2]=='p')
					playe[2].Power=10;
			}
			for(int q=19;q>=0;q--){
				if(c[q]=='b'&&c[q-1]=='u'&&c[q-2]=='s')
					playe[2].Power=-10;
			}
			for(int x=19;x>=0;x--){
				if(d[x]=='u'&&d[x-1]=='l'&&d[x-2]=='p')
					playe[3].Power=10;
			}
			for(int y=19;y>=0;y--){
				if(d[y]=='b'&&d[y-1]=='u'&&d[y-2]=='s')
					playe[3].Power=-10;
			}
			break;
				}         //传玩家名字
		default: MessageBox("请选择游戏人数！"); return;
		}
 		
 	}
	else
	{
		MessageBox("请选择游戏人数！");
		return;
	}
	CDialog::OnOK();
}

void CPeople::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	exit(0); //退出程序
	
	CDialog::OnCancel();
}

