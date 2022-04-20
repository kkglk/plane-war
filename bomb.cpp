#include "bomb.h"
#include<QDebug>
Bomb::Bomb()
{
    //将所有爆炸pixmap放入数组中
    for(int i=1;i<=BOMB_MAX;i++)
    {
        QString str=QString(BOMB_PATH).arg(i);
        m_PixArr.push_back(QPixmap(str));
    }

    //坐标
    Bomb_x=0;
    Bomb_y=0;
    //初始化空闲状态
    Bomb_Free=true;
    //当前播放图片下标
    bombing_index=0;
    //爆炸间隔记录
    Bomb_Recorder=0;
}

void Bomb::updateInfo()
{
    //空闲状态下的爆炸效果直接return
    if(Bomb_Free)
    {
        return;
    }
    //爆炸间隔记录
    Bomb_Recorder++;

    if(Bomb_Recorder<BOMB_INTERVAL)
    {
        return;   //未到，直接return，不切图
    }
    //重置记录
    Bomb_Recorder=0;

    bombing_index++;//切换爆炸显示图片下标

    if(bombing_index>BOMB_MAX-1)//数组下标从0开始计算
    {
        bombing_index=0;
        Bomb_Free=true;
    }
}

