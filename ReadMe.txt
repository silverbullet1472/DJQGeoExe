========================================================================
                              _ooOoo_
                             o8888888o
                             88" . "88
                             (| -_- |)
                              O\ = /O
                          ____/`---'\____
                          .   ' \\| |// `.
                         / \\||| : |||// \
                       / _||||| -:- |||||- \
                         | | \\\ - /// | |
                       | \_| ''\---/'' | |
                        \ .-\__ `-` ___/-. /
                     ___`. .' /--.--\ `. . __
                  ."" '< `.___\_<|>_/___.' >'"".
                 | | : `- \`.;`\ _ /`;.`/ - ` : | |
                   \ \ `-. \_ __\ /__ _/ .-` / /
           ======`-.____`-.___\_____/___.-`____.-'======
                              `=---='
========================================================================

CMap1:直线生成
	下含CDDAline1类，实现DDA算法画直线,读取LINEGENERATINGTEST（READDATA1）

CMap2:直线及字体生成
	下含CMyline2类，实现直线及字体绘制，种子填充法

CMap3:橡皮条绘制
	1.橡皮条绘制（VIEW中鼠标动作设置）
	2.下含CITY3结构体，读取CITIES3数据（点状）（READDATA3）
	3.图形缩放（ONPREPAREDC）

CMap4:区域填充
	1.下含CMyPolygon4类
	2.读取CHNFILLTEST(READDATA4)，实现省级区划读取并填充

CMap5:橡皮条裁剪
	1.下含CMyClipLine5类
	2.VIEW中鼠标事件绘制橡皮条，并利用CMyClipLine5检测裁剪后激活绘制红线

CMap6:区域裁剪
	1.下含CGeoMap6、CGeoLayer6、CGeoPolyline6类
	2.读取clipdata(readdata6)，实现区域裁剪

CMap7:凸壳生成
	1.下含CConvexHull7类,point7结构体
	2.读取TUKE(readdata7)，在读取过程后存入数据、完成处理
	3.数据处理过程中使用了：
		vector容器、goto语句
	4.另外引入了CVector类，处理有关向量的计算，但实际算法并未使用

CMap8:地图投影
	1.下含CGeoLayer8，CGeoPoint8，CGeoObject8，CMapProjection8类，
	CMapProjection8派生CMapProjectionLambert8等类
	2.读文件函数readdata8.

CMap9:多边形内点生成
	1.readdata9读取多边形顶点
	2.getPoint函数获取内点

CMap10:生成内点并填充
	1.下含CGeoLayer10，CGeoObject10（虚基类），CGeoPolygon10，CGeoPolyline10类
	2.readdata10读取面状信息
	3.getCenterPoint函数获取内点
	4.使用FloodFill函数填充

CMap11:多边形顺逆时针判断
	1.下含CGeoMap11类
	2.readdata11读取坐标信息
	3.clockJudge函数判断是否为顺时针

CMap12:空间索引
	1.下含CGeoMap12、CSpatialIndex、CSpatialIndexArea类
	2.readdata12读取坐标信息（1为读取文本文件、2为读取二进制文件）
	3.点击空间索引toolbar调用OnIndex生成索引
/////////////////////////////////////////////////////////////////////////////
