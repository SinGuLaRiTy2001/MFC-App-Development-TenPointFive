// LegendView.h : interface of the CMyLegendView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LegendVIEW_H__9FFD9BE9_6E3B_410D_A5CC_1AADA214E9ED__INCLUDED_)
#define AFX_LegendVIEW_H__9FFD9BE9_6E3B_410D_A5CC_1AADA214E9ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"People.h"
#include"LegendDoc.h"
#include"LegendView.h"
#include "Managers.h"


class CMyLegendView : public CView
{
protected: // create from serialization only
//	CMyLegendView();
	DECLARE_DYNCREATE(CMyLegendView)

// Attributes
public:
	CMyLegendDoc* GetDocument();
	CMyLegendView();

	//定义变量
	CDC BACK;//定义背景的CDC
	CDC BEGIN;//开始按钮的CDC
	CDC RULE;//规则按钮
	CDC PLAYINGBACK;
	CBitmap m_back;//相应的CBitmap
	CBitmap m_begin;
	CBitmap m_rule;
	CBitmap m_playingback;
	void RankShow();
	void CardShow();
	Managers manager;

// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyLegendView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int People;
	virtual ~CMyLegendView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
// Generated message map functions
protected:
	//{{AFX_MSG(CMyLegendView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LegendView.cpp
inline CMyLegendDoc* CMyLegendView::GetDocument()
   { return (CMyLegendDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LegendVIEW_H__9FFD9BE9_6E3B_410D_A5CC_1AADA214E9ED__INCLUDED_)
