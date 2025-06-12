#include "GameSkill.h"
#include "GameData.h"
#include <tchar.h>
#include <graphics.h>

// 检查分数是否达到技能解锁条件，并解锁新技能
void skill_require()
{
    // 判断是否达到第一个技能的分数要求且未获得该技能
    if (score >= tmpscore1 && skill1 == 0) {
        skill1 = 1; // 解锁第一个技能
        settextstyle(14, 0, _T("宋体"));
        // 显示获得新技能提示
        TCHAR Skill[] = _T("获得新技能：空中向右可瞬移");
        outtextxy(width / 8 - textwidth(Skill) / 2, height / 16, Skill);
        Sleep(1500);
        settextstyle(7, 0, _T("宋体"));
    }
    // 判断是否达到第二个技能的分数要求且未获得该技能
    if (score >= tmpscore2 && skill2 == 0) {
        skill2 = 1; // 解锁第二个技能
        settextstyle(14, 0, _T("宋体"));
        // 显示获得新技能提示
        TCHAR Skill[] = _T("获得新技能：空中可二段跳");
        outtextxy(width / 8 - textwidth(Skill) / 2, height / 16, Skill);
        Sleep(1500);
        settextstyle(7, 0, _T("宋体"));
    }
}
