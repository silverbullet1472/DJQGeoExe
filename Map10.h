#pragma once
#include  "afxtempl.h"
#include  "GeoLayer10.h"
class CMap10
{
public:
	CArray <CGeoLayer10*, CGeoLayer10 *> geoLayers;
	void	Draw(CDC *pDC);
	CRect   wcRect;
	void    addLayer(CGeoLayer10 *layer);
	float L0, B0, L1, B1;
	int mapScale;
	CMap10();
	~CMap10();
};


