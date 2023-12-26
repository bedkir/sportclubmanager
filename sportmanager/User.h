#pragma once
#include <iostream>
using namespace std;

class User
{
protected:
	string login;
	string password;

	string name;
	string surname;

public:
	User();
	User(string, string, string, string);
	User(const User &);
	virtual ~User();

	inline string getLogin() const;
	inline string getPassword() const;
	inline string getName() const;
	inline string getSurname() const;

	inline User& setLogin(string);
	inline User& setPassword(string);
	inline User& setName(string);
	inline User& setSurname(string);

	virtual bool SignIn(string, string) = 0;
};

