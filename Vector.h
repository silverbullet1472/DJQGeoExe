#pragma once
#include <math.h>

class CVector
{
public:
	CVector();
	CVector(CPoint pt1,CPoint pt2);
	float x, y;
	float crossProduct(CVector v2);
	float dotProduct(CVector v2);
	float getAngle(CVector);
	CVector Plus(CVector v2);
	CVector Minus(CVector v2);
	float getXValue();
	float getYValue();

	~CVector();
};

