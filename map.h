#ifndef MAP_H
#define MAP_H
#include <QPixmap>
#include <QWidget>

class Map
{
public:
    //���캯��
    Map();

    //��ͼ�����������
    void mapPosition();

    //��ͼͼƬ����
    QPixmap m_map1;
    QPixmap m_map2;

    //��ͼY������
    int m_map1_posY;
    int m_map2_posY;

    //��ͼ��������
    int m_scroll_speed;
};

#endif // MAP_H


