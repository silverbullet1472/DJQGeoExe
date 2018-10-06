// GeoLayer.h: interface for the CGeoLayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOLAYER_H__80D754D2_4249_40AA_A95A_9CD6B2351320__INCLUDED_)
#define AFX_GEOLAYER_H__80D754D2_4249_40AA_A95A_9CD6B2351320__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "afxtempl.h"
#include "GeoPolyline6.h"

class CGeoLayer6  
{
public:
	CGeoLayer6();
	virtual ~CGeoLayer6();
	CArray<CGeoPolyline6* , CGeoPolyline6 *> geoPolylines;
	void Draw(CDC *pDC);
	void addPolyline(CGeoPolyline6 *line);
	void clipLayer(CRect clipRect1);


};

#endif // !defined(AFX_GEOLAYER_H__80D754D2_4249_40AA_A95A_9CD6B2351320__INCLUDED_)
