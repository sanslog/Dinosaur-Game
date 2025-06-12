#include "GameInit.h" // 包含游戏初始化相关的头文件  
#include "GameInput.h" // 包含游戏输入处理相关的头文件  
#include "GameLogic.h" // 包含游戏逻辑处理相关的头文件  
#include <ctime> // 包含时间相关的头文件，用于随机数种子生成  

int main()  
{  
   Init(); // 初始化游戏资源和设置  
   pre_print(); // 预打印游戏界面或相关信息  
   input_key(); // 处理用户输入的按键  
   srand((int)time(0)); // 设置随机数种子，基于当前时间  
   closegraph(); // 关闭图形界面，释放资源  
   return 0; // 返回程序执行状态，0表示正常结束  
}