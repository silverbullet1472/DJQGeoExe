#include "stdafx.h"
#include "GeoLayer8.h"


CGeoLayer8::CGeoLayer8()
{
}


void CGeoLayer8::Draw(CDC * pDC, CMapProjection8 * mapPrj)
{
	int size = geoObjs.GetSize();
	for (int i = 0; i<size; i++)
		geoObjs.GetAt(i)->Draw(pDC, mapPrj);
}

void CGeoLayer8::addObjects(CGeoObject8 * geoObj)
{
		this->geoObjs.Add(geoObj);
}

CGeoLayer8::~CGeoLayer8()
{
}
