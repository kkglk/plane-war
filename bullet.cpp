#include "bullet.h"
#include<QDebug>
Bullet::Bullet()
{
    //������Դ
    m_Bullet.load(BULLET_PATH);

    m_Bullet1.load(BULLET_PATH1);


    //�ӵ�����
    bullet_X=(GAME_WIDTH-m_Bullet.width())*0.5;
    bullet_Y=GAME_HEIGHT;

    bullet_X1=(GAME_WIDTH-m_Bullet.width())*0.5;
    bullet_Y1=GAME_HEIGHT;


    //�ӵ�״̬
    bullet_Free=true;

    bullet_Free1=true;
    //�ӵ��ٶ�
    bullet_Speed=BULLET_SPEED;
    //�ӵ����α߿�
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
        //����״̬�µ��ӵ������������
        if(bullet_Free)
        {
            return;
        }
        bullet_Y-=bullet_Speed;//�ӵ������ƶ�
        bullet_Rect.moveTo(bullet_X,bullet_Y);

        if(bullet_Y<=0)//�ӵ�λ�ó�����Ļ״̬ΪΪ����
        {
            bullet_Free=true;
        }

    }


void Bullet::updateBulletPosition1()
{
    //����״̬�µ��ӵ������������
    if(bullet_Free1)
    {
        return;
    }
    bullet_Y1-=bullet_Speed;//�ӵ������ƶ�
    bullet_Rect1.moveTo(bullet_X1,bullet_Y1);

    if(bullet_Y1<=0)//�ӵ�λ�ó�����Ļ״̬ΪΪ����
    {
        bullet_Free1=true;
    }

}




