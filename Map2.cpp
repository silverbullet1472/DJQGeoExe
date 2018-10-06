// Map2.cpp: implementation of the CMap2 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DJQGeoExe.h"
#include "Map2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMap2::CMap2()
{

}

CMap2::~CMap2()
{

}

void CMap2::Draw(CDC *pDC)
{
	  line.Draw(pDC);
}
