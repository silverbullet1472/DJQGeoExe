#include "stdafx.h"
#include "MapProjection8.h"


CMapProjection8::CMapProjection8()
{
	ae = 6378137;
	e = sqrt(2 * (1 / 298.257222101));
	mapScale = 10000000;
	mapShowScale = 1;
}


void CMapProjection8::getXY(float L, float B, float * x, float * y)
{
}

void CMapProjection8::getLB(float x, float y, float * L, float * B)
{
}

void CMapProjection8::Draw(CDC * pDC)
{
}

CMapProjection8::~CMapProjection8()
{
}
