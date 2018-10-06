#include "stdafx.h"
#include "Vector.h"



CVector::CVector()
{
	x = 0; y = 0;
}

CVector::CVector(CPoint pt1, CPoint pt2)
{
	x = pt2.x - pt1.x;
	y = pt2.y - pt1.y;
}

float CVector::crossProduct(CVector v2)
{
		return (x*v2.y-v2.x*y);
}

float CVector::dotProduct(CVector v2)
{
	return (x*v2.x+y*v2.y);
}

float CVector::getAngle(CVector)
{
	if (atan(y / x) > 0)
		return atan(y / x);
	else
		return (-atan(y / x) + 0.5*3.1415926);

}

CVector CVector::Plus(CVector v2)
{
	float x0 = x + v2.x;
	float y0 = y + v2.y;
	CVector v0;
	v0.x = x0;
	v0.y = y0;
	return v0;
}

CVector CVector::Minus(CVector v2)
{
	float x0 = x - v2.x;
	float y0 = y - v2.y;
	CVector v0;
	v0.x = x0;
	v0.y = y0;
	return v0;
}

float CVector::getXValue()
{
	return x;
}

float CVector::getYValue()
{
	return y;
}


CVector::~CVector()
{
}
