#pragma once
#include  "afxtempl.h"
#include  "GeoObject8.h"
#include  "MapProjection8.h"
class CGeoLayer8
{
public:
	CGeoLayer8();
	float L0, L1, B0, B1;
	CArray< CGeoObject8 *, CGeoObject8 *> geoObjs;
	void	Draw(CDC *pDC, CMapProjection8 *mapPrj);
	void	addObjects(CGeoObject8 *geoObj);
	~CGeoLayer8();
};

