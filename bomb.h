#ifndef BOMB_H
#define BOMB_H
#include<QVector>
#include<QPixmap>
#include"config.h"


class Bomb
{
public:
    Bomb();

    void updateInfo();//������Ϣ

    //�ű�ը��Դ����
    QVector<QPixmap>m_PixArr;

    //��ըλ��
    int Bomb_x;
    int Bomb_y;

    //��ը״̬
    bool Bomb_Free;

    //��ըʱ����
    int Bomb_Recorder;

    //��ըʱ���ص�ͼƬ�±�
    int bombing_index;
};

#endif // BOMB_H

