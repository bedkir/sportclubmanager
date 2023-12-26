#pragma once
#include "User.h"

#include <iostream>
#include <vector>
using namespace std;

class Coach : public User
{
private:
	vector<string> groups;

public:
	Coach();
	Coach(string, string, string, string, vector<string>);
	Coach(const Coach &);
	virtual ~Coach();

	inline vector<string> getGroups() const;

	inline Coach& setGroups(vector<string>&);

	Coach& operator=(const Coach&);

	bool SignIn(string, string) override;
	bool SignUp(string, string, string, string, string);
};

