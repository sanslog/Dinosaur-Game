#include "GameLogic.h"
#include "GameData.h"
#include "GameInit.h"
#include "GameRender.h"
#include "GameInput.h"
#include "GameSkill.h"
#include <windows.h>
#include <tchar.h>
#include <graphics.h>
#include<conio.h>

// ������Ϸ�и������λ�úͶ���֡
void change_location()
{
    dino_vy = dino_vy + gravity; // ������ֱ�ٶ�������Ӱ��
    dino_Topy = dino_Topy + dino_vy; // ������ֱλ�ø���
    dino_Lfetx = dino_Lfetx + dino_vx; // ����ˮƽλ�ø���
    rec1_Leftx = rec1_Leftx + rec1_vx; // �ϰ���1λ�ø���
    rec2_Leftx = rec2_Leftx + rec2_vx; // �ϰ���2λ�ø���
    cloud_x -= 0.5; // ��1�ƶ�
    cloud_x2 -= 0.5; // ��2�ƶ�
    ani = (ani + 1) % 9; // ����֡�л�
}

// �ϰ�����Ƶ�ѭ�������߼�
void recircle()
{
    if (rec1_Leftx <= 0) {
        rec1_flag++;
        rec1_Leftx = width / 4;
        if (rec2_Leftx + rec1_width >= width / 4) rec1_Leftx = rec2_Leftx + rand_range(2, 4) * 50;
        score++;
        if (score >= 10)
            rec1_vx -= 0.1, rec2_vx -= 0.1; // �Ѷ�����
    }
    else if (rec2_Leftx <= 0)
    {
        rec2_flag++;
        rec_distance = randwid[rand() % 5];
        if (rec1_flag > rec2_flag) rec_distance = width / 4 - rec1_Leftx;
        rec2_Leftx = width / 4 + rec_distance + randwid[rand() % 5];
        score++;
    }
    if (cloud_x <= 0)   cloud_x = width / 4 + 27; // ��1����
    if (cloud_x2 <= 0)  cloud_x2 = width / 4 + 63; // ��2����
}

// �����������߼�
void ground_dino()
{
    if (dino_Topy >= bottom - dino_height) {
        dino_vy = 0;
        dino_Topy = bottom - dino_height;
        ground_flag = 1;
        skill1_flag = 1;
        if (score >= tmpscore2)
            ground_flag = 2; // �ﵽ������ɶ���һ��
    }
    else {
        ani = 3; // ���ж���
    }
}

// ���������ϰ����߽����ײ
bool dino_collision()
{
    if ((rec1_Leftx < dino_Lfetx + dino_width && rec1_Topy + 1 < dino_Topy + dino_height && dino_Lfetx < rec1_Leftx + rec1_width) ||
        ((rec2_Leftx < dino_Lfetx + dino_width && rec2_Topy + 1 < dino_Topy + dino_height && dino_Lfetx < rec2_Leftx + rec2_width)) ||
        (dino_Lfetx <= 0 || dino_Lfetx + dino_width >= width / 4))
        return 1;
    return 0;
}

// ��ʽ��Ϸ��ѭ��
void Startgame()
{
    Init();
    while (1) {
        input_game(); // ��������
        change_location(); // ����λ��
        ground_dino(); // ��ؼ��
        dino_collision(); // ��ײ���
        if (dino_collision())
            break; // ��ײ�����
        recircle(); // �ϰ���ѭ��
        cleardevice(); // ����
        BeginBatchDraw();
        print_game(); // ������Ϸ
        EndBatchDraw();
        skill_require(); // ���ܼ��
        Sleep(24); // ����֡��
    }
    End_game(score); // ��Ϸ��������
}

// ����ʽ��ѧģʽ��ѭ��
void Start_intgame()
{
    Init();
    TCHAR tmp[30];
    int flag1 = 1, flag2 = 1, flag3 = 1, flag4 = 1, flag5 = 1;
    while (1)
    {
        if (_kbhit())
        {
            char input = _getch();
            if ((int)(input) == -32)
            {
                input = _getch();
                if ((int)input == 72 && ground_flag >= 1) {
                    dino_vy = -5; // �ϼ���Ծ
                    ground_flag -= 1;
                    skill1_flag = 0;
                    flag1 = 0;
                }
                if ((int)input == 80) {
                    dino_vy = 5; // �¼�����
                    dino_vx = 0;
                    flag2 = 0;
                }
                if ((int)input == 77) {
                    dino_vx = 1; // �Ҽ�����
                    flag3 = 0;
                    if (ground_flag >= 0 && skill1_flag == 0)
                        dino_Lfetx += 10, skill1_flag = 1, flag5 = 0; // ����˲�Ƽ���
                }
                if ((int)input == 75) {
                    dino_vx = -1; // �������
                    flag4 = 0;
                }
            }
            if (input == ' ') {
                Startgame(); // �ո�ʼ��ʽ��Ϸ
            }
        }
        cleardevice();
        change_location();
        ground_dino();
        BeginBatchDraw();
        print_game();

        settextstyle(7, 0, _T("����"));
        // ���ݽ�ѧ������ʾ��ͬ��ʾ
        if (flag1 == 1)	wcscpy_s(tmp, _T("�������  ������Ծ"));
        else if (flag2 == 1)	wcscpy_s(tmp, _T("��  ��������,����ˮƽ�ٶ�Ϊ0"));
        else if (flag3 == 1)	wcscpy_s(tmp, _T("�������  ����ˮƽ���Ҽ���,�¿�ֹͣ"));
        else if (flag4 == 1)	wcscpy_s(tmp, _T("�������  ����ˮƽ�������")), skill1 = 1;
        else if (flag5 == 1)	wcscpy_s(tmp, _T("�������  ����:���п�˲��"));
        else wcscpy_s(tmp, _T("�ո���ʽ��ʼ��Ϸ"));

        outtextxy(width / 8 - textwidth(tmp) / 2, height / 8, tmp);
        EndBatchDraw();
        Sleep(24);
    }
}