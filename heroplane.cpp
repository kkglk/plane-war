#include "heroplane.h"
#include"config.h"
#include"map.h"
#include"bullet.h"
HeroPlane::HeroPlane()
{
    m_hero.load(HERO_PATH);//设置飞机模型

    //初始化飞机坐标
    m_x=GAME_WIDTH*0.5-m_hero.width()+50;
    m_y=GAME_HEIGHT*0.5-m_hero.height()+300;

    //初始化矩形边框
    m_rect.setWidth(m_hero.width());
    m_rect.setHeight(m_hero.height());
    //移动
    m_rect.moveTo(m_x,m_y);

    hero_free=false;
    //初始化子弹记录间隔
    m_recorder=0;
    m_recorder1=0;
   }

void HeroPlane::shoot()
{
    //累加时间间隔记录变量
    m_recorder++;
    //如果记录的数字未达到子弹发射的间隔
    if(m_recorder<BULLET_INTERVAL)
    {
        return;//不发射
    }
    m_recorder=0;
    //发射子弹
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果子弹空闲 则发射
        if(m_bullets[i].bullet_Free)
        {
            //将空闲状态改为假
            m_bullets[i].bullet_Free=false;
            //设置子弹坐标
            m_bullets[i].bullet_X=m_x+m_rect.width()*0.5-10;
            m_bullets[i].bullet_Y=m_y-25;
            break;
        }
    }


}
void HeroPlane::shoot1()
{
    //累加时间间隔记录变量
    m_recorder1++;
    //如果记录的数字未达到子弹发射的间隔
    if(m_recorder1<BULLET_INTERVAL)
    {
        return;//不发射
    }
    m_recorder1=0;
    //发射子弹
    for(int q=0;q<BULLET_NUM;q++)
    {
        //如果子弹空闲 则发射
        if(m_bullets1[q].bullet_Free1)
        {
            //将空闲状态改为假
            m_bullets1[q].bullet_Free1=false;
            //设置子弹坐标
            m_bullets1[q].bullet_X1=m_x;
            m_bullets1[q].bullet_Y1=m_y+25;
            break;
        }
    }

}
//飞机位置时时改变
   void HeroPlane::setPlanePosition(int x, int y)
   {
       m_x=x;
       m_y=y;

       m_rect.moveTo(m_x,m_y);

}
