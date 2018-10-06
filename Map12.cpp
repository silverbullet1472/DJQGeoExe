#include "stdafx.h"
#include "Map12.h"


CMap12::CMap12()
{

}


void CMap12::Draw(CDC * pDC)
{
	if (isIndexed == 0)
	{
		int size = objs.GetSize();
		for (int i = 0; i<size; i++)
			objs.GetAt(i)->Draw(pDC);
	}
	else 
	{
		for (int i = 0; i < 25; i++)
		{
			int size = index.indexArea.GetAt(i)->objIDs.GetSize();
			CPen pen1(PS_SOLID, 1, i*60000);
			CPen *oldPen = pDC->SelectObject(&pen1);
			CRect rect = index.indexArea.GetAt(i)->rect;
			float x = (index.indexArea.GetAt(i)->x1 + index.indexArea.GetAt(i)->x2)*0.5;
			float y = (index.indexArea.GetAt(i)->y1 + index.indexArea.GetAt(i)->y2)*0.5;
			pDC->Rectangle(rect);
			CString t0;
			t0.Format("%d", i+1);
			pDC->TextOut(x, y, t0);
			for (int j = 0; j < size; j++) {
				int k = index.indexArea.GetAt(i)->objIDs[j];
				objs.GetAt(k)->Draw(pDC);
			}
			pDC->SelectObject(oldPen);
		}
	}
}

void CMap12::buildIndex()
{
	float dx = float(abs(mapRect.Width())) / 5;   //每个网格的长
	float dy = float(abs(mapRect.Height())) / 5;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			CSpatialIndexArea12 *area = new CSpatialIndexArea12();
			area->id = j + (i - 1) * 5;
			area->rect.left = mapRect.left + int(dx*(j - 1));
			area->rect.top = mapRect.top + int(dy*(i - 1));
			area->rect.right = mapRect.left + int(dx*j);
			area->rect.bottom = mapRect.top + int(dy*i);

			area->x1 = mapRect.left + int(dx*(j - 1));
			area->y1 = mapRect.top + int(dy*(i - 1));
			area->x2 = mapRect.left + int(dx*j);
			area->y2 = mapRect.top + int(dy*i);
			this->index.indexArea.Add(area);
		}
	}
	int size = objs.GetSize();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			CRect rect = this->index.indexArea[j]->rect;
			//判断这个对象在不在当前网格中
			float x = objs[i]->x;
			float y = objs[i]->y;
			if ((x > rect.left) && (x < rect.right) && (y > rect.top) && (y < rect.bottom))
			{				
				this->index.indexArea.GetAt(j)->addObject(i);
			}
		}
	}
	isIndexed = 1;
}

void CMap12::addObject(CSpatialObject12 *obj)
{
	this->objs.Add(obj);
}

void CMap12::getMinMax()
{
	x1 = INT_MAX;
	y1 = INT_MAX;
	x2 = INT_MIN;
	y2 = INT_MIN;
	int size = objs.GetSize();
	for (int i = 0; i < size; i++)
	{
		if (objs.GetAt(i)->x > x2)
		{
			x2 = objs.GetAt(i)->x;
		}
		if (objs.GetAt(i)->y > y2)
		{
			y2 = objs.GetAt(i)->y;
		}
		if (objs.GetAt(i)->x < x1)
		{
			x1 = objs.GetAt(i)->x;
		}
		if (objs.GetAt(i)->y < y1)
		{
			y1 = objs.GetAt(i)->y;
		}
	}
	this->mapRect = CRect(x1,y1,x2,y2);
}

float CMap12::getDistance(float x, float y, CSpatialIndexArea12 * area, CSpatialObject12 & obj)
{
	float dist = INT_MAX;
	if (area != NULL)
	{
	int size = area->objIDs.GetSize();
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		int k = area->objIDs[i];
		float x0 = this->objs[k]->x;
		float y0 = this->objs[k]->y;
		float temp = fabs((x - x0)*(y - y0));
		if (temp < dist)
		{
			dist = temp;
			j = k;
		}
	}
	obj = *objs[j];
	return dist;
	}
	else return dist;
}

CMap12::~CMap12()
{
}
