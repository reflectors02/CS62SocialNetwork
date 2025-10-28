#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "network.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H


class SocialNetworkWindow : public MainWindow
{
public:
    SocialNetworkWindow(char* users, char* posts);

    void setLoggedUser(User* logged);

    void setDisplayedUser(User* displayed);

    void onLoginButton();

    void hideLoginWindow();

    void hideDisplayWindow();



    void showDisplayWindow(User* user);

    void display_setupFriendSuggestionTable(User* user);

    void display_setupFriendTable(User* user);

    void display_setupPostTable(User* user);




    void onfriendTableClicked(int r, int c);

    void onReturnButtonClicked();

    void onFriendAddButtonClicked();

    void updateFiles();

    void onRecommendedFriendClicked(int r, int c);

    void onPostButtonClicked();

private:
    Network network;
    User* logged_User;
    User* displayed_User;
    Ui::MainWindow *ui;

};
