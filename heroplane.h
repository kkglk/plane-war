#ifndef HEROPLANE_H
#define HEROPLANE_H
#include<QPixmap>
#include<QRect>
#include"bullet.h"
class HeroPlane
{
public:
    HeroPlane();
    //�����ӵ�
       void shoot();
       void shoot1();

       //���÷ɻ�λ��
       void setPlanePosition(int x,int y);

       bool hero_free;


       //�ɻ���Դ ����
       QPixmap m_hero;

       //�ɻ�����
       int m_x;
       int m_y;

       //�ɻ����α߿�
       QRect m_rect;

       //�ӵ�����
       Bullet m_bullets[BULLET_NUM];//����
       int m_recorder; //��������¼

       //�ӵ�����2
       Bullet m_bullets1[BULLET_NUM];//����
       int m_recorder1; //��������¼

};

#endif // HEROPLANE_H
