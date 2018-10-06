#pragma once
#include  "afxtempl.h"
class CSpatialIndexArea12
{
public:
	CSpatialIndexArea12();
	int id;
	CRect rect;
	float x1, y1, x2, y2;
	CArray<int, int> objIDs;
	void Draw(CDC *pDC);
	void addObject(int i);
	~CSpatialIndexArea12();
};

