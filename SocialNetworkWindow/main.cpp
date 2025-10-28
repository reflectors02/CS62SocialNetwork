#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SocialNetworkWindow w("users.txt", "posts.txt");
    w.show();
    return a.exec();
}
