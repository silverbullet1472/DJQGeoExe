#pragma once
class CSpatialObject12
{
public:
	CSpatialObject12();
	float x, y;
	CString name;
	int id;
	float getDistance(float x,float y);
	void Draw(CDC *pDC);
	~CSpatialObject12();
};

