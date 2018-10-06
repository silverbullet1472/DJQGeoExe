#pragma once
#include "MapProjection8.h"
#include "GeoPoint8.h"
#include  "afxtempl.h"

class CGeoObject8
{
public:
	CGeoObject8();
	float L0, L1, B0, B1;
	void  Draw(CDC *pDC, CMapProjection8 *mapPrj);
	void  addPoint(CGeoPoint8 *geoPoint);
	CArray <CGeoPoint8 *, CGeoPoint8 *> pts;
	~CGeoObject8();
};

