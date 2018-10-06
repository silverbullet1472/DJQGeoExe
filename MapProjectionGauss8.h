#pragma once
#include "MapProjection8.h"

#include "math.h"
#define IPI 0.0174532925199433 
class CMapProjectionGauss8 :
	public CMapProjection8
{
public:
	CMapProjectionGauss8(float L0, float B0, float L1, float B1);
	~CMapProjectionGauss8();
	void getLonLat(float x, float y, float *lon, float *lat);
	void Draw(CDC *pDC, CRect wcRect);
	void getXY(float lamda, float fai, float *x, float *y);
	int ProjNo;
	float long0, lat0;
	float X0, Y0;
	float a, f, e2, ee;
	float e61, e62, e63, e64, e65;
	int showMapScale;
};

