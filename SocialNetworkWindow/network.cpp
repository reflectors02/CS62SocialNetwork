#include "network.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <set>
#include <queue>
#include <unordered_map>
#include <stack>

Network::Network()
{
	users_ = std::vector<User*>();
	posts_ = std::vector<std::vector<Post*>>();
}

User* Network::getUser(int id)
{
	for(int i = 0; i < users_.size(); i++)
	{
		if(users_[i]->getId() == id)
		{
			return users_[i];
		}
	}
	return nullptr;
}

void Network::addUser(User* user)
{
	users_.push_back(user);
	posts_.push_back(std::vector<Post*>());
}

int Network::numUsers()
{
	return users_.size();
}

int Network::getId(std::string s1)
{
	for(int i = 0; i < numUsers(); i++)
	{
		if(users_[i]->getName() == s1)
		{
			return users_[i]->getId();
		}
	}
	return -1;
}


int Network::addConnection(std::string s1, std::string s2)
{
	int user1 = getId(s1);
	int user2 = getId(s2);
	if(user1 == -1 || user2 == -1){return -1;}

	users_[user1]->addFriend(user2);
	users_[user2]->addFriend(user1);

	return 0;
}

int Network::deleteConnection(std::string s1, std::string s2)
{
	int user1 = getId(s1);
	int user2 = getId(s2);
	if(user1 == -1 || user2 == -1){return -1;}

	users_[user1]->deleteFriend(user2);
	users_[user2]->deleteFriend(user1);

	return 0;

}

void Network::readUsers(const char* fname )
{
	std::ifstream FileIn(fname);
	std::string name, myline;
	int expected_size, id, year, zip, friend_id;	

	//We are using getline so that we don't end up in an empty line when we do getline next.
	std::getline(FileIn, myline);
	//the expected size isn't particularly useful right now, but potentially could be useful to counter any potential garbage data.
	expected_size = stoi(myline);

	while(std::getline(FileIn, myline))
	{
		std::set<int> friends; 

		id = stoi(myline);

		std::getline(FileIn, myline);
		//Get rid of leading tab
		name = myline.substr(1);


		std::getline(FileIn, myline);
		year = stoi(myline);

		std::getline(FileIn, myline);
		zip = stoi(myline);

		std::getline(FileIn, myline);

		std::stringstream ss;
		ss.str(myline);
		while(ss >> friend_id)
		{
			friends.insert(friend_id);
		}
		addUser(new User(id, name, year, zip, friends));
	}
}

void Network::writeUsers(const char* fname)
{
	std::ofstream FileOut(fname);
	FileOut << numUsers() << std::endl;

	for(int i = 0; i < users_.size(); i++)
	{
		FileOut << users_[i]->getId() << std::endl;
		FileOut << "\t" << users_[i]->getName() << std::endl;
		FileOut << "\t" << users_[i]->getYear() << std::endl;
		FileOut << "\t" << users_[i]->getZip() << std::endl;
		FileOut << "\t";

		for(const auto friend_id : users_[i]->getFriends())
		{
			FileOut << friend_id << " ";
		}

		FileOut << std::endl;

	}
}

std::vector<int> Network::shortestPath(int from, int to)
{
	std::vector<bool> visited(numUsers(), false);
	std::queue<int> qu;
	std::vector<int> prev(numUsers(), -1);
	qu.push(from);
	visited[from] = true;

	while(!qu.empty())
	{
		int curr = qu.front();
		qu.pop();

		for(const auto neighbor_id : users_[curr]->getFriends())
		{
			if(!visited[neighbor_id])
			{
				qu.push(neighbor_id);
				visited[neighbor_id] = true;
				prev[neighbor_id] = curr;
			}

			if(neighbor_id == to)
			{
				break;
			}
		}
	}

	//if to is nto visited at end of BFS, then there is no path connecting from to to.
	if(visited[to] == false){return {};}

	std::vector<int> output = {};
	int curr = to;

	while(curr != -1)
	{
		output.push_back(curr);
		curr = prev[curr];
	}

	std::reverse(output.begin(), output.end());
	return output;
}


std::vector<int> Network::distanceUser(int from, int & to, int distance)
{
	std::queue<int> qu;
	std::vector<bool> visited(numUsers(), false);
	std::vector<int> prev(numUsers(), -1);

	//we will store every single node as distance to the from i.e. {node, distance from from}
	std::unordered_map<int, int> id_distance;

	qu.push(from);
	visited[from] = true;
	prev[from] = -1;
	id_distance[from] = 0;

	while(!qu.empty())
	{
		int curr = qu.front();
		qu.pop();

		for(const auto & neighbor_id : users_[curr]->getFriends())
		{
			if(!visited[neighbor_id])
			{
				qu.push(neighbor_id);
				visited[neighbor_id] = true;
				prev[neighbor_id] = curr;

				//The distance from the source to this neighbor is always the current + 1, which makes sense.
				id_distance[neighbor_id] = id_distance[curr] + 1;
			}

			//if the distance is right, and is the first one we see. Then to should be changed to this.
			if(id_distance[neighbor_id] == distance)
			{
				to = neighbor_id;

				//we should break because we found our target---no need to do the entire graph
				break;
			}
		}	
	}

	std::vector<int> sol;
	int curr = to;

	while(curr != -1)
	{
		sol.push_back(curr);
		curr = prev[curr];
	}

	reverse(sol.begin(), sol.end());

	if(sol.empty()){to = -1;}

	return sol;
}


std::vector<int> Network::suggestFriends(int who, int & score)
{
	std::queue<int> qu;
	std::vector<bool> visited(numUsers(), false);
	std::set<int> source_friends = users_[who]->getFriends();

	//We will store how many friends each node share in common with the source node as a unordered_map
	std::unordered_map<int,int> common_friends_map;

	qu.push(who);
	visited[who] = true;

	while(!qu.empty())
	{
		int curr = qu.front();
		qu.pop();

		for(const auto & friend_id : users_[curr]->getFriends())
		{
			if(!visited[friend_id])
			{
				qu.push(friend_id);
				visited[friend_id] = true;

				if(!source_friends.contains(friend_id))
				{
					int common_friends = 0;

					//check for how many common friends does this user have with source
					for(const auto & x : users_[friend_id]->getFriends())
					{
						if(source_friends.contains(x))
						{
							common_friends++;
						}
					}

					common_friends_map[friend_id] = common_friends;
					score = std::max(score, common_friends);
				}
			}
		}
	}

	std::vector<int> sol;

	for(const auto & pair : common_friends_map)
	{
		if(pair.second == score)
		{
			sol.push_back(pair.first);
		}
	}

	return sol;
}



void Network::dfsHelper(int curr, std::vector<bool> & visited, std::vector<int> & connected)
{
	if(!visited[curr])
	{
		visited[curr] = true;
		connected.push_back(curr);

		for(int neighbor : users_[curr]->getFriends())
		{
			dfsHelper(neighbor, visited, connected);
		}	
	}
}

std::vector<int> Network::dfs(int curr, std::vector<bool> & visited)
{
	std::vector<int> connected;
	dfsHelper(curr, visited, connected);
	return connected;
}



std::vector<std::vector<int>> Network::groups()
{
	std::vector<std::vector<int>> sol;
	std::vector<bool> visited(numUsers(), 0);

	for(int i = 0; i < numUsers(); i++)
	{
		//if the node isn't visited---then it means this is another separated group. We should then we run dfs to it. 
		if(!visited[i])
		{
			sol.push_back(dfs(i, visited));
		}
	}	

	return sol;
}

int Network::numPosts()
{
	int sol = 0;
	for(int i = 0; i < posts_.size(); i++)
	{
		sol += posts_[i].size();
	}
	
	return sol;
}


void Network::addPost(Post* post)
{
	post->setMessageId(numPosts());
	posts_[post->getProfileId()].push_back(post);
}


std::vector<Post*> Network::getPosts(int id)
{
	return posts_[id];
}

std::string Network::postDisplayString(Post* post)
{
	if(post == nullptr){return "Invalid post";}
	if(post->getAuthorId() < 0 || post->getAuthorId() >= posts_.size()) {return "invalid authorid";}

	return users_[post->getAuthorId()]->getName() + " wrote: " + post->toString();
}


std::string Network::getPostsString(int profileId, int howMany)
{
	if(profileId < 0){return "invalid name";}

	std::string sol;
	int post_size = posts_[profileId].size();
	int counter = 1;

	if(post_size <= 0){return "No posts for the user";}

	while(post_size - counter >= 0 && counter <= howMany)
	{
		int index = post_size - counter;
		std::string message = postDisplayString(posts_[profileId][index]);
		sol = sol + message + "\n\n";
		counter++;
	}

	return sol;
}

int Network::readPosts(char* fname)
{
	std::ifstream FileIn(fname);
	std::string myline;
	std::getline(FileIn, myline);
	std::stringstream ss(myline);

	int sum_posts;
	ss >> sum_posts;
	ss.clear();

	while(std::getline(FileIn, myline))
	{
		int postId;	//this is set automatically, but to keep it organzied we will take in it anyways.
		ss.str(myline);
		ss >> postId;
		ss.clear();

		std::getline(FileIn, myline);
		std::string message = myline.substr(1);

		std::getline(FileIn, myline);
		int profileId;
		ss.str(myline);
		ss >> profileId;
		ss.clear();

		std::getline(FileIn, myline);
		int authorId;
		ss.str(myline);
		ss >> authorId;
		ss.clear();

		std::getline(FileIn, myline);
		int likes;
		ss.str(myline);
		ss >> likes;
		ss.clear();

		std::getline(FileIn, myline);

		if(!myline.empty())
		{
			std::string url = myline.substr(1);
			addPost(new LinkPost(profileId, authorId, message, likes, url));
		}

		else
		{
			addPost(new Post(profileId, authorId, message, likes));

		}
	}
	return sum_posts;
}

int Network::writePosts(char* fname)	//USE A HASHMAP AND ITERATE ONCE THROUGH N() POSTS. NOTE DOWN THEIR MESSAGEID CORRESPONDING TO THE ACTUAL POST
{
	std::unordered_map<int, Post*> idtoPost;

	for(int i = 0; i < posts_.size(); i++)
	{
		for(int j = 0; j < posts_[i].size(); j++)
		{
			Post* post = posts_[i][j];
			idtoPost[post->getMessageId()] = post;
		}
	}


	std::ofstream FileOut(fname);
	FileOut << numPosts() << "\n";

	for(int i = 0; i < numPosts(); i++)
	{
		Post* post = idtoPost[i];
		FileOut << i << "\n";
		FileOut << "\t" << post->getMessage() << "\n";
		FileOut << "\t" << post->getProfileId() << "\n";
		FileOut << "\t" << post->getAuthorId() << "\n";
		FileOut << "\t" << post->getLikes() << "\n";
		if(post->getURL() != "")
		{
			FileOut << "\t" << post->getURL() << "\n";
		}
		else
		{
			FileOut << "\n";
		}

	}
	return 1;
}


//HW7


void Network::addAdminAccount(User* user)
{
	int id = user->getId();
	adminAccounts_.insert(id);
	updateAdmin();
}

void Network::deleteAdminAccount(User* user)
{
	int id = user->getId();
	adminAccounts_.erase(id);
	updateAdmin();
}

void Network::updateAdmin()
{
	std::ofstream FileOut("admin.txt");

	for(int adminId : adminAccounts_)
	{
		FileOut << adminId << "\n";
	}

}

void Network::readAdmin()
{
    std::ifstream FileIn("admin.txt");
    if(!FileIn.is_open())
    {
        std::ofstream FileOut("admin.txt");
        FileOut.close();
    }
	std::stringstream ss;
	std::string myline;

	while(std::getline(FileIn, myline))
	{
		int id;
		ss.str(myline);

		if(ss >> id)
		{
			adminAccounts_.insert(id);
		}
		ss.clear();
	}
}

bool Network::isAdmin(User* user)
{
	return adminAccounts_.contains(user->getId());
}


void Network::addBannedUser(User* user)
{
	int id = user->getId();
	bannedUsers_.insert(id);
	updateBanned();
}

void Network::removeBannedUser(User* user)
{
	int id = user->getId();
	bannedUsers_.erase(id);
	updateBanned();
}

void Network::updateBanned()
{
	std::ofstream FileOut("banned.txt");

	for(int bannedId : bannedUsers_)
	{
		FileOut << bannedId << "\n";
	}
}

void Network::readBanned()
{
	std::ifstream FileIn("banned.txt");
    if(!FileIn.is_open())
    {
        std::ofstream FileOut("banned.txt");
        FileOut.close();
    }

	std::stringstream ss;
	std::string myline;

	while(std::getline(FileIn, myline))
	{
		int id;
		ss.str(myline);

		if(ss >> id)
		{
			bannedUsers_.insert(id);

		}
		ss.clear();
	}
}

//will see if the user is banned---will return a bool value
bool Network::isBanned(User* user)
{
	return bannedUsers_.contains(user->getId());
}
