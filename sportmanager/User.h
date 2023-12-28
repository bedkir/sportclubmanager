#pragma once
#include <iostream>
#include <vector>

using namespace std;

class User
{
protected:
	string login;
	string password;

	string name;
	string surname;

	vector<string> groups;

public:
	User();
	User(string, string, string, string, vector<string>);
	User(const User &);
	virtual ~User();

	string operator[](int index) const;

	bool operator==(const User&) const;

	inline string getLogin() const;
	inline string getPassword() const;
	inline string getName() const;
	inline string getSurname() const;
	inline vector<string> getGroups() const;

	inline User& setLogin(string);
	inline User& setPassword(string);
	inline User& setName(string);
	inline User& setSurname(string);
	inline User& setGroups(vector<string>&);

	virtual bool SignIn(string, string) = 0;
	
	virtual void getGroupsListFromFile() = 0;

	void deleteMember(string, string, string, string);
};

