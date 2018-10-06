// Map6.cpp: implementation of the CMap6 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DJQGeoExe.h"
#include "Map6.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMap6::CMap6()
{

}

CMap6::~CMap6()
{
	int size = geoLayers.GetSize();
	for(int i=0;i<size;i++)
	 delete geoLayers.ElementAt(i);
}

void CMap6::addLayer(CGeoLayer6 *layer)
{
    this->geoLayers.Add(layer);
}

void CMap6::Draw(CDC *pDC)
{	
	clipMap(clipRect);

	CPen pen1(PS_SOLID, 1, RGB(0,0,255));
	CPen *oldPen = pDC->SelectObject(&pen1);	
	pDC->Rectangle(clipRect);
	pDC->SelectObject(oldPen);
    
	int size = geoLayers.GetSize() ;
    for(int i=0;i<size;i++)
	geoLayers.GetAt(i)->Draw(pDC);	
}

void CMap6::clipMap(CRect clipRect)
{
   	int size = geoLayers.GetSize() ;
    for(int i=0;i<size;i++)
	geoLayers.GetAt(i)->clipLayer(clipRect);	
}	


