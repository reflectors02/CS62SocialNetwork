#include "mainwindow.h"
#include <QDir>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDir::setCurrent("/Users/hankang/Desktop/cs/cs62/HW/");



    SocialNetworkWindow w("users.txt", "posts.txt");
    w.show();

    return a.exec();
}
