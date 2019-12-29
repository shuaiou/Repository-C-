#include "chess.h"

int l = 1;
int count = 0;
int b, c;
int a[30][30] = { 0 };

MOUSEMSG m;

void  start_interface()
{
	IMAGE img1;
	loadimage(&img1, _T("E:\\1574696673577.jpg"));
	putimage(0, 0, 400, 400, &img1, 640, 400, 0x00EE0086);
	//	Resize(&img1,400,400);
}


void start_text()
{
	settextcolor(BGR(RGB(100, 0, 100)));
	settextstyle(15, 15, _T("宋体"), 1, NULL, 400, true, true, false);
	outtextxy(0, 250, "START");
	outtextxy(0, 275, "exit ");
}

int start_come()
{
	while (1)
	{
		m = GetMouseMsg();
		if (m.x <= 75 && m.y >= 250 && m.y <= 275 && m.uMsg == WM_LBUTTONDOWN)
			return 1;
		if (m.x <= 75 && m.y >= 275 && m.y <= 290 && m.uMsg == WM_LBUTTONDOWN)
			return 0;
	}
}

void draw_line_color_bk()
{
	//	setbkcolor(RGB(200, 200, 200));
	//	cleardevice();
	loadimage(NULL, _T("E:\\1574697050676.jpg"));
	setlinecolor(RED);
	for (b = 20; b <= 400; b = b + 20)
	{
		line(b, 0, b, 400);
	}
	for (c = 20; c <= 400; c = c + 20)
	{
		line(0, c, 400, c);
	}
}

void judge_color()
{
	if (count % 2 == 0) { setfillcolor(RED); }
	if (count % 2 == 1) { setfillcolor(BLACK); }
}

void ass_pass_col()
{
	if (count % 2 == 0)a[b / 20][c / 20] = 2;
	if (count % 2 == 1)a[b / 20][c / 20] = 1;
	judge_color();
}

void vic_r_b(int i)
{
	settextcolor(RED);
	if (i == 2)
	{
		settextstyle(30, 30, _T("黑体"), 1, NULL, 400, true, true, false);
		outtextxy(65, 185, "red win!!");
	}
	if (i == 1)
	{
		settextstyle(30, 30, _T("黑体"), 1, NULL, 400, true, true, false);
		outtextxy(65, 185, "blk win!!");
	}
}


int vic_o_def()
{
	int i, j;
	for (i = 1; i <= 20; i++)
	{
		for (j = 1; j <= 20; j++)
		{
			if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i + 2][j] == 1 && a[i + 3][j] == 1 && a[i + 4][j] == 1 || a[i][j + 1] == 1 && a[i][j + 2] == 1 && a[i][j] == 1 && a[i][j + 3] == 1 && a[i][j + 4] == 1 || a[i + 1][j + 1] == 1 && a[i + 2][j + 2] == 1 && a[i + 3][j + 3] == 1 && a[i + 4][j + 4] == 1 && a[i][j] == 1 || a[i + 1][j - 1] == 1 && a[i + 2][j - 2] == 1 && a[i + 3][j - 3] == 1 && a[i + 4][j - 4] == 1 && a[i][j] == 1)
			{
				vic_r_b(1); return 0;
			}
			if (a[i][j] == 2 && a[i + 1][j] == 2 && a[i + 2][j] == 2 && a[i + 3][j] == 2 && a[i + 4][j] == 2 || a[i][j + 1] == 2 && a[i][j + 2] == 2 && a[i][j] == 2 && a[i][j + 3] == 2 && a[i][j + 4] == 2 || a[i + 1][j + 1] == 2 && a[i + 2][j + 2] == 2 && a[i + 3][j + 3] == 2 && a[i + 4][j + 4] == 2 && a[i][j] == 2 || a[i + 1][j - 1] == 2 && a[i + 2][j - 2] == 2 && a[i + 3][j - 3] == 2 && a[i + 4][j - 4] == 2 && a[i][j] == 2)
			{
				vic_r_b(2); return 0;
			}
		}
	}
	return 1;
}

void end_text()
{
	settextcolor(BGR(RGB(100, 0, 100)));
	settextstyle(15, 15, _T("宋体"), 1, NULL, 400, true, true, false);
	outtextxy(197, 230, "restart");
	outtextxy(197, 270, "  exit ");
}

void re_zero()
{
	for (b = 1; b <= 20; b++)
		for (c = 1; c <= 20; c++)
			a[b][c] = 0;
	count = 0;
}

int end_re_ex()
{
	while (1)
	{
		m = GetMouseMsg();
		if (m.x <= 302 && m.x >= 197 && m.y >= 230 && m.y <= 245 && m.uMsg == WM_LBUTTONDOWN)
		{
			cleardevice();
			return 1;
		}
		if (m.x <= 302 && m.x >= 197 && m.y >= 270 && m.y <= 285 && m.uMsg == WM_LBUTTONDOWN)
			return 0;
	}
}

void chessing_y_n_undo(long int m, long int n, int r, int mouse, bool ctrl)
{
	IMAGE img1;
	static IMAGE img2;
	static int i, j;
	for (b = 20; b <= 400; b = b + 20)
	{
		for (c = 20; c <= 400; c = c + 20)
		{
			if ((m<b + 10 && m>b - 10) && (n<c + 10 && n>c - 10) && mouse == 0x0201)
			{
				if (a[b / 20][c / 20] != 1 && a[b / 20][c / 20] != 2)
				{
					getimage(&img1, b - 8, c - 8, b + 8, c + 8);
					ass_pass_col();
					fillcircle(b, c, r);
					count++; i = b; j = c;
				}
			}
			if ((m<i + 10 && m>i - 10) && (n<j + 10 && n>j - 10) && mouse == 0x0204 && ctrl == true)
			{
				if (a[i / 20][j / 20] == 1 || a[i / 20][j / 20] == 2)
				{
					clearcircle(i, j, 8);
					putimage(i - 8, j - 8, &img2, 0x00EE0086);
					a[i / 20][j / 20] = 0;
					count--;
				}
			}
		}
	}
	img2 = img1;
}


int exit()
{
	if (m.uMsg == WM_RBUTTONDBLCLK)
		return 0;
	else
		return 1;
}

/**************************

**************************/

void frame()
{
	int i = 1;
	while (i == 1)
	{
		m = GetMouseMsg();
		setlinecolor(GREEN);
		chessing_y_n_undo(m.x, m.y, 8, m.uMsg, m.mkCtrl);
		if (exit() == 0 || vic_o_def() == 0)
			i = 0;
	}
}

void framework_sum()
{
	int i;
	i = start_come();
	while (i)
	{
		draw_line_color_bk();
		frame();
		end_text();
		i = end_re_ex();
		re_zero();
	}
}