#include "GameInit.h"
#include "GameData.h"
#include <tchar.h>
#include <graphics.h>
#include <cstdio>
#include <windows.h>

int rand_range(int x, int y)
{
    return rand() % (y + 1) + x;
}

void PutPng(int x, int y, IMAGE* im_show1, IMAGE* im_show2)
{
    putimage(x, y, im_show1, SRCAND);
    putimage(x, y, im_show2, SRCPAINT);
}

void Init()
{
    loadimage(&im_bg, _T("./src/background.png"));
    loadimage(&im_logo1, _T("./src/logo1.png"));
    loadimage(&im_logo2, _T("./src/logo2.png"));

    loadimage(&im_dino21, _T("./src/move2_1.png"));
    loadimage(&im_dino22, _T("./src/move2_2.png"));
    loadimage(&im_dino31, _T("./src/move3_1.png"));
    loadimage(&im_dino32, _T("./src/move3_2.png"));
    loadimage(&im_dino41, _T("./src/move4_1.png"));
    loadimage(&im_dino42, _T("./src/move4_2.png"));
    loadimage(&im_fly1, _T("./src/fly_1.png"));
    loadimage(&im_fly2, _T("./src/fly_2.png"));

    loadimage(&im_ground, _T("./src/1.png"));
    loadimage(&im_Tree, _T("./src/Tree.png"));
    loadimage(&im_cloud, _T("./src/cloud.png"));

    width = 1000;
    height = 400;
    bottom = (height - 46) / 4;
    initgraph(width, height);
    setaspectratio(4.0, 4.0);
    settextcolor(RGB(0, 0, 0));
    setbkcolor(RGB(177, 236, 240));

    dino_width = 14;
    dino_height = 16;
    dino_Lfetx = width / 20;
    dino_Topy = bottom - dino_height;
    dino_vx = 0;
    dino_vy = 0;
    gravity = 0.25;
    ground_flag = 1;
    ani = 0;

    rec1_width = rec2_width = 16;
    rec1_height = rec2_height = 21;
    rec1_Leftx = width / 4 - 25;
    rec_distance = 100;
    rec2_Leftx = rec1_Leftx + rec_distance;
    rec1_Topy = rec2_Topy = bottom - rec1_height;
    rec1_vx = rec2_vx = -2.5;
    rec1_flag = rec2_flag = 0;

    score = 0;
    skill1 = 0; skill2 = 0;
    skill1_flag = 1;
}

void pre_print()
{
    putimage(0, 0, &im_bg);
    settextstyle(15, 0, _T("Consolas"));
    settextcolor(RGB(253, 138, 101));

    TCHAR Intro[30];
    wcscpy_s(Intro, _T("New Dinosaur"));
    int Intro_wid = width / 8 - textwidth(Intro) / 2;
    int Intro_hei = height / 8 - textheight(Intro);
    outtextxy(Intro_wid + 10, Intro_hei, Intro);
    PutPng(Intro_wid - dino_width * 2 + 10, Intro_hei - 1, &im_logo1, &im_logo2);
    Sleep(1500);

    cleardevice();
    putimage(0, 0, &im_bg);
    putimage(0, 0, &im_bg);
    putimage(cloud_x, 10, &im_cloud);
    putimage(cloud_x2, 10 + 5, &im_cloud);
    PutPng(dino_Lfetx, dino_Topy, &im_logo1, &im_logo2);
    for (int i = 0; i < width / 4 * 46; i++)
        putimage(i * 46, bottom, &im_ground);

    settextcolor(RGB(0, 0, 0));
    settextstyle(8, 0, _T("宋体"));
    wcscpy_s(Intro, _T("开始 -   空格"));
    Intro_wid = width / 8 - textwidth(Intro) / 2;
    Intro_hei = height / 8 - textheight(Intro) * 2;
    outtextxy(Intro_wid, Intro_hei, Intro);
    wcscpy_s(Intro, _T("教程 - press A"));
    Intro_hei = Intro_hei + textheight(Intro);
    outtextxy(Intro_wid, Intro_hei + 5, Intro);
    wcscpy_s(Intro, _T("退出 - press B"));
    outtextxy(Intro_wid, Intro_hei + textheight(Intro) + 10, Intro);
}
