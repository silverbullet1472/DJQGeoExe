// DJQGeoExeDoc.h : interface of the CDJQGeoExeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DJQGEOEXEDOC_H__6EFE2AFA_FF70_469F_B430_91F4E070664D__INCLUDED_)
#define AFX_DJQGEOEXEDOC_H__6EFE2AFA_FF70_469F_B430_91F4E070664D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDJQGeoExeDoc : public CDocument
{
protected: // create from serialization only
	CDJQGeoExeDoc();
	DECLARE_DYNCREATE(CDJQGeoExeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDJQGeoExeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDJQGeoExeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDJQGeoExeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DJQGEOEXEDOC_H__6EFE2AFA_FF70_469F_B430_91F4E070664D__INCLUDED_)
