#include "stdafx.h"
#include "Map10.h"


void CMap10::Draw(CDC * pDC)
{
	int size = geoLayers.GetSize();
	for (int i = 0; i<size; i++)
		geoLayers.GetAt(i)->Draw(pDC);
}

void CMap10::addLayer(CGeoLayer10 * layer)
{
	this->geoLayers.Add(layer);
}

CMap10::CMap10()
{

}


CMap10::~CMap10()
{
}
