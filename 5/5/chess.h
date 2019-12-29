#include <graphics.h>
#include <conio.h>
#include <stdio.h>


void start_interface();  //开始界面
void start_text();    //开始文字
int start_come();		//入口
void draw_line_color_bk();              //背景图AND画线AND线颜色
void judge_color();					//棋子颜色
void ass_pass_col();               //值传递AND棋子颜色
void vic_r_b(int i);                //   判断胜利方
int vic_o_def();                      // 判断胜利
void end_text();					// 结束文字
void re_zero();						//初始化
int end_re_ex();			//继续OR退出
void chessing_y_n_undo(long int m, long int n, int r, int mouse, bool ctrl);//下棋OR悔棋
int exit();              //退出（CTRL&左击）
void frame();                      //初始框架
void framework_sum();             //再度框架

