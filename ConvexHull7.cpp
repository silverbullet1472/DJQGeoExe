#include "stdafx.h"
#include "ConvexHull7.h"
#include <windows.h>


CConvexHull7::CConvexHull7()
{
}

void CConvexHull7::Draw(CDC * pDC)
{

	pDC->Rectangle(crWCRect);
	for (int q = 0; q < pts.size(); q++)
	{
		point7 p1 = pts[q];
		pDC->Ellipse(p1.x, p1.y, p1.x + 5, p1.y + 5);
	}
	for (int p = 0; p < Chpts.size(); p++)
	{
		point7 p1 = Chpts[p];
		pDC->Ellipse(p1.x, p1.y, p1.x + 5, p1.y + 5);
		CString t;
		t.Format("%d -> %.1f,%.1f", p, p1.x, p1.y);
		pDC->TextOut(p1.x, p1.y, t);
		Sleep(100);
		if (p == 0)
			pDC->MoveTo(Chpts[p].x, Chpts[p].y);
		else
			pDC->LineTo(Chpts[p].x, Chpts[p].y);
	}
	pDC->LineTo(Chpts[0].x, Chpts[0].y);
}

void CConvexHull7::getConvexHull1()
{
	sort1();//按角度进行排序
number1:
	int k = 4;
number2:
	int j = 2;
number3:
	bool diff = different(Chpts[1], Chpts[k - j], Chpts[k - j + 1], Chpts[k]);
	if (diff)
	{
		Chpts.erase(Chpts.begin() + k - 1);
		k--;
		j--;
	}
	else { 
	}
number4:
	j++;
	if (j != k - 1)
		goto number3;
number5:
	k++;
	int s = Chpts.size();
	if (k != s)
		goto number2;
}

void CConvexHull7::sort1()
{
	sort(Chpts.begin(), Chpts.end(), ismin);//找到最低点
	point7 first = Chpts[0];
	for (vector<point7>::iterator iter = Chpts.begin(); iter != Chpts.end(); iter++)//求出各点与起点的角度
	{
		(*iter).angle = my_angle(first, *iter);
	}
	sort(Chpts.begin(), Chpts.end(), isAngle);//按角度排序
}

bool CConvexHull7::different(point7 A, point7 B, point7 C, point7 D)
{
	float x1 = A.x, x2 = B.x, x3 = C.x, x4 = D.x;
	float y1 = A.y, y2 = B.y, y3 = C.y, y4 = D.y;
	if (x3 == x2)
	{
		if ((x1 - x2)*(x4 - x2) < 0)
			return true;
		else
			return false;
	}
	else
	{
		float k = (y2 - y3) / (x2 - x3);
		float b = y2 - k*x2;
		float y10 = y1 - k*x1 - b;
		float y40 = y4 - k*x4 - b;
		float t = y10*y40;
		if (t < 0)
			return true;
		else
			return false;
	}
}

float CConvexHull7::my_angle(point7 A, point7 B)
{
	if (A.x == B.x && A.y == B.y)
		return 0;
	return acos((B.x - A.x) / (sqrt((B.y - A.y)*(B.y - A.y) + (B.x - A.x)*(B.x - A.x))));
}


bool CConvexHull7::ismin(point7 A, point7 B)
{
	return A.y < B.y;
}

bool CConvexHull7::isAngle(point7 A, point7 B)
{
	return A.angle < B.angle;
}



void CConvexHull7::getcrWCRect()
{
	//以下读取矩形范围
	int size = this->pts.size();
	float xmin = this->pts[0].x;
	float xmax = this->pts[0].x;
	float ymin = this->pts[0].y;
	float ymax = this->pts[0].y;
	for (int i = 1; i < size; i++)
	{
		if (this->pts[i].x > xmax)
			xmax = this->pts[i].x;
		if (this->pts[i].x < xmin)
			xmin = this->pts[i].x;
		if (this->pts[i].y > ymax)
			ymax = this->pts[i].y;
		if (this->pts[i].y < ymin)
			ymin = this->pts[i].y;
	}
	CRect rect(xmin - 50, ymin - 50, xmax + 50, ymax + 50);
	this->crWCRect = rect;
}


CConvexHull7::~CConvexHull7()
{
}
