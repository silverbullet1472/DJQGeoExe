#pragma once
#include "afxtempl.h"
#include "SpatialObject12.h"
#include "SpatialIndex12.h"
class CMap12
{
public:
	CMap12();
	CArray< CSpatialObject12*, CSpatialObject12 *> objs;
	CSpatialIndex12 index;
	CRect mapRect;
	int isIndexed = 0;
	void Draw(CDC *pDC);
	void buildIndex();
	void addObject(CSpatialObject12 *obj);
	void getMinMax();
	float x1, y1, x2, y2;
	float getDistance(float x, float y, CSpatialIndexArea12 * area, CSpatialObject12 & obj);
	~CMap12();
};

