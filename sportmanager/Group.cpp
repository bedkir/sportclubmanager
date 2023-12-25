#include "Group.h"

Group::Group()
{
}

Group::Group(string sportName, User coach, vector<User>members)
{
	this->sportName = sportName;
	this->coach = coach;
	this->members = members;
}

Group::Group(Group& group)
{
	this->sportName = group.getSportName();
	this->coach = group.getCoach();
	this->members = group.getMembers();
}

Group::~Group()
{
	this->members.clear();
}

inline string Group::getSportName() const
{
	return this->sportName;
}

inline User Group::getCoach() const
{
	return this->coach;
}

inline vector<User> Group::getMembers() const
{
	return this->members;
}

inline Group& Group::setSportName(string sportName)
{
	this->sportName = sportName;
	return *this;
}

inline Group& Group::setCoach(User& coach)
{
	this->coach = coach;
	return *this;
}

inline Group& Group::setMembers(vector<User>& members)
{
	this->members = members;
	return *this;
}
