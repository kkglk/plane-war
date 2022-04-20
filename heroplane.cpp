#include "heroplane.h"
#include"config.h"
#include"map.h"
#include"bullet.h"
HeroPlane::HeroPlane()
{
    m_hero.load(HERO_PATH);//���÷ɻ�ģ��

    //��ʼ���ɻ�����
    m_x=GAME_WIDTH*0.5-m_hero.width()+50;
    m_y=GAME_HEIGHT*0.5-m_hero.height()+300;

    //��ʼ�����α߿�
    m_rect.setWidth(m_hero.width());
    m_rect.setHeight(m_hero.height());
    //�ƶ�
    m_rect.moveTo(m_x,m_y);

    hero_free=false;
    //��ʼ���ӵ���¼���
    m_recorder=0;
    m_recorder1=0;
   }

void HeroPlane::shoot()
{
    //�ۼ�ʱ������¼����
    m_recorder++;
    //�����¼������δ�ﵽ�ӵ�����ļ��
    if(m_recorder<BULLET_INTERVAL)
    {
        return;//������
    }
    m_recorder=0;
    //�����ӵ�
    for(int i=0;i<BULLET_NUM;i++)
    {
        //����ӵ����� ����
        if(m_bullets[i].bullet_Free)
        {
            //������״̬��Ϊ��
            m_bullets[i].bullet_Free=false;
            //�����ӵ�����
            m_bullets[i].bullet_X=m_x+m_rect.width()*0.5-10;
            m_bullets[i].bullet_Y=m_y-25;
            break;
        }
    }


}
void HeroPlane::shoot1()
{
    //�ۼ�ʱ������¼����
    m_recorder1++;
    //�����¼������δ�ﵽ�ӵ�����ļ��
    if(m_recorder1<BULLET_INTERVAL)
    {
        return;//������
    }
    m_recorder1=0;
    //�����ӵ�
    for(int q=0;q<BULLET_NUM;q++)
    {
        //����ӵ����� ����
        if(m_bullets1[q].bullet_Free1)
        {
            //������״̬��Ϊ��
            m_bullets1[q].bullet_Free1=false;
            //�����ӵ�����
            m_bullets1[q].bullet_X1=m_x;
            m_bullets1[q].bullet_Y1=m_y+25;
            break;
        }
    }

}
//�ɻ�λ��ʱʱ�ı�
   void HeroPlane::setPlanePosition(int x, int y)
   {
       m_x=x;
       m_y=y;

       m_rect.moveTo(m_x,m_y);

}
