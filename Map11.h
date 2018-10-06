#pragma once
#include "afxtempl.h"
#include  <vector>
#include  <algorithm>
#include <string>
#include  "Vector.h"
using namespace std;

class CMap11
{
public:
	CMap11();
	vector <CPoint> pts;//原始点集
	void Draw(CDC *pDC);//绘制结果
	void clockJudge();//得到内点操作
	float xmin, ymin, xmax, ymax;//外接矩形参数
	bool clockWise;//是否为顺时针
	~CMap11();
};

