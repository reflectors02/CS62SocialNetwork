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
    QPushButton *admin_banButton;
    QPushButton *admin_unbanButton;
    QPushButton *admin_addAdminButton;
    QPushButton *admin_removeAdminButton;
    QPushButton *display_logoutButton;
    QPushButton *display_removeFriend;
    QTableWidget *display_table_Users;
    QLabel *display_allUserLabel;
    QPushButton *display_goToUserButton;
    QTextEdit *display_goToUserTextField;
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
        display_table_friends->setGeometry(QRect(330, 330, 261, 261));
        display_table_posts = new QTableWidget(centralwidget);
        display_table_posts->setObjectName("display_table_posts");
        display_table_posts->setGeometry(QRect(620, 80, 981, 391));
        display_returnButton = new QPushButton(centralwidget);
        display_returnButton->setObjectName("display_returnButton");
        display_returnButton->setGeometry(QRect(970, 10, 100, 32));
        display_addFriendButton = new QPushButton(centralwidget);
        display_addFriendButton->setObjectName("display_addFriendButton");
        display_addFriendButton->setGeometry(QRect(670, 0, 100, 32));
        display_suggestFriendsTable = new QTableWidget(centralwidget);
        display_suggestFriendsTable->setObjectName("display_suggestFriendsTable");
        display_suggestFriendsTable->setGeometry(QRect(330, 80, 261, 211));
        display_postTextInput = new QTextEdit(centralwidget);
        display_postTextInput->setObjectName("display_postTextInput");
        display_postTextInput->setGeometry(QRect(620, 500, 851, 91));
        display_postButton = new QPushButton(centralwidget);
        display_postButton->setObjectName("display_postButton");
        display_postButton->setGeometry(QRect(1480, 500, 121, 91));
        display_recommendedLabel = new QLabel(centralwidget);
        display_recommendedLabel->setObjectName("display_recommendedLabel");
        display_recommendedLabel->setGeometry(QRect(340, 50, 141, 20));
        display_friendsLabel = new QLabel(centralwidget);
        display_friendsLabel->setObjectName("display_friendsLabel");
        display_friendsLabel->setGeometry(QRect(340, 310, 58, 16));
        admin_banButton = new QPushButton(centralwidget);
        admin_banButton->setObjectName("admin_banButton");
        admin_banButton->setGeometry(QRect(1660, 910, 100, 32));
        admin_unbanButton = new QPushButton(centralwidget);
        admin_unbanButton->setObjectName("admin_unbanButton");
        admin_unbanButton->setGeometry(QRect(1800, 910, 100, 32));
        admin_addAdminButton = new QPushButton(centralwidget);
        admin_addAdminButton->setObjectName("admin_addAdminButton");
        admin_addAdminButton->setGeometry(QRect(1660, 970, 100, 32));
        admin_removeAdminButton = new QPushButton(centralwidget);
        admin_removeAdminButton->setObjectName("admin_removeAdminButton");
        admin_removeAdminButton->setGeometry(QRect(1800, 970, 100, 32));
        display_logoutButton = new QPushButton(centralwidget);
        display_logoutButton->setObjectName("display_logoutButton");
        display_logoutButton->setGeometry(QRect(1280, 20, 100, 32));
        display_removeFriend = new QPushButton(centralwidget);
        display_removeFriend->setObjectName("display_removeFriend");
        display_removeFriend->setGeometry(QRect(670, 40, 100, 32));
        display_table_Users = new QTableWidget(centralwidget);
        display_table_Users->setObjectName("display_table_Users");
        display_table_Users->setGeometry(QRect(30, 80, 256, 511));
        display_allUserLabel = new QLabel(centralwidget);
        display_allUserLabel->setObjectName("display_allUserLabel");
        display_allUserLabel->setGeometry(QRect(30, 60, 58, 16));
        display_goToUserButton = new QPushButton(centralwidget);
        display_goToUserButton->setObjectName("display_goToUserButton");
        display_goToUserButton->setGeometry(QRect(210, 590, 71, 71));
        display_goToUserTextField = new QTextEdit(centralwidget);
        display_goToUserTextField->setObjectName("display_goToUserTextField");
        display_goToUserTextField->setGeometry(QRect(30, 590, 181, 71));
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
        display_postTextInput->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Post here</p></body></html>", nullptr));
        display_postButton->setText(QCoreApplication::translate("MainWindow", "Post!", nullptr));
        display_recommendedLabel->setText(QCoreApplication::translate("MainWindow", "Recommended", nullptr));
        display_friendsLabel->setText(QCoreApplication::translate("MainWindow", "friends", nullptr));
        admin_banButton->setText(QCoreApplication::translate("MainWindow", "Ban", nullptr));
        admin_unbanButton->setText(QCoreApplication::translate("MainWindow", "Unban", nullptr));
        admin_addAdminButton->setText(QCoreApplication::translate("MainWindow", "AddAdmin", nullptr));
        admin_removeAdminButton->setText(QCoreApplication::translate("MainWindow", "removeAdmin", nullptr));
        display_logoutButton->setText(QCoreApplication::translate("MainWindow", "LogOut", nullptr));
        display_removeFriend->setText(QCoreApplication::translate("MainWindow", "Remove Friend", nullptr));
        display_allUserLabel->setText(QCoreApplication::translate("MainWindow", "All Users", nullptr));
        display_goToUserButton->setText(QCoreApplication::translate("MainWindow", "Go", nullptr));
        display_goToUserTextField->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Type user here</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
