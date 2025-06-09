#include "GameData.h"

//初始化头文件变量
IMAGE im_logo1, im_logo2;
IMAGE im_ground, im_Tree, im_bg, im_cloud;
IMAGE im_dino21, im_dino22, im_dino31, im_dino32, im_dino41, im_dino42, im_fly1, im_fly2;

double width, height, bottom;
double dino_width, dino_height, dino_Lfetx, dino_Topy;
double dino_vy, dino_vx, gravity;
double rec1_width, rec1_height, rec1_Leftx, rec1_Topy, rec1_vx, rec_distance, rec1_flag;
double rec2_width, rec2_height, rec2_Leftx, rec2_Topy, rec2_vx, rec2_flag;
int score, tmpscore1 = 10, tmpscore2 = 25, ground_flag, skill1_flag, ani;
double cloud_x = 220, cloud_x2 = 220 + 70;
int randwid[5] = { 80,32,48,16,64 }, skill1, skill2;