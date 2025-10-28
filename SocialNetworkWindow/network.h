#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include <string>
#include "user.h"
#include "post.h"

class Network
{
public:

	//pre:
	//post: A network is created with no users
	Network();


	//pre: target user ID is passed in as parameter
	//post: a pointer that points to the target user is returned
	//		nullptr if invalid
	User* getUser(int id);


	//pre: A pointer to the target user is passed in
	//post: the said user is now in this network
	void addUser(User*);


	//pre:
	//post: returns the number of users in this network
	int numUsers();

	//pre: Two strings in the form of [first name] [last name] format is passed in as parameter
	//post: these two users is now connected
	//		-1 if either of them are invalid
	int addConnection(std::string s1, std::string s2);


	//pre: Two strings in the form of [first name] [last name] format is passed in as parameter
	//post: these two users are now not connected
	//		-1 if either of them are invalid
	int deleteConnection(std::string s1, std::string s2);


	//pre: target user's name in the format of [first name] [last name] is passed in as parameter
	//post: returns the target user's id
	//		-1 if invalid
	int getId(std::string name);


	//pre: takes the file name as a char* (c string) e.g., "users.txt"
	//post: all information of the users in the file is now in this network
	void readUsers(const char* fname);


	//pre: takes in a file name as char *
	//post: writes all the information of this network onto the file name char * e.g, "output.txt"
	void writeUsers(const char* fname);


	//pre: Initial node and final node is passed in as parameter
	//post: a vector containing the shortest path from the inital node to the target node is given e.g., 1->2->3 is given as [1,2,3]
	std::vector<int> shortestPath(int from, int to);


	//pre: takes in from and to as parameter and distance---distance is the distance exact between the from and the to
	//post: to is set to the closest neighbor with distance exactly as provided. A vector<int> of all neighbors that are same distance is provided
	//		if no neighbor that matches the distance---then an empty vector will be returned and to is set to -1
	std::vector<int> distanceUser(int from, int & to, int distance);


	//pre: A user id is passed in. The score should be changed within the function
	//post: a list of users who share the most common friends with the provided user should be returned
	// 		score of the potential new friend should be the amount of common friends they share. 
	std::vector<int> suggestFriends(int who, int & score);


	//Helper function for dfs
	void dfsHelper(int source, std::vector<bool> & visited, std::vector<int> & connected);

	//pre: a source to do dfs is passed in as parameter
	//post: a vector that shows user connected to the source is returned.
	std::vector<int> dfs(int source, std::vector<bool> & visited);

	//pre: NONE
	//post: all groups that are connected are returned in a list, there should be multiple lists returned if the groups are not connected by any user.
	std::vector<std::vector<int>> groups();

	//helper function for addPost
	//pre:
	//post: returns number of posts currently stored in this network
	int numPosts();

	//pre: A pointer to a post is passed in as parameter
	//post: The post is now added to. The messageId of the post is by default set to -1. All posts are id'd by 1,2,3...n. This post should be put to n+1
	//		The index of which to add to the posts_ vector can be found in the post->getauthorId
	void addPost(Post* post);

	//pre: A id of the user of interest is passed in as parameter
	//post: the posts of the user is returned in a vector of posts*
	std::vector<Post*> getPosts(int id);

	//pre: a pointer to a post is passed in as parameter
	//post: A string in the format of "[author name] wrote: [toString]" where author name is the author name (can be access with authorId) and toString is the content of the post
	std::string postDisplayString(Post* post);

	//pre: profileId of interest as well as howMany posts is needed to be displayed is passed in as parameter
	//post: profileId's "howMany" most recent posts are returned. If there are not enough posts, do all of the posts. 
	// 		the returned string will be the concatonation of all the posts---separated by two new lines per post.
	std::string getPostsString(int profileId, int howMany);

	//pre: name of file of interest is passed in as c string. The file contains formatted posts as well as posts with link. This function should read it into the network
	//post: All of the posts and linkPosts have been inswerted into posts_.
	int readPosts(char* fname);

	//pre: name of file to output is passed in as c-string
	//post: all of the posts in this network is written onto the fname with format.
	int writePosts(char* fname);



	//HW7-Administrator and banned

	//pre: id of admin to add is passed in
	//post: this id is now an adminAccount
	void addAdminAccount(User* user);

	//pre: id of an admina ccount is passed in
	//post: this user is now no longer an admin
	void deleteAdminAccount(User* user);

	//pre: 
	//post: update admin.txt
	void updateAdmin();

	//pre: 
	//post: all admins are read into adminAccounts_
	void readAdmin();

	//pre:
	//post: return whether this user is an admin or not
	bool isAdmin(User* user);




	//Banned

	//pre: user id is passed in
	//post: this user is now banned
	void addBannedUser(User* user);

	//pre: banned user id is passed in
	//post: this user is now not banned
	void removeBannedUser(User* user);

	//pre: 
	//post: updated banned.txt
	void updateBanned();

	//pre:
	//post: all users are read into bannedUsers_
	void readBanned();

	//pre:
	//post: return whether this user is banned or not
	bool isBanned(User* user);

private:
	std::vector<User*> users_;
	std::vector<std::vector<Post*>> posts_;
	std::set<int> adminAccounts_; 
	std::set<int> bannedUsers_;
	//Make adminAccounts.txt and banned.txt
};

#endif