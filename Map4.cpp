// Map4.cpp: implementation of the CMap4 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DJQGeoExe.h"
#include "Map4.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMap4::CMap4()
{

}

CMap4::~CMap4()
{
	int size = polygons.GetSize();
	for(int i=0;i<size;i++)
		delete polygons.ElementAt(i);
}

void CMap4::Draw(CDC *pDC)
{
	int size = polygons.GetSize();//超过35有异常，则调整size为最多34
	size = size>0?34:0;
	for(int i=0;i<size;i++)        
		polygons[i]->Draw(pDC);
}