// LegendView.cpp : implementation of the CMyLegendView class
//

#include "stdafx.h"
#include "Legend.h"
#include "People.h"
#include "LegendDoc.h"
#include "LegendView.h"
#include "Managers.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyLegendView

IMPLEMENT_DYNCREATE(CMyLegendView, CView)

BEGIN_MESSAGE_MAP(CMyLegendView, CView)
	//{{AFX_MSG_MAP(CMyLegendView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyLegendView construction/destruction

CMyLegendView::CMyLegendView()
{
	// TODO: add construction code here

}

CMyLegendView::~CMyLegendView()
{
}

BOOL CMyLegendView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyLegendView drawing

void CMyLegendView::OnDraw(CDC* pDC)
{
	CMyLegendDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	//将位图加载到程序中，初始化各个CDC
	static BOOL Loaded=false;
	if(Loaded==false)
	{
		m_back.LoadBitmap(IDB_BACK);
		BACK.CreateCompatibleDC(pDC);
		BACK.SelectObject(m_back);

		m_begin.LoadBitmap(IDB_BEGIN);
		BEGIN.CreateCompatibleDC(pDC);
		BEGIN.SelectObject(m_begin);
		
		m_rule.LoadBitmap(IDB_RULE);
		RULE.CreateCompatibleDC(pDC);
		RULE.SelectObject(m_rule);
		
		Loaded=true;
	};
	pDC->BitBlt(0, 0, 857, 580, &BACK, 0, 0, SRCCOPY);
	pDC->BitBlt(359, 331, 193, 46, &BEGIN, 0, 0, SRCCOPY);
	pDC->BitBlt(359, 400, 184, 46, &RULE, 0, 0, SRCCOPY);

}

/////////////////////////////////////////////////////////////////////////////
// CMyLegendView printing

BOOL CMyLegendView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyLegendView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyLegendView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyLegendView diagnostics

#ifdef _DEBUG
void CMyLegendView::AssertValid() const
{
	CView::AssertValid();
}

void CMyLegendView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyLegendDoc* CMyLegendView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyLegendDoc)));
	return (CMyLegendDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyLegendView message handlers

void CMyLegendView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	//分别另外定义x,y,以便在提取利用传进来的坐标的同时避免发生对原数据进行不必要的修改
	int x=point.x;
	int y=point.y;
	if(x>=358&&x<=544&&y>=327&&y<=371)    //游戏开始
	{
		CDC *pDC=GetDC();
		m_playingback.LoadBitmap(IDB_P1);
		PLAYINGBACK.CreateCompatibleDC(pDC);
		PLAYINGBACK.SelectObject(m_playingback);
		LOOP:pDC->BitBlt(0, 0, 857, 580, &PLAYINGBACK, 0, 0, SRCCOPY);//开始后换背景
		CPeople p(0);
		p.DoModal();               //
		manager.Player=p.Player;
		int i=0;
		for(;i<4;i++){
			manager.play[i]=p.playe[i];
			manager.play[i].add=i;
			p.playe[i].add=i;
		}
		manager.GameStart();
		CardShow();
	//发牌，
		while(manager.count<=52){
			if(manager.Deal()==1){
				goto LOOP;
			}
			CardShow();
			manager.BubbleSort();
			manager.Ranking();
			manager.Add_BubbleSort();
			RankShow();
		}
	}
	if(x>=358&&x<=544&&y>=400&&y<=448)   
		MessageBox("牌不分花色，只按点数计分，1～9按牌点计，其它按0.5点计。若点数之和超过10.5，计0分；正好10.5，计3分；当玩家要5张牌，且5张均为0.5点时，计5分；若双方均不足10.5，则接近10.5的计2分，另一方计1分；若双方均不足10.5，且点数相同，则双方均计0.5；若只有一方不足10.5，则根据对方得分两种情况，若对方得分>=3，则计1分，否则计2分。");//游戏规则说明	
	CView::OnLButtonDown(nFlags, point);
}

void CMyLegendView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//跟踪光标鼠标
	int mx=point.x;
	int my=point.y;

	CString st;
	CDC *pDC=GetDC();
	st.Format("%d,%d", point.x, point.y);
	pDC->TextOut(400, 5, st);
	ReleaseDC(pDC);

	CView::OnMouseMove(nFlags, point);
}

void CMyLegendView::RankShow(){
	for(int i=0;i<manager.Player;i++)
	{
		CDC *pDC=GetDC();
		CString temp;
		temp.Format(_T("%.1lf"),manager.play[i].Power); 
		switch(manager.play[i].add)
		{
		case 0:{pDC->TextOut(350, 200+60*i, "玩家一：");break;}
		case 1:{pDC->TextOut(350, 200+60*i, "玩家二：");break;}
		case 2:{pDC->TextOut(350, 200+60*i, "玩家三：");break;}
		case 3:{pDC->TextOut(350, 200+60*i, "玩家四：");break;}
		}
		pDC->TextOut(400, 200+60*i, manager.play[i].name+"得分:"+temp);
		temp.Format(_T("%.d"),manager.play[i].rank);
		pDC->TextOut(400, 220+60*i, "排名:"+temp);
		int ctemp;
		ctemp=52-manager.count;
		temp.Format(_T("%.2d"),ctemp);
		pDC->TextOut(340,180,"牌库剩余数量为："+temp);
		ReleaseDC(pDC);
	}
	/*CDC *pDC=GetDC();
	CString temp;
	temp.Format(_T("%.1lf"),manager.play[0].Power); 
	pDC->TextOut(630, 100, manager.play[0].name+"得分:"+temp);
	temp.Format(_T("%.d"),manager.play[0].rank);
	pDC->TextOut(630, 150, "排名:"+temp);
	ReleaseDC(pDC);
	
	CDC *pD=GetDC();
	temp.Format(_T("%.1lf"),manager.play[1].Power); 
	pD->TextOut(630, 211, manager.play[1].name+"得分:"+temp);
	temp.Format(_T("%.d"), manager.play[1].rank);
	pD->TextOut(630, 261, "排名:"+temp);
	ReleaseDC(pD);

	if(manager.Player>=3)
	{
		CDC *pDC=GetDC();
		temp.Format(_T("%.1lf"),manager.play[2].Power); 
		pDC->TextOut(630, 322, manager.play[2].name+"得分:"+temp);
		temp.Format(_T("%.d"),manager.play[2].rank);
		pDC->TextOut(630, 372, "排名:"+temp);
		ReleaseDC(pDC);
		if(manager.Player==4)
		{
			CString sr4;
			CString sa4;
			CDC *pDC=GetDC();
			temp.Format(_T("%.1lf"),manager.play[3].Power); 
			pDC->TextOut(630, 433, manager.play[3].name+"得分:"+temp);
			temp.Format(_T("%.d"),manager.play[3].rank);
			pDC->TextOut(630, 483, "排名:"+temp);
			ReleaseDC(pDC);
		}
		
	}*/
}
	void CMyLegendView::CardShow(){
		int m=60,n=80;//牌的大小
		int i=70,j=70;//初始：第一个玩家的第一张牌的位置
		for(int q=0; q<2; q++)//四个玩家
		{
			j=70;
			switch(q)
			{
			case 0:{CDC *pDC=GetDC();pDC->TextOut(150, 180, "玩家一：");CBitmap m_pic1;CDC P1;m_pic1.LoadBitmap(IDB_P2);P1.CreateCompatibleDC(pDC);P1.SelectObject(m_pic1);pDC->BitBlt(150,200,80,80,&P1,0,0,SRCCOPY);break;}
			case 1:{CDC *pDC=GetDC();pDC->TextOut(620, 180, "玩家二：");CBitmap m_pic2;CDC P2;m_pic2.LoadBitmap(IDB_P3);P2.CreateCompatibleDC(pDC);P2.SelectObject(m_pic2);pDC->BitBlt(620,200,80,80,&P2,0,0,SRCCOPY);break;}
			}
			for(int p=0; p<5; p++) 
			{ 
				CDC *pDC=GetDC();//玩家的五张牌
				switch(manager.play[q].a[p].Suit){ //玩家q的第p张牌 花色为suit
					case 2: {
						switch (manager.play[q].a[p].Number) {
							case 'A': 
								{ CBitmap m_H1; CDC H1; m_H1.LoadBitmap(IDB_H1); H1.CreateCompatibleDC(pDC); H1.SelectObject(m_H1); pDC->BitBlt(i, j, m, n, &H1, 0, 0, SRCCOPY); break;}

							case '2':
								{ CBitmap m_H2; CDC H2; m_H2.LoadBitmap(IDB_H2); H2.CreateCompatibleDC(pDC); H2.SelectObject(m_H2); pDC->BitBlt(i, j, m, n, &H2, 0, 0, SRCCOPY); break;}

							case '3':
								{ CBitmap m_H3; CDC H3; m_H3.LoadBitmap(IDB_H3); H3.CreateCompatibleDC(pDC); H3.SelectObject(m_H3); pDC->BitBlt(i, j, m, n, &H3, 0, 0, SRCCOPY); break;}

							case '4':
								{ CBitmap m_H4; CDC H4; m_H4.LoadBitmap(IDB_H4); H4.CreateCompatibleDC(pDC); H4.SelectObject(m_H4); pDC->BitBlt(i, j, m, n, &H4, 0, 0, SRCCOPY); break;}

							case '5': 
								{ CBitmap m_H5; CDC H5; m_H5.LoadBitmap(IDB_H5); H5.CreateCompatibleDC(pDC); H5.SelectObject(m_H5); pDC->BitBlt(i, j, m, n, &H5, 0, 0, SRCCOPY); break;}

							case '6':
								{CBitmap m_H6; CDC H6; m_H6.LoadBitmap(IDB_H6);
								H6.CreateCompatibleDC(pDC); H6.SelectObject(m_H6);
								pDC->BitBlt(i, j, m, n, &H6, 0, 0, SRCCOPY);
								break;
							}

							case '7': {
								CBitmap m_H7; CDC H7; m_H7.LoadBitmap(IDB_H7);
								H7.CreateCompatibleDC(pDC); H7.SelectObject(m_H7);
								pDC->BitBlt(i, j, m, n, &H7, 0, 0, SRCCOPY);
								break;
							}

							case '8': {
								CBitmap m_H8; CDC H8; m_H8.LoadBitmap(IDB_H8);
								H8.CreateCompatibleDC(pDC); H8.SelectObject(m_H8);
								pDC->BitBlt(i, j, m, n, &H8, 0, 0, SRCCOPY);
								break;
							}

							case '9': {
								CBitmap m_H9; CDC H9; m_H9.LoadBitmap(IDB_H9);
								H9.CreateCompatibleDC(pDC); H9.SelectObject(m_H9);
								pDC->BitBlt(i, j, m, n, &H9, 0, 0, SRCCOPY);
								break;
							}

							case 'T': {
								CBitmap m_H10; CDC H10; m_H10.LoadBitmap(IDB_H10);
								H10.CreateCompatibleDC(pDC); H10.SelectObject(m_H10);
								pDC->BitBlt(i, j, m, n, &H10, 0, 0, SRCCOPY);
								break;
							}
							case 'J': {
								CBitmap m_H11; CDC H11; m_H11.LoadBitmap(IDB_H11);
								H11.CreateCompatibleDC(pDC); H11.SelectObject(m_H11);
								pDC->BitBlt(i, j, m, n, &H11, 0, 0, SRCCOPY);
								break;
							}
							case 'Q': {
								CBitmap m_H12; CDC H12; m_H12.LoadBitmap(IDB_H12);
								H12.CreateCompatibleDC(pDC); H12.SelectObject(m_H12);
								pDC->BitBlt(i, j, m, n, &H12, 0, 0, SRCCOPY);
								break;
							}

							case 'K': {
								CBitmap m_H13; CDC H13; m_H13.LoadBitmap(IDB_H13);
								H13.CreateCompatibleDC(pDC); H13.SelectObject(m_H13);
								pDC->BitBlt(i, j, m, n, &H13, 0, 0, SRCCOPY);
								break;
							}
						}
						break;
					}

					case 3: {
						switch(manager.play[q].a[p].Number){
							case 'A':{
								CBitmap m_A14; CDC A14; m_A14.LoadBitmap(IDB_A14);  
								A14.CreateCompatibleDC(pDC); A14.SelectObject(m_A14);
								pDC->BitBlt(i, j, m, n, &A14, 0, 0, SRCCOPY);
								break;
							}
							
							case '2':{
								CBitmap m_A15; CDC A15; m_A15.LoadBitmap(IDB_A15); 
								A15.CreateCompatibleDC(pDC); A15.SelectObject(m_A15);  
								pDC->BitBlt(i, j, m, n, &A15, 0, 0, SRCCOPY);
								break;
							}
							
							case '3':{
								CBitmap m_A16; CDC A16; m_A16.LoadBitmap(IDB_A16); 
								A16.CreateCompatibleDC(pDC); A16.SelectObject(m_A16); 
								pDC->BitBlt(i, j, m, n, &A16, 0, 0, SRCCOPY);	
								break;
							}
						
							case '4':{
								CBitmap m_A17; CDC A17; m_A17.LoadBitmap(IDB_A17);  
								A17.CreateCompatibleDC(pDC); A17.SelectObject(m_A17); 
								pDC->BitBlt(i, j, m, n, &A17, 0, 0, SRCCOPY);
								break;
							}
							
							case '5':{
								CBitmap m_A18; CDC A18; m_A18.LoadBitmap(IDB_A18);  
								A18.CreateCompatibleDC(pDC); A18.SelectObject(m_A18); 
								pDC->BitBlt(i, j, m, n, &A18, 0, 0, SRCCOPY);
								break;
							}
							
							case '6':{
								CBitmap m_A19; CDC A19; m_A19.LoadBitmap(IDB_A19); 
								A19.CreateCompatibleDC(pDC); A19.SelectObject(m_A19);  
								pDC->BitBlt(i, j, m, n, &A19, 0, 0, SRCCOPY);
								break;
							}
							
							case '7':{
								CBitmap m_A20; CDC A20; m_A20.LoadBitmap(IDB_A20); 
								A20.CreateCompatibleDC(pDC); A20.SelectObject(m_A20); 
								pDC->BitBlt(i, j, m, n, &A20, 0, 0, SRCCOPY);}
								break;
							case '8':{
								CBitmap m_A21; CDC A21; m_A21.LoadBitmap(IDB_A21);  
								A21.CreateCompatibleDC(pDC); A21.SelectObject(m_A21); 
								pDC->BitBlt(i, j, m, n, &A21, 0, 0, SRCCOPY);
								break;
							}
							
							case '9':{
								CBitmap m_A22; CDC A22; m_A22.LoadBitmap(IDB_A22); 
								A22.CreateCompatibleDC(pDC); A22.SelectObject(m_A22); 
								pDC->BitBlt(i, j, m, n, &A22, 0, 0, SRCCOPY);
								break;
							}
							
							case 'T':{
								CBitmap m_A23; CDC A23; m_A23.LoadBitmap(IDB_A23); 
								A23.CreateCompatibleDC(pDC); A23.SelectObject(m_A23);  
								pDC->BitBlt(i, j, m, n, &A23, 0, 0, SRCCOPY);
								break;
							}
							
							case 'J':{
								CBitmap m_A24; CDC A24; m_A24.LoadBitmap(IDB_A24); 
								A24.CreateCompatibleDC(pDC); A24.SelectObject(m_A24);  
								pDC->BitBlt(i, j, m, n, &A24, 0, 0, SRCCOPY);
								break;
							}
							
							case 'Q':{
								CBitmap m_A25; CDC A25; m_A25.LoadBitmap(IDB_A25); 
								A25.CreateCompatibleDC(pDC); A25.SelectObject(m_A25);
								pDC->BitBlt(i, j, m, n, &A25, 0, 0, SRCCOPY);
								break;
							}
							
							case 'K': {
								CBitmap m_A26; CDC A26; m_A26.LoadBitmap(IDB_A26);
								A26.CreateCompatibleDC(pDC); A26.SelectObject(m_A26);
								pDC->BitBlt(i, j, m, n, &A26, 0, 0, SRCCOPY);
								break;
							}
						}
						break;
					}

					case  4: {
						switch (manager.play[q].a[p].Number) {
							case 'A':
							{ CBitmap m_M27; CDC M27; m_M27.LoadBitmap(IDB_M27);   M27.CreateCompatibleDC(pDC); M27.SelectObject(m_M27);    pDC->BitBlt(i, j, m, n, &M27, 0, 0, SRCCOPY); break; }
							case '2':
							{ CBitmap m_M28; CDC M28; m_M28.LoadBitmap(IDB_M28);   M28.CreateCompatibleDC(pDC); M28.SelectObject(m_M28);    pDC->BitBlt(i, j, m, n, &M28, 0, 0, SRCCOPY); break; }
							case '3':
							{ CBitmap m_M29; CDC M29; m_M29.LoadBitmap(IDB_M29);   M29.CreateCompatibleDC(pDC); M29.SelectObject(m_M29);    pDC->BitBlt(i, j, m, n, &M29, 0, 0, SRCCOPY); break; }
							case '4':
							{ CBitmap m_M30; CDC M30; m_M30.LoadBitmap(IDB_M30);   M30.CreateCompatibleDC(pDC); M30.SelectObject(m_M30);    pDC->BitBlt(i, j, m, n, &M30, 0, 0, SRCCOPY); break; }
							case '5':
							{ CBitmap m_M31; CDC M31; m_M31.LoadBitmap(IDB_M31);   M31.CreateCompatibleDC(pDC); M31.SelectObject(m_M31);    pDC->BitBlt(i, j, m, n, &M31, 0, 0, SRCCOPY); break; }
							case '6':
							{ CBitmap m_M32; CDC M32; m_M32.LoadBitmap(IDB_M31);   M32.CreateCompatibleDC(pDC); M32.SelectObject(m_M32);    pDC->BitBlt(i, j, m, n, &M32, 0, 0, SRCCOPY); break; }
							case '7':
							{ CBitmap m_M33; CDC M33; m_M33.LoadBitmap(IDB_M31);   M33.CreateCompatibleDC(pDC); M33.SelectObject(m_M33);    pDC->BitBlt(i, j, m, n, &M33, 0, 0, SRCCOPY); break; }
							case '8':
							{ CBitmap m_M34; CDC M34; m_M34.LoadBitmap(IDB_M34);   M34.CreateCompatibleDC(pDC); M34.SelectObject(m_M34);    pDC->BitBlt(i, j, m, n, &M34, 0, 0, SRCCOPY); break; }
							case '9':
							{ CBitmap m_M35; CDC M35; m_M35.LoadBitmap(IDB_M35);   M35.CreateCompatibleDC(pDC); M35.SelectObject(m_M35);    pDC->BitBlt(i, j, m, n, &M35, 0, 0, SRCCOPY); break; }
							case 'T':
							{ CBitmap m_M36; CDC M36; m_M36.LoadBitmap(IDB_M36);   M36.CreateCompatibleDC(pDC); M36.SelectObject(m_M36);    pDC->BitBlt(i, j, m, n, &M36, 0, 0, SRCCOPY); break; }
							case 'J':
							{ CBitmap m_M37; CDC M37; m_M37.LoadBitmap(IDB_M37);   M37.CreateCompatibleDC(pDC); M37.SelectObject(m_M37);    pDC->BitBlt(i, j, m, n, &M37, 0, 0, SRCCOPY); break; }
							case 'Q':
							{ CBitmap m_M38; CDC M38; m_M38.LoadBitmap(IDB_M38);   M38.CreateCompatibleDC(pDC); M38.SelectObject(m_M38);    pDC->BitBlt(i, j, m, n, &M38, 0, 0, SRCCOPY); break; }
							case 'K':
							{ CBitmap m_M39; CDC M39; m_M39.LoadBitmap(IDB_M39);   M39.CreateCompatibleDC(pDC); M39.SelectObject(m_M39);    pDC->BitBlt(i, j, m, n, &M39, 0, 0, SRCCOPY); break; }
						}
						break;
					}
				
					case  5: {
						switch(manager.play[q].a[p].Number){
							case 'A':
								{ CBitmap m_K40; CDC K40; m_K40.LoadBitmap(IDB_K40);   K40.CreateCompatibleDC(pDC); K40.SelectObject(m_K40);    pDC->BitBlt(i, j, m, n, &K40, 0, 0, SRCCOPY);break;}
							case '2':
								{ CBitmap m_K41; CDC K41; m_K41.LoadBitmap(IDB_K41);   K41.CreateCompatibleDC(pDC); K41.SelectObject(m_K41);    pDC->BitBlt(i, j, m, n, &K41, 0, 0, SRCCOPY);break;}
							case '3':
								{ CBitmap m_K42; CDC K42; m_K42.LoadBitmap(IDB_K42);   K42.CreateCompatibleDC(pDC); K42.SelectObject(m_K42);    pDC->BitBlt(i, j, m, n, &K42, 0, 0, SRCCOPY);break;}
							case '4':
								{ CBitmap m_K43; CDC K43; m_K43.LoadBitmap(IDB_K43);   K43.CreateCompatibleDC(pDC); K43.SelectObject(m_K43);    pDC->BitBlt(i, j, m, n, &K43, 0, 0, SRCCOPY);break;}
							case '5':
								{ CBitmap m_K44; CDC K44; m_K44.LoadBitmap(IDB_K44);   K44.CreateCompatibleDC(pDC); K44.SelectObject(m_K44);    pDC->BitBlt(i, j, m, n, &K44, 0, 0, SRCCOPY);break;}
							case '6':
								{ CBitmap m_K45; CDC K45; m_K45.LoadBitmap(IDB_K45);   K45.CreateCompatibleDC(pDC); K45.SelectObject(m_K45);    pDC->BitBlt(i, j, m, n, &K45, 0, 0, SRCCOPY);break;}
							case '7':
								{ CBitmap m_K46; CDC K46; m_K46.LoadBitmap(IDB_K46);   K46.CreateCompatibleDC(pDC); K46.SelectObject(m_K46);    pDC->BitBlt(i, j, m, n, &K46, 0, 0, SRCCOPY);break;}
							case '8':
								{ CBitmap m_K47; CDC K47; m_K47.LoadBitmap(IDB_K47);   K47.CreateCompatibleDC(pDC); K47.SelectObject(m_K47);    pDC->BitBlt(i, j, m, n, &K47, 0, 0, SRCCOPY);break;}
							case '9':
								{ CBitmap m_K48; CDC K48; m_K48.LoadBitmap(IDB_K48);   K48.CreateCompatibleDC(pDC); K48.SelectObject(m_K48);    pDC->BitBlt(i, j, m, n, &K48, 0, 0, SRCCOPY);break;}
							case 'T':
								{ CBitmap m_K49; CDC K49; m_K49.LoadBitmap(IDB_K49);   K49.CreateCompatibleDC(pDC); K49.SelectObject(m_K49);    pDC->BitBlt(i, j, m, n, &K49, 0, 0, SRCCOPY);break;}
							case 'J':
								{ CBitmap m_K50; CDC K50; m_K50.LoadBitmap(IDB_K50);   K50.CreateCompatibleDC(pDC); K50.SelectObject(m_K50);    pDC->BitBlt(i, j, m, n, &K50, 0, 0, SRCCOPY);break;}
							case 'Q':
								{ CBitmap m_K51; CDC K51; m_K51.LoadBitmap(IDB_K51);   K51.CreateCompatibleDC(pDC); K51.SelectObject(m_K51);    pDC->BitBlt(i, j, m, n, &K51, 0, 0, SRCCOPY);break;}
							case 'K':
								{ CBitmap m_K52; CDC K52; m_K52.LoadBitmap(IDB_K52);   K52.CreateCompatibleDC(pDC); K52.SelectObject(m_K52);    pDC->BitBlt(i, j, m, n, &K52, 0, 0, SRCCOPY);break;}
						}
						break;
					}
					default:{CBitmap m_K53; CDC K53; m_K53.LoadBitmap(IDB_CARDBACK);   K53.CreateCompatibleDC(pDC); K53.SelectObject(m_K53);    pDC->BitBlt(i, j, m, n, &K53, 0, 0, SRCCOPY);break;}
				}
				j+=90;
				ReleaseDC(pDC);
			}
			i+=667;
		}

		if(manager.Player>2)//如果玩家个数大于二
		{
			i=179;j=30;
			for(int q=2; q<manager.Player; q++)//后两个玩家
			{
			i=179;
			switch(q)
			{
			case 2:{CDC *pDC=GetDC();pDC->TextOut(200, 130, "玩家三：");CBitmap m_pic3;CDC P3;m_pic3.LoadBitmap(IDB_P4);P3.CreateCompatibleDC(pDC);P3.SelectObject(m_pic3);pDC->BitBlt(250,110,80,80,&P3,0,0,SRCCOPY);break;}
			case 3:{CDC *pDC=GetDC();pDC->TextOut(505, 360, "玩家四：");CBitmap m_pic4;CDC P4;m_pic4.LoadBitmap(IDB_P5);P4.CreateCompatibleDC(pDC);P4.SelectObject(m_pic4);pDC->BitBlt(560,360,80,80,&P4,0,0,SRCCOPY);break;}
			}
			for(int p=0; p<5; p++) 
			{ 
				CDC *pDC=GetDC();//玩家的五张牌
				switch(manager.play[q].a[p].Suit){ //玩家q的第p张牌 花色为suit
					case 2: {
						switch (manager.play[q].a[p].Number) {
							case 'A': 
								{ CBitmap m_H1; CDC H1; m_H1.LoadBitmap(IDB_H1); H1.CreateCompatibleDC(pDC); H1.SelectObject(m_H1); pDC->BitBlt(i, j, m, n, &H1, 0, 0, SRCCOPY); break;}

							case '2':
								{ CBitmap m_H2; CDC H2; m_H2.LoadBitmap(IDB_H2); H2.CreateCompatibleDC(pDC); H2.SelectObject(m_H2); pDC->BitBlt(i, j, m, n, &H2, 0, 0, SRCCOPY); break;}

							case '3':
								{ CBitmap m_H3; CDC H3; m_H3.LoadBitmap(IDB_H3); H3.CreateCompatibleDC(pDC); H3.SelectObject(m_H3); pDC->BitBlt(i, j, m, n, &H3, 0, 0, SRCCOPY); break;}

							case '4':
								{ CBitmap m_H4; CDC H4; m_H4.LoadBitmap(IDB_H4); H4.CreateCompatibleDC(pDC); H4.SelectObject(m_H4); pDC->BitBlt(i, j, m, n, &H4, 0, 0, SRCCOPY); break;}

							case '5': 
								{ CBitmap m_H5; CDC H5; m_H5.LoadBitmap(IDB_H5); H5.CreateCompatibleDC(pDC); H5.SelectObject(m_H5); pDC->BitBlt(i, j, m, n, &H5, 0, 0, SRCCOPY); break;}

							case '6':
								{CBitmap m_H6; CDC H6; m_H6.LoadBitmap(IDB_H6);
								H6.CreateCompatibleDC(pDC); H6.SelectObject(m_H6);
								pDC->BitBlt(i, j, m, n, &H6, 0, 0, SRCCOPY);
								break;
							}

							case '7': {
								CBitmap m_H7; CDC H7; m_H7.LoadBitmap(IDB_H7);
								H7.CreateCompatibleDC(pDC); H7.SelectObject(m_H7);
								pDC->BitBlt(i, j, m, n, &H7, 0, 0, SRCCOPY);
								break;
							}

							case '8': {
								CBitmap m_H8; CDC H8; m_H8.LoadBitmap(IDB_H8);
								H8.CreateCompatibleDC(pDC); H8.SelectObject(m_H8);
								pDC->BitBlt(i, j, m, n, &H8, 0, 0, SRCCOPY);
								break;
							}

							case '9': {
								CBitmap m_H9; CDC H9; m_H9.LoadBitmap(IDB_H9);
								H9.CreateCompatibleDC(pDC); H9.SelectObject(m_H9);
								pDC->BitBlt(i, j, m, n, &H9, 0, 0, SRCCOPY);
								break;
							}

							case 'T': {
								CBitmap m_H10; CDC H10; m_H10.LoadBitmap(IDB_H10);
								H10.CreateCompatibleDC(pDC); H10.SelectObject(m_H10);
								pDC->BitBlt(i, j, m, n, &H10, 0, 0, SRCCOPY);
								break;
							}
							case 'J': {
								CBitmap m_H11; CDC H11; m_H11.LoadBitmap(IDB_H11);
								H11.CreateCompatibleDC(pDC); H11.SelectObject(m_H11);
								pDC->BitBlt(i, j, m, n, &H11, 0, 0, SRCCOPY);
								break;
							}
							case 'Q': {
								CBitmap m_H12; CDC H12; m_H12.LoadBitmap(IDB_H12);
								H12.CreateCompatibleDC(pDC); H12.SelectObject(m_H12);
								pDC->BitBlt(i, j, m, n, &H12, 0, 0, SRCCOPY);
								break;
							}

							case 'K': {
								CBitmap m_H13; CDC H13; m_H13.LoadBitmap(IDB_H13);
								H13.CreateCompatibleDC(pDC); H13.SelectObject(m_H13);
								pDC->BitBlt(i, j, m, n, &H13, 0, 0, SRCCOPY);
								break;
							}
						}
						break;
					}

					case 3: {
						switch(manager.play[q].a[p].Number){
							case 'A':{
								CBitmap m_A14; CDC A14; m_A14.LoadBitmap(IDB_A14);  
								A14.CreateCompatibleDC(pDC); A14.SelectObject(m_A14);
								pDC->BitBlt(i, j, m, n, &A14, 0, 0, SRCCOPY);
								break;
							}
							
							case '2':{
								CBitmap m_A15; CDC A15; m_A15.LoadBitmap(IDB_A15); 
								A15.CreateCompatibleDC(pDC); A15.SelectObject(m_A15);  
								pDC->BitBlt(i, j, m, n, &A15, 0, 0, SRCCOPY);
								break;
							}
							
							case '3':{
								CBitmap m_A16; CDC A16; m_A16.LoadBitmap(IDB_A16); 
								A16.CreateCompatibleDC(pDC); A16.SelectObject(m_A16); 
								pDC->BitBlt(i, j, m, n, &A16, 0, 0, SRCCOPY);	
								break;
							}
						
							case '4':{
								CBitmap m_A17; CDC A17; m_A17.LoadBitmap(IDB_A17);  
								A17.CreateCompatibleDC(pDC); A17.SelectObject(m_A17); 
								pDC->BitBlt(i, j, m, n, &A17, 0, 0, SRCCOPY);
								break;
							}
							
							case '5':{
								CBitmap m_A18; CDC A18; m_A18.LoadBitmap(IDB_A18);  
								A18.CreateCompatibleDC(pDC); A18.SelectObject(m_A18); 
								pDC->BitBlt(i, j, m, n, &A18, 0, 0, SRCCOPY);
								break;
							}
							
							case '6':{
								CBitmap m_A19; CDC A19; m_A19.LoadBitmap(IDB_A19); 
								A19.CreateCompatibleDC(pDC); A19.SelectObject(m_A19);  
								pDC->BitBlt(i, j, m, n, &A19, 0, 0, SRCCOPY);
								break;
							}
							
							case '7':{
								CBitmap m_A20; CDC A20; m_A20.LoadBitmap(IDB_A20); 
								A20.CreateCompatibleDC(pDC); A20.SelectObject(m_A20); 
								pDC->BitBlt(i, j, m, n, &A20, 0, 0, SRCCOPY);}
								break;
							case '8':{
								CBitmap m_A21; CDC A21; m_A21.LoadBitmap(IDB_A21);  
								A21.CreateCompatibleDC(pDC); A21.SelectObject(m_A21); 
								pDC->BitBlt(i, j, m, n, &A21, 0, 0, SRCCOPY);
								break;
							}
							
							case '9':{
								CBitmap m_A22; CDC A22; m_A22.LoadBitmap(IDB_A22); 
								A22.CreateCompatibleDC(pDC); A22.SelectObject(m_A22); 
								pDC->BitBlt(i, j, m, n, &A22, 0, 0, SRCCOPY);
								break;
							}
							
							case 'T':{
								CBitmap m_A23; CDC A23; m_A23.LoadBitmap(IDB_A23); 
								A23.CreateCompatibleDC(pDC); A23.SelectObject(m_A23);  
								pDC->BitBlt(i, j, m, n, &A23, 0, 0, SRCCOPY);
								break;
							}
							
							case 'J':{
								CBitmap m_A24; CDC A24; m_A24.LoadBitmap(IDB_A24); 
								A24.CreateCompatibleDC(pDC); A24.SelectObject(m_A24);  
								pDC->BitBlt(i, j, m, n, &A24, 0, 0, SRCCOPY);
								break;
							}
							
							case 'Q':{
								CBitmap m_A25; CDC A25; m_A25.LoadBitmap(IDB_A25); 
								A25.CreateCompatibleDC(pDC); A25.SelectObject(m_A25);
								pDC->BitBlt(i, j, m, n, &A25, 0, 0, SRCCOPY);
								break;
							}
							
							case 'K': {
								CBitmap m_A26; CDC A26; m_A26.LoadBitmap(IDB_A26);
								A26.CreateCompatibleDC(pDC); A26.SelectObject(m_A26);
								pDC->BitBlt(i, j, m, n, &A26, 0, 0, SRCCOPY);
								break;
							}
						}
						break;
					}

					case  4: {
						switch (manager.play[q].a[p].Number) {
							case 'A':
							{ CBitmap m_M27; CDC M27; m_M27.LoadBitmap(IDB_M27);   M27.CreateCompatibleDC(pDC); M27.SelectObject(m_M27);    pDC->BitBlt(i, j, m, n, &M27, 0, 0, SRCCOPY); break; }
							case '2':
							{ CBitmap m_M28; CDC M28; m_M28.LoadBitmap(IDB_M28);   M28.CreateCompatibleDC(pDC); M28.SelectObject(m_M28);    pDC->BitBlt(i, j, m, n, &M28, 0, 0, SRCCOPY); break; }
							case '3':
							{ CBitmap m_M29; CDC M29; m_M29.LoadBitmap(IDB_M29);   M29.CreateCompatibleDC(pDC); M29.SelectObject(m_M29);    pDC->BitBlt(i, j, m, n, &M29, 0, 0, SRCCOPY); break; }
							case '4':
							{ CBitmap m_M30; CDC M30; m_M30.LoadBitmap(IDB_M30);   M30.CreateCompatibleDC(pDC); M30.SelectObject(m_M30);    pDC->BitBlt(i, j, m, n, &M30, 0, 0, SRCCOPY); break; }
							case '5':
							{ CBitmap m_M31; CDC M31; m_M31.LoadBitmap(IDB_M31);   M31.CreateCompatibleDC(pDC); M31.SelectObject(m_M31);    pDC->BitBlt(i, j, m, n, &M31, 0, 0, SRCCOPY); break; }
							case '6':
							{ CBitmap m_M32; CDC M32; m_M32.LoadBitmap(IDB_M31);   M32.CreateCompatibleDC(pDC); M32.SelectObject(m_M32);    pDC->BitBlt(i, j, m, n, &M32, 0, 0, SRCCOPY); break; }
							case '7':
							{ CBitmap m_M33; CDC M33; m_M33.LoadBitmap(IDB_M31);   M33.CreateCompatibleDC(pDC); M33.SelectObject(m_M33);    pDC->BitBlt(i, j, m, n, &M33, 0, 0, SRCCOPY); break; }
							case '8':
							{ CBitmap m_M34; CDC M34; m_M34.LoadBitmap(IDB_M34);   M34.CreateCompatibleDC(pDC); M34.SelectObject(m_M34);    pDC->BitBlt(i, j, m, n, &M34, 0, 0, SRCCOPY); break; }
							case '9':
							{ CBitmap m_M35; CDC M35; m_M35.LoadBitmap(IDB_M35);   M35.CreateCompatibleDC(pDC); M35.SelectObject(m_M35);    pDC->BitBlt(i, j, m, n, &M35, 0, 0, SRCCOPY); break; }
							case 'T':
							{ CBitmap m_M36; CDC M36; m_M36.LoadBitmap(IDB_M36);   M36.CreateCompatibleDC(pDC); M36.SelectObject(m_M36);    pDC->BitBlt(i, j, m, n, &M36, 0, 0, SRCCOPY); break; }
							case 'J':
							{ CBitmap m_M37; CDC M37; m_M37.LoadBitmap(IDB_M37);   M37.CreateCompatibleDC(pDC); M37.SelectObject(m_M37);    pDC->BitBlt(i, j, m, n, &M37, 0, 0, SRCCOPY); break; }
							case 'Q':
							{ CBitmap m_M38; CDC M38; m_M38.LoadBitmap(IDB_M38);   M38.CreateCompatibleDC(pDC); M38.SelectObject(m_M38);    pDC->BitBlt(i, j, m, n, &M38, 0, 0, SRCCOPY); break; }
							case 'K':
							{ CBitmap m_M39; CDC M39; m_M39.LoadBitmap(IDB_M39);   M39.CreateCompatibleDC(pDC); M39.SelectObject(m_M39);    pDC->BitBlt(i, j, m, n, &M39, 0, 0, SRCCOPY); break; }
						}
						break;
					}
				
					case  5: {
						switch(manager.play[q].a[p].Number){
							case 'A':
								{ CBitmap m_K40; CDC K40; m_K40.LoadBitmap(IDB_K40);   K40.CreateCompatibleDC(pDC); K40.SelectObject(m_K40);    pDC->BitBlt(i, j, m, n, &K40, 0, 0, SRCCOPY);break;}
							case '2':
								{ CBitmap m_K41; CDC K41; m_K41.LoadBitmap(IDB_K41);   K41.CreateCompatibleDC(pDC); K41.SelectObject(m_K41);    pDC->BitBlt(i, j, m, n, &K41, 0, 0, SRCCOPY);break;}
							case '3':
								{ CBitmap m_K42; CDC K42; m_K42.LoadBitmap(IDB_K42);   K42.CreateCompatibleDC(pDC); K42.SelectObject(m_K42);    pDC->BitBlt(i, j, m, n, &K42, 0, 0, SRCCOPY);break;}
							case '4':
								{ CBitmap m_K43; CDC K43; m_K43.LoadBitmap(IDB_K43);   K43.CreateCompatibleDC(pDC); K43.SelectObject(m_K43);    pDC->BitBlt(i, j, m, n, &K43, 0, 0, SRCCOPY);break;}
							case '5':
								{ CBitmap m_K44; CDC K44; m_K44.LoadBitmap(IDB_K44);   K44.CreateCompatibleDC(pDC); K44.SelectObject(m_K44);    pDC->BitBlt(i, j, m, n, &K44, 0, 0, SRCCOPY);break;}
							case '6':
								{ CBitmap m_K45; CDC K45; m_K45.LoadBitmap(IDB_K45);   K45.CreateCompatibleDC(pDC); K45.SelectObject(m_K45);    pDC->BitBlt(i, j, m, n, &K45, 0, 0, SRCCOPY);break;}
							case '7':
								{ CBitmap m_K46; CDC K46; m_K46.LoadBitmap(IDB_K46);   K46.CreateCompatibleDC(pDC); K46.SelectObject(m_K46);    pDC->BitBlt(i, j, m, n, &K46, 0, 0, SRCCOPY);break;}
							case '8':
								{ CBitmap m_K47; CDC K47; m_K47.LoadBitmap(IDB_K47);   K47.CreateCompatibleDC(pDC); K47.SelectObject(m_K47);    pDC->BitBlt(i, j, m, n, &K47, 0, 0, SRCCOPY);break;}
							case '9':
								{ CBitmap m_K48; CDC K48; m_K48.LoadBitmap(IDB_K48);   K48.CreateCompatibleDC(pDC); K48.SelectObject(m_K48);    pDC->BitBlt(i, j, m, n, &K48, 0, 0, SRCCOPY);break;}
							case 'T':
								{ CBitmap m_K49; CDC K49; m_K49.LoadBitmap(IDB_K49);   K49.CreateCompatibleDC(pDC); K49.SelectObject(m_K49);    pDC->BitBlt(i, j, m, n, &K49, 0, 0, SRCCOPY);break;}
							case 'J':
								{ CBitmap m_K50; CDC K50; m_K50.LoadBitmap(IDB_K50);   K50.CreateCompatibleDC(pDC); K50.SelectObject(m_K50);    pDC->BitBlt(i, j, m, n, &K50, 0, 0, SRCCOPY);break;}
							case 'Q':
								{ CBitmap m_K51; CDC K51; m_K51.LoadBitmap(IDB_K51);   K51.CreateCompatibleDC(pDC); K51.SelectObject(m_K51);    pDC->BitBlt(i, j, m, n, &K51, 0, 0, SRCCOPY);break;}
							case 'K':
								{ CBitmap m_K52; CDC K52; m_K52.LoadBitmap(IDB_K52);   K52.CreateCompatibleDC(pDC); K52.SelectObject(m_K52);    pDC->BitBlt(i, j, m, n, &K52, 0, 0, SRCCOPY);break;}
						}
						break;
					}
					default:{CBitmap m_K53; CDC K53; m_K53.LoadBitmap(IDB_CARDBACK);   K53.CreateCompatibleDC(pDC); K53.SelectObject(m_K53);    pDC->BitBlt(i, j, m, n, &K53, 0, 0, SRCCOPY);break;}
				}
				i+=109;
				ReleaseDC(pDC);
			}
			j+=420;
		}

		}
	}
