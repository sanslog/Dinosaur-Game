#include "GameSkill.h"
#include "GameData.h"
#include <tchar.h>
#include <graphics.h>

// �������Ƿ�ﵽ���ܽ����������������¼���
void skill_require()
{
    // �ж��Ƿ�ﵽ��һ�����ܵķ���Ҫ����δ��øü���
    if (score >= tmpscore1 && skill1 == 0) {
        skill1 = 1; // ������һ������
        settextstyle(14, 0, _T("����"));
        // ��ʾ����¼�����ʾ
        TCHAR Skill[] = _T("����¼��ܣ��������ҿ�˲��");
        outtextxy(width / 8 - textwidth(Skill) / 2, height / 16, Skill);
        Sleep(1500);
        settextstyle(7, 0, _T("����"));
    }
    // �ж��Ƿ�ﵽ�ڶ������ܵķ���Ҫ����δ��øü���
    if (score >= tmpscore2 && skill2 == 0) {
        skill2 = 1; // �����ڶ�������
        settextstyle(14, 0, _T("����"));
        // ��ʾ����¼�����ʾ
        TCHAR Skill[] = _T("����¼��ܣ����пɶ�����");
        outtextxy(width / 8 - textwidth(Skill) / 2, height / 16, Skill);
        Sleep(1500);
        settextstyle(7, 0, _T("����"));
    }
}
