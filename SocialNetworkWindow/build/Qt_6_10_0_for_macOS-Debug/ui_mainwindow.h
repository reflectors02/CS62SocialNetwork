/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *login_textEdit;
    QPushButton *login_Button;
    QLabel *login_label;
    QLabel *display_label;
    QTableWidget *display_table_friends;
    QTableWidget *display_table_posts;
    QPushButton *display_returnButton;
    QPushButton *display_addFriendButton;
    QTableWidget *display_suggestFriendsTable;
    QTextEdit *display_postTextInput;
    QPushButton *display_postButton;
    QLabel *display_recommendedLabel;
    QLabel *display_friendsLabel;
    QPushButton *admin_ban;
    QPushButton *admin_unbanButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setEnabled(true);
        login_textEdit = new QTextEdit(centralwidget);
        login_textEdit->setObjectName("login_textEdit");
        login_textEdit->setGeometry(QRect(710, 190, 361, 71));
        login_Button = new QPushButton(centralwidget);
        login_Button->setObjectName("login_Button");
        login_Button->setGeometry(QRect(1070, 190, 111, 71));
        login_label = new QLabel(centralwidget);
        login_label->setObjectName("login_label");
        login_label->setGeometry(QRect(710, 140, 351, 31));
        display_label = new QLabel(centralwidget);
        display_label->setObjectName("display_label");
        display_label->setEnabled(true);
        display_label->setGeometry(QRect(840, 10, 281, 16));
        display_table_friends = new QTableWidget(centralwidget);
        display_table_friends->setObjectName("display_table_friends");
        display_table_friends->setGeometry(QRect(330, 330, 256, 192));
        display_table_posts = new QTableWidget(centralwidget);
        display_table_posts->setObjectName("display_table_posts");
        display_table_posts->setGeometry(QRect(620, 330, 961, 192));
        display_returnButton = new QPushButton(centralwidget);
        display_returnButton->setObjectName("display_returnButton");
        display_returnButton->setGeometry(QRect(1250, 530, 100, 32));
        display_addFriendButton = new QPushButton(centralwidget);
        display_addFriendButton->setObjectName("display_addFriendButton");
        display_addFriendButton->setGeometry(QRect(730, 10, 100, 32));
        display_suggestFriendsTable = new QTableWidget(centralwidget);
        display_suggestFriendsTable->setObjectName("display_suggestFriendsTable");
        display_suggestFriendsTable->setGeometry(QRect(330, 80, 256, 192));
        display_postTextInput = new QTextEdit(centralwidget);
        display_postTextInput->setObjectName("display_postTextInput");
        display_postTextInput->setGeometry(QRect(1100, 250, 104, 71));
        display_postButton = new QPushButton(centralwidget);
        display_postButton->setObjectName("display_postButton");
        display_postButton->setGeometry(QRect(1210, 240, 121, 81));
        display_recommendedLabel = new QLabel(centralwidget);
        display_recommendedLabel->setObjectName("display_recommendedLabel");
        display_recommendedLabel->setGeometry(QRect(340, 50, 141, 20));
        display_friendsLabel = new QLabel(centralwidget);
        display_friendsLabel->setObjectName("display_friendsLabel");
        display_friendsLabel->setGeometry(QRect(350, 290, 58, 16));
        admin_ban = new QPushButton(centralwidget);
        admin_ban->setObjectName("admin_ban");
        admin_ban->setGeometry(QRect(340, 650, 100, 32));
        admin_unbanButton = new QPushButton(centralwidget);
        admin_unbanButton->setObjectName("admin_unbanButton");
        admin_unbanButton->setGeometry(QRect(480, 650, 100, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 37));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        login_Button->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        login_label->setText(QCoreApplication::translate("MainWindow", "Enter your name", nullptr));
        display_label->setText(QCoreApplication::translate("MainWindow", "Display Label", nullptr));
        display_returnButton->setText(QCoreApplication::translate("MainWindow", "Return", nullptr));
        display_addFriendButton->setText(QCoreApplication::translate("MainWindow", "Add Friend", nullptr));
        display_postButton->setText(QCoreApplication::translate("MainWindow", "Post!", nullptr));
        display_recommendedLabel->setText(QCoreApplication::translate("MainWindow", "Recommended", nullptr));
        display_friendsLabel->setText(QCoreApplication::translate("MainWindow", "friends", nullptr));
        admin_ban->setText(QCoreApplication::translate("MainWindow", "Ban", nullptr));
        admin_unbanButton->setText(QCoreApplication::translate("MainWindow", "Unban", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
