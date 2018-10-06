// Map3.h: interface for the CMap3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAP3_H__CE6915EB_560B_4EC1_A681_17993040B3F0__INCLUDED_)
#define AFX_MAP3_H__CE6915EB_560B_4EC1_A681_17993040B3F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "afxtempl.h"

struct city_Struct3
{
	int id;
	float lon;
	float lat;
	CString name;
};

typedef struct city_Struct3 CITY;

class CMap3  
{
public:
	CArray<CITY,CITY>cities;
	CRect wcRect;
	void Draw(CDC *pDC);
	void addCity(CITY city);
	CMap3();
	virtual ~CMap3();

};

#endif // !defined(AFX_MAP3_H__CE6915EB_560B_4EC1_A681_17993040B3F0__INCLUDED_)
