// Map6.h: interface for the CMap6 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAP6_H__146DC3C4_C43C_44D8_9726_28975F44DA35__INCLUDED_)
#define AFX_MAP6_H__146DC3C4_C43C_44D8_9726_28975F44DA35__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "afxtempl.h"
#include "GeoLayer6.h"

class CMap6  
{
public:
	CMap6();
	virtual ~CMap6();
	CRect wcRect;
	CRect clipRect;
	CArray<CGeoLayer6 *,CGeoLayer6 *>geoLayers;
	void Draw(CDC *pDC);
	void addLayer(CGeoLayer6 *layer);
	void clipMap(CRect clipRect1);


};

#endif // !defined(AFX_MAP6_H__146DC3C4_C43C_44D8_9726_28975F44DA35__INCLUDED_)
