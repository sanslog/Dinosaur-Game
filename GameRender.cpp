#include "GameRender.h"
#include "GameData.h"
#include "GameInit.h"
#include <tchar.h>
#include <graphics.h>
#include "GameInput.h"

// ��Ϸ����Ⱦ���������������Ϸ�����Ԫ��
void print_game()
{
    // ���Ʊ���
    putimage(0, 0, &im_bg);
    // ���������ƣ����춯̬Ч��
    putimage(cloud_x, 10, &im_cloud);
    putimage(cloud_x2, 10 + 5, &im_cloud);

    // ���ݶ���֡��ani���Ʋ�ͬ״̬��С������ʵ�ֱ��ܶ���
    if (ani <= 3) PutPng(dino_Lfetx, dino_Topy, &im_dino21, &im_dino22);
    else if (ani > 3 && ani <= 5) PutPng(dino_Lfetx, dino_Topy, &im_dino31, &im_dino32);
    else PutPng(dino_Lfetx, dino_Topy, &im_dino41, &im_dino42);

    // ѭ�����Ƶ��棬ʵ�ֵ���ƽ��
    for (int i = 0; i < width / 46; i++)
        putimage(i * 46, bottom, &im_ground);

    // ���������ϰ�����
    putimage(rec1_Leftx, rec1_Topy, &im_Tree);
    putimage(rec2_Leftx, rec2_Topy, &im_Tree);

    // ��ʾ��ǰ����
    TCHAR s[20];
    swprintf_s(s, _T("%d"), score);
    settextstyle(14, 0, _T("Consolas"));
    outtextxy(50 / 4, 30 / 4, s);
}

// ��Ϸ����������Ⱦ��������ʾ��������ʾ��Ϣ
void End_game(int score)
{
    TCHAR tmp[20];
    // ��ʾ���յ÷�
    swprintf_s(tmp, _T("Score:%d"), score);
    settextstyle(14, 0, _T("����"));
    outtextxy(width / 8 - textwidth(tmp) / 2, height / 8 - textheight(tmp), tmp);

    // ��ʾ���¿�ʼ��Ϸ����ʾ
    settextstyle(7, 0, _T("����"));
    wcscpy_s(tmp, _T("�ո�-���¿�ʼ��Ϸ"));
    outtextxy(width / 8 - textwidth(tmp) / 2, height / 8 + 0.5 * textheight(tmp), tmp);

    // ��ʾ������Ϣ
    settextstyle(15, 0, _T("Consolas"));
    wcscpy_s(tmp, _T("made by zbwer"));
    settextstyle(7, 0, _T("����"));
    outtextxy(width / 8 - textwidth(tmp) / 2, height / 8 + 2 * textheight(tmp), tmp);

    // �ȴ�������룬���ո�����¿�ʼ
    settextstyle(15, 0, _T("Consolas"));
    input_key();
}