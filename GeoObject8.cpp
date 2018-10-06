#include "stdafx.h"
#include "GeoObject8.h"


CGeoObject8::CGeoObject8()
{
}


void CGeoObject8::Draw(CDC * pDC, CMapProjection8 * mapPrj)
{
	if(mapPrj!=NULL)
	{
		int size = pts.GetSize();
		for (int i = 0; i < size; i++)
		{
			float *x = new float ; float *y = new float ;
			mapPrj->getXY(pts[i]->L, pts[i]->B, x, y);
			if (i == 0)
				pDC->MoveTo(*x, *y);
			else
				pDC->LineTo(*x, *y);
		}
	}
	else
	{
		int size = pts.GetSize();
		for (int i = 0; i < size; i++)
		{
			if (i == 0)
				pDC->MoveTo((pts[i]->L), (pts[i]->B));
			else
				pDC->LineTo((pts[i]->L), (pts[i]->B));
		}
	}
}

void CGeoObject8::addPoint(CGeoPoint8  *geoPoint)
{
	this->pts.Add(geoPoint);
}

CGeoObject8::~CGeoObject8()
{
}
