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
	// ��ȡĬ�ϻ�ͼ���ڵ� HDC ���
/*	HDC hdc = GetImageHDC();
	// ִ�� Windows GDI ��ͼ����
	MoveToEx(hdc, 20, 10, NULL);
	LineTo(hdc, 200, 200);
	// ʹ֮ǰ�� Windows GDI ��ͼ��Ч
	FlushBatchDraw();                        //GetWorkingImage  
	// ������СΪ 200x200 �� img ����r
	IMAGE img(200, 200);
	setbkcolor(RED);
	cleardevice();
	// ��ȡ�� img ����� HDC ���
	hdc = GetImageHDC(&img);
	// ִ�� Windows GDI ��ͼ����
	Ellipse(hdc, 0, 50, 199, 150);
	// �� img ������ʾ����ͼ��������
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
//	putimage(100, 100, &img);    // ����һ���ط��ٴ���ʾ����
	// ��ȡͼƬ����ͼ����
//	loadimage(NULL, "E:\\1574696673577.jpg");
//	loadimage(NULL, _T("E:\\1574697050676.jpg"));

	// ���� 200x200 �� img ����
/*	IMAGE img(200, 200);    //֮���������м�
	// ���û�ͼĿ��Ϊ img ����
	SetWorkingImage(&img);
	// ���»�ͼ������������� img ��������
	line(0, 100, 200, 100);
	line(100, 0, 100, 200);
	circle(100, 100, 50);
	// ���û�ͼĿ��Ϊ��ͼ����
	SetWorkingImage();
	// �� img ������ʾ�ڻ�ͼ������
	putimage(220, 140, &img);*/


		// ��ȡָ���Դ��ָ��
/*	DWORD* pMem = GetImageBuffer();
	// ֱ�Ӷ��Դ渳ֵ
	for(int i = 0; i < 640 * 480; i++)
		pMem[i] = BGR(RGB(0, 0, i * 256 / (640 * 480) ));//pMem[i]huaxian
	// ʹ�Դ���Ч��ע������ָ�� IMAGE ���Դ治��Ҫ������䣩
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
	// ��������ǵ������������
	double a = PI / 2;
	for (int i = 0; i < 5; i++)
	{	pts[i].x = int(320 + cos(a) * 100);
		pts[i].y = int(240 - sin(a) * 100);
		a += PI * 4 / 5;}
	// �������ģʽΪ WINDING (��� EasyX �����ֲ�)
	setpolyfillmode(ALTERNATE);
	// ���������ɫΪ��ɫ
	setfillcolor(RED);
	// ���������(�ޱ߿�)
	solidpolygon(pts, 5);*/


//	DWORD a[4] = {50, 20, 30, 10};
//	setlinestyle(PS_DOT, 1, a, 4);
//	setlinestyle(PS_DASHDOTDOT,5,PS_JOIN_ROUND);
//	setlinestyle(PS_USERSTYLE,1,NULL,NULL);
//	setlinestyle(PS_SOLID | PS_JOIN_ROUND | PS_ENDCAP_FLAT,2);
//	line(400,400,500,40);line(400,400,0,0);
//	POINT pts[] = { {50, 50}, {50, 200},{400,400} ,{300, 50} };//�������! picture
//	polygon(pts,4);

	
	// ������䵥Ԫ
/*	IMAGE img(10, 8);
	// ������䵥Ԫ
	SetWorkingImage(&img);	// ���û�ͼĿ��Ϊ img ����
	setfillcolor(WHITE);	// ��ɫ����Ϊ�Զ���ͼ��
	solidcircle(1, 1, 8);	//����ͼ��
	SetWorkingImage(NULL);	// �ָ���ͼĿ��ΪĬ�ϻ�ͼ����
	// ���������ʽΪ�Զ������ͼ��
	setfillstyle(BS_PATTERN, NULL, &img);
	// �����Զ���ͼ���������ɫ
	settextcolor(GREEN);
	// �����ޱ߿����������
	POINT pts[] = { {50, 50}, {50, 200},{400,400} ,{300, 50} };//�������! picture
	solidpolygon(pts, 4);//�������ߣ���˳��0 1 2 3......��*/
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
	setcliprgn(NULL);*/     //**************ģ��
