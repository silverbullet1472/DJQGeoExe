// DJQGeoExeDoc.cpp : implementation of the CDJQGeoExeDoc class
//

#include "stdafx.h"
#include "DJQGeoExe.h"

#include "DJQGeoExeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDJQGeoExeDoc

IMPLEMENT_DYNCREATE(CDJQGeoExeDoc, CDocument)

BEGIN_MESSAGE_MAP(CDJQGeoExeDoc, CDocument)
	//{{AFX_MSG_MAP(CDJQGeoExeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDJQGeoExeDoc construction/destruction

CDJQGeoExeDoc::CDJQGeoExeDoc()
{
	// TODO: add one-time construction code here

}

CDJQGeoExeDoc::~CDJQGeoExeDoc()
{
}

BOOL CDJQGeoExeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDJQGeoExeDoc serialization

void CDJQGeoExeDoc::Serialize(CArchive& ar)
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
// CDJQGeoExeDoc diagnostics

#ifdef _DEBUG
void CDJQGeoExeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDJQGeoExeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDJQGeoExeDoc commands
