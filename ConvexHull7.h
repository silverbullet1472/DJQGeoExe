#include  "afxtempl.h"
#include  <vector>
#include  <algorithm>
#include  <math.h>
#include <string>
using namespace std;

#pragma once
struct point7
{
	float x;
	float y;
	float angle;
};

class CConvexHull7
{
public:
	CConvexHull7();
	CRect crWCRect;

	void getConvexHull1();
	void sort1();
	bool different(point7 A, point7 B, point7 C, point7 D);
	float my_angle(point7 A, point7 B);
	static bool ismin(point7 A, point7 B);
	static bool isAngle(point7 A, point7 B);
	vector <point7> pts;
	vector <point7> Chpts;

	void getcrWCRect();
	void Draw(CDC *pDC);
	~CConvexHull7();

	int j;
};

