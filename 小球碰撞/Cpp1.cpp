#include <graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include "windows.h"

int main()
{
    initgraph(640, 480);   // ������ͼ���ڣ���СΪ 640x480 ����
    circle(100,100,100); // ��Բ��Բ��(200, 200)���뾶 100            // �����������
  //  closegraph();          // �رջ�ͼ����
	system("pause");
}