// LegendDoc.h : interface of the CMyLegendDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LegendDOC_H__9B973BA9_4E97_4622_9A97_0DECCD942413__INCLUDED_)
#define AFX_LegendDOC_H__9B973BA9_4E97_4622_9A97_0DECCD942413__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyLegendDoc : public CDocument
{
protected: // create from serialization only
	CMyLegendDoc();
	DECLARE_DYNCREATE(CMyLegendDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyLegendDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyLegendDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyLegendDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
//	CPeople a;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LegendDOC_H__9B973BA9_4E97_4622_9A97_0DECCD942413__INCLUDED_)
