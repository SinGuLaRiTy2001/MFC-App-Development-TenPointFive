// LegendDoc.cpp : implementation of the CMyLegendDoc class
//

#include "stdafx.h"
#include "Legend.h"

#include "LegendDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyLegendDoc

IMPLEMENT_DYNCREATE(CMyLegendDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyLegendDoc, CDocument)
	//{{AFX_MSG_MAP(CMyLegendDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyLegendDoc construction/destruction

CMyLegendDoc::CMyLegendDoc()
{
	// TODO: add one-time construction code here

}

CMyLegendDoc::~CMyLegendDoc()
{
}

BOOL CMyLegendDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	SetTitle("十点半");//标题设置

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyLegendDoc serialization

void CMyLegendDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyLegendDoc diagnostics

#ifdef _DEBUG
void CMyLegendDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyLegendDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyLegendDoc commands
