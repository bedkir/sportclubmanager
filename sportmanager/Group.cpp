#include "Group.h"
#include "ClubMember.h"

#include <fstream>
#include <string>
#include <sstream>
#include <regex>

int Group::amountOfGroups = 0;

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

int Group::getAmountOfGroups()
{
	return amountOfGroups;
}

void Group::setAmountOfGroups()
{
	ifstream F;
	F.open("groups.txt", ofstream::out | ofstream::app);

	string line, prev_line;

	getline(F, line);
	getline(F, line);

	while (true)
	{
		prev_line = line;
		getline(F, line);
		if (line == "") break;
	}

	F.close();

	if (prev_line != "")
		Group::amountOfGroups = stoi(prev_line.erase(0, 5));
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

inline Group& Group::setCoach(const Coach& coach)
{
	this->coach = coach;
	return *this;
}

inline Group& Group::setMembers(vector<string>& members)
{
	this->members = members;
	return *this;
}

void Group::fillGroupData(string groupName)
{
	this->groupName = groupName;

	ifstream F;
	F.open(groupName + ".txt", ofstream::out | ofstream::app);

	string line;

	getline(F, line);
	this->sportName = line;

	getline(F, line);

	regex loginRegex("\\(([^)]+)\\)");
	smatch match;
	regex_search(line, match, loginRegex);
	string login = match[1];

	//start
	ifstream S;
	S.open(login + ".txt", ofstream::out | ofstream::app);

	string line1;


	vector<string> data, coachGroups;
	for (int i = 0; i < 4; i++)
	{
		getline(S, line1);
		data.push_back(line1);
	}

	while (true)
	{
		getline(S, line1);
		if (line1 == "") break;
		coachGroups.push_back(line1);
	}

	S.close();

	//stop

	Coach tempCoach(data.at(0), data.at(1), data.at(2), data.at(3), coachGroups);
	this->setCoach(tempCoach);
	//this->coach = line;

	vector<string> members;

	while (true)
	{
		getline(F, line);
		if (line == "") break;
		members.push_back(line);
	}

	F.close();

	this->members = members;
}