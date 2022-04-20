#ifndef BULLET_H
#define BULLET_H
#include"config.h"
#include<QPixmap>

class Bullet
{
public:
    Bullet();

       //更新子弹坐标
        void updateBulletPosition();
        void updateBulletPosition1();

        //子弹资源对象
        QPixmap m_Bullet;
        QPixmap m_Bullet1;
        //子弹坐标
        int bullet_X;
        int bullet_Y;
        int bullet_X1;
        int bullet_Y1;

        //子弹移动速度
        int bullet_Speed;

        //子弹是否闲置
        bool bullet_Free;
        bool bullet_Free1;

        //子弹矩形边框
        QRect bullet_Rect;
        QRect bullet_Rect1;

};

#endif // BULLET_H
