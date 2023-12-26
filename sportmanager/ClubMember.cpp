#include "ClubMember.h"

ClubMember::ClubMember()
{
}

ClubMember::ClubMember(string login, string password, vector<string> groups)
{
	this->login = login;
	this->password = password;
	this->groups = groups;
}

ClubMember::ClubMember(const ClubMember& member)
{
	this->login = member.getLogin();
	this->password = member.getPassword();
	this->groups = member.getGroups();
}

ClubMember::~ClubMember()
{
	this->groups.clear();
}

inline vector<string> ClubMember::getGroups() const
{
	return this->groups;
}

inline ClubMember& ClubMember::setGroups(vector<string>& groups)
{
	this->groups = groups;
	return *this;
}

bool ClubMember::SignIn(string, string)
{
	return false;
}

bool ClubMember::SignUp(string, string, string)
{
	return false;
}
