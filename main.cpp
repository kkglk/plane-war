#include "widget.h"

#include<QResource>
#include"config.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //ע���ⲿ�Ķ�������Դ�ļ�
    QResource::registerResource(GAME_RES_PATH);

    Widget w;
    w.show();
    return a.exec();
}
