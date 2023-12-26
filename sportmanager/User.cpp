#include "User.h"

User::User()
{
}

User::User(string login, string password, string name, string surname)
{
	this->login = login;
	this->password = password;
	this->name = name;
	this->surname = surname;
}

User::User(const User& user)
{
	this->login = user.getLogin();
	this->password = user.getPassword();
	this->name = user.getName();
	this->surname = user.getSurname();
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

inline string User::getName() const
{
	return this->name;
}

inline string User::getSurname() const
{
	return this->surname;
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

inline User& User::setName(string name)
{
	this->name = name;
	return *this;
}

inline User& User::setSurname(string surname)
{
	this->surname = surname;
	return *this;
}


