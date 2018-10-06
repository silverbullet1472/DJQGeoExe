// Map4.h: interface for the CMap4 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAP4_H__51AD8E2C_9834_4E38_83D8_C7B9A6F20A14__INCLUDED_)
#define AFX_MAP4_H__51AD8E2C_9834_4E38_83D8_C7B9A6F20A14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "afxtempl.h"
#include "MyPolygon4.h"


class CMap4  
{
public:
	CMap4();
	CArray<CMyPolygon4 *,CMyPolygon4 *>polygons;
	void Draw(CDC *pDC);
	virtual ~CMap4();

};

#endif // !defined(AFX_MAP4_H__51AD8E2C_9834_4E38_83D8_C7B9A6F20A14__INCLUDED_)
