#include "bullet.h"
#include<QDebug>
Bullet::Bullet()
{
    //加载资源
    m_Bullet.load(BULLET_PATH);

    m_Bullet1.load(BULLET_PATH1);


    //子弹坐标
    bullet_X=(GAME_WIDTH-m_Bullet.width())*0.5;
    bullet_Y=GAME_HEIGHT;

    bullet_X1=(GAME_WIDTH-m_Bullet.width())*0.5;
    bullet_Y1=GAME_HEIGHT;


    //子弹状态
    bullet_Free=true;

    bullet_Free1=true;
    //子弹速度
    bullet_Speed=BULLET_SPEED;
    //子弹矩形边框
    bullet_Rect.setWidth(m_Bullet.width());
    bullet_Rect.setHeight(m_Bullet.height());
    bullet_Rect.moveTo(bullet_X,bullet_Y);
//}
    bullet_Rect1.setWidth(m_Bullet1.width());
    bullet_Rect1.setHeight(m_Bullet1.height());
    bullet_Rect1.moveTo(bullet_X1,bullet_Y1);
}
    void Bullet::updateBulletPosition()
    {
        //空闲状态下的子弹无需计算坐标
        if(bullet_Free)
        {
            return;
        }
        bullet_Y-=bullet_Speed;//子弹向上移动
        bullet_Rect.moveTo(bullet_X,bullet_Y);

        if(bullet_Y<=0)//子弹位置超出屏幕状态为为空闲
        {
            bullet_Free=true;
        }

    }


void Bullet::updateBulletPosition1()
{
    //空闲状态下的子弹无需计算坐标
    if(bullet_Free1)
    {
        return;
    }
    bullet_Y1-=bullet_Speed;//子弹向上移动
    bullet_Rect1.moveTo(bullet_X1,bullet_Y1);

    if(bullet_Y1<=0)//子弹位置超出屏幕状态为为空闲
    {
        bullet_Free1=true;
    }

}




