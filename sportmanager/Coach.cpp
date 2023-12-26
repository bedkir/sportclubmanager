#include "Coach.h"

Coach::Coach()
{
}

Coach::Coach(string login, string password, vector<string> group)
{
	this->login = login;
	this->password = password;
	this->groups = group;
}

Coach::Coach(const Coach& coach)
{
	this->login = coach.getLogin();
	this->password = coach.getPassword();
	this->groups = coach.getGroups();
}

Coach::~Coach()
{
	this->groups.clear();
}

inline vector<string> Coach::getGroups() const
{
	return this->groups;
}

inline Coach& Coach::setGroups(vector<string>& groups)
{
	this->groups = groups;
	return *this;
}

Coach& Coach::operator=(const Coach& otherCoach)
{
	this->groups = otherCoach.getGroups();
	this->login = otherCoach.getLogin();
	this->password = otherCoach.getPassword();
	return *this;
}

bool Coach::SignIn(string, string)
{
	return false;
}

bool Coach::SignUp(string, string, string)
{
	return false;
}
