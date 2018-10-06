// Map5.h: interface for the CMap5 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAP5_H__22951378_2265_4B32_894E_3977714536F0__INCLUDED_)
#define AFX_MAP5_H__22951378_2265_4B32_894E_3977714536F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyClipLine5.h"

class CMap5  
{
public:
	CMap5();
	virtual ~CMap5();
	CMyClipLine5 clipLine;
	void Draw(CDC *pDC);

};

#endif // !defined(AFX_MAP5_H__22951378_2265_4B32_894E_3977714536F0__INCLUDED_)
