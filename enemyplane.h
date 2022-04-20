#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include<QPixmap>
#include"config.h"
#include<QVector>

class EnemyPlane
{
public:
    EnemyPlane();

    //��������
    void updateEnemyPosition();

    //�л���Դ����
    QPixmap m_enemy;

    //λ��
    int enemy_x;
    int enemy_y;



    //�л����α߿�
    QRect enemy_rect;

    //�Ƿ����
    bool enemy_free;

    //�л��ٶ�
    int enemy_speed;


};

#endif // ENEMYPLANE_H

