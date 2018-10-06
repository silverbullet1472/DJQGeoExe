#pragma once
#include "GeoObject10.h"
#include "afxtempl.h"


class CGeoPolygon10 :
	public CGeoObject10
{
public:
	CPoint	pt;
	CArray <CPoint, CPoint > pts;
	CArray <int, int > segs;
	CArray <CPoint, CPoint > clipPts;
	void	Draw(CDC *pDC);
	void	addPoint(CPoint pt);
	void	addSeg(int seg);
	void	getCenterPt();
	float   minx, miny, maxx, maxy;
	static bool ismax(CPoint A, CPoint B);
	CGeoPolygon10();
	~CGeoPolygon10();
};

