#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <set>


class User
{
public:
	//pre: NONE
	//post: a User of arbitrary values were created
	User();

	//pre: parameters are passed in
	//post: a user object is created using the passed in parameters. 
	User(int id, std::string name, int year, int zip, std::set<int> friends);

	//pre: friend ID is taken
	//post: friend ID is added into the set<int> friends_
	void addFriend(int id);

	//pre: friend ID is taken
	//post: friend ID is removed from the set<int> friends_
	void deleteFriend(int id);


	//GETTER FUNCTIONS

	//pre: NONE
	//post: a copy of id_ is returned
	int getId() const;

	//pre: NONE
	//post: a copy of name is returned
	std::string getName() const;

	//pre: NONE
	//post: a copy of the year is returned
	int getYear() const;

	//pre: NONE
	//post: a copy of zip_ is returned
	int getZip() const;


	//pre: NONE
	//post: a copy of friends_ set is returned
	std::set<int> & getFriends();


private:
	std::string name_;
	int id_, year_, zip_;
	std::set<int> friends_;
};

#endif