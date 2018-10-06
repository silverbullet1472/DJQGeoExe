// Map1.h: interface for the CMap1 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAP1_H__1A1DD7ED_FB7E_4933_BBB5_237ADDA8ED4B__INCLUDED_)
#define AFX_MAP1_H__1A1DD7ED_FB7E_4933_BBB5_237ADDA8ED4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "afxtempl.h" 
#include "DDAline1.h" 

class CMap1  
{
public:
	CMap1();
	virtual ~CMap1();
	CArray<CDDAline1*,CDDAline1*> lines;
	void Draw(CDC *pDC);
	void addLine(CDDAline1 *line);


};

#endif // !defined(AFX_MAP1_H__1A1DD7ED_FB7E_4933_BBB5_237ADDA8ED4B__INCLUDED_)
