#include "post.h"
#include <string>

Post::Post()
{
	messageId_ = -1; 
}

Post::Post(int profileId, int authorId, std::string message, int likes)
{
	profileId_ = profileId;
	authorId_ = authorId;
	message_ = message;
	likes_ = likes;
	messageId_ = -1; 
}

int Post::getMessageId()
{
	return messageId_;
}

void Post::setMessageId(int id)
{
	messageId_ = id;
}

int Post::getProfileId()
{
	return profileId_;
}

int Post::getAuthorId()
{
	return authorId_;
}

std::string Post::getMessage()
{
	return message_;
}

int Post::getLikes()
{
	return likes_;
}

std::string Post::getURL()
{
	return "";
}

std::string Post::toString()
{
	return message_ + " (" + std::to_string(likes_) + " " + "likes)";
}





LinkPost::LinkPost()
{
	url_ = getURL();
}

LinkPost::LinkPost(int profileId, int authorId, std::string message, int likes, std::string url) : Post(profileId, authorId, message, likes)
{
	url_ = url;
}

std::string LinkPost::getURL()
{
	return url_;
}

std::string LinkPost::toString() 
{
	return getMessage() + " (url: " + url_ + ") (" + std::to_string(getLikes()) + " likes)";
}
