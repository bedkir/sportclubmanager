#include "User.h"

User::User()
{
}

User::User(string login, string password)
{
	this->login = login;
	this->password = password;
}

User::User(const User& user)
{
	this->login = user.getLogin();
	this->password = user.getPassword();
}

User::~User()
{
}

inline string User::getLogin() const
{
	return this->login;
}

inline string User::getPassword() const
{
	return this->password;
}

inline User& User::setLogin(string login)
{
	this->login = login;
	return *this;
}

inline User& User::setPassword(string password)
{
	this->password = password;
	return *this;
}


