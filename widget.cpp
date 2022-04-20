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


    //����ͼ����Դ
    setWindowIcon(QIcon(GAME_ICON));

    //��ʱ������
    m_Timer.setInterval(GAME_RATE);
    //������ʱ��������ˢ��ͼƬ
    playGame();

    //�о��������
    enemy_recorder = 0;

    //���������
    srand((unsigned int)time(NULL));

    //����
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
    //������ʱ��
    m_Timer.start();

    //��������
//     QSoundEffect::play(SUOND_BACKGROUND);

    //������ʱ��
    connect(&m_Timer,&QTimer::timeout,[=]()
    {
        //�л�����
        enemyToscreen();
        //������Ϸ��Ԫ�ص�����
        updatePosition();
        //���»���ͼƬ
        update();//��repaint����

        //��ײ���
        collisionDetection();

    });

}
//������Ϸ��Ԫ�ص����꣬Ϊ������׼��
void Widget::updatePosition()
{
    //���µ�ͼ����
    m_map.mapPosition();

    //�����ӵ�
      m_hero.shoot();
      //�������зǿ����ӵ�����
      for(int i=0;i<BULLET_NUM;i++)
      {
          //����ǿ��� ���㷢��λ��
          if(m_hero.m_bullets[i].bullet_Free==false)
          {
              m_hero.m_bullets[i].updateBulletPosition();
          }
      }
      //�����ӵ�2
      m_hero.shoot1();
      //�������зǿ����ӵ�����2
      for(int z=0;z<BULLET_NUM1;z++)
      {
          //����ǿ��� ���㷢��λ��
          if(m_hero.m_bullets1[z].bullet_Free1==false)
          {
              m_hero.m_bullets1[z].updateBulletPosition1();

          }
      }
      //�л�
      for(int i=0;i<ENEMY_NUM;i++)
      {
          if(m_enemies[i].enemy_free==false)
          {
              m_enemies[i].updateEnemyPosition();
          }
      }
      //��ըͼƬ����
      for(int i=0;i<BOMB_NUM;i++)
      {
          if(m_bombs[i].Bomb_Free==false)
          {
              m_bombs[i].updateInfo();
          }
      }

}
//���ƺ���
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //���Ƶ�ͼ
    //1 painter.drawPixmap(0,0,QPixmap(MAP_PATH));
    painter.drawPixmap(0,m_map.m_map1_posY , m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY , m_map.m_map2);
    //�ɻ�
    painter.drawPixmap(m_hero.m_x,m_hero.m_y,m_hero.m_hero);

   // �����ӵ�
   // painter.drawPixmap(temp_Bullet.m_X,temp_Bullet.m_Y,temp_Bullet.m_Bullet);

    //�����ӵ�
    for(int i=0;i<BULLET_NUM;i++)
    {
        //����ǿ��� ����
        if(m_hero.m_bullets[i].bullet_Free==false)
        {
            painter.drawPixmap(m_hero.m_bullets[i].bullet_X,
                               m_hero.m_bullets[i].bullet_Y,
                               m_hero.m_bullets[i].m_Bullet);
        }
    }

    //�����ӵ�2
    for(int a=0;a<BULLET_NUM;a++)
    {
        //����ǿ��� ����
        if(m_hero.m_bullets1[a].bullet_Free1==false)
        {
            painter.drawPixmap(m_hero.m_bullets1[a].bullet_X1,
                               m_hero.m_bullets1[a].bullet_Y1,
                               m_hero.m_bullets1[a].m_Bullet1);
        }
    }

    //���Ƶл�
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //����ǿ��� ����
        if(m_enemies[i].enemy_free==false)
        {
            painter.drawPixmap(m_enemies[i].enemy_x,
                               m_enemies[i].enemy_y,
                               m_enemies[i].m_enemy);
        }
    }

    //��ը�Ļ���
    for(int i=0;i<BOMB_NUM;i++)
    {
        //����ǿ��� ����
        if(m_bombs[i].Bomb_Free==false)
        {
            painter.drawPixmap(m_bombs[i].Bomb_x,
                               m_bombs[i].Bomb_y,
                               m_bombs[i].m_PixArr[m_bombs[i].bombing_index]);
        }
    }


 }
//�ɻ����ƶ�
void Widget::mouseMoveEvent(QMouseEvent *event)
{

    int x,y;
    x=event->x() -m_hero.m_rect.width()*0.5 ; //��0.5��Ϊ��������ڷɻ��ƶ�������
    y=event->y() -m_hero.m_rect.height()*0.5 ;



    //�߽���
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

//�л�����
   void Widget::enemyToscreen()
    {
       //�ۼӳ������
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

               //����
               m_enemies[i].enemy_x=rand() %( GAME_WIDTH -m_enemies[i].enemy_rect.width());
               m_enemies[i].enemy_y=-m_enemies[i].enemy_rect.height();
               break;
           }
       }

   }
//��ײ���
   void Widget::collisionDetection()
   {
       //�������зǿ��еĵл�
       for(int i=0;i<ENEMY_NUM;i++)
       {
           if(m_enemies[i].enemy_free)
           {
               continue;//���зɻ� ��ת����һ��ѭ��
           }
           //�ӵ�1����ײ���ͷɻ���л���
           for(int k=0;k<BULLET_NUM;k++)
           {
               if(m_hero.m_bullets[k].bullet_Free)
               {
                   continue;
               }

               //����ӵ���͵л����ཻ
               if(m_enemies[i].enemy_rect.intersects(m_hero.m_bullets[k].bullet_Rect))
               {
                   m_enemies[i].enemy_free=true;
                   m_hero.m_bullets[k].bullet_Free=true;

                   //��ը
                   for(int b=0;b<BOMB_NUM;b++)
                   {
                       m_bombs[b].Bomb_Free =false;
                       m_bombs[b].Bomb_x=m_enemies[i].enemy_x;
                       m_bombs[b].Bomb_y=m_enemies[i].enemy_y;
                       break;

                   }
                   //��ը��Ч
                   QSoundEffect *bomb =new QSoundEffect(this);
                   bomb->setSource(QUrl::fromLocalFile(SOUND_BOMB));
                   bomb->setLoopCount(1);
                   bomb->setVolume(0.9f);
                   bomb->play();
               }

           }


           //�ӵ�2����ײ���
           for(int x=0;x<BULLET_NUM1;x++)
           {
               if(m_hero.m_bullets[x].bullet_Free)
               {
                   continue;
               }

               //����ӵ���͵л����ཻ
               if(m_enemies[i].enemy_rect.intersects(m_hero.m_bullets1[x].bullet_Rect1))
               {
                   m_enemies[i].enemy_free=true;
                   m_hero.m_bullets1[x].bullet_Free1=true;

                   //��ը
                   for(int b=0;b<BOMB_NUM;b++)
                   {
                       m_bombs[b].Bomb_Free =false;
                       m_bombs[b].Bomb_x=m_enemies[i].enemy_x;
                       m_bombs[b].Bomb_y=m_enemies[i].enemy_y;
                       break;

                   }
                   //��ը��Ч
                   QSoundEffect *bomb =new QSoundEffect(this);
                   bomb->setSource(QUrl::fromLocalFile(SOUND_BOMB));
                   bomb->setLoopCount(1);
                   bomb->setVolume(0.9f);
                   bomb->play();

               }
           }


       }
   }

