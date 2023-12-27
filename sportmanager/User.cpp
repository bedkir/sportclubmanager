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

void User::deleteMember(string groupName, string login, string name, string surname)
{
	vector<string> temp;

	//Group file
	ifstream F;
	F.open(groupName + ".txt", ofstream::out | ofstream::app);

	string line;

	while (true)
	{
		getline(F, line);
		temp.push_back(line);
		if (line == name + " " + surname + " (" + login + ")")
			temp.pop_back();
		else if (line == "") break;
	}

	F.close();

	ofstream S;
	S.open(groupName + ".txt", ofstream::trunc);

	for (int i = 0; i < temp.size(); i++)
		S << temp.at(i) << endl;

	S.close();
	temp.clear();

	//Member file

	ifstream T;
	T.open(login + ".txt", ofstream::out | ofstream::app);

	while (true)
	{
		getline(T, line);
		temp.push_back(line);
		if (line == groupName)
			temp.pop_back();
		else if (line == "") break;
	}

	T.close();

	ofstream K;
	K.open(login + ".txt", ofstream::trunc);

	for (int i = 0; i < temp.size(); i++)
		K << temp.at(i) << endl;

	K.close();
	temp.clear();

	this->getGroupsListFromFile();
}