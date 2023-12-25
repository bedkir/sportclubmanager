#include "ClubMember.h"

ClubMember::ClubMember()
{
}

ClubMember::ClubMember(string login, string password, vector<Group> groups)
{
	this->login = login;
	this->password = password;
	this->groups = groups;
}

ClubMember::ClubMember(ClubMember& member)
{
	this->login = member.getLogin();
	this->password = member.getPassword();
	this->groups = member.getGroups();
}

ClubMember::~ClubMember()
{
	this->groups.clear();
}

inline vector<Group> ClubMember::getGroups() const
{
	return this->groups;
}

inline ClubMember& ClubMember::setGroups(vector<Group>& groups)
{
	this->groups = groups;
	return *this;
}
