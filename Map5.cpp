// Map5.cpp: implementation of the CMap5 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DJQGeoExe.h"
#include "Map5.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMap5::CMap5()
{
	clipLine.setRect(CRect(300,100,700,400));
	clipLine.setCoords(250,80,800,500);
	clipLine.clipSutherland();
}

CMap5::~CMap5()
{

}

void CMap5::Draw(CDC *pDC)
{
	clipLine.Draw(pDC);
}
