#ifndef BULLET_H
#define BULLET_H
#include"config.h"
#include<QPixmap>

class Bullet
{
public:
    Bullet();

       //�����ӵ�����
        void updateBulletPosition();
        void updateBulletPosition1();

        //�ӵ���Դ����
        QPixmap m_Bullet;
        QPixmap m_Bullet1;
        //�ӵ�����
        int bullet_X;
        int bullet_Y;
        int bullet_X1;
        int bullet_Y1;

        //�ӵ��ƶ��ٶ�
        int bullet_Speed;

        //�ӵ��Ƿ�����
        bool bullet_Free;
        bool bullet_Free1;

        //�ӵ����α߿�
        QRect bullet_Rect;
        QRect bullet_Rect1;

};

#endif // BULLET_H
