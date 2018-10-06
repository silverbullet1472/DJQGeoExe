// Map3.cpp: implementation of the CMap3 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DJQGeoExe.h"
#include "Map3.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMap3::CMap3()
{

}

CMap3::~CMap3()
{

}


void CMap3::addCity(CITY city)
{
	cities.Add(city);
}

void CMap3::Draw(CDC *pDC)
{
	int size = cities.GetSize();
	CITY ocity;
	int r = 1000000;
	for(int i = 0;i<size;i++)
	{
		ocity = cities.GetAt(i);
		pDC->Ellipse(ocity.lon,ocity.lat,ocity.lon+r,ocity.lat+r);
	}
}
