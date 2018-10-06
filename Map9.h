#pragma once
#include "afxtempl.h"
#include  <vector>
#include  <algorithm>
#include <string>
using namespace std;

class CMap9
{
public:
	CMap9();
	vector <CPoint> pts;//原始点集
	vector <CPoint> Chpts;//算法中求取的边与直线的交点
	void Draw(CDC *pDC);//绘制结果
	void getPoint();//得到内点操作
	static bool ismax(CPoint A, CPoint B);//排序所需函数
	void getintersectPoint();//得到边与直线交点的函数
	float x0, y0;//内点左边
	float xmin, ymin, xmax,ymax;//外接矩形参数
	~CMap9();
};

