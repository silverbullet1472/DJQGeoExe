#include "stdafx.h"
#include "Map9.h"



CMap9::CMap9()
{
}

void CMap9::Draw(CDC * pDC)
{
	CPen pen1(PS_SOLID, 1, RGB(0, 0, 0));
	CPen *oldPen = pDC->SelectObject(&pen1);
	int size1 = pts.size();
	for (int i = 0; i<size1; i++)
	{
		if (i == 0)
		{
			pDC->MoveTo(pts[i]);
			CString t0;
			t0.Format("%d -> %d,%d", i, pts[i].x, pts[i].y);
			pDC->TextOut(pts[i].x, pts[i].y, t0);
		}	
		else
		{
			pDC->LineTo(pts[i]);
			CString t;
			t.Format("%d -> %d,%d", i, pts[i].x, pts[i].y);
			pDC->TextOut(pts[i].x, pts[i].y, t);
		}
	}
	pDC->LineTo(pts[0]);
	getintersectPoint();
	getPoint();

	//pDC->LineTo(pts[0]);                   //²âÊÔFloodFillº¯Êý
	//pDC->SelectObject(oldPen);
	//CBrush brush;
	//brush.CreateSolidBrush(RGB(255, 255, 0));
	//CBrush *oldBrush = pDC->SelectObject(&brush);
	//pDC->FloodFill(x0, y0, RGB(0, 0, 0));
	//pDC->SelectObject(oldPen);

	CPen pen2(PS_SOLID, 2, RGB(0, 0, 255));
	oldPen = pDC->SelectObject(&pen2);
	CPoint p;
	p.x = x0;
	p.y = y0;
	CString t2;
	t2.Format("%d,%d", p.x, p.y);
	pDC->TextOut(p.x+10, p.y-10, t2);
	pDC->Ellipse(p.x, p.y, p.x + 20, p.y + 20);
	pDC->SelectObject(oldPen);
}

bool  CMap9::ismax(CPoint A, CPoint B)
{
	return A.y > B.y;
}

void CMap9::getPoint()
{
	sort(Chpts.begin(), Chpts.end(), ismax);
	int size = Chpts.size();
	float y = 0, ty = 0;
	for (int i = 0; i < size-1; i++)
	{
		y = Chpts[i].y - Chpts[i + 1].y;
		if (y > ty)
		{
			ty = y;
			this->y0 = (Chpts[i].y + Chpts[i + 1].y) / 2;
		}
	}
	this->x0 = (xmin + xmax) / 2;
}

void CMap9::getintersectPoint()
{
	float x1 = (xmin+xmax) / 2;
	int size = pts.size();
	for (int i = 0; i<size-1; i++)
	{
		if (((pts[i].x - x1)*(pts[i + 1].x - x1)) < 0)
		{
			float k = ((pts[i + 1].y) - (pts[i].y) )/ ((pts[i + 1].x) - (pts[i].x));
			float b = (pts[i + 1].y) - k*(pts[i + 1].x);
			float y = k*x1 + b;
 			CPoint p(x1, y);
			Chpts.push_back(p);
		}
	}
}


CMap9::~CMap9()
{
}
