#ifndef BOMB_H
#define BOMB_H
#include<QVector>
#include<QPixmap>
#include"config.h"


class Bomb
{
public:
    Bomb();

    void updateInfo();//更新信息

    //放爆炸资源数组
    QVector<QPixmap>m_PixArr;

    //爆炸位置
    int Bomb_x;
    int Bomb_y;

    //爆炸状态
    bool Bomb_Free;

    //爆炸时间间隔
    int Bomb_Recorder;

    //爆炸时加载的图片下标
    int bombing_index;
};

#endif // BOMB_H

