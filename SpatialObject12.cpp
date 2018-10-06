#include "stdafx.h"
#include "SpatialObject12.h"


CSpatialObject12::CSpatialObject12()
{
}


void CSpatialObject12::Draw(CDC * pDC)
{
	CString t;
	//t.Format("%d -> %s", this->id, this->name);
	//pDC->TextOut(this->x, this->y, t);
	pDC->Ellipse(this->x, this->y, this->x + 10, this->y + 10);
}

CSpatialObject12::~CSpatialObject12()
{
}
