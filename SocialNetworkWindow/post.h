#ifndef POST_H
#define POST_H
#include <string>

class Post
{
public:
	//pre:
	//post: A Post object is created. messageId_ should be -1 by default
	Post();


	//pre: ProfileId, authorId, message and the likes are passed in as parameter
	//post: A post of the given parameters are used to create a Post of these specifications. messageId_ should be -1 by default
	Post(int profileId, int authorId, std::string message, int likes);

	//pre:
	//post: MessageId is returned
	int getMessageId();

	//pre: ID to set is passed in as parameter
	//post: This post's messageId_ is now set to id
	void setMessageId(int id);

	//pre: 
	//post: profileId_ is returned
	int getProfileId();	

	//pre: 
	//post: authorId_ is returned
	int getAuthorId();

	//pre:
	//post: the message_ is returned
	std::string getMessage();

	//pre:
	//post: number of likes---likes_ is returned
	int getLikes();

	//pre:
	//post: URL is returned as a string---currently it should just return a empty string
	virtual std::string getURL();

	//pre:
	//post: a string of "[message_] ([likes_] likes)" is returned
	virtual std::string toString();

private:
	int messageId_, profileId_, authorId_, likes_;
	std::string message_;
};


class LinkPost : public Post
{
public:
	//pre:
	//post: a LinkPost is created
	LinkPost();

	//pre: profileId, authorID, message, likes, url is passed in as parameter
	//post: a LinkPost with the given parameters is created
	LinkPost(int profileId, int authorId, std::string message, int likes, std::string url);

	//pre:
	//post: the URL is returned as a string
	std::string getURL() override;

	//pre:
	//post: return a string in the format: "[message_] (url: [url_]) ([likes_] likes)"
	std::string toString() override;

private:
	std::string url_;
};




#endif