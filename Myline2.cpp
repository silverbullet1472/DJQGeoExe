// Myline.cpp: implementation of the CMyline class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DJQGeoExe.h"
#include "Myline2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyline2::CMyline2()
{
	crColor = RGB(255,0,0);
	nPenStyle = 0;
	nWidth = 1;
	x1=300;y1=100;
	x2=500;y2=400;
	testStr = "GIS绝不为难丁家祺";
	//
	pts.Add(CPoint(600,100));
	pts.Add(CPoint(500,300));
	pts.Add(CPoint(560,400));
	pts.Add(CPoint(800,300));
	pts.Add(CPoint(600,200));
	pts.Add(CPoint(700,150));
	pts.Add(CPoint(600,100));
}

CMyline2::~CMyline2()
{

}

void CMyline2::Draw(CDC *pDC)
{
	CPen pen(nPenStyle,nWidth,crColor);
	CPen *oldPen = pDC->SelectObject(&pen);
	pDC->MoveTo(x1,y1);
	pDC->LineTo(x2,y2);
	pDC->SelectObject(oldPen);
	//字符串显示
	CFont font;
	font.CreateFont(20,0,0,0,FW_MEDIUM,FALSE,FALSE,0,ANSI_CHARSET,
	OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_SWISS,"楷体");
	CFont *pFont = pDC->SelectObject(&font);
	pDC->TextOut(400,200,testStr);
	pDC->SelectObject(pFont);
	//
	int size = pts.GetSize();
	for(int i = 0;i<size;i++)
	{
		if(i==0)
			pDC->MoveTo(pts[i]);
		else
			pDC->LineTo(pts[i]);
	}
	 /*FillPolygon(pDC,600,320,RGB(255,255,255),RGB(255,0,0));*/
}

void  CMyline2::setPenStyle(int nPenStyle1)
{
	this->nPenStyle=nPenStyle1;
}

void  CMyline2::setWidth(int nWidth)
{
	this->nWidth=nWidth;
}

void  CMyline2::setPoints(int x1,int y1,int x2,int y2)
{
	this->x1=x1;
	this->y1=y1;
	this->x2=x2;
	this->y2=y2;
}

void  CMyline2::setColor(int nColor)
{
	this->crColor= nColor;
}

void  CMyline2::	FillPolygon (CDC *pDC,int x,int y,int colorOld,int colorNew)
{
	if (pDC->GetPixel( CPoint(x, y) ) == colorOld)  
    {  
        pDC->SetPixel( CPoint(x, y), colorNew);  
  
        FillPolygon(pDC, x, y - 1, colorOld, colorNew);  
        FillPolygon(pDC, x, y + 1, colorOld, colorNew);  
        FillPolygon(pDC, x - 1, y, colorOld, colorNew);  
        FillPolygon(pDC, x + 1, y, colorOld, colorNew);  
    }  
}
