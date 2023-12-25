#pragma once
#include <iostream>
using namespace std;

class User
{
protected:
	string login, password;

public:
	User();
	User(string, string);
	User(const User &);
	virtual ~User();

	inline string getLogin() const;
	inline string getPassword() const;

	inline User& setLogin(string);
	inline User& setPassword(string);

};

