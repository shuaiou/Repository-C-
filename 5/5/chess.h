#include <graphics.h>
#include <conio.h>
#include <stdio.h>


void start_interface();  //��ʼ����
void start_text();    //��ʼ����
int start_come();		//���
void draw_line_color_bk();              //����ͼAND����AND����ɫ
void judge_color();					//������ɫ
void ass_pass_col();               //ֵ����AND������ɫ
void vic_r_b(int i);                //   �ж�ʤ����
int vic_o_def();                      // �ж�ʤ��
void end_text();					// ��������
void re_zero();						//��ʼ��
int end_re_ex();			//����OR�˳�
void chessing_y_n_undo(long int m, long int n, int r, int mouse, bool ctrl);//����OR����
int exit();              //�˳���CTRL&�����
void frame();                      //��ʼ���
void framework_sum();             //�ٶȿ��

