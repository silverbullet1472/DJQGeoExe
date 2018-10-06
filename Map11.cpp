#include "stdafx.h"
#include "Map11.h"


CMap11::CMap11()
{

}

void CMap11::Draw(CDC * pDC)
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

	clockJudge();

	CPen pen2(PS_SOLID, 2, RGB(0, 0, 255));
	oldPen = pDC->SelectObject(&pen2);
	CPoint p;
	p.x = (xmin + xmax) / 2.0;
	p.y = (ymin + ymax) / 2.0;
	CString t2;
	if(this->clockWise==true) 
		t2.Format("Ë³Ê±Õë");
	else
		t2.Format("ÄæÊ±Õë");
	pDC->TextOut(p.x + 10, p.y - 10, t2);
	pDC->SelectObject(oldPen);
}

void CMap11::clockJudge()
{
	int size = pts.size();
	for (int i = 0; i < size; i++)
	{
		if (pts[i].x == this->xmax)
		{
			CVector v1(pts[i], pts[i - 1]);
			CVector v2(pts[i], pts[i + 1]);
			if (v1.crossProduct(v2) > 0)
				this -> clockWise = false;
			else 
				this->clockWise = true;
			break;
		}
	}
}


CMap11::~CMap11()
{
}
