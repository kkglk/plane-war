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
#include<QMutex>  //暂停
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
    //地图对象
     Map m_map;
private:
    Ui::Widget *ui;
    QTimer m_Timer;
protected:
    //启动游戏  用于启动定时器对象
    void playGame();
    //更新坐标
    void updatePosition();
    //绘图事件
    void paintEvent(QPaintEvent *);
    //飞机
    HeroPlane m_hero;
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *event);
    //zhidan 测试
    //Bullet temp_Bullet;

    //敌机出场
      void enemyToscreen();
    //敌机数组
     EnemyPlane m_enemies[ENEMY_NUM];
    //敌军出场间隔
     int enemy_recorder;

     //碰撞检测
     void collisionDetection();

     //爆炸数组
     Bomb m_bombs[BOMB_NUM];

//     MyThread *thread;


};
#endif // WIDGET_H
