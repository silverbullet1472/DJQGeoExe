#include "stdafx.h"
#include "MapProjectionGauss8.h"
#include "MapProjection8.h"

#define ZONEWIDE 6

CMapProjectionGauss8::~CMapProjectionGauss8()
{
}

CMapProjectionGauss8::CMapProjectionGauss8(float L0, float B0, float L1, float B1)
{
	showMapScale = 1;
	mapScale = 10000000;
	a = 6378140.0;
	f = 1 / 298.257; //80年西安坐标系参数 

					 /*
					 a = 6378137.0
					 f =1/298.257222101	 //2000坐标系
					 */

					 //ProjNo = (int)(longitude / ZONEWIDE) ; //所属高斯投影带
					 //long0 = ProjNo * ZONEWIDE + ZONEWIDE / 2; //该带的中心经线，y坐标轴
					 //long0 = long0 * IPI ;//换算成弧度
	lat0 = 0; //赤道，x坐标轴
	long0 = 105.0*IPI;   //基本位于中国中央

	e2 = 2 * f - f*f;
	ee = e2*(1.0 - e2);

	e61 = 1 - e2 / 4 - 3 * e2*e2 / 64 - 5 * e2*e2*e2 / 256;
	e62 = 3 * e2 / 8 + 3 * e2*e2 / 32;
	e63 = 45 * e2*e2*e2 / 1024;
	e64 = 15 * e2*e2 / 256 + 45 * e2*e2*e2 / 1024;
	e65 = 35 * e2*e2*e2 / 3072;

	//X0 = 1000000L*(ProjNo+1)+500000L; //计算带号，并且添加西移的500公里值
	//Y0 = 0; 
	this->L0 = L0; this->B0 = B0; this->L1 = L1; this->B1 = B1;
	float x0;
	float y0;
	float x1;
	float y1;
	getXY(L0, B0, &x0, &y0);
	getXY(L1, B1, &x1, &y1);
	this->wcRect = CRect(x0, y0, x1, y1);//参数为int
}


void CMapProjectionGauss8::getXY(float lamda, float fai, float *x, float *y)
{
	lamda = lamda / 10000000.0;
	fai = fai / 10000000.0;
	float long1 = lamda * IPI; //经度转换为弧度
	float lat1 = fai * IPI; //纬度转换为弧度

	float NN = a / sqrt(1.0 - e2*sin(lat1)*sin(lat1));
	float T = tan(lat1)*tan(lat1);
	float C = ee*cos(lat1)*cos(lat1);
	float A = (long1 - long0)*cos(lat1);
	float M = a*(e61*lat1 - (e62 + e63)*sin(2 * lat1) + e64*sin(4 * lat1) - e65*sin(6 * lat1));
	*x = NN*(A + (1 - T + C)*A*A*A / 6 + (5 - 18 * T + T*T + 72 * C - 58 * ee)*A*A*A*A*A / 120);
	*y = M + NN*tan(lat1)*(A*A / 2 + (5 - T + 9 * C + 4 * C*C)*A*A*A*A / 24 + (61 - 58 * T + T*T + 600 * C - 330 * ee)*A*A*A*A*A*A / 720);
}

void CMapProjectionGauss8::Draw(CDC *pDC, CRect wcRect)
{
	float xExtends = float(wcRect.Width()) / mapScale;
	float yExtends = float(wcRect.Height()) / mapScale;

	//经纬度以5度划分，绘制经纬网
	int degree = 5;
	int m = xExtends / degree;
	int n = yExtends / degree;

	int i, j;
	int left = wcRect.left;
	int right = wcRect.right;
	int top = wcRect.top;
	int bottom = wcRect.bottom;
	float x1, y1, x2, y2;
	CPoint pt1, pt2;

	int xStart = left / mapScale / degree;
	//int yStart
	CString infoStr;
	for (i = 0; i<m + 2; i++)
	{//绘制经线
		for (j = 0; j<yExtends + 1; j++)
		{
			x1 = (xStart + i)*degree;
			y1 = bottom / mapScale - j;
			if (x1<left / mapScale) x1 = left / mapScale;
			if (x1>right / mapScale) x1 = right / mapScale;

			getXY(x1, y1, &x2, &y2);
			pt1.x = x2*showMapScale;
			pt1.y = y2*showMapScale;
			if (j == 0)
				pDC->MoveTo(pt1);
			else
				pDC->LineTo(pt1);

		}
		infoStr.Format("%d", int(x1));
		pDC->TextOut(pt1.x, pt1.y, infoStr);
	}

	int yStart = top / mapScale / degree;
	//int yStart
	for (i = 0; i<n + 2; i++)
	{//绘制纬线
		for (j = 0; j<xExtends + 1; j++)
		{
			x1 = left / mapScale + j;
			y1 = (yStart + i)*degree;
			if (y1<top / mapScale) y1 = top / mapScale;
			if (y1>bottom / mapScale) y1 = bottom / mapScale;
			getXY(x1, y1, &x2, &y2);
			pt1.x = x2*showMapScale;
			pt1.y = y2*showMapScale;
			if (j == 0)
				pDC->MoveTo(pt1);
			else
				pDC->LineTo(pt1);
		}
		if (i == 0) continue;
		infoStr.Format("%d", int(y1));
		pDC->TextOut(pt1.x, pt1.y, infoStr);
	}
}

void CMapProjectionGauss8::getLonLat(float x, float y, float *lon, float *lat)
{

	int ProjNo;
	double longitude1, latitude1, longitude0, latitude0, X0, Y0, xval, yval;
	double e1, e2, f, a, ee, NN, T, C, M, D, R, u, fai;

	//a = 6378245.0; f = 1.0/298.3; //54年北京坐标系参数 
	a = 6378140.0; f = 1 / 298.257; //80年西安坐标系参数 

	ProjNo = (int)(x / 1000000L); //查找带号
	longitude0 = (ProjNo - 1) * ZONEWIDE + ZONEWIDE / 2;
	longitude0 = longitude0 * IPI; //中央经线
	X0 = ProjNo * 1000000L + 500000L;
	Y0 = 0;
	xval = x - X0; yval = y - Y0; //带内大地坐标
	e2 = 2 * f - f*f;
	e1 = (1.0 - sqrt(1 - e2)) / (1.0 + sqrt(1 - e2));
	ee = e2 / (1 - e2);
	M = yval;
	u = M / (a*(1 - e2 / 4 - 3 * e2*e2 / 64 - 5 * e2*e2*e2 / 256));
	fai = u + (3 * e1 / 2 - 27 * e1*e1*e1 / 32)*sin(2 * u) + (21 * e1*e1 / 16 - 55 * e1*e1*e1*e1 / 32)*sin(
		4 * u)
		+ (151 * e1*e1*e1 / 96)*sin(6 * u) + (1097 * e1*e1*e1*e1 / 512)*sin(8 * u);
	C = ee*cos(fai)*cos(fai);
	T = tan(fai)*tan(fai);
	NN = a / sqrt(1.0 - e2*sin(fai)*sin(fai));
	R = a*(1 - e2) / sqrt((1 - e2*sin(fai)*sin(fai))*(1 - e2*sin(fai)*sin(fai))*(1 - e2*sin
	(fai)*sin(fai)));
	D = xval / NN;
	//计算经度(Longitude) 纬度(Latitude)
	longitude1 = longitude0 + (D - (1 + 2 * T + C)*D*D*D / 6 + (5 - 2 * C + 28 * T - 3 * C*C + 8 * ee + 24 * T*T)*D
		*D*D*D*D / 120) / cos(fai);
	latitude1 = fai - (NN*tan(fai) / R)*(D*D / 2 - (5 + 3 * T + 10 * C - 4 * C*C - 9 * ee)*D*D*D*D / 24
		+ (61 + 90 * T + 298 * C + 45 * T*T - 256 * ee - 3 * C*C)*D*D*D*D*D*D / 720);
	//转换为度 DD
	*lon = longitude1 / IPI;
	*lat = latitude1 / IPI;
}