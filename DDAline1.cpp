// DDAline.cpp: implementation of the CDDAline class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DJQGeoExe.h"
#include "DDAline1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDDAline1::CDDAline1()
{

}

CDDAline1::~CDDAline1()
{

}

void CDDAline1::setCoords(int x1,int y1,int x2,int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

void CDDAline1::Draw(CDC *pDC)
{	
	float x, y, xincre, yincre;  
    int k = abs(x2 - x1);  //|dx|
    if (abs(y2 - y1) > k)  //|dy|
    {  
        k = abs(y2 - y1);  
    }					   //k=max(|dx|,|dy|) ->²½³¤
	if(x1<x2)
	{
	xincre = (float)(x2 - x1)/k;  
    yincre = (float)(y2 - y1)/k;  
  	}
    else
	{
	xincre = -(float)(x2 - x1)/k;  
    yincre = -(float)(y2 - y1)/k;  
	}

    x = x1;  
    y = y1;  
    for (int i = 1; i <= k; i++)  
    {  
        pDC->SetPixel(x, y, RGB(255, 0, 0));  
        x = x + xincre;  
        y = y + yincre;  
    } 
}
