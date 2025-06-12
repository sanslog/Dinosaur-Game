#include "GameInput.h"
#include "GameData.h"
#include "GameLogic.h"
#include <conio.h>
#include <windows.h>

void input_game()
{
    // 检查是否有键盘输入
    if (_kbhit())
    {
        // 获取按下的键
        char input = _getch();
        // 判断是否为方向键（扩展码-32）
        if ((int)(input) == -32)
        {
            input = _getch(); // 获取实际方向键值
            // 上箭头，角色跳跃
            if ((int)input == 72 && ground_flag >= 1) {
                dino_vy = -5; // 设置竖直速度为向上
                ground_flag -= 1; // 跳跃后减少地面标志
                skill1_flag = 0; // 重置技能1标志
            }
            // 下箭头，角色下落
            if ((int)input == 80) {
                dino_vy = 5; // 设置竖直速度为向下
                dino_vx = 0; // 水平速度归零
            }
            // 右箭头，角色向右移动
            if ((int)input == 77) {
                dino_vx = 1; // 设置水平速度为向右
                // 满足条件时触发技能1
                if (score >= tmpscore1 && ground_flag >= 0 && skill1_flag == 0) {
                    dino_Lfetx += 10; // 技能1效果：位置增加
                    skill1_flag = 1; // 标记技能1已用
                }
            }
            // 左箭头，角色向左移动
            if ((int)input == 75) {
                dino_vx = -1; // 设置水平速度为向左
            }
        }
    }
}

// 处理主菜单的按键输入
void input_key()
{
    while (1)
    {
        // 获取用户按下的键
        char input = _getch();
        if (input == ' ')
        {
            // 按下空格键，开始游戏
            Startgame();
            break;
        }
        else if (input == 'B') 
            // 按下B键，退出程序
            exit(0);
        else if (input == 'A')
        {
            // 按下A键，开始中级游戏
            Start_intgame();
            break;
        }
    }
}