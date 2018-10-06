// GeoPolyline.cpp: implementation of the CGeoPolyline class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DJQGeoExe.h"
#include "GeoPolyline6.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoPolyline6::CGeoPolyline6()
{

}

CGeoPolyline6::~CGeoPolyline6()
{

}

void CGeoPolyline6::addPoint(CPoint pt)
{
    this->pts.Add(pt);
}

void CGeoPolyline6::Draw(CDC *pDC)
{
	CPen pen1(PS_SOLID, 1, RGB(255,0,0));
	CPen *oldPen = pDC->SelectObject(&pen1);
	int size1 = pts.GetSize();
	for(int i = 0;i<size1;i++)
	{
		if(i==0)
			pDC->MoveTo(pts[i]);
		else
			pDC->LineTo(pts[i]);
	}
	
	CPen pen2(PS_SOLID, 2, RGB(0,0,255));
	oldPen = pDC->SelectObject(&pen2);
	int size2 = clipPts.GetSize();
	for(int j = 0;j<size2;j++)
	{
		if(j==0)
			pDC->MoveTo(clipPts[j]);
		else
			pDC->LineTo(clipPts[j]);
	}

	pDC->SelectObject(oldPen);

}  

void CGeoPolyline6::clipPolyline(CRect clipRect)
{
	this->clipRect=clipRect;
	int size = pts.GetSize();
	if( size == 1)
		 return;
	for(int i = 0;i<size-1;i++)//读到第18条线出现错误 完善 循环裁剪
	{
		int x1 = pts[i].x;
		int y1 = pts[i].y;
		int x2 = pts[i+1].x;
		int y2 = pts[i+1].y;
		int code1 = getCode(x1,y1);
    	int code2 = getCode(x2,y2);
		int code;
		int x,y;

	    if( (code1 & code2) != 0) //完全落在外部 
			{
				continue;
			}
		
		while( (code1 & code2) ==0 )
		{	
			if( code1 ==0 && code2 == 0) //完全落在内部 
			{
			   CPoint pt1(x1,y1);CPoint pt2(x2,y2);
			   this->clipPts.Add(pt1);
			   this->clipPts.Add(pt2);
			   break;
			}
			code = code1;
			if(code ==0 ) //减少计算次数，如果code1落在内部，计算code2对应的边线即可
				code = code2; 		
			//以下实现裁剪
			if( (1 & code) !=0 )
			{
				x=clipRect.left;        
				y=y1+(y2-y1)*1.0*(clipRect.left-x1)/(x2-x1);
			}
			else if( (2 & code) !=0 )
			{
				x=clipRect.right;        
				y=y1+(y2-y1)*1.0*(clipRect.right-x1)/(x2-x1);
			}
			else if( (4 & code) !=0 )
			{
				y=clipRect.top;  
				x=x1+(x2-x1)*1.0*(clipRect.top-y1)/(y2-y1);
			}
			else if( (8 & code) !=0 )
			{
				y=clipRect.bottom;  
				x=x1+(x2-x1)*1.0*(clipRect.bottom-y1)/(y2-y1);
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
} 

int CGeoPolyline6::getCode(int x1,int y1)
{
	int code = 0;	//按由低到高位编码，左、右、上、下
	if( x1 < clipRect.left) 
		code += 1;
	if( x1 > clipRect.right) 
		code += 2;
	if( y1 < clipRect.top) 
		code += 4;
	if( y1 > clipRect.bottom) 
		code += 8;	
	return code;
}