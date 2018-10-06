// DJQGeoExeView.cpp : implementation of the CDJQGeoExeView class
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "DJQGeoExe.h"
#include "DJQGeoExeDoc.h"
#include "DJQGeoExeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDJQGeoExeView

IMPLEMENT_DYNCREATE(CDJQGeoExeView, CView)

BEGIN_MESSAGE_MAP(CDJQGeoExeView, CView)
	//{{AFX_MSG_MAP(CDJQGeoExeView)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_COMMAND(ID_Lambert, &CDJQGeoExeView::OnLambert)
	ON_COMMAND(ID_Gauss, &CDJQGeoExeView::OnGauss)
	ON_COMMAND(ID_INDEX, &CDJQGeoExeView::OnIndex)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDJQGeoExeView construction/destruction

CDJQGeoExeView::CDJQGeoExeView()
{
	//需要调用New对象即可
	 Map1 = NULL;
	 Map2 = NULL;
	 Map3 = NULL;
	 this->isPressed = FALSE;
	 Map4 = NULL;
	 Map5 = NULL;
	 Map6 = NULL;
	 Map7 = NULL;
	 Map8 = NULL;
	 mapPrj = NULL;
	 Map9 = NULL;
	 Map10 = NULL;
	 Map11 = NULL;
	 Map12 = NULL;
}


CDJQGeoExeView::~CDJQGeoExeView()
{
	    if( Map1 != NULL)
		delete Map1;
	    if( Map2 != NULL)
		delete Map2;
	    if( Map3 != NULL)
		delete Map3;
		if( Map4 != NULL)
		delete Map4;
		if( Map5 != NULL)
		delete Map5;
		if( Map6 != NULL)
		delete Map6;
		if (Map7 != NULL)
			delete Map7;
		if (Map8 != NULL)
			delete Map8;
		if (mapPrj != NULL)
			delete mapPrj;
		if (Map9 != NULL)
			delete Map9;
		if (Map10 != NULL)
			delete Map10;
		if (Map11 != NULL)
			delete Map11;
		if (Map12 != NULL)
			delete Map12;
}

BOOL CDJQGeoExeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDJQGeoExeView drawing

void CDJQGeoExeView::OnDraw(CDC* pDC)
{
	CDJQGeoExeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	if (Map1 != NULL) 
	Map1->Draw(pDC);
	if (Map2 != NULL) 
	Map2->Draw(pDC);
	if (Map3 != NULL) 
	Map3->Draw(pDC);
//	line.Draw(pDC);
	if (Map4 != NULL) 
	Map4->Draw(pDC);
	if (Map5 != NULL) 
	Map5->Draw(pDC);
	if (Map6 != NULL) 
	Map6->Draw(pDC);
	if (Map7 != NULL)
		Map7->Draw(pDC);
	if (Map8 != NULL)
		Map8->Draw(pDC,mapPrj);
	if (Map9 != NULL)
		Map9->Draw(pDC);
	if (Map10 != NULL)
		Map10->Draw(pDC);
	if (Map11 != NULL)
		Map11->Draw(pDC);
	if (Map12 != NULL)
		Map12->Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CDJQGeoExeView printing

BOOL CDJQGeoExeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDJQGeoExeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDJQGeoExeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDJQGeoExeView diagnostics

#ifdef _DEBUG
void CDJQGeoExeView::AssertValid() const
{
	CView::AssertValid();
}

void CDJQGeoExeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDJQGeoExeDoc* CDJQGeoExeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDJQGeoExeDoc)));
	return (CDJQGeoExeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDJQGeoExeView message handlers

void CDJQGeoExeView::OnFileOpen() 
{
	// TODO: Add your command handler code here

	CFileDialog fDlg(true);//"ture"->对话框为"打开"  "false"->对话框为"保存"
	if(fDlg.DoModal() == IDOK) 
	{
		CString fileName = fDlg.GetPathName();
		if (fileName.Right(22) == "lineGeneratingTest.txt")
		readData1(fileName);
		if (fileName.Right(10) == "cities.txt")
		readData3(fileName);
		if (fileName.Right(15) == "chnFillTest.txt")
		readData4(fileName);
		if (fileName.Right(12) == "clipData.txt")
		readData6(fileName);
		if (fileName.Right(8) == "TUKE.txt")
		readData7(fileName);
		if(fileName.Right(5)=="L.mif")
		readData8(fileName);
		if (fileName.Right(8) == "Map9.txt")
		readData9(fileName);
		if (fileName.Right(5) == "P.MIF")
			readData10(fileName);
		if (fileName.Right(9) == "Map11.txt")
			readData11(fileName);
		if (fileName.Right(9) == "index.txt")//字符读取
			readData12_1(fileName);
		if (fileName.Right(9) == "index.dat")//二进制读取
			readData12_2(fileName);
	}

   else
	{
	     MessageBox("请选择打开文件！");  //弹出消息框
	     return;
	}
	Invalidate(); //激活 并调用ondraw函数开始绘制
}


void CDJQGeoExeView::readData1(CString fileName)
{
	FILE *fp = fopen(fileName,"r+");
	if(fp == NULL)                        //如果源文件不存在了
	{
	     MessageBox("打开文件有误！");
	     return;
	}

	
	if(Map1 != NULL)
	    delete Map1;
	Map1 = new CMap1;

	while (!feof(fp))
	{
		int x1,y1,x2,y2;
		fscanf(fp,"%d %d %d %d",&x1,&y1,&x2,&y2);
		CDDAline1 *line = new CDDAline1;
		line->setCoords(x1,y1,x2,y2);
		Map1->addLine(line);
	}
	fclose(fp); 

}

void CDJQGeoExeView::OnMouseMove(UINT nFlags, CPoint point) 
{
	//if( !this->isPressed)
	//	return;
	//CClientDC dc(this);
	//dc.SetROP2(R2_NOTXORPEN);
	////橡皮条绘制线
	//dc.MoveTo(pt1);
	//dc.LineTo(pt2);
	//pt2= point;
	//dc.MoveTo(pt1);
	//dc.LineTo(pt2);
	////橡皮条绘制矩形
	//CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	//CBrush *oldBrush = dc.SelectObject(brush);
	//CPen pen(2,1,RGB(255,0,0));
	//CPen *oldPen = dc.SelectObject(&pen);
	//dc.Rectangle(pt1.x,pt1.y,pt2.x,pt2.y);
	//pt2 = point;
	//dc.Rectangle(pt1.x,pt1.y,pt2.x,pt2.y);
	//dc.SelectObject(oldBrush);

	//索引查询
	if (Map12 != NULL && Map12->isIndexed)
	{
		CMainFrame *frame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		CString info;
		CPoint pt = point;
		int idxID = -1;
		int idxAreaNum = -1;
		CString objName = "";
		float minDist = 0.0;
		CDC *DC = this->GetDC();
		this->OnPrepareDC(DC);
		DC->DPtoLP(&pt);

		CSpatialIndexArea12 *area = Map12->index.getCurrentIndexArea(pt.x, pt.y);
		CSpatialObject12 obj;

		if (area != NULL)
		{
			idxID = area->id;
			idxAreaNum = area->objIDs.GetSize();
		}
		minDist = Map12->getDistance(pt.x, pt.y, area, obj);
		CSize size(3, 3);
		DC->DPtoLP(&size);
		if (minDist <= size.cx*size.cx) {
			objName = obj.name;
			//m_tool.SetDelayTime(0);
			//m_tool.UpdateTipText(objName, this);
		}
		else;
			//m_tool.SetDelayTime(1);

		info.Format("DC:[x=%d,y=%d]   WC:[x=%d,y=%d]   IndexNo:%d   ObjectNum:%d ObjectName:%s",
			point.x, point.y, pt.x, pt.y, idxID, idxAreaNum, objName);
		frame->SetPaneText(0, info);
		CView::OnMouseMove(nFlags, point);
	}
}

void CDJQGeoExeView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	this->isPressed = FALSE;
	/*橡皮条实现
	CClientDC dc(this);
	CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *oldBrush = dc.SelectObject(brush);
	CPen pen(0,1,RGB(255,0,0));
	CPen *oldPen = dc.SelectObject(&pen);
	pt2 = point;
	dc.Rectangle(pt1.x,pt1.y,pt2.x,pt2.y);
	dc.SelectObject(oldBrush);
	dc.SelectObject(oldPen);
	CView::OnLButtonUp(nFlags, point);*/
	//裁剪实现
/*	Map5->clipLine.setCoords(pt1.x,pt1.y,point.x,point.y);
	Map5->clipLine.clipSutherland();
	Invalidate();
	CView::OnLButtonUp(nFlags, point);*/

}

void CDJQGeoExeView::OnLButtonDown(UINT nFlags, CPoint point) 
{	
	this->isPressed = TRUE;
	pt1 = point;
	pt2 = point;
	CView::OnLButtonDown(nFlags, point);
}

void CDJQGeoExeView::readData3(CString fileName)
{
	FILE *fp = fopen(fileName,"r"); //创建文件指针，并打开对应文件
	if( fp == NULL) //如果文件打开失败，提示信息
	{
		MessageBox("文件打开失败!");
		return;
	}

	if(Map3 != NULL)
	    delete Map3;
	Map3 = new CMap3;

	float lon,lat;
	int id;
	CString name;
	float minx,miny,maxx,maxy;  //数据范围
	int scale = 1000000;   //定义一比例尺，使其保证原始数据精度，同时满足绘制int需要
	minx = miny =  180 * scale;  //经纬度最大值
	maxx = maxy = -180 * scale;   //经纬度最小值

	while( !feof(fp) ) //文件没有结束
	{
		CITY city;
		fscanf(fp,"%d%f%f%s",&id,&lon,&lat,name); //读取数据
		lon = lon * scale;
		lat  =  lat * scale;
		minx = minx > lon? lon: minx;    //获取最小外接矩形
		miny = miny > lat? lat: miny;
		maxx = maxx < lon? lon: maxx;
		maxy = maxy < lat? lat: maxy;
		
		city.id = id;
		city.lat = lat;
		city.lon = lon;
		city.name = name;
		Map3->addCity(city);   //将其加入到数组中
	}
	fclose(fp);    //文件关闭
	Map3->wcRect = CRect(minx,miny,maxx,maxy);  //设置其坐标范围
    

}

void CDJQGeoExeView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	//有数据才加载变换
	/*if(Map3 != NULL)*/
	//if (Map6 != NULL)//以下为Map6设置
	//{
	//	CSize size;
	//	CPoint pt;
	//	CRect rectD;

	//	this->GetClientRect(&rectD);
	//	size.cx = rectD.Width();
	//	size.cy = rectD.Height();
	//	pt = rectD.CenterPoint();

	//	pDC->SetMapMode(MM_ISOTROPIC);
	//	pDC->SetViewportExt(size);
	//	pDC->SetViewportOrg(pt);

	//	size = Map6->wcRect.Size();
	//	size.cx = (int)(size.cx *1.02);
	//	size.cy = -(int)(size.cy * 1.02);	    //Y方向相反，所以前面加 -
	//	pt = Map6->wcRect.CenterPoint();

	//	pDC->SetWindowExt(size);
	//	pDC->SetWindowOrg(pt);
	//}

	//if (Map7 != NULL)
	if (Map8 != NULL)
	{
		if (mapPrj != NULL)
		{
			//由边缘经纬度变换到wcRect
			CSize size;
			//结构SIZE表示一个矩形的长度和宽度，其定义为：typedef struct tagSIZE{LONG cx;LONG cy;} SIZE;
			//其中 cx、cy分别是宽度和高度
			CPoint pt;
			CRect rectD;

			this->GetClientRect(&rectD);//取得客户区矩形区域,当前窗口的左上角x，y为0,右下角为当前窗口的宽度、高度
			size.cx = rectD.Width();
			size.cy = rectD.Height();
			pt = rectD.CenterPoint();//CRect类的CenterPoint()成员函数返回中心点坐标，是CPoint类型的变量
			pDC->SetMapMode(MM_ISOTROPIC);
			//设置映射模式,SetMapMode函数设置指定设备环境的映射方式，映射方式定义了将逻辑单位转换为设备单位的度量单位，
			//并定义了设备的X、Y轴的方向。MM_ANISOTROPIC：逻辑单位转换成具有任意比例轴的任意单位，
			//用SetWindowExtEx和SetViewportExtEx函数可指定单位、方向和比例。
			pDC->SetViewportExt(size);  //SetViewportExt设定视口尺寸
			pDC->SetViewportOrg(pt);//设置窗口中心点为坐标系原点--Viewport使用物理大小  

			//以下计算我们读取的坐标中的对应长、宽，以及需要设置的坐标中心点
			CRect wcRect=mapPrj->wcRect;
			size.cx = wcRect.Width();
			size.cy = -wcRect.Height();
			pt = wcRect.CenterPoint();
			pDC->SetWindowExt(size);
			pDC->SetWindowOrg(pt);
			
		}
		else
		{
			CSize size;
			CPoint pt;
			CRect rectD;

			this->GetClientRect(&rectD);
			size.cx = rectD.Width();
			size.cy = rectD.Height();
			pt = rectD.CenterPoint();

			pDC->SetMapMode(MM_ISOTROPIC);
			pDC->SetViewportExt(size); 
			pDC->SetViewportOrg(pt);

			rectD = CRect(Map8->L0, Map8->B0, Map8->L1, Map8->B1);
			size.cx = rectD.Width();
			size.cy = -rectD.Height();
			pt = rectD.CenterPoint();
			pDC->SetWindowExt(size);
			pDC->SetWindowOrg(pt);
		}
	}
	if (Map12 != NULL)
	{
				CSize size;
				CPoint pt;
				CRect rectD;

				this->GetClientRect(&rectD);
				size.cx = rectD.Width();
				size.cy = rectD.Height();
				pt = rectD.CenterPoint();

				pDC->SetMapMode(MM_ISOTROPIC);
				pDC->SetViewportExt(size);  
				pDC->SetViewportOrg(pt); 
				
				rectD = Map12->mapRect;
				size.cx = rectD.Width()*1.2;
				size.cy = -rectD.Height()*1.2;
				pt = rectD.CenterPoint();
				pDC->SetWindowExt(size);
				pDC->SetWindowOrg(pt);
	}
	CView::OnPrepareDC(pDC, pInfo);
}

void CDJQGeoExeView::readData4(CString fileName)
{
	FILE *fp = fopen(fileName,"r"); //创建文件指针，并打开对应文件
	if( fp == NULL) //如果文件打开失败，提示信息
	{
		MessageBox("文件打开失败!");
		return;
	}

	
	if(Map4 != NULL)
	    delete Map4;
	Map4 = new CMap4;

	int i,j,partNum,ptNum;
	int color,x,y;
	while( !feof(fp)) //判断是否结束
	{
		fscanf(fp,"%d",&partNum); //段数
		CMyPolygon4 *plgon = new CMyPolygon4;
		Map4->polygons.Add(plgon);

		for(i=0;i<partNum;i++)
		{
			fscanf(fp,"%d",&ptNum); //点数
			for(j=0;j<ptNum;j++)
			{
				fscanf(fp,"%d%d",&x,&y); //坐标,  只保留第一个多边形，其余跳过
			    if(i==0)
					plgon->AddPoint(CPoint(x,y));				
			}
		}
		fscanf(fp,"%d%d",&x,&y); //内部点坐标
		fscanf(fp,"%d",&color); //内部点坐标
		plgon->SetCenterPt(CPoint(x,y));
		plgon->color=color;		
	}
	fclose(fp);
}



void CDJQGeoExeView::readData6(CString fileName)
{
	FILE *fp = fopen(fileName,"r+");
	if(fp == NULL)                        //如果源文件不存在了
	{
	     MessageBox("打开文件有误！");
	     return;
	}

	if(Map6 != NULL)
	    delete Map6;
	Map6 = new CMap6;                

    int x1,y1,x2,y2;
	fscanf(fp,"%d %d",&x1,&y1);
	fscanf(fp,"%d %d",&x2,&y2);
	Map6->wcRect = CRect(x1,y1,x2,y2);
	x1=int(x1*0.5);	y1=int(y1*0.5);	x2=int(x2*0.5);	y2=int(y2*0.5);
	Map6->clipRect = CRect(x1,y1,x2,y2);
	CGeoLayer6 *layer = new CGeoLayer6;

    while (!feof(fp))                     //没到文件末尾之前
	{		
		int PointNum,i;
	    fscanf(fp,"%d",&PointNum);
		CGeoPolyline6 *line = new CGeoPolyline6;
		for(i=0;i<PointNum;i++)
		{
		 int x,y;
		 fscanf(fp,"%d %d",&x,&y);
		 CPoint pt(x,y);
		 line->addPoint(pt);
		}
		layer->addPolyline(line);
	}
	Map6->addLayer(layer);
	fclose(fp);	
}

void CDJQGeoExeView::readData7(CString fileName)
{
	FILE *fp = fopen(fileName, "r+");
	if (fp == NULL)                        //如果源文件不存在了
	{
		MessageBox("打开文件有误！");
		return;
	}	
	Map7 = new CMap7;

	float x1, y1;
	point7 temp;
	while (!feof(fp))                     //没到文件末尾之前
	{
		fscanf(fp, "%f %f", &x1, &y1);
		temp.x = x1;
		temp.y = y1;
		temp.angle = 0;
		Map7->convexHull.pts.push_back(temp);
	}
	Map7->convexHull.Chpts = Map7->convexHull.pts;//将原始数据存入处理容器
	Map7->convexHull.getConvexHull1();            //处理得到凸壳点
	Map7->convexHull.getcrWCRect();               //获取外接矩形
	fclose(fp);
}

void CDJQGeoExeView::readData8(CString fileName)
{
	FILE *fp = fopen(fileName, "r+");
	if (fp == NULL)                        //如果源文件不存在了
	{
		MessageBox("打开文件有误！");
		return;
	}

	if (Map8 != NULL)
		delete Map8;
	Map8 = new CMap8;
	Map8->mapScale = 10000000;

	CGeoLayer8 *layer = new CGeoLayer8;
	while (!feof(fp))
	{
		CString s;
		fscanf(fp, "%s", s);

		if (s == "Bounds")
		{
			float x1, y1, x2, y2;
			fscanf(fp, " (%f, %f) (%f, %f)",&x1,&y1,&x2,&y2);
			Map8->L0 = x1*(Map8->mapScale);
			Map8->B0 = y1*(Map8->mapScale);
			Map8->L1 = x2*(Map8->mapScale);
			Map8->B1 = y2*(Map8->mapScale);
		}

		if (s == "Pline")
		{
			int a;
			float l, b;
			CGeoObject8 *obj = new CGeoObject8;
			fscanf(fp, "%d", &a);
			for (int i = 0; i < a; i++)
			{
				fscanf(fp, "%f %f", &l, &b);
				CGeoPoint8 *pt = new CGeoPoint8;
				pt->setPoint((Map8->mapScale)*l, (Map8->mapScale)*b);//乘以倍数存储
				obj->addPoint(pt);
			}
			fscanf(fp, "%*[^\n]");
			layer->addObjects(obj);
		}
	}
	Map8->addLayers(layer);
	//暂时不设置投影
	fclose(fp);
}

void CDJQGeoExeView::readData9(CString fileName)
{
	FILE *fp = fopen(fileName, "r+");
	if (fp == NULL)                        //如果源文件不存在了
	{
		MessageBox("打开文件有误！");
		return;
	}
	Map9 = new CMap9;

	float x1, y1;
	CPoint temp;
	fscanf(fp, "%f %f", &x1, &y1);
	Map9->xmax = x1;
	Map9->ymax = y1;
	Map9->xmin = x1;
	Map9->ymin = y1;
	temp.x = x1;
	temp.y = y1;
	Map9->pts.push_back(temp);
	while (!feof(fp))                     //没到文件末尾之前
	{
		fscanf(fp, "%f %f", &x1, &y1);
		temp.x = x1;
		temp.y = y1;
		Map9->pts.push_back(temp);
		if (temp.x > Map9->xmax)
		{
			Map9->xmax = temp.x;
		}
		if (temp.y > Map9->ymax)
		{
			Map9->ymax = temp.y;
		}
		if (temp.x < Map9->xmin)
		{
			Map9->xmin = temp.x;
		}
		if (temp.y < Map9->ymin)
		{
			Map9->ymin = temp.y;
		}
	}
	fclose(fp);
}

void CDJQGeoExeView::readData10(CString fileName)
{
	FILE *fp = fopen(fileName, "r+");
	if (fp == NULL)                        //如果源文件不存在了
	{
		MessageBox("打开文件有误！");
		return;
	}

	if (Map10 != NULL)
		delete Map10;
	Map10 = new CMap10;
	Map10->mapScale = 10000000;
	CGeoLayer10 *layer = new CGeoLayer10;
	while (!feof(fp))
	{
		CString s;
		fscanf(fp, "%s", s);

		if (s == "Bounds")
		{
			float x1, y1, x2, y2;
			fscanf(fp, " (%f, %f) (%f, %f)", &x1, &y1, &x2, &y2);
			Map10->L0 = x1*(Map10->mapScale);
			Map10->B0 = y1*(Map10->mapScale);
			Map10->L1 = x2*(Map10->mapScale);
			Map10->B1 = y2*(Map10->mapScale);
			Map10->wcRect = CRect(Map10->L0, Map10->B0, Map10->L1, Map10->B1);
		}

		if (s == "Region")
		{
			CGeoPolygon10 *polygon = new CGeoPolygon10;	
			int t=0;
			int b; 
			fscanf(fp, "%d", &b);
			for (int j = 0; j < b; j++)
			{		
				int a;
				fscanf(fp, "%d", &a);
				polygon->addSeg(a);
				float minx = INT_MAX;
				float miny = INT_MAX;
				float maxx = INT_MIN;
				float maxy = INT_MIN;
				for (int i = 0; i < a; i++)
				{
					float x1, y1;
					fscanf(fp, "%f %f", &x1, &y1);
					x1 *= Map10->mapScale;
					y1 *= Map10->mapScale;
					CPoint pt(x1, y1);
					polygon->addPoint(pt);
					if (j == 0) 
					{
						minx = minx < x1 ? minx : x1;
						miny = miny < y1 ? miny : y1;
						maxx = maxx > x1 ? maxx : x1;
						maxy = maxy > y1 ? maxy : y1;
						t++;
					}
				}
				if (j == 0) 
				{
					polygon->minx = minx;
					polygon->miny = miny;
					polygon->maxx = maxx;
					polygon->maxy = maxy;
					polygon->getCenterPt();
				}
				//if (t >= 40) //对边界点数较多的面才进行处理，避免一些特殊面的影响
				//{
				//	layer->addObject(polygon);
				//}
			}
			fscanf(fp, "%s", s);    //读取文件中自带的内部点坐标
			fscanf(fp, "%s", s);
			fscanf(fp, "%s", s);
			fscanf(fp, "%s", s);
			fscanf(fp, "%s", s);
			if (s == "Center")
			{
				float x2, y2;
				fscanf(fp, " %f %f", &x2, &y2);
				x2 *= Map10->mapScale; y2 *= Map10->mapScale;
				polygon->pt = CPoint(x2, y2);
			}
			layer->addObject(polygon);
			
		}
	}
	Map10->addLayer(layer);
	//暂时不设置投影
	fclose(fp);
}

void CDJQGeoExeView::readData11(CString fileName)
{
	FILE *fp = fopen(fileName, "r+");
	if (fp == NULL)                        //如果源文件不存在了
	{
		MessageBox("打开文件有误！");
		return;
	}
	Map11 = new CMap11;

	float x1, y1;
	CPoint temp;
	Map11->xmax = INT_MIN;
	Map11->ymax = INT_MIN;
	Map11->xmin = INT_MAX;
	Map11->ymin = INT_MAX;
	while (!feof(fp))                     //没到文件末尾之前
	{
		fscanf(fp, "%f %f", &x1, &y1);
		temp.x = x1;
		temp.y = y1;
		Map11->pts.push_back(temp);
		if (temp.x > Map11->xmax)
		{
			Map11->xmax = temp.x;
		}
		if (temp.y > Map11->ymax)
		{
			Map11->ymax = temp.y;
		}
		if (temp.x < Map11->xmin)
		{
			Map11->xmin = temp.x;
		}
		if (temp.y < Map11->ymin)
		{
			Map11->ymin = temp.y;
		}
	}
	fclose(fp);
}

void CDJQGeoExeView::readData12_1(CString fileName)
{
	FILE *fp = fopen(fileName, "r+");
	if (fp == NULL)                        //如果源文件不存在了
	{
		MessageBox("打开文件有误！");
		return;
	}
	Map12 = new CMap12;
	int mapScale = 20;

	while (!feof(fp))                     //没到文件末尾之前
	{
		int id1;
		float x0, y0;
		CSpatialObject12 *temp = new CSpatialObject12();
		CString s1;
		fscanf(fp, "%d %f %f %s", &id1, &x0, &y0,s1);
		temp->id = id1;
		temp->x = x0*mapScale;
		temp->y = y0*mapScale;
		temp->name.Format("%s",s1);	
		Map12->addObject(temp);
	}
	Map12->getMinMax();
	fclose(fp);
}

void CDJQGeoExeView::readData12_2(CString fileName)
{
	FILE *fp = fopen(fileName, "rb");
	if (fp == NULL)                        //如果源文件不存在了
	{
		MessageBox("打开文件有误！");
		return;
	}
	Map12 = new CMap12;
	int mapScale = 20;
	int id;
	float x, y;
	short len;
	char name1[80];

	while (fread(&id, sizeof(int), 1, fp) == 1)                    //没到文件末尾之前
	{
		CSpatialObject12 *temp = new CSpatialObject12();
		fread(&x, sizeof(float), 1, fp);
		fread(&y, sizeof(float), 1, fp);
		fread(&len, sizeof(short), 1, fp);
		fread(name1, sizeof(char), len, fp);
		name1[len] = '\0';

		temp->id = id;
		temp->x = x*mapScale;
		temp->y = y*mapScale;
		temp->name.Format("%s", name1);
		Map12->addObject(temp);
	}
	Map12->getMinMax();
	fclose(fp);

}


void CDJQGeoExeView::OnLambert()
{
	if (Map8 != NULL)
	{
		mapPrj = new CMapProjectionLambert8(Map8->L0, Map8->B0, Map8->L1, Map8->B1);
		Invalidate();
	}
}



void CDJQGeoExeView::OnGauss()
{
	if (Map8 != NULL)
	{
		mapPrj = new CMapProjectionGauss8(Map8->L0, Map8->B0, Map8->L1, Map8->B1);
		Invalidate();
	}
}


void CDJQGeoExeView::OnIndex()
{
	if (Map12 != NULL)
	{
		Map12->buildIndex();
		Invalidate();
	}
}
