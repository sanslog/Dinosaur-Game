#include "GameInput.h"
#include "GameData.h"
#include "GameLogic.h"
#include <conio.h>
#include <windows.h>

void input_game()
{
    // ����Ƿ��м�������
    if (_kbhit())
    {
        // ��ȡ���µļ�
        char input = _getch();
        // �ж��Ƿ�Ϊ���������չ��-32��
        if ((int)(input) == -32)
        {
            input = _getch(); // ��ȡʵ�ʷ����ֵ
            // �ϼ�ͷ����ɫ��Ծ
            if ((int)input == 72 && ground_flag >= 1) {
                dino_vy = -5; // ������ֱ�ٶ�Ϊ����
                ground_flag -= 1; // ��Ծ����ٵ����־
                skill1_flag = 0; // ���ü���1��־
            }
            // �¼�ͷ����ɫ����
            if ((int)input == 80) {
                dino_vy = 5; // ������ֱ�ٶ�Ϊ����
                dino_vx = 0; // ˮƽ�ٶȹ���
            }
            // �Ҽ�ͷ����ɫ�����ƶ�
            if ((int)input == 77) {
                dino_vx = 1; // ����ˮƽ�ٶ�Ϊ����
                // ��������ʱ��������1
                if (score >= tmpscore1 && ground_flag >= 0 && skill1_flag == 0) {
                    dino_Lfetx += 10; // ����1Ч����λ������
                    skill1_flag = 1; // ��Ǽ���1����
                }
            }
            // ���ͷ����ɫ�����ƶ�
            if ((int)input == 75) {
                dino_vx = -1; // ����ˮƽ�ٶ�Ϊ����
            }
        }
    }
}

// �������˵��İ�������
void input_key()
{
    while (1)
    {
        // ��ȡ�û����µļ�
        char input = _getch();
        if (input == ' ')
        {
            // ���¿ո������ʼ��Ϸ
            Startgame();
            break;
        }
        else if (input == 'B') 
            // ����B�����˳�����
            exit(0);
        else if (input == 'A')
        {
            // ����A������ʼ�м���Ϸ
            Start_intgame();
            break;
        }
    }
}