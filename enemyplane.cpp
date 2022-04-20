#include "enemyplane.h"
#include"config.h"
//#include"startgame.h"
#include<QDebug>
EnemyPlane::EnemyPlane()
{
//    StartGame *str;
//    str=new StartGame();
    m_enemy.load(ENEMY_PATH);

    //敌机位置
    enemy_x=0;
    enemy_y=0;

    //敌机状态
    enemy_free=true;

    //敌机速度
    enemy_speed=ENEMY_SPEED;

    //敌机矩形
    enemy_rect.setWidth(m_enemy.width());
    enemy_rect.setHeight(m_enemy.height());
    enemy_rect.moveTo(enemy_x,enemy_y);
}

void EnemyPlane::updateEnemyPosition()
{
    //空闲敌机 不计算坐标
    if(enemy_free)
    {
        return;
    }

    enemy_y+=enemy_speed;
    enemy_rect.moveTo(enemy_x,enemy_y);

    //如果超出屏幕
    if(enemy_y>GAME_HEIGHT)
    {
        enemy_free=true;
    }
}

