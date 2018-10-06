// Myline.h: interface for the CMyline class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYLINE_H__CF35036F_DDB6_4073_BE09_9DD6265FD056__INCLUDED_)
#define AFX_MYLINE_H__CF35036F_DDB6_4073_BE09_9DD6265FD056__INCLUDED_

#include "afxtempl.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyline2  
{
public:
	CMyline2();
	virtual ~CMyline2();
	int x1,y1,x2,y2;
	int crColor;
	int nPenStyle; 
	int nWidth; 
	void Draw(CDC *pDC);
//»­Ïß
	void setPenStyle(int nPenStyle1);
	void setWidth(int nWidth);
	void setPoints(int x1,int y1,int x2,int y2);
	void setColor(int nColor);
//´ò×Ö
	CString testStr;
//Ìî³ä
	CArray<CPoint,CPoint>pts; 
	CArray<CPoint,CPoint>seeds; 
	void FillPolygon (CDC *pDC,int x,int y,int colorOld,int colorNew);

};

#endif // !defined(AFX_MYLINE_H__CF35036F_DDB6_4073_BE09_9DD6265FD056__INCLUDED_)
