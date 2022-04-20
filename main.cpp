#include "widget.h"

#include<QResource>
#include"config.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //注册外部的二进制资源文件
    QResource::registerResource(GAME_RES_PATH);

    Widget w;
    w.show();
    return a.exec();
}
