#include "GameSkill.h"
#include "GameData.h"
#include <tchar.h>
#include <graphics.h>

void skill_require()
{
    if (score >= tmpscore1 && skill1 == 0) {
        skill1 = 1;
        settextstyle(14, 0, _T("����"));
        TCHAR Skill[] = _T("����¼��ܣ��������ҿ�˲��");
        outtextxy(width / 8 - textwidth(Skill) / 2, height / 16, Skill);
        Sleep(1500);
        settextstyle(7, 0, _T("����"));
    }
    if (score >= tmpscore2 && skill2 == 0) {
        skill2 = 1;
        settextstyle(14, 0, _T("����"));
        TCHAR Skill[] = _T("����¼��ܣ����пɶ�����");
        outtextxy(width / 8 - textwidth(Skill) / 2, height / 16, Skill);
        Sleep(1500);
        settextstyle(7, 0, _T("����"));
    }
}
