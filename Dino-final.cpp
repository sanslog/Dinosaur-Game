#include "GameInit.h"
#include "GameInput.h"
#include "GameLogic.h"
#include <ctime>

int main()
{
    Init();
    pre_print();
    input_key();
    srand((int)time(0));
    closegraph();
    return 0;
}