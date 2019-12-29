#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include "windows.h"

int main()
{
    initgraph(640, 480);   // 创建绘图窗口，大小为 640x480 像素
    circle(100,100,100); // 画圆，圆心(200, 200)，半径 100            // 按任意键继续
  //  closegraph();          // 关闭绘图窗口
	system("pause");
}