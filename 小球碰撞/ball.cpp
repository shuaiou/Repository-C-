#include "graphics.h"
#include "conio.h"
#include "time.h"

#define n 6      //����С������

void main()
{
	initgraph(480, 480);
	setbkcolor(BLUE);//bk color
	cleardevice();
	int convastx[n], convasty[n], convastvx[n], convastvy[n];  //С�����ٶ�     
	int j,i;
	int a,b;
	srand(time(0));
	for(i=0;i<n;i++)
	{
		convastx[i] = rand() % 400;
		convasty[i] = rand() % 400;
		convastvx[i]=3;   //�ٶ�
		convastvy[i]=3;
	}
	BeginBatchDraw();
	while (1)
	{
		setcolor(GREEN);
		setfillcolor(RED);
		for (i=0; i<n; i++)            //����
		{
			fillcircle(convastx[i], convasty[i],20);
		}
		FlushBatchDraw();              //����
		Sleep(10);
		//setcolor(BLUE);
	//	setfillcolor(BLUE);
		for(i=0;i<n;i++)             
		{
			fillcircle(convastx[i], convasty[i], 20);//���𣨸���ԭ����circle��
			convastx[i] = convastx[i] + convastvx[i];  //�仯Ϊ��һ���ص�
			convasty[i] = convasty[i] + convastvy[i];
			if (convastx[i] > 400 || convastx[i] <20)  //����qiang
			{
				convastvx[i] = -convastvx[i];
			}
			if (convasty[i] > 400 || convasty[i] <20)  //����qiang
			{
				convastvy[i] = -convastvy[i];
			}
			for(j=0;j<n;j++)    //��ײ
			{
				a=(convastx[i]-convastx[j])*(convastx[i]-convastx[j]);
				b=(convasty[i]-convasty[j])*(convasty[i]-convasty[j]);
				if((a+b)<=1600 && i!=j)
				{
					convastvx[i] = -convastvx[i];
					convastvy[i] = -convastvy[i];
					convastvy[j] = -convastvy[j];
					convastvx[j] = -convastvx[j];
				}
			}
		}
	}
	EndBatchDraw();
	closegraph();
}





//((convastx[i]-convastx[j])*(convastx[i]-convastx[j])+(convasty[i]-convasty[j])*(convasty[i]-convasty[j]))==1600
//a=(convastx[i]-convastx[j])*(convastx[i]-convastx[j])
//b=(convasty[i]-convasty[j])*(convasty[i]-convasty[j])