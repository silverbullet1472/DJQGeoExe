#include "stdafx.h"
#include "MapProjectionLambert8.h"


CMapProjectionLambert8::CMapProjectionLambert8(float L0, float B0, float L1, float B1)
{
	ac = 0.590276175;
	c = 12840667;
	us = 1;
	ps = c / pow(us, ac);
	lm = (105.0 / 180)*pi;

	this->L0 = L0; this->B0 = B0; this->L1 = L1; this->B1 = B1;
	float *x0 = new float;
	float *y0 = new float;
	float *x1 = new float;
	float *y1 = new float;
	getXY(L0, B0, x0, y0);
	getXY(L1, B1, x1, y1);
	this->wcRect = CRect((int)*x0, (int)*y0 - 1100000, -(int)*x0, (int)*y1 + 600000);
}

void CMapProjectionLambert8::getXY(float L, float B, float * x, float * y)
{
	float l, b;
	L = L / mapScale;
	B = B / mapScale;
	l = (L / 180)*pi;
	b = (B / 180)*pi;
	float p;
	float u;
	u= tan(pi / 4 + b / 2)*pow(((1 - e*sin(b)) / (1 + e*sin(b))), e / 2);
	p = c / pow(u,ac);
	*y = mapShowScale*(ps - p*cos(ac*(l-lm)));
	*x = mapShowScale*(p*sin(ac*(l - lm)));
}

void CMapProjectionLambert8::Draw(CDC * pDC)
{
	float L, B;
	float *x = new float; float *y = new float;
	for (int i = 0; i < 8;i++)//经线网绘制
	{
		L = (70.0 + 10 * i)*10000000;
		for (int j=0;j<7;j++)
		{
			B = (10 * j)*10000000;
			getXY(L, B, x, y);
			if (j==0)
			pDC->MoveTo(*x, *y);
			else
				pDC->LineTo(*x, *y);
		}
	}
	for (int m = 0; m < 7; m++)//纬线网绘制
	{
		B = (10 * m)*10000000;
		for (int n = 0; n<8; n++)
		{
			L = (70.0 + 10 * n)*10000000;
			getXY(L, B, x, y);
			if (n == 0)
				pDC->MoveTo(*x, *y);
			else
				pDC->LineTo(*x, *y);
		}
	}	
}


CMapProjectionLambert8::~CMapProjectionLambert8()
{
}
