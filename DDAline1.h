// DDAline.h: interface for the CDDAline class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDALINE_H__E75199AB_F226_49D7_87A5_45542FE30426__INCLUDED_)
#define AFX_DDALINE_H__E75199AB_F226_49D7_87A5_45542FE30426__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDDAline1  
{
public:
	CDDAline1();
	int x1,y1,x2,y2;
	void setCoords(int x1,int y1,int x2,int y2);
	void Draw(CDC *pDC);
	virtual ~CDDAline1();

};

#endif // !defined(AFX_DDALINE_H__E75199AB_F226_49D7_87A5_45542FE30426__INCLUDED_)
