#include "User.h"
#include <fstream>
#include <string>

User::User()
{
}

User::User(string login, string password, string name, string surname, vector<string> groups)
{
	this->login = login;
	this->password = password;
	this->name = name;
	this->surname = surname;
	this->groups = groups;
}

User::User(const User& user)
{
	this->login = user.getLogin();
	this->password = user.getPassword();
	this->name = user.getName();
	this->surname = user.getSurname();
	this->groups = user.getGroups();
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


inline vector<string> User::getGroups() const
{
	return this->groups;
}

inline User& User::setGroups(vector<string>& groups)
{
	this->groups = groups;
	return *this;
}


void User::getGroupsListfromFile()
{
	vector<string> groupsList;

	ifstream F;
	F.open(this->login + ".txt", ifstream::app);

	string line;

	getline(F, line);
	getline(F, line);
	getline(F, line);
	getline(F, line);

	while (getline(F, line))
		groupsList.push_back(line);

	F.close();

	this->groups = groupsList;
}

