#include "Group.h"

Group::Group()
{
}

Group::Group(string sportName, Coach coach, vector<string>members)
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

inline string Group::getGroupName() const
{
	return this->groupName;
}

inline Coach Group::getCoach() const
{
	return this->coach;
}

inline vector<string> Group::getMembers() const
{
	return this->members;
}

inline Group& Group::setSportName(string sportName)
{
	this->sportName = sportName;
	return *this;
}

inline Group& Group::setGroupName(string groupName)
{
	this->groupName = groupName;
	return *this;
}

inline Group& Group::setCoach(Coach& coach)
{
	this->coach = coach;
	return *this;
}

inline Group& Group::setMembers(vector<string>& members)
{
	this->members = members;
	return *this;
}
