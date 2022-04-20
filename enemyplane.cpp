#include "enemyplane.h"
#include"config.h"
//#include"startgame.h"
#include<QDebug>
EnemyPlane::EnemyPlane()
{
//    StartGame *str;
//    str=new StartGame();
    m_enemy.load(ENEMY_PATH);

    //�л�λ��
    enemy_x=0;
    enemy_y=0;

    //�л�״̬
    enemy_free=true;

    //�л��ٶ�
    enemy_speed=ENEMY_SPEED;

    //�л�����
    enemy_rect.setWidth(m_enemy.width());
    enemy_rect.setHeight(m_enemy.height());
    enemy_rect.moveTo(enemy_x,enemy_y);
}

void EnemyPlane::updateEnemyPosition()
{
    //���ел� ����������
    if(enemy_free)
    {
        return;
    }

    enemy_y+=enemy_speed;
    enemy_rect.moveTo(enemy_x,enemy_y);

    //���������Ļ
    if(enemy_y>GAME_HEIGHT)
    {
        enemy_free=true;
    }
}

