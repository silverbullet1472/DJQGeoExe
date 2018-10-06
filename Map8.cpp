#include "stdafx.h"
#include "Map8.h"


CMap8::CMap8()
{
}


void CMap8::Draw(CDC * pDC, CMapProjection8 * mapPrj)
{
	if(mapPrj!=NULL) mapPrj->Draw(pDC);
	int size = geoLayers.GetSize();
	for (int i = 0; i<size; i++)
		geoLayers.GetAt(i)->Draw(pDC, mapPrj);
}

void CMap8::addLayers(CGeoLayer8 * geoLayer)
{
	this->geoLayers.Add(geoLayer);
}

CMap8::~CMap8()
{
}
