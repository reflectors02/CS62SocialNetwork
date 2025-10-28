#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


SocialNetworkWindow::SocialNetworkWindow(char* users, char* posts)
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);

    network.readUsers(users);
    network.readPosts(posts);
    network.readAdmin();
    network.readBanned();

    hideDisplayWindow();
    hideAdminPanel();

    ui->login_Button->setText(QString::fromStdString("Login"));

    connect(ui->login_Button, &QPushButton::clicked, this, &SocialNetworkWindow::onLoginButton);
    connect(ui->display_table_friends, &QTableWidget::cellDoubleClicked, this, &SocialNetworkWindow::onfriendTableClicked);
    connect(ui->display_returnButton, &QPushButton::clicked, this, &SocialNetworkWindow::onReturnButtonClicked);
    connect(ui->display_addFriendButton, &QPushButton::clicked, this, &SocialNetworkWindow::onFriendAddButtonClicked);
    connect(ui->display_suggestFriendsTable, &QTableWidget::cellDoubleClicked, this, &SocialNetworkWindow::onRecommendedFriendClicked);
    connect(ui->display_postButton, &QPushButton::clicked, this, &SocialNetworkWindow::onPostButtonClicked);
    connect(ui->admin_banButton, &QPushButton::clicked, this, &SocialNetworkWindow::admin_onBanButtonClicked);
    connect(ui->admin_unbanButton, &QPushButton::clicked, this, &SocialNetworkWindow::admin_onUnbanButtonClicked);
    connect(ui->admin_addAdminButton, &QPushButton::clicked, this, &SocialNetworkWindow::admin_onAdminAddAdminButtonClicked);
    connect(ui->admin_removeAdminButton, &QPushButton::clicked, this, &SocialNetworkWindow::admin_onAdminRemoveAdminButtonClicked);
    connect(ui->display_logoutButton, &QPushButton::clicked, this, &SocialNetworkWindow::onLogoutButton);
}

void SocialNetworkWindow::onLoginButton()
{
    std::string name = ui->login_textEdit->toPlainText().toStdString();
    int loggedId = network.getId(name);


    if(loggedId == -1)
    {
        ui->login_label->setText(QString::fromStdString("Wrong name, enter again"));
        return;
    }

    if(network.isBanned(network.getUser(loggedId)))
    {
        ui->login_label->setText(QString::fromStdString("You are banned"));
        return;
    }


    logged_User = network.getUser(loggedId);
    displayed_User = logged_User;

    ui->login_label->setText(QString::fromStdString("Enter your name"));

    hideLoginWindow();

    showDisplayWindow(logged_User);
    setupAdminPanel(logged_User);

}

void SocialNetworkWindow::onLogoutButton()
{
    displayed_User = nullptr;
    logged_User = nullptr;

    hideAdminPanel();
    hideDisplayWindow();
    showLoginWindow();
}

void SocialNetworkWindow::hideAdminPanel()
{
    ui->admin_unbanButton->hide();
    ui->admin_banButton->hide();
    ui->admin_addAdminButton->hide();
    ui->admin_removeAdminButton->hide();
}

void SocialNetworkWindow::hideLoginWindow()
{
    ui->login_Button->hide();
    ui->login_label->hide();
    ui->login_textEdit->hide();
}

void SocialNetworkWindow::showLoginWindow()
{
    ui->login_Button->show();
    ui->login_label->show();
    ui->login_textEdit->show();
}

void SocialNetworkWindow::hideDisplayWindow()
{
    ui->display_label->hide();
    ui->display_table_friends->hide();
    ui->display_table_posts->hide();
    ui->display_returnButton->hide();
    ui->display_addFriendButton->hide();
    ui->display_suggestFriendsTable->hide();
    ui->display_postTextInput->hide();
    ui->display_postButton->hide();
    ui->display_recommendedLabel->hide();
    ui->display_friendsLabel->hide();
    ui->display_logoutButton->hide();
}

void SocialNetworkWindow::showAdminPanel()
{
    ui->admin_banButton->show();
    ui->admin_unbanButton->show();
    ui->admin_addAdminButton->show();
    ui->admin_removeAdminButton->show();
}

void SocialNetworkWindow::display_setupFriendSuggestionTable(User* user)
{
    int score = 2;
    if(user == logged_User)
    {
        ui->display_recommendedLabel->show();
        std::vector<int> suggested_friends = network.suggestFriends(logged_User->getId(), score);
        ui->display_suggestFriendsTable->setRowCount(suggested_friends.size());
        ui->display_suggestFriendsTable->setColumnCount(1);
        ui->display_suggestFriendsTable->show();

        int index = 0;
        for(int friend_id : suggested_friends)
        {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(QString::fromStdString(network.getUser(friend_id)->getName()));
            ui->display_suggestFriendsTable->setItem(index, 0, item);
            index++;
        }

    }

    else
    {
        ui->display_suggestFriendsTable->hide();
        ui->display_recommendedLabel->hide();

    }
}

void SocialNetworkWindow::display_setupFriendTable(User* user)
{
    int num_friends = user->getFriends().size();
    ui->display_table_friends->setRowCount(num_friends);
    ui->display_table_friends->setColumnCount(1);

    int i = 0;
    for(int neighbor : user->getFriends())
    {
        User* user_friend = network.getUser(neighbor);
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::fromStdString(user_friend->getName()));
        ui->display_table_friends->setItem(i, 0, item);
        i++;
    }
    ui->display_table_friends->resizeColumnsToContents();
    ui->display_table_friends->show();
}

void SocialNetworkWindow::display_setupPostTable(User* user)
{
    ui->display_table_posts->setRowCount(5);
    ui->display_table_posts->setColumnCount(1);

    int profileId = network.getId(user->getName());
    std::string posts = network.getPostsString(profileId, 5);
    std::stringstream ss(posts);
    std::string myLine;

    int index = 0;
    while(std::getline(ss, myLine))
    {
        if(myLine.empty()){continue;}
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::fromStdString(myLine));
        ui->display_table_posts->setItem(index, 0, item);
        index++;
    }
    ui->display_table_posts->resizeColumnsToContents();
    ui->display_table_posts->show();
}

void SocialNetworkWindow::setupAdminPanel(User* user)
{
    if(network.isAdmin(user))
    {
        showAdminPanel();
    }

    else
    {
        hideAdminPanel();
    }
}


void SocialNetworkWindow::showDisplayWindow(User* user)
{
    if(user != logged_User)
    {
        ui->display_returnButton->show();
        ui->display_label->setText(QString::fromStdString(user->getName() + "'s Profile"));
        ui->display_addFriendButton->show();
    }

    else
    {
        ui->display_returnButton->hide();
        ui->display_label->setText(QString::fromStdString("My Profile"));
        ui->display_addFriendButton->hide();
    }

    //setting up friend_suggestions
    display_setupFriendSuggestionTable(user);

    //setting up friends table
    display_setupFriendTable(user);

    //Setting up posts table
    display_setupPostTable(user);



    ui->display_label->show();
    ui->display_postTextInput->show();
    ui->display_postButton->show();
    ui->display_friendsLabel->show();
    ui->display_logoutButton->show();
}

void SocialNetworkWindow::onfriendTableClicked(int r, int c)
{
    auto *item = ui->display_table_friends->item(r,c);
    if(!item){return;}

    std::string friend_name = ui->display_table_friends->item(r,c)->text().toStdString();
    int friendId = network.getId(friend_name);
    displayed_User = network.getUser(friendId);

    showDisplayWindow(displayed_User);
}

void SocialNetworkWindow::onReturnButtonClicked()
{
    displayed_User = logged_User;
    showDisplayWindow(logged_User);
}

void SocialNetworkWindow::onFriendAddButtonClicked()
{
    network.addConnection(logged_User->getName(), displayed_User->getName());
    updateFiles();
}

void SocialNetworkWindow::updateFiles()
{
    network.writePosts("posts.txt");
    network.writeUsers("users.txt");
}

void SocialNetworkWindow::onRecommendedFriendClicked(int r, int c)
{
    auto *item = ui->display_suggestFriendsTable->item(r,c);
    if(!item){return;}

    std::string friend_name = ui->display_suggestFriendsTable->item(r,c)->text().toStdString();
    int friendId = network.getId(friend_name);
    displayed_User = network.getUser(friendId);

    showDisplayWindow(displayed_User);

}

void SocialNetworkWindow::onPostButtonClicked()
{
    std::string post_message = ui->display_postTextInput->toPlainText().toStdString();
    int profileId = displayed_User->getId();
    int authorId = logged_User->getId();

    Post* new_post = new Post(profileId, authorId, post_message, 0);
    network.addPost(new_post);
    updateFiles();
    showDisplayWindow(displayed_User);
}



void SocialNetworkWindow::admin_onBanButtonClicked()
{
    network.addBannedUser(displayed_User);
}

void SocialNetworkWindow::admin_onUnbanButtonClicked()
{
    network.removeBannedUser(displayed_User);
}

void SocialNetworkWindow::admin_onAdminAddAdminButtonClicked()
{
    network.addAdminAccount(displayed_User);
}

void SocialNetworkWindow::admin_onAdminRemoveAdminButtonClicked()
{
    network.deleteAdminAccount(displayed_User);
}


