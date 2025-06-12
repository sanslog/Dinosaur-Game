#include "GameRender.h"
#include "GameData.h"
#include "GameInit.h"
#include <tchar.h>
#include <graphics.h>
#include "GameInput.h"

// 游戏主渲染函数，负责绘制游戏界面各元素
void print_game()
{
    // 绘制背景
    putimage(0, 0, &im_bg);
    // 绘制两朵云，制造动态效果
    putimage(cloud_x, 10, &im_cloud);
    putimage(cloud_x2, 10 + 5, &im_cloud);

    // 根据动画帧数ani绘制不同状态的小恐龙，实现奔跑动画
    if (ani <= 3) PutPng(dino_Lfetx, dino_Topy, &im_dino21, &im_dino22);
    else if (ani > 3 && ani <= 5) PutPng(dino_Lfetx, dino_Topy, &im_dino31, &im_dino32);
    else PutPng(dino_Lfetx, dino_Topy, &im_dino41, &im_dino42);

    // 循环绘制地面，实现地面平铺
    for (int i = 0; i < width / 46; i++)
        putimage(i * 46, bottom, &im_ground);

    // 绘制两棵障碍物树
    putimage(rec1_Leftx, rec1_Topy, &im_Tree);
    putimage(rec2_Leftx, rec2_Topy, &im_Tree);

    // 显示当前分数
    TCHAR s[20];
    swprintf_s(s, _T("%d"), score);
    settextstyle(14, 0, _T("Consolas"));
    outtextxy(50 / 4, 30 / 4, s);
}

// 游戏结束界面渲染函数，显示分数和提示信息
void End_game(int score)
{
    TCHAR tmp[20];
    // 显示最终得分
    swprintf_s(tmp, _T("Score:%d"), score);
    settextstyle(14, 0, _T("宋体"));
    outtextxy(width / 8 - textwidth(tmp) / 2, height / 8 - textheight(tmp), tmp);

    // 显示重新开始游戏的提示
    settextstyle(7, 0, _T("宋体"));
    wcscpy_s(tmp, _T("空格-重新开始游戏"));
    outtextxy(width / 8 - textwidth(tmp) / 2, height / 8 + 0.5 * textheight(tmp), tmp);

    // 显示作者信息
    settextstyle(15, 0, _T("Consolas"));
    wcscpy_s(tmp, _T("made by zbwer"));
    settextstyle(7, 0, _T("宋体"));
    outtextxy(width / 8 - textwidth(tmp) / 2, height / 8 + 2 * textheight(tmp), tmp);

    // 等待玩家输入，按空格键重新开始
    settextstyle(15, 0, _T("Consolas"));
    input_key();
}