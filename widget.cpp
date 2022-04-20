#include "widget.h"
#include"enemyplane.h"
#include<QTime>
#include<QSoundEffect>
#include "ui_widget.h"
#include "config.h"
#include<QIcon>
#include"map.h"
#include<QPainter>
#include<QMouseEvent>
#include"heroplane.h"
#include"bullet.h"
#include<ctime>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    setWindowTitle(GAME_TITLE);


    //设置图标资源
    setWindowIcon(QIcon(GAME_ICON));

    //定时器设置
    m_Timer.setInterval(GAME_RATE);
    //启动定时器并不断刷新图片
    playGame();

    //敌军出场间隔
    enemy_recorder = 0;

    //随机数种子
    srand((unsigned int)time(NULL));

    //音乐
    QSoundEffect *sound =new QSoundEffect(this);
    sound->setSource(QUrl::fromLocalFile(SUOND_BACKGROUND));
    sound->setVolume(0.3f);
    sound->play();


}

Widget::~Widget()
{
    delete ui;
}
void Widget::playGame()
{
    //启动定时器
    m_Timer.start();

    //背景音乐
//     QSoundEffect::play(SUOND_BACKGROUND);

    //监听定时器
    connect(&m_Timer,&QTimer::timeout,[=]()
    {
        //敌机出场
        enemyToscreen();
        //更新游戏中元素的坐标
        updatePosition();
        //重新绘制图片
        update();//或repaint（）

        //碰撞检测
        collisionDetection();

    });

}
//更新游戏中元素的坐标，为绘制做准备
void Widget::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();

    //发射子弹
      m_hero.shoot();
      //计算所有非空闲子弹坐标
      for(int i=0;i<BULLET_NUM;i++)
      {
          //如果非空闲 计算发射位置
          if(m_hero.m_bullets[i].bullet_Free==false)
          {
              m_hero.m_bullets[i].updateBulletPosition();
          }
      }
      //发射子弹2
      m_hero.shoot1();
      //计算所有非空闲子弹坐标2
      for(int z=0;z<BULLET_NUM1;z++)
      {
          //如果非空闲 计算发射位置
          if(m_hero.m_bullets1[z].bullet_Free1==false)
          {
              m_hero.m_bullets1[z].updateBulletPosition1();

          }
      }
      //敌机
      for(int i=0;i<ENEMY_NUM;i++)
      {
          if(m_enemies[i].enemy_free==false)
          {
              m_enemies[i].updateEnemyPosition();
          }
      }
      //爆炸图片计算
      for(int i=0;i<BOMB_NUM;i++)
      {
          if(m_bombs[i].Bomb_Free==false)
          {
              m_bombs[i].updateInfo();
          }
      }

}
//绘制函数
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    //1 painter.drawPixmap(0,0,QPixmap(MAP_PATH));
    painter.drawPixmap(0,m_map.m_map1_posY , m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY , m_map.m_map2);
    //飞机
    painter.drawPixmap(m_hero.m_x,m_hero.m_y,m_hero.m_hero);

   // 测试子弹
   // painter.drawPixmap(temp_Bullet.m_X,temp_Bullet.m_Y,temp_Bullet.m_Bullet);

    //绘制子弹
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果非空闲 绘制
        if(m_hero.m_bullets[i].bullet_Free==false)
        {
            painter.drawPixmap(m_hero.m_bullets[i].bullet_X,
                               m_hero.m_bullets[i].bullet_Y,
                               m_hero.m_bullets[i].m_Bullet);
        }
    }

    //绘制子弹2
    for(int a=0;a<BULLET_NUM;a++)
    {
        //如果非空闲 绘制
        if(m_hero.m_bullets1[a].bullet_Free1==false)
        {
            painter.drawPixmap(m_hero.m_bullets1[a].bullet_X1,
                               m_hero.m_bullets1[a].bullet_Y1,
                               m_hero.m_bullets1[a].m_Bullet1);
        }
    }

    //绘制敌机
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //如果非空闲 绘制
        if(m_enemies[i].enemy_free==false)
        {
            painter.drawPixmap(m_enemies[i].enemy_x,
                               m_enemies[i].enemy_y,
                               m_enemies[i].m_enemy);
        }
    }

    //爆炸的绘制
    for(int i=0;i<BOMB_NUM;i++)
    {
        //如果非空闲 绘制
        if(m_bombs[i].Bomb_Free==false)
        {
            painter.drawPixmap(m_bombs[i].Bomb_x,
                               m_bombs[i].Bomb_y,
                               m_bombs[i].m_PixArr[m_bombs[i].bombing_index]);
        }
    }


 }
//飞机的移动
void Widget::mouseMoveEvent(QMouseEvent *event)
{

    int x,y;
    x=event->x() -m_hero.m_rect.width()*0.5 ; //乘0.5是为了让鼠标在飞机移动的中心
    y=event->y() -m_hero.m_rect.height()*0.5 ;



    //边界检测
    if(x<=0)
    {
        x=0;
    }
    if(x>=GAME_WIDTH-m_hero.m_rect.width())
    {
        x=GAME_WIDTH-m_hero.m_rect.width();
    }
    if(y<=0)
    {
        y=0;
    }
    if(y>=GAME_HEIGHT-m_hero.m_rect.height())
    {
        y=GAME_HEIGHT-m_hero.m_rect.height();
    }

    m_hero.setPlanePosition(x,y);

}

//敌机出场
   void Widget::enemyToscreen()
    {
       //累加出场间隔
       enemy_recorder++;
       if(enemy_recorder<ENEMY_INTERVAL)
       {
           return;
       }
       enemy_recorder=0;
       for(int i=0;i<ENEMY_NUM;i++)
       {
           if(m_enemies[i].enemy_free)
           {
               m_enemies[i].enemy_free=false;

               //坐标
               m_enemies[i].enemy_x=rand() %( GAME_WIDTH -m_enemies[i].enemy_rect.width());
               m_enemies[i].enemy_y=-m_enemies[i].enemy_rect.height();
               break;
           }
       }

   }
//碰撞检测
   void Widget::collisionDetection()
   {
       //遍历所有非空闲的敌机
       for(int i=0;i<ENEMY_NUM;i++)
       {
           if(m_enemies[i].enemy_free)
           {
               continue;//空闲飞机 跳转到下一次循环
           }
           //子弹1的碰撞检测和飞机与敌机的
           for(int k=0;k<BULLET_NUM;k++)
           {
               if(m_hero.m_bullets[k].bullet_Free)
               {
                   continue;
               }

               //如果子弹框和敌机框相交
               if(m_enemies[i].enemy_rect.intersects(m_hero.m_bullets[k].bullet_Rect))
               {
                   m_enemies[i].enemy_free=true;
                   m_hero.m_bullets[k].bullet_Free=true;

                   //爆炸
                   for(int b=0;b<BOMB_NUM;b++)
                   {
                       m_bombs[b].Bomb_Free =false;
                       m_bombs[b].Bomb_x=m_enemies[i].enemy_x;
                       m_bombs[b].Bomb_y=m_enemies[i].enemy_y;
                       break;

                   }
                   //爆炸音效
                   QSoundEffect *bomb =new QSoundEffect(this);
                   bomb->setSource(QUrl::fromLocalFile(SOUND_BOMB));
                   bomb->setLoopCount(1);
                   bomb->setVolume(0.9f);
                   bomb->play();
               }

           }


           //子弹2的碰撞检测
           for(int x=0;x<BULLET_NUM1;x++)
           {
               if(m_hero.m_bullets[x].bullet_Free)
               {
                   continue;
               }

               //如果子弹框和敌机框相交
               if(m_enemies[i].enemy_rect.intersects(m_hero.m_bullets1[x].bullet_Rect1))
               {
                   m_enemies[i].enemy_free=true;
                   m_hero.m_bullets1[x].bullet_Free1=true;

                   //爆炸
                   for(int b=0;b<BOMB_NUM;b++)
                   {
                       m_bombs[b].Bomb_Free =false;
                       m_bombs[b].Bomb_x=m_enemies[i].enemy_x;
                       m_bombs[b].Bomb_y=m_enemies[i].enemy_y;
                       break;

                   }
                   //爆炸音效
                   QSoundEffect *bomb =new QSoundEffect(this);
                   bomb->setSource(QUrl::fromLocalFile(SOUND_BOMB));
                   bomb->setLoopCount(1);
                   bomb->setVolume(0.9f);
                   bomb->play();

               }
           }


       }
   }

