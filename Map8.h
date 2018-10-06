#pragma once
#include  "afxtempl.h"
#include  "GeoLayer8.h"
#include  "MapProjection8.h"
class CMap8
{
public:
	CMap8();
	float L0, L1, B0, B1;
	CArray <CGeoLayer8 *, CGeoLayer8 *> geoLayers;
	void	Draw(CDC *pDC, CMapProjection8 *mapPrj);
	void	addLayers(CGeoLayer8 *geoLayer);
	int mapScale;
	~CMap8();
};

