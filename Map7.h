#pragma once
#include "ConvexHull7.h"

class CMap7
{
public:
	CMap7();
	CConvexHull7 convexHull;
	void Draw(CDC *pDC);
	~CMap7();
};

