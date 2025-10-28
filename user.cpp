#include "user.h"
#include <iostream>
#include <set>
#include <string>

User::User()
{
	id_ = 0;
	name_ = "Oberleutnant von Cossel";
	year_ = 1918;
	zip_ = 88;
	friends_ = std::set<int>();	
}

User::User(int id, std::string name, int year, int zip, std::set<int> friends)
{
	id_ = id;
	name_ = name;
	year_ = year;
	zip_ = zip;
	friends_ = friends;
}

void User::addFriend(int id){ friends_.insert(id);}

void User::deleteFriend(int id){friends_.erase(id);}

int User::getId() const{return id_;}

std::string User::getName() const {return name_;}

int User::getYear() const{return year_;}

int User::getZip() const{return zip_;}

std::set<int> & User::getFriends(){return friends_;}