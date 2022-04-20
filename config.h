#ifndef CONFIG_H
#define CONFIG_H

#define LOG qDebug()<<__FILE__<<__LINE__<<QDateTime::currentDateTime().toString("yyy-MM-dd hh:mm:ss:zzz")
#define GAME_WIDTH 512
#define GAME_HEIGHT 720
#define GAME_TITLE "plane wars"
#define GAME_RES_PATH "./plane.rcc" //rcc�ļ�·��
//ͼ��
#define GAME_ICON "./res/app.ico"   //ͼ��
//��ͼ
#define MAP_PATH "./res/img_bg_level_1.jpg" //��ͼͼƬ��ַ
#define MAP_SCROLL_SPEED 5 //��ͼ�����ٶ�
#define GAME_RATE  20  //ˢ�¼����֡�� ��λ����
//�ɻ�����
#define HERO_PATH "./res/hero2.png"

//�ӵ�����
#define BULLET_PATH "./res/hero_bullet_7.png" //�ӵ�ģ��
#define BULLET_PATH1 "./res/bullet_10.png" //�ӵ�ģ��
#define BULLET_SPEED 10  //�ӵ��ٶ�
#define BULLET_NUM 30 //�ӵ�����
#define BULLET_NUM1 30 //�ӵ�����
#define BULLET_INTERVAL 20 //�ӵ�������

//�л�����
#define ENEMY_PATH  "./res/img-plane_5.png"
#define ENEMY_SPEED 3  //�о��ƶ��ٶ�
#define ENEMY_NUM 20   //�о�������
#define ENEMY_INTERVAL 20 //�о�����ʱ����

//��ըЧ��
#define BOMB_PATH "./res/bomb-%1.png"
#define BOMB_NUM 50 //��ը����
#define BOMB_MAX 7 //��ըͼƬ�������
#define BOMB_INTERVAL 5//��ը��ͼʱ����

//��Ч
#define SUOND_BACKGROUND "./res/bg.wav"
#define SOUND_BOMB "./res/bomb.wav"

#endif // CONFIG_H
