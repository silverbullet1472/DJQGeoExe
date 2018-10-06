// Map2.h: interface for the CMap2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAP2_H__076D51CB_C7B9_4178_BA03_5384A4FEB872__INCLUDED_)
#define AFX_MAP2_H__076D51CB_C7B9_4178_BA03_5384A4FEB872__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Myline2.h"

class CMap2  
{
public:
	CMap2();
	virtual ~CMap2();
	CMyline2 line;
	void Draw(CDC *pDC);
};

#endif // !defined(AFX_MAP2_H__076D51CB_C7B9_4178_BA03_5384A4FEB872__INCLUDED_)
