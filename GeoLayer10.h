#pragma once
#include "afxtempl.h"
#include "GeoObject10.h"
class CGeoLayer10
{
public:
	CArray<CGeoObject10*, CGeoObject10 *> geoObjs;
	void Draw(CDC *pDC);
	void addObject(CGeoObject10 *obj);
	CGeoLayer10();
	~CGeoLayer10();
};
