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
    //pre:
    //post: A new SocialNetworkWindow is created. users and posts will be initialized into a network
    SocialNetworkWindow(char* users, char* posts);

    //pre: A user object is passed in
    //post: The logged_User is set to this user
    void setLoggedUser(User* logged);

    //pre: A user object is passed in
    //post: the displayed_User is set to this user
    void setDisplayedUser(User* displayed);

    //pre: display_loginButton is clicked
    //post: Logged_User becomes the logged user and taken to display screen
    void onLoginButton();

    //pre:
    //post: hides the admin panel
    void hideAdminPanel();

    //pre:
    //post: hides loginWindow
    void hideLoginWindow();

    //pre:
    //post: loginWindow is now shown
    void showLoginWindow();

    //pre:
    //post: hides the display window
    void hideDisplayWindow();

    //pre:
    //post: show the admin panel
    void showAdminPanel();

    void showAmadeus();

    void hideAmadeus();

    //pre: A user is passed in
    //post: If the user is part of adminUsers, then display the adminPanel
    //      if not, then hide it
    void setupAdminPanel(User* user);


    //pre:
    //post: login screen is shown, and everything else should be hidden
    //      Additionally, displayed_User and logged_User should reset to nullptr
    void onLogoutButton();


    //pre:  user is passed in
    //post: user of interest is now the displayed_User, and every widget should display the user of interest's
    void showDisplayWindow(User* user);

    //The following are Helper functions for showDisplayWindow(User* user)
    void display_setupFriendSuggestionTable(User* user);

    void display_setupFriendTable(User* user);

    void display_setupPostTable(User* user);

    void display_setupUserTable();

    //pre: The user clicked on a cell in the ALL users table
    //post: displayed User is now the clicked user's profile
    void onAllUserTableClicked(int r, int c);

    //pre: the user double clicked on a cell on the friend Table
    //post: Gets taken to the friend's page.
    void onfriendTableClicked(int r, int c);

    //pre: The user hit the return button
    //post: displayed is now the logged user, should be taken back to own page
    void onReturnButtonClicked();

    //pre: Add friend button is clicked
    //post: The displayed_User is now a friend of the logged_User
    void onFriendAddButtonClicked();

    //pre:
    //post: every txt file is now updated to the latest changes
    void updateFiles();

    //pre: clicked on a cell in the recommended table
    //post: taken to the recommended friend's page
    void onRecommendedFriendClicked(int r, int c);

    //pre: Post button is clicked
    //post: new post with message taken from the text input
    void onPostButtonClicked();

    //pre:
    //post: this friend is removed from logged_User's friend list
    void onRemoveFriendButtonClicked();

    //pre: The user clicked on GO
    //post: displayed User is now the user from the display_goToUserInputField's input
    //      if user not found, change the text to "USER NOT FOUND, TRY AGAIN"
    void ongoToUserButtonClicked();


    void onEnterAmadeusButtonClicked();

    void onAmadeusPostButtonClicked();


    //pre: clicked on ban
    //post: the displayed_User is now banned
    void admin_onBanButtonClicked();

    //pre: clicked on unban button
    //post: this user is now unbanned
    void admin_onUnbanButtonClicked();

    //pre: Add admin button is clicked
    //post This displayed_User is now an administrator
    void admin_onAdminAddAdminButtonClicked();

    //pre: remove admin button is clicked
    //post: this displayed_User is no longer an admin.
    void admin_onAdminRemoveAdminButtonClicked();



private:
    Network network;
    User* logged_User;
    User* displayed_User;
    Ui::MainWindow *ui;

};
