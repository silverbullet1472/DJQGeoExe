// Map1.cpp: implementation of the CMap1 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DJQGeoExe.h"
#include "Map1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMap1::CMap1()
{

}

CMap1::~CMap1()
{
	int size = lines.GetSize();
	for(int i=0;i<size;i++)
	delete lines.ElementAt(i);
}

void CMap1::Draw(CDC *pDC)
{
   int size = lines.GetSize() ;
    for(int i=0;i<size;i++)
	  lines.GetAt(i)->Draw(pDC);
}

void CMap1::addLine(CDDAline1 *line)
{
    this->lines.Add(line);
}
