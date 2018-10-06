// GeoPolyline.h: interface for the CGeoPolyline class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOPOLYLINE_H__F24BD97D_B7D4_49E8_BE32_698DB279B505__INCLUDED_)
#define AFX_GEOPOLYLINE_H__F24BD97D_B7D4_49E8_BE32_698DB279B505__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "afxtempl.h"

class CGeoPolyline6  
{
public:
	CRect clipRect;
	CGeoPolyline6();
	virtual ~CGeoPolyline6();
	CArray<CPoint , CPoint> pts;
	CArray<CPoint , CPoint> clipPts;
	void Draw(CDC *pDC);
	void addPoint(CPoint pt);
	void clipPolyline(CRect clipRect);
	int getCode(int x1,int y1);

};

#endif // !defined(AFX_GEOPOLYLINE_H__F24BD97D_B7D4_49E8_BE32_698DB279B505__INCLUDED_)
