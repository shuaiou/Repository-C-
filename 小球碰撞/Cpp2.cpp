#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void main()
{
//	double a=0,r=100;
//	int i=0,j=0;
//	int b,c,count=1;
//	float  i;
	while(1){
//	scanf("%d%d%d",&a,&b,&c);
	initgraph(640,480);
//	setbkcolor(RGB(200,200,200));//GREEN  eps. 
//	setbkmode(TRANSPARENT);
	cleardevice();


//void outtextxy(200,200,s);
	// 获取默认绘图窗口的 HDC 句柄
/*	HDC hdc = GetImageHDC();
	// 执行 Windows GDI 绘图函数
	MoveToEx(hdc, 20, 10, NULL);
	LineTo(hdc, 200, 200);
	// 使之前的 Windows GDI 绘图生效
	FlushBatchDraw();                        //GetWorkingImage  
	// 创建大小为 200x200 的 img 对象r
	IMAGE img(200, 200);
	setbkcolor(RED);
	cleardevice();
	// 获取该 img 对象的 HDC 句柄
	hdc = GetImageHDC(&img);
	// 执行 Windows GDI 绘图函数
	Ellipse(hdc, 0, 50, 199, 150);
	// 将 img 对象显示到绘图窗口上面
	putimage(100, 0, &img);*/






	int i;
	IMAGE img1, img2;
	loadimage(&img1, _T("E:\\1574696673577.jpg"));
	img2 = img1;
	BeginBatchDraw();
	while(1){
	for(i=1;i<=900;i++)
	{putimage(10,10,700,500,&img2,i,400,0x00EE0086);cleardevice();FlushBatchDraw();} //DWORD dwRop = SRCCOPY  
	for(i=900;i>=0;i--)
	{putimage(10,10,700,500,&img2,i,400,0x00EE0086);cleardevice();FlushBatchDraw();} }EndBatchDraw();
//	IMAGE img;
//	loadimage(&img, _T("IMAGE"), _T("Player"));//
//	putimage(100, 100, &img);    // 在另一个地方再次显示背景
	// 读取图片至绘图窗口
//	loadimage(NULL, "E:\\1574696673577.jpg");
//	loadimage(NULL, _T("E:\\1574697050676.jpg"));

	// 创建 200x200 的 img 对象
/*	IMAGE img(200, 200);    //之定义在正中间
	// 设置绘图目标为 img 对象
	SetWorkingImage(&img);
	// 以下绘图操作都会绘制在 img 对象上面
	line(0, 100, 200, 100);
	line(100, 0, 100, 200);
	circle(100, 100, 50);
	// 设置绘图目标为绘图窗口
	SetWorkingImage();
	// 将 img 对象显示在绘图窗口中
	putimage(220, 140, &img);*/


		// 获取指向显存的指针
/*	DWORD* pMem = GetImageBuffer();
	// 直接对显存赋值
	for(int i = 0; i < 640 * 480; i++)
		pMem[i] = BGR(RGB(0, 0, i * 256 / (640 * 480) ));//pMem[i]huaxian
	// 使显存生效（注：操作指向 IMAGE 的显存不需要这条语句）
	FlushBatchDraw();*/


//	char s[] = "Hello World";
//	outtextxy(10, 20, s);
//	TCHAR s[] = _T("Hello World");
//	outtextxy(10, 20, s);
//	char c = 'A';
//	outtextxy(10, 40, c);
//	char s[5];
//	sprintf(s, "%d", 1024);
//	outtextxy(10, 60, s);

/*	RECT r = {0, 0, 640, 480};
	drawtext(_T("Hello World"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);*/
/*	MOUSEMSG m;
	setlinecolor(RED);
	for(b=20;b<=400;b=b+20)
	{line(b,0,b,400);}
	for(c=20;c<=400;c=c+20)
	{line(0,c,400,c);}
	while(1){
	m=GetMouseMsg();
	setlinecolor(GREEN);
	if(count%2==1)	setfillcolor(RED);
	if(count%2==0)  setfillcolor(BLACK);
	if(m.uMsg==WM_LBUTTONDOWN)
	for(b=20;b<=400;b=b+20)
	{for(c=20;c<=400;c=c+20)
	if((m.x<b+10 && m.x>b-10) && (m.y<c+10 && m.y>c-10))
	{fillcircle(b,c,5);count++;}}
	}*/
	
/*	while(1)
	{	m=GetMouseMsg();
		setlinecolor(RED);
		if(m.uMsg==WM_LBUTTONDOWN)
		circle(m.x,m.y,50);FlushMouseMsgBuffer();}*/

/*		POINT pts[5];
	// 计算五角星的五个顶点坐标
	double a = PI / 2;
	for (int i = 0; i < 5; i++)
	{	pts[i].x = int(320 + cos(a) * 100);
		pts[i].y = int(240 - sin(a) * 100);
		a += PI * 4 / 5;}
	// 设置填充模式为 WINDING (详见 EasyX 帮助手册)
	setpolyfillmode(ALTERNATE);
	// 设置填充颜色为红色
	setfillcolor(RED);
	// 绘制五角星(无边框)
	solidpolygon(pts, 5);*/


//	DWORD a[4] = {50, 20, 30, 10};
//	setlinestyle(PS_DOT, 1, a, 4);
//	setlinestyle(PS_DASHDOTDOT,5,PS_JOIN_ROUND);
//	setlinestyle(PS_USERSTYLE,1,NULL,NULL);
//	setlinestyle(PS_SOLID | PS_JOIN_ROUND | PS_ENDCAP_FLAT,2);
//	line(400,400,500,40);line(400,400,0,0);
//	POINT pts[] = { {50, 50}, {50, 200},{400,400} ,{300, 50} };//点点连线! picture
//	polygon(pts,4);

	
	// 定义填充单元
/*	IMAGE img(10, 8);
	// 绘制填充单元
	SetWorkingImage(&img);	// 设置绘图目标为 img 对象
	setfillcolor(WHITE);	// 白色区域为自定义图案
	solidcircle(1, 1, 8);	//绘制图案
	SetWorkingImage(NULL);	// 恢复绘图目标为默认绘图窗口
	// 设置填充样式为自定义填充图案
	setfillstyle(BS_PATTERN, NULL, &img);
	// 设置自定义图案的填充颜色
	settextcolor(GREEN);
	// 绘制无边框填充三角形
	POINT pts[] = { {50, 50}, {50, 200},{400,400} ,{300, 50} };//点点连线! picture
	solidpolygon(pts, 4);//连几根线（按顺序0 1 2 3......）*/
//	FILLSTYLE(style);
//	setfillstyle(BS_HATCHED,4,NULL);
//	fillcircle(200,200,50);

/*	while(1){
	for(i=1;i>=0;i=i-0.01)
	{setfillcolor(HSLtoRGB(200+i,i,i));
	fillcircle(200,200,50);Sleep(30);}
	i=1;}*/

/*	setfillcolor(RGB(0,200,0));
	fillcircle(200,200,50);
	setfillcolor(BGR(RGB(200,0,0)));
	fillcircle(200,300,50);*/

/*	setfillcolor(RED);
	i=GetRValue(GREEN);
	c=GetBValue(GREEN);
//	b=GetGValue(GREEN);
	b=RGBtoGRAY(LIGHTGRAY);
	if(b>100) b=100;
	fillcircle(i,c,b);*/

//	setlinecolor(RED);
   
	/*while(1)
	for(i=0;i<600;i++){
	setlinecolor(RGB(i/3,i/3,i/3));
//	setlinecolor(rgb(i,i,0));
//	setlinecolor(rgb(i,0,i));
//	setlinecolor(rgb(0,i,i));
//	setlinecolor(rgb(0,0,i));
//	setlinecolor(rgb(0,i,0));
//	setlinecolor(rgb(i,0,0));
	line(200,200,200+100*cos(a),200+100*sin(a));
	a=a+0.01;}*/

/*	while(1)
	{
		Sleep(30);
		a=-1;
		clearcliprgn();
	i=200+r*cos(a);
	j=200+r*sin(a);
		line(200,200,i,j);
		_getch();
	while(a<0)
	{
	i=200+r*cos(a);
	j=200+r*sin(a);
		line(200,200,i,j);
	a=a+0.01;Sleep(0.1);}}*/



//	while(1)
//	{clearcliprgn();line(20,i,400,i);i++;Sleep(20);}
/*	{clearcliprgn();rectangle(10+i,10+j,300,200);i++;j++;
	if(i==400) while(i!=0){clearcliprgn();rectangle(10+i,10+j,300,200);i--;j--;Sleep(10);}}*/
//	setcolor(RED);
//	setlinecolor(RGB(200,10,60));

//	rectangle(10,10,300,200);

/*	line(20,50,200,300);
	line(200,300,380,50);
	moveto(10,10);
	lineto(100,200);
	lineto(200,100);
	lineto(10,10);*/


/*	for(i=0;i<=100;i++)
	{putpixel(100+i,10,RED);}
	for(i=0;i<=100;i++)
	{putpixel(100,10+i,RED);}
	for(i=0;i<=100;i++)
	{putpixel(100+i,110,RED);}
	for(i=0;i<=100;i++)
	{putpixel(200,10+i,RED);}*/

//	arc(10,10,50,20,10,10);*/
//	circle(a,b,c);
//	_getch();	
	//setorigin(100,100);

/*	setfillcolor(RED);
	fillcircle(100,100,20);
	solidcircle(100,120,10);*/


//	getfillcolor(BLUE);	
//	fillcircle(a,b,c);
/*	getch();
	graphdefaults();
	circle(a,b,2*c);
	_getch();
	setaspectratio(0.5,0.5);
	circle(a,b,c);                   //    WinDef.h 
	_getch();*/
/*	getaspectratio(2,2);
    _getch();
	clearcircle(100,100,20);
	_getch();
	cleardevice();
	_getch();*/
/*	clearcircle(a,b,c);*/

	_getch();
	closegraph();
	}
}
/*	HRGN rgn = CreateRectRgn(100, 100,200,200);
	setcliprgn(rgn);
	DeleteObject(rgn);
	setcliprgn(NULL);*/     //**************模板
