// Mypolygon.cpp: implementation of the CMypolygon class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DJQGeoExe.h"
#include "Mypolygon4.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyPolygon4::CMyPolygon4()
{

}

CMyPolygon4::~CMyPolygon4()
{

}

void CMyPolygon4::AddPoint(CPoint pt)
{
	pts.Add(pt);
}

void CMyPolygon4::SetCenterPt(CPoint pt)
{
	cenPt = pt;
}

void CMyPolygon4::Draw(CDC *pDC)
{
	int size = pts.GetSize();
	pDC->Polygon(pts.GetData(),size);
		
	FillPolygon(pDC);
}

void CMyPolygon4::FillPolygon(CDC *pDC)
{	
	CArray<CPoint,CPoint>seeds;
	int whiteColor = RGB(255,255,255); //白色
	if( pDC->GetPixel(cenPt) == whiteColor)
		seeds.Add(cenPt);
	CPoint pt;
	int x,y;
	while(seeds.GetSize() > 0)
	{
	   pt= seeds.GetAt(seeds.GetSize()-1);
	   pDC->SetPixel(pt,color);   //测试pDC->SetPixel(pt,RGB(255,0,0));
	   seeds.RemoveAt(seeds.GetSize()-1);	
		x = pt.x;
		y = pt.y;		
		//四方向扩展，确定其他种子点
		if( pDC->GetPixel(x+1,y) == whiteColor) 
			seeds.Add(CPoint(x+1,y));
		if( pDC->GetPixel(x,y+1) == whiteColor)
			seeds.Add(CPoint(x,y+1));
		if( pDC->GetPixel(x-1,y) == whiteColor)
			seeds.Add(CPoint(x-1,y));
		if( pDC->GetPixel(x,y-1) == whiteColor)
			seeds.Add(CPoint(x,y-1));
	}
}
