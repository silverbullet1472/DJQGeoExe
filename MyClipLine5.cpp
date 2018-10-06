// MyClipLine.cpp: implementation of the CMyClipLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DJQGeoExe.h"
#include "MyClipLine5.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyClipLine5::CMyClipLine5()
{

}

CMyClipLine5::~CMyClipLine5()
{

}

void CMyClipLine5::setCoords(int x1,int y1,int x2,int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}
void CMyClipLine5::setRect(CRect rect1)
{
	rect= rect1;
}

int CMyClipLine5::getCode(int x1,int y1)
{
	int code = 0;
	//按由低到高位编码，左、右、上、下
	if( x1 < rect.left) 
		code += 1;
	if( x1 > rect.right) 
		code += 2;
	if( y1 < rect.top) 
		code += 4;
	if( y1 > rect.bottom) 
		code += 8;
	
	return code;
}

void CMyClipLine5::Draw(CDC *pDC)
{
	pDC->Rectangle(rect);

	CPen pen1(PS_SOLID, 1, RGB(0,0,255));
	CPen *oldPen = pDC->SelectObject(&pen1);
	pDC->MoveTo(x1,y1);
	pDC->LineTo(x2,y2);

	if(!(cx1 == cx2 && cy1 == cy2))
	{
		CPen pen2(PS_SOLID, 2, RGB(255,0,0));
		oldPen = pDC->SelectObject(&pen2);
		pDC->MoveTo(cx1,cy1);
		pDC->LineTo(cx2,cy2);
	}
   pDC->SelectObject(oldPen);
}

void CMyClipLine5::clipSutherland()
{
	int x1 = this->x1;
	int y1 = this->y1;
	int x2 = this->x2;
	int y2 = this->y2;	
	int code1 = getCode(x1,y1);
	int code2 = getCode(x2,y2);
	int code;
	int x,y;
	while( (code1 & code2) ==0 )
	{
		if( code1 ==0 && code2 == 0) //完全落在内部 
		{
			cx1 = x1;
			cy1 = y1;
			cx2 = x2;
			cy2 = y2;
			return;
		}
		else if( (code1 & code2) != 0) //完全落在外部 
		{
			cx1 = cx2 = 0;
			cy1 = cy2 = 0;
			return;
		}	
		code = code1;
		if(code ==0 ) //减少计算次数，如果code1落在内部，计算code2对应的边线即可
			code = code2; 	
		//以下实现裁剪
		if( (1 & code) !=0 )
		{
			x=rect.left;        
			y=y1+(y2-y1)*1.0*(rect.left-x1)/(x2-x1);
		}
		else if( (2 & code) !=0 )
		{
			x=rect.right;        
			y=y1+(y2-y1)*1.0*(rect.right-x1)/(x2-x1);
		}
		else if( (4 & code) !=0 )
		{
			y=rect.top;  
			x=x1+(x2-x1)*1.0*(rect.top-y1)/(y2-y1);
		}
		else if( (8 & code) !=0 )
		{
			y=rect.bottom;  
			x=x1+(x2-x1)*1.0*(rect.bottom-y1)/(y2-y1);
		}
		
		if(code == code1) 
		{
			x1 = x;
			y1 = y;
			code1 = getCode(x,y);
		}
		else
		{
			x2 = x;
			y2 = y;
			code2 = getCode(x,y);
		}
	}
}

