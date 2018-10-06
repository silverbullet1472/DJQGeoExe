#include "stdafx.h"
#include "Map7.h"


CMap7::CMap7()
{
}


CMap7::~CMap7()
{
}

void CMap7::Draw(CDC *pDC)
{
	this->convexHull.Draw(pDC);
}
