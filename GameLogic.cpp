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

void change_location()
{
    dino_vy = dino_vy + gravity;
    dino_Topy = dino_Topy + dino_vy;
    dino_Lfetx = dino_Lfetx + dino_vx;
    rec1_Leftx = rec1_Leftx + rec1_vx;
    rec2_Leftx = rec2_Leftx + rec2_vx;
    cloud_x -= 0.5;
    cloud_x2 -= 0.5;
    ani = (ani + 1) % 9;
}

void recircle()
{
    if (rec1_Leftx <= 0) {
        rec1_flag++;
        rec1_Leftx = width / 4;
        if (rec2_Leftx + rec1_width >= width / 4) rec1_Leftx = rec2_Leftx + rand_range(2, 4) * 50;
        score++;
        if (score >= 10)
            rec1_vx -= 0.1, rec2_vx -= 0.1;
    }
    else if (rec2_Leftx <= 0)
    {
        rec2_flag++;
        rec_distance = randwid[rand() % 5];
        if (rec1_flag > rec2_flag) rec_distance = width / 4 - rec1_Leftx;
        rec2_Leftx = width / 4 + rec_distance + randwid[rand() % 5];
        score++;
    }
    if (cloud_x <= 0)   cloud_x = width / 4 + 27;
    if (cloud_x2 <= 0)  cloud_x2 = width / 4 + 63;
}

void ground_dino()
{
    if (dino_Topy >= bottom - dino_height) {
        dino_vy = 0;
        dino_Topy = bottom - dino_height;
        ground_flag = 1;
        skill1_flag = 1;
        if (score >= tmpscore2)
            ground_flag = 2;
    }
    else {
        ani = 3;
    }
}

bool dino_collision()
{
    if ((rec1_Leftx < dino_Lfetx + dino_width && rec1_Topy + 1 < dino_Topy + dino_height && dino_Lfetx < rec1_Leftx + rec1_width) ||
        ((rec2_Leftx < dino_Lfetx + dino_width && rec2_Topy + 1 < dino_Topy + dino_height && dino_Lfetx < rec2_Leftx + rec2_width)) ||
        (dino_Lfetx <= 0 || dino_Lfetx + dino_width >= width / 4))
        return 1;
    return 0;
}

void Startgame()
{
    Init();
    while (1) {
        input_game();
        change_location();
        ground_dino();
        dino_collision();
        if (dino_collision())
            break;
        recircle();
        cleardevice();
        BeginBatchDraw();
        print_game();
        EndBatchDraw();
        skill_require();
        Sleep(24);
    }
    End_game(score);
}

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
                    dino_vy = -5;
                    ground_flag -= 1;
                    skill1_flag = 0;
                    flag1 = 0;
                }
                if ((int)input == 80) {
                    dino_vy = 5;
                    dino_vx = 0;
                    flag2 = 0;
                }
                if ((int)input == 77) {
                    dino_vx = 1;
                    flag3 = 0;
                    if (ground_flag >= 0 && skill1_flag == 0)
                        dino_Lfetx += 10, skill1_flag = 1, flag5 = 0;
                }
                if ((int)input == 75) {
                    dino_vx = -1;
                    flag4 = 0;
                }
            }
            if (input == ' ') {
                Startgame();
            }
        }
        cleardevice();
        change_location();
        ground_dino();
        BeginBatchDraw();
        print_game();

        settextstyle(7, 0, _T("宋体"));
        if (flag1 == 1)	wcscpy_s(tmp, _T("方向键上  控制跳跃"));
        else if (flag2 == 1)	wcscpy_s(tmp, _T("下  控制下落,并让水平速度为0"));
        else if (flag3 == 1)	wcscpy_s(tmp, _T("方向键右  控制水平向右加速,下可停止"));
        else if (flag4 == 1)	wcscpy_s(tmp, _T("方向键左  控制水平向左加速")), skill1 = 1;
        else if (flag5 == 1)	wcscpy_s(tmp, _T("方向键右  技能:空中可瞬移"));
        else wcscpy_s(tmp, _T("空格正式开始游戏"));

        outtextxy(width / 8 - textwidth(tmp) / 2, height / 8, tmp);
        EndBatchDraw();
        Sleep(24);
    }
}