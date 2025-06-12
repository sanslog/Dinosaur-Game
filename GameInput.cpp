#include "GameInput.h"
#include "GameData.h"
#include "GameLogic.h"
#include <conio.h>
#include <windows.h>

void input_game()
{
    if (_kbhit())
    {
        char input = _getch();
        if ((int)(input) == -32)
        {
            input = _getch();
            if ((int)input == 72 && ground_flag >= 1) {
                dino_vy = -5;
                ground_flag -= 1;
                skill1_flag = 0;
            }
            if ((int)input == 80) {
                dino_vy = 5;
                dino_vx = 0;
            }
            if ((int)input == 77) {
                dino_vx = 1;
                if (score >= tmpscore1 && ground_flag >= 0 && skill1_flag == 0) {
                    dino_Lfetx += 10, skill1_flag = 1;
                }
            }
            if ((int)input == 75) {
                dino_vx = -1;
            }
        }
    }
}

void input_key()
{
    while (1)
    {
        char input = _getch();
        if (input == ' ')
        {
            Startgame();
            break;
        }
        else if (input == 'B') exit(0);
        else if (input == 'A')
        {
            Start_intgame();
            break;
        }
    }
}