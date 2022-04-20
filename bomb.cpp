#include "bomb.h"
#include<QDebug>
Bomb::Bomb()
{
    //�����б�ըpixmap����������
    for(int i=1;i<=BOMB_MAX;i++)
    {
        QString str=QString(BOMB_PATH).arg(i);
        m_PixArr.push_back(QPixmap(str));
    }

    //����
    Bomb_x=0;
    Bomb_y=0;
    //��ʼ������״̬
    Bomb_Free=true;
    //��ǰ����ͼƬ�±�
    bombing_index=0;
    //��ը�����¼
    Bomb_Recorder=0;
}

void Bomb::updateInfo()
{
    //����״̬�µı�ըЧ��ֱ��return
    if(Bomb_Free)
    {
        return;
    }
    //��ը�����¼
    Bomb_Recorder++;

    if(Bomb_Recorder<BOMB_INTERVAL)
    {
        return;   //δ����ֱ��return������ͼ
    }
    //���ü�¼
    Bomb_Recorder=0;

    bombing_index++;//�л���ը��ʾͼƬ�±�

    if(bombing_index>BOMB_MAX-1)//�����±��0��ʼ����
    {
        bombing_index=0;
        Bomb_Free=true;
    }
}

