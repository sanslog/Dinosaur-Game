#include "GameSkill.h"
#include "GameData.h"
#include <tchar.h>
#include <graphics.h>

// �������������¼��ܵĺ���
void skill_require()
{
    // �ж��Ƿ�ﵽ��õ�һ�����ܵķ�������δ��øü���
    if (score >= tmpscore1 && skill1 == 0) {
        skill1 = 1; // �����һ������
        settextstyle(14, 0, _T("����")); // ����������ʽ
        TCHAR Skill[] = _T("����¼��ܣ��������ҿ�˲��");
        // ����Ļָ��λ����ʾ��ü��ܵ���ʾ
        outtextxy(width / 8 - textwidth(Skill) / 2, height / 16, Skill);
        Sleep(1500); // ͣ��1.5���Ա���ҿ�����ʾ
        settextstyle(7, 0, _T("����")); // �ָ�������ʽ
    }
    // �ж��Ƿ�ﵽ��õڶ������ܵķ�������δ��øü���
    if (score >= tmpscore2 && skill2 == 0) {
        skill2 = 1; // ����ڶ�������
        settextstyle(14, 0, _T("����")); // ����������ʽ
        TCHAR Skill[] = _T("����¼��ܣ����пɶ�����");
        // ����Ļָ��λ����ʾ��ü��ܵ���ʾ
        outtextxy(width / 8 - textwidth(Skill) / 2, height / 16, Skill);
        Sleep(1500); // ͣ��1.5���Ա���ҿ�����ʾ
        settextstyle(7, 0, _T("����")); // �ָ�������ʽ
    }
}