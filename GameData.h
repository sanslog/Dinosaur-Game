#pragma once
#include<graphics.h>

//ÏñËØÍ¼Æ¬ËØ²Ä
extern IMAGE im_logo1, im_logo2;
extern IMAGE im_ground, im_Tree, im_bg, im_cloud;
extern IMAGE im_dino21, im_dino22, im_dino31, im_dino32, im_dino41, im_dino42, im_fly1, im_fly2;

// ÓÎÏ·²ÎÊý
extern double width, height, bottom;
extern double dino_width, dino_height, dino_Lfetx, dino_Topy;
extern double dino_vy, dino_vx, gravity;
extern double rec1_width, rec1_height, rec1_Leftx, rec1_Topy, rec1_vx, rec_distance, rec1_flag;
extern double rec2_width, rec2_height, rec2_Leftx, rec2_Topy, rec2_vx, rec2_flag;
extern int score, tmpscore1, tmpscore2, ground_flag, skill1_flag, ani;
extern double cloud_x, cloud_x2;
extern int randwid[5], skill1, skill2;