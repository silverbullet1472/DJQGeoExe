// MyClipLine.h: interface for the CMyClipLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCLIPLINE_H__07D68F79_D6D9_4035_928B_6E489E495DC0__INCLUDED_)
#define AFX_MYCLIPLINE_H__07D68F79_D6D9_4035_928B_6E489E495DC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMyClipLine5  
{
public:
	void clipSutherland();
	CMyClipLine5();
	int x1,y1,x2,y2;
	int cx1,cy1,cx2,cy2;
	CRect rect;
	void setRect(CRect rect);
	void setCoords(int x1,int y1,int x2,int y2);
	void Draw(CDC *pDC);
	int getCode(int x1,int y1);
	virtual ~CMyClipLine5();
};

#endif // !defined(AFX_MYCLIPLINE_H__07D68F79_D6D9_4035_928B_6E489E495DC0__INCLUDED_)
