#pragma once
#define pi 3.141592654

class CMapProjection8
{
public:
	CMapProjection8();
	float L0, L1, B0, B1;
	float ae;//椭圆长半径
	float e;//第一偏心率（约等于开平方（2倍扁率））
	int mapShowScale;
	int mapScale;
	virtual void getXY(float L, float B, float *x, float *y);
	void getLB(float x, float y, float *L, float *B);
	virtual void Draw(CDC *pDC);
	CRect wcRect;
	~CMapProjection8();
};

