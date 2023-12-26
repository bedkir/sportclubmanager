#include "ClubMember.h"

ClubMember::ClubMember()
{
}

ClubMember::ClubMember(string login, string password, string name, string surname, int birthYear, vector<string> groups)
{
	this->login = login;
	this->password = password;
	this->name = name;
	this->surname = surname;
	this->birthYear = birthYear;
	this->groups = groups;
}

ClubMember::ClubMember(const ClubMember& member) : User(member)
{
	this->birthYear = member.getBirthYear();
	this->groups = member.getGroups();
}

ClubMember::~ClubMember()
{
	this->groups.clear();
}

inline int ClubMember::getBirthYear() const
{
	return this->birthYear;
}

inline vector<string> ClubMember::getGroups() const
{
	return this->groups;
}

inline ClubMember& ClubMember::setBirthYear(int birthYear)
{
	this->birthYear = birthYear;
	return *this;
}

inline ClubMember& ClubMember::setGroups(vector<string>& groups)
{
	this->groups = groups;
	return *this;
}

bool ClubMember::SignIn(string login, string password)
{
	return false;
}

bool ClubMember::SignUp(string login, string password, string secPassword, string name, string surname, int birthYear)
{
	return false;
}
