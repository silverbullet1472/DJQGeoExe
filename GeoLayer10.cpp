#include "stdafx.h"
#include "GeoLayer10.h"


void CGeoLayer10::Draw(CDC * pDC)
{
	int size = geoObjs.GetSize();
	for (int i = 0; i < size; i++)
	{
		geoObjs.GetAt(i)->Draw(pDC);
	}
}

void CGeoLayer10::addObject(CGeoObject10 * obj)
{
	this->geoObjs.Add(obj);
}

CGeoLayer10::CGeoLayer10()
{
}


CGeoLayer10::~CGeoLayer10()
{
}
