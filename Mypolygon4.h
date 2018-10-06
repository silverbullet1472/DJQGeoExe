// Mypolygon.h: interface for the CMypolygon class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYPOLYGON_H__1BDF7576_5BE1_4E5B_A5E6_9CD36953D6D4__INCLUDED_)
#define AFX_MYPOLYGON_H__1BDF7576_5BE1_4E5B_A5E6_9CD36953D6D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "afxtempl.h"

class CMyPolygon4  
{
public:
	CMyPolygon4();
	CArray<CPoint,CPoint>pts;
	CPoint cenPt;
	int color;
	void AddPoint(CPoint pt);
	void SetCenterPt(CPoint pt);
	void Draw(CDC *pDC);
	void FillPolygon(CDC *pDC);
	virtual ~CMyPolygon4();

};

#endif // !defined(AFX_MYPOLYGON_H__1BDF7576_5BE1_4E5B_A5E6_9CD36953D6D4__INCLUDED_)
