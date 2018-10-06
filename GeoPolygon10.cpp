#include "stdafx.h"
#include "GeoPolygon10.h"
#include <algorithm>
using namespace std;

void CGeoPolygon10::Draw(CDC * pDC)
{
	//pDC->Ellipse(pt.x, pt.y, pt.x + 10000000, pt.y + 10000000);
	CPen pen(PS_SOLID, 1, RGB(0,0,0));
	CPen *oldPen = pDC->SelectObject(&pen);
	int size = pts.GetSize();
	for (int i = 0; i<size; i++)
	{
		if (i == 0)
			pDC->MoveTo(pts[i]);
		else
			pDC->LineTo(pts[i]);
	}
	pDC->SelectObject(oldPen);
	CBrush brush;
	brush.CreateSolidBrush(pts.GetSize()*6.0);
	CBrush *oldBrush = pDC->SelectObject(&brush);
	if(pt.x!=0) pDC->FloodFill(pt.x, pt.y, RGB(0,0,0));
	pDC->SelectObject(oldPen);
}

void CGeoPolygon10::addPoint(CPoint pt)
{
	this->pts.Add(pt);
}

void CGeoPolygon10::addSeg(int seg)
{
	this->segs.Add(seg);
}

void CGeoPolygon10::getCenterPt()
{
	float x0, y0;
	x0 = (minx + maxx) / 2.0;
	int size = pts.GetSize();
	for (int i = 0; i<size-1; i++)
	{
			if (((pts[i].x - x0)*(pts[i + 1].x - x0)) < 0)
			{
				float k = ((pts[i + 1].y) - (pts[i].y)) / ((pts[i + 1].x) - (pts[i].x));
				float b = (pts[i + 1].y) - k*(pts[i + 1].x);
				float y = k*x0 + b;
				CPoint p(x0, y);
				clipPts.Add(p);
			}
	}
	sort(clipPts.GetData(),clipPts.GetData()+clipPts.GetSize(),ismax);
	if (clipPts.GetSize() >= 2) 
	{
		y0 = (clipPts[0].y + clipPts[1].y) / 2;
	}
	else
	{
		y0 = (miny + maxy) / 2.0;
	}
	this->pt = CPoint (x0, y0);
}

CGeoPolygon10::CGeoPolygon10()
{
}


CGeoPolygon10::~CGeoPolygon10()
{
}

bool CGeoPolygon10::ismax(CPoint A, CPoint B)
{
	return A.y > B.y;
}
