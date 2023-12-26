#include "Coach.h"
#include "Group.h"

#include <fstream>
#include <string>
#include <algorithm>


Coach& Coach::C = *new Coach();


Coach::Coach()
{
}

Coach::Coach(string login, string password, string name, string surname, vector<string> group)
{
	this->login = login;
	this->password = password;
	this->name = name;
	this->surname = surname;
	this->groups = group;
}

Coach::Coach(const Coach& coach) : User(coach)
{
}

Coach::~Coach()
{
	this->groups.clear();
}


Coach& Coach::operator=(const Coach& otherCoach)
{
	this->groups = otherCoach.getGroups();
	this->login = otherCoach.getLogin();
	this->password = otherCoach.getPassword();
	return *this;
}


bool containsCoach(string login)
{
	ifstream F;
	F.open("Coaches.txt", ifstream::app);


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


bool Coach::SignIn(string login, string password)
{
	string temp;

	if (!containsCoach(login))
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


	this->getGroupsListfromFile();

	return true;
}


bool Coach::SignUp(string login, string password, string secPassword, string name, string surname)
{
	if (password != secPassword)
		return false;
	
	ifstream S;
	S.open("Members.txt", ifstream::app);

	string line;

	while (getline(S, line))
		if (line == login)
		{
			S.close();
			return false;
		}

	if (containsCoach(login))
		return false;

	this->login = login;
	this->password = password;
	this->name = name;
	this->surname = surname;


	ofstream F;
	F.open(login + ".txt", ofstream::out | ofstream::app);

	F << login << endl << password << endl << name 
	  << endl << surname << endl;

	F.close();


	ofstream T;
	T.open("Coaches.txt", ofstream::out | ofstream::app);

	T << login << endl;

	T.close();

	return true;
}


void Coach::createGroup(string sportName)
{
	ofstream F;
	F.open(this->login + ".txt", ofstream::out | ofstream::app);

	F << "group" + to_string(Group::getAmountOfGroups() + 1) << endl;

	F.close();


	ofstream T;
	T.open("group" + to_string(Group::getAmountOfGroups() + 1) + ".txt", ofstream::out | ofstream::app);

	T << sportName << endl << this->name + " " + this->surname
	  << endl; // for members -> name surname (login)

	T.close();

	ofstream S;
	S.open("groups.txt", ofstream::out | ofstream::app);

	S << "group" + to_string(Group::getAmountOfGroups() + 1)
		<< endl;

	S.close();

	Group::setAmountOfGroups();
}


vector<string> Coach::openGroup(string groupName)
{
	vector<string> result;

	ifstream F;
	F.open(groupName + ".txt", ofstream::out | ofstream::app);

	string line;

	getline(F, line);
	getline(F, line);

	while (true)
	{
		getline(F, line);
		if (line == "") break;
		result.push_back(line);
	}

	F.close();

	return result;
}


vector<string> Coach::searchMembers(string request, string groupName)
{
	vector<string> result;

	ifstream F;
	F.open(groupName + ".txt", ofstream::out | ofstream::app);

	string line;

	getline(F, line);
	getline(F, line);

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


vector<string> Coach::sortMembers(string groupName)
{
	vector<string> result;

	ifstream F;
	F.open(groupName + ".txt", ofstream::out | ofstream::app);

	string line;

	getline(F, line);
	getline(F, line);

	while (true)
	{
		getline(F, line);
		if (line == "") break;
		result.push_back(line);
	}

	sort(result.begin(), result.end());

	F.close();

	return result;
}

vector<string> Coach::getInfoOfMember(string login)
{
	vector<string> result;

	ifstream F;
	F.open(login +  ".txt", ofstream::out | ofstream::app);

	string line;
	for (int i = 0; i < 5; i++)
	{
		getline(F, line);
		result.push_back(line);
	}

	F.close();

	return result;
}