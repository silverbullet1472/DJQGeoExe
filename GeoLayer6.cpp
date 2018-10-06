// GeoLayer.cpp: implementation of the CGeoLayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DJQGeoExe.h"
#include "GeoLayer6.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoLayer6::CGeoLayer6()
{

}

CGeoLayer6::~CGeoLayer6()
{
	int size = geoPolylines.GetSize();
	for(int i=0;i<size;i++)
	 delete geoPolylines.ElementAt(i);
}


void CGeoLayer6::Draw(CDC *pDC)
{
    int size = geoPolylines.GetSize() ;
    for(int i=0;i<size;i++)
	geoPolylines.GetAt(i)->Draw(pDC);
}


void CGeoLayer6::addPolyline(CGeoPolyline6 *line)
{
    this->geoPolylines.Add(line);
}

void CGeoLayer6::clipLayer(CRect clipRect)
{
    int size = geoPolylines.GetSize() ;
    for(int i=0;i<size;i++)
	geoPolylines.GetAt(i)->clipPolyline(clipRect);
}