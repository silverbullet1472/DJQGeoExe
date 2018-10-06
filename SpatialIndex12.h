#pragma once
#include "SpatialIndexArea12.h"
#include  "afxtempl.h"
class CSpatialIndex12
{
public:
	CSpatialIndex12();
	float x1, y1, x2, y2;
	CArray< CSpatialIndexArea12*, CSpatialIndexArea12 *> indexArea;
	CSpatialIndexArea12 * getCurrentIndexArea (float x, float y);
	//CArray< CInverIndex, CInverIndex > inversIndex;
	int m, n;
	void Draw(CDC *pDC);
	~CSpatialIndex12();
};

