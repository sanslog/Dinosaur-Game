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

// 更新游戏中各对象的位置和动画帧
void change_location()
{
    dino_vy = dino_vy + gravity; // 恐龙竖直速度受重力影响
    dino_Topy = dino_Topy + dino_vy; // 恐龙竖直位置更新
    dino_Lfetx = dino_Lfetx + dino_vx; // 恐龙水平位置更新
    rec1_Leftx = rec1_Leftx + rec1_vx; // 障碍物1位置更新
    rec2_Leftx = rec2_Leftx + rec2_vx; // 障碍物2位置更新
    cloud_x -= 0.5; // 云1移动
    cloud_x2 -= 0.5; // 云2移动
    ani = (ani + 1) % 9; // 动画帧切换
}

// 障碍物和云的循环重置逻辑
void recircle()
{
    if (rec1_Leftx <= 0) {
        rec1_flag++;
        rec1_Leftx = width / 4;
        if (rec2_Leftx + rec1_width >= width / 4) rec1_Leftx = rec2_Leftx + rand_range(2, 4) * 50;
        score++;
        if (score >= 10)
            rec1_vx -= 0.1, rec2_vx -= 0.1; // 难度提升
    }
    else if (rec2_Leftx <= 0)
    {
        rec2_flag++;
        rec_distance = randwid[rand() % 5];
        if (rec1_flag > rec2_flag) rec_distance = width / 4 - rec1_Leftx;
        rec2_Leftx = width / 4 + rec_distance + randwid[rand() % 5];
        score++;
    }
    if (cloud_x <= 0)   cloud_x = width / 4 + 27; // 云1重置
    if (cloud_x2 <= 0)  cloud_x2 = width / 4 + 63; // 云2重置
}

// 处理恐龙落地逻辑
void ground_dino()
{
    if (dino_Topy >= bottom - dino_height) {
        dino_vy = 0;
        dino_Topy = bottom - dino_height;
        ground_flag = 1;
        skill1_flag = 1;
        if (score >= tmpscore2)
            ground_flag = 2; // 达到分数后可多跳一次
    }
    else {
        ani = 3; // 空中动画
    }
}

// 检测恐龙与障碍物或边界的碰撞
bool dino_collision()
{
    if ((rec1_Leftx < dino_Lfetx + dino_width && rec1_Topy + 1 < dino_Topy + dino_height && dino_Lfetx < rec1_Leftx + rec1_width) ||
        ((rec2_Leftx < dino_Lfetx + dino_width && rec2_Topy + 1 < dino_Topy + dino_height && dino_Lfetx < rec2_Leftx + rec2_width)) ||
        (dino_Lfetx <= 0 || dino_Lfetx + dino_width >= width / 4))
        return 1;
    return 0;
}

// 正式游戏主循环
void Startgame()
{
    Init();
    while (1) {
        input_game(); // 处理输入
        change_location(); // 更新位置
        ground_dino(); // 落地检测
        dino_collision(); // 碰撞检测
        if (dino_collision())
            break; // 碰撞则结束
        recircle(); // 障碍物循环
        cleardevice(); // 清屏
        BeginBatchDraw();
        print_game(); // 绘制游戏
        EndBatchDraw();
        skill_require(); // 技能检测
        Sleep(24); // 控制帧率
    }
    End_game(score); // 游戏结束处理
}

// 交互式教学模式主循环
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
                    dino_vy = -5; // 上键跳跃
                    ground_flag -= 1;
                    skill1_flag = 0;
                    flag1 = 0;
                }
                if ((int)input == 80) {
                    dino_vy = 5; // 下键下落
                    dino_vx = 0;
                    flag2 = 0;
                }
                if ((int)input == 77) {
                    dino_vx = 1; // 右键加速
                    flag3 = 0;
                    if (ground_flag >= 0 && skill1_flag == 0)
                        dino_Lfetx += 10, skill1_flag = 1, flag5 = 0; // 空中瞬移技能
                }
                if ((int)input == 75) {
                    dino_vx = -1; // 左键加速
                    flag4 = 0;
                }
            }
            if (input == ' ') {
                Startgame(); // 空格开始正式游戏
            }
        }
        cleardevice();
        change_location();
        ground_dino();
        BeginBatchDraw();
        print_game();

        settextstyle(7, 0, _T("宋体"));
        // 根据教学进度显示不同提示
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