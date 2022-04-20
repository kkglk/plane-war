#ifndef CONFIG_H
#define CONFIG_H

#define LOG qDebug()<<__FILE__<<__LINE__<<QDateTime::currentDateTime().toString("yyy-MM-dd hh:mm:ss:zzz")
#define GAME_WIDTH 512
#define GAME_HEIGHT 720
#define GAME_TITLE "plane wars"
#define GAME_RES_PATH "./plane.rcc" //rcc文件路径
//图标
#define GAME_ICON "./res/app.ico"   //图标
//地图
#define MAP_PATH "./res/img_bg_level_1.jpg" //地图图片地址
#define MAP_SCROLL_SPEED 5 //地图滚动速度
#define GAME_RATE  20  //刷新间隔，帧率 单位毫秒
//飞机数据
#define HERO_PATH "./res/hero2.png"

//子弹数据
#define BULLET_PATH "./res/hero_bullet_7.png" //子弹模型
#define BULLET_PATH1 "./res/bullet_10.png" //子弹模型
#define BULLET_SPEED 10  //子弹速度
#define BULLET_NUM 30 //子弹数量
#define BULLET_NUM1 30 //子弹数量
#define BULLET_INTERVAL 20 //子弹发射间隔

//敌机数据
#define ENEMY_PATH  "./res/img-plane_5.png"
#define ENEMY_SPEED 3  //敌军移动速度
#define ENEMY_NUM 20   //敌军总数量
#define ENEMY_INTERVAL 20 //敌军出场时间间隔

//爆炸效果
#define BOMB_PATH "./res/bomb-%1.png"
#define BOMB_NUM 50 //爆炸数量
#define BOMB_MAX 7 //爆炸图片最大索引
#define BOMB_INTERVAL 5//爆炸切图时间间隔

//音效
#define SUOND_BACKGROUND "./res/bg.wav"
#define SOUND_BOMB "./res/bomb.wav"

#endif // CONFIG_H
