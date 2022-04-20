#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include<QPixmap>
#include"config.h"
#include<QVector>

class EnemyPlane
{
public:
    EnemyPlane();

    //更新坐标
    void updateEnemyPosition();

    //敌机资源对象
    QPixmap m_enemy;

    //位置
    int enemy_x;
    int enemy_y;



    //敌机矩形边框
    QRect enemy_rect;

    //是否空闲
    bool enemy_free;

    //敌机速度
    int enemy_speed;


};

#endif // ENEMYPLANE_H

