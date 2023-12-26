#include "ClubMember.h"
#include "Group.h"

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

	this->getGroupsListfromFile();

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
	  << endl << surname << endl << birthYear << endl;

	F.close();


	ofstream T;
	T.open("Members.txt", ofstream::out | ofstream::app);

	T << login << endl;

	T.close();

	return true;
}



