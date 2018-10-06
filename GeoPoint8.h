#pragma once
class CGeoPoint8
{
public:
	CGeoPoint8();
	float L, B;
	void  setPoint(float L, float B);
	void  getPoint(float *L, float *B);
	~CGeoPoint8();
};

