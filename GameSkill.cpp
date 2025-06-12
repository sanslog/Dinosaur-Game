#include "GameSkill.h"
#include "GameData.h"
#include <tchar.h>
#include <graphics.h>

// 检查分数并授予新技能的函数
void skill_require()
{
    // 判断是否达到获得第一个技能的分数且尚未获得该技能
    if (score >= tmpscore1 && skill1 == 0) {
        skill1 = 1; // 授予第一个技能
        settextstyle(14, 0, _T("宋体")); // 设置文字样式
        TCHAR Skill[] = _T("获得新技能：空中向右可瞬移");
        // 在屏幕指定位置显示获得技能的提示
        outtextxy(width / 8 - textwidth(Skill) / 2, height / 16, Skill);
        Sleep(1500); // 停留1.5秒以便玩家看到提示
        settextstyle(7, 0, _T("宋体")); // 恢复文字样式
    }
    // 判断是否达到获得第二个技能的分数且尚未获得该技能
    if (score >= tmpscore2 && skill2 == 0) {
        skill2 = 1; // 授予第二个技能
        settextstyle(14, 0, _T("宋体")); // 设置文字样式
        TCHAR Skill[] = _T("获得新技能：空中可二段跳");
        // 在屏幕指定位置显示获得技能的提示
        outtextxy(width / 8 - textwidth(Skill) / 2, height / 16, Skill);
        Sleep(1500); // 停留1.5秒以便玩家看到提示
        settextstyle(7, 0, _T("宋体")); // 恢复文字样式
    }
}