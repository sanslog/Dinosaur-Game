#include "GameSkill.h"
#include "GameData.h"
#include <tchar.h>
#include <graphics.h>

void skill_require()
{
    if (score >= tmpscore1 && skill1 == 0) {
        skill1 = 1;
        settextstyle(14, 0, _T("宋体"));
        TCHAR Skill[] = _T("获得新技能：空中向右可瞬移");
        outtextxy(width / 8 - textwidth(Skill) / 2, height / 16, Skill);
        Sleep(1500);
        settextstyle(7, 0, _T("宋体"));
    }
    if (score >= tmpscore2 && skill2 == 0) {
        skill2 = 1;
        settextstyle(14, 0, _T("宋体"));
        TCHAR Skill[] = _T("获得新技能：空中可二段跳");
        outtextxy(width / 8 - textwidth(Skill) / 2, height / 16, Skill);
        Sleep(1500);
        settextstyle(7, 0, _T("宋体"));
    }
}
