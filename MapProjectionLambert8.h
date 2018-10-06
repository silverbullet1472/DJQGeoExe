#pragma once
#include "MapProjection8.h"
class CMapProjectionLambert8 :
	public CMapProjection8
{
public:
	CMapProjectionLambert8(float L0, float B0, float L1, float B1);
	void getXY(float L, float B, float *x, float *y);
	void Draw(CDC *pDC);
	//应用指定双标准纬线求投影常数
	float b1, b2;//经度
	float r1, r2;//与地轴距离
	float n1, n2;//卯酉圈半径
	float u1, u2;//积分公式中所用数值
	float ac, c;//等角割圆柱投影所需常数
	float ps;//求最低纬线投影所需常数
	float lm;//中央经线
	float us;
	float bs;
	~CMapProjectionLambert8();
};

