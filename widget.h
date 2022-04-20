#ifndef WIDGET_H
#define WIDGET_H
#include"bomb.h"
#include <QWidget>
#include"config.h"
#include<QIcon>
#include<QTimer>
#include<QPaintEvent>
#include"map.h"
#include<QPainter>
#include<QMouseEvent>
#include<QMessageBox>
#include<QMutex>  //��ͣ
#include<QThread>
#include<QDebug>
#include"heroplane.h"
#include"bullet.h"
#include"enemyplane.h"
#include <QSoundEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //��ͼ����
     Map m_map;
private:
    Ui::Widget *ui;
    QTimer m_Timer;
protected:
    //������Ϸ  ����������ʱ������
    void playGame();
    //��������
    void updatePosition();
    //��ͼ�¼�
    void paintEvent(QPaintEvent *);
    //�ɻ�
    HeroPlane m_hero;
    //����ƶ�
    void mouseMoveEvent(QMouseEvent *event);
    //zhidan ����
    //Bullet temp_Bullet;

    //�л�����
      void enemyToscreen();
    //�л�����
     EnemyPlane m_enemies[ENEMY_NUM];
    //�о��������
     int enemy_recorder;

     //��ײ���
     void collisionDetection();

     //��ը����
     Bomb m_bombs[BOMB_NUM];

//     MyThread *thread;


};
#endif // WIDGET_H
