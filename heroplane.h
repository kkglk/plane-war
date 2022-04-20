#ifndef HEROPLANE_H
#define HEROPLANE_H
#include<QPixmap>
#include<QRect>
#include"bullet.h"
class HeroPlane
{
public:
    HeroPlane();
    //发射子弹
       void shoot();
       void shoot1();

       //设置飞机位置
       void setPlanePosition(int x,int y);

       bool hero_free;


       //飞机资源 对象
       QPixmap m_hero;

       //飞机坐标
       int m_x;
       int m_y;

       //飞机矩形边框
       QRect m_rect;

       //子弹数组
       Bullet m_bullets[BULLET_NUM];//弹夹
       int m_recorder; //发射间隔记录

       //子弹数组2
       Bullet m_bullets1[BULLET_NUM];//弹夹
       int m_recorder1; //发射间隔记录

};

#endif // HEROPLANE_H
