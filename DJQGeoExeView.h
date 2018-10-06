// DJQGeoExeView.h : interface of the CDJQGeoExeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DJQGEOEXEVIEW_H__BD57B391_F7C8_47BC_A481_63A2621C5488__INCLUDED_)
#define AFX_DJQGEOEXEVIEW_H__BD57B391_F7C8_47BC_A481_63A2621C5488__INCLUDED_

#include "DDAline1.h"
#include "Myline2.h"
#include "Map1.h"
#include "Map2.h"	
#include "Map3.h"
#include "Map4.h"
#include "Map5.h"
#include "Map6.h"
#include "Map7.h"
#include "Map8.h"
#include "MapProjection8.h"
#include "MapProjectionLambert8.h"
#include "MapProjectionGauss8.h"
#include "Map9.h"
#include "Map10.h"
#include "GeoObject10.h"
#include "GeoPolyline10.h"
#include "GeoPolygon10.h"
#include "Map11.h"
#include "Map12.h"
#include "MainFrm.h"// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDJQGeoExeView : public CView
{
protected: // create from serialization only
	CDJQGeoExeView();
	DECLARE_DYNCREATE(CDJQGeoExeView)

// Attributes
public:
	CDJQGeoExeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDJQGeoExeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	
	CMap1 *Map1;
	CMap2 *Map2;
	CPoint pt1,pt2;
	BOOL isPressed;
	CMap3 *Map3;
	//CMyline2 line;
	CMap4 *Map4;
	CMap5 *Map5;
	CMap6 *Map6;
	CMap7 *Map7;
	CMap8 *Map8;
	CMapProjection8 *mapPrj;
	CMap9 *Map9;
	CMap10 *Map10;
	CMap11 *Map11;
	CMap12 *Map12;
	CToolTipCtrl m_tool;
	void readData1(CString fileName);
	void readData3(CString fileName);
	void readData4(CString fileName);
	void readData6(CString fileName);
	void readData7(CString fileName);
	void readData8(CString fileName);
	void readData9(CString fileName);
	void readData10(CString fileName);
	void readData11(CString fileName);
	void readData12_1(CString fileName);
	void readData12_2(CString fileName);
	virtual ~CDJQGeoExeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDJQGeoExeView)
	afx_msg void OnFileOpen();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLambert();
	afx_msg void OnGauss();
	afx_msg void OnIndex();
};

#ifndef _DEBUG  // debug version in DJQGeoExeView.cpp
inline CDJQGeoExeDoc* CDJQGeoExeView::GetDocument()
   { return (CDJQGeoExeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DJQGEOEXEVIEW_H__BD57B391_F7C8_47BC_A481_63A2621C5488__INCLUDED_)
