#include "ClubMember.h"

#include <fstream>
#include <string>


ClubMember& ClubMember::CM = *new ClubMember();


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
}

ClubMember::~ClubMember()
{
	this->groups.clear();
}

inline int ClubMember::getBirthYear() const
{
	return this->birthYear;
}


inline ClubMember& ClubMember::setBirthYear(int birthYear)
{
	this->birthYear = birthYear;
	return *this;
}


bool containsMember(string login)
{
	ifstream F;
	F.open("Members.txt", ifstream::app);


	string line;

	while (getline(F, line))
		if (line == login)
		{
			F.close();
			return true;
		}

	F.close();
	return false;
}


bool ClubMember::SignIn(string login, string password)
{
	string temp;

	if (!containsMember(login))
		return false;

	ifstream F;
	F.open(login + ".txt", ifstream::app);


	getline(F, temp);
	getline(F, temp);

	F.close();

	if (temp != password)
		return false;

	this->login = login;
	this->password = password;

	ifstream T;
	T.open(login + ".txt", ifstream::app);


	getline(T, temp);
	getline(T, temp);
	getline(T, temp);

	this->name = temp;

	getline(T, temp);

	this->surname = temp;

	T.close();

	this->getGroupsListFromFile();

	return true;
}



bool ClubMember::SignUp(string login, string password, string secPassword, string name, string surname, int birthYear)
{
	if (password != secPassword)
		return false;

	ifstream S;
	S.open("Coaches.txt", ifstream::app);

	string line;

	while (getline(S, line))
		if (line == login)
		{
			S.close();
			return false;
		}

	if (containsMember(login))
		return false;

	this->login = login;
	this->password = password;
	this->name = name;
	this->surname = surname;
	this->birthYear = birthYear;


	ofstream F;
	F.open(login + ".txt", ofstream::out | ofstream::app);

	F << login << endl << password << endl << name
	  << endl << surname << endl << birthYear << endl; //group1

	F.close();


	ofstream T;
	T.open("Members.txt", ofstream::out | ofstream::app);

	T << login << endl;

	T.close();

	return true;
}

void ClubMember::getGroupsListFromFile()
{
	vector<string> groupsList;

	ifstream F;
	F.open(this->login + ".txt", ofstream::out | ofstream::app);

	string line;
	for (int i = 0; i < 5; i++)
		getline(F, line);

	while (true)
	{
		getline(F, line);
		if (line == "") break;
		groupsList.push_back(line);
	}

	F.close();
	
	this->groups = groupsList;
}

vector<string> ClubMember::showAvailableGroups()
{
	vector<string> myGroups, result;

	ifstream F;
	F.open("groups.txt", ofstream::out | ofstream::app);

	string line;

	while (true)
	{
		getline(F, line);
		if (line == "") break;
		result.push_back(line);
	}

	F.close();

	ifstream S;
	S.open(this->login + ".txt", ofstream::out | ofstream::app);

	while (true)
	{
		getline(S, line);
		if (line == "") break;
		myGroups.push_back(line);
	}

	S.close();

	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < myGroups.size(); j++)
		{
			if (result.at(i) == myGroups.at(j))
				result.erase(result.begin() + i);
		}
	}

	return result;
}

vector<string> ClubMember::searchGroup(string request)
{
	vector<string> result;

	ifstream F;
	F.open("groups.txt", ofstream::out | ofstream::app);

	string line;

	while (true)
	{
		getline(F, line);
		if (line == "") break;
		size_t found = line.find(request);

		if (found != string::npos) {
			result.push_back(line);
		}
	}

	F.close();

	return result;
}

void ClubMember::enterTheGroup(string groupName, string fullGroupName)
{
	ofstream F;
	F.open(this->login + ".txt", ofstream::out | ofstream::app);

	F << fullGroupName << endl;
	
	F.close();

	ofstream T;
	T.open(groupName + ".txt", ofstream::out | ofstream::app);

	T << this->name + " " + this->surname + " (" + this->login + ")"
	  << endl;

	T.close();

	this->groups.push_back(groupName);
}

Group ClubMember::groupInfo(string groupName)
{
	Group group;
	group.fillGroupData(groupName);
	return group;
}