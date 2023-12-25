#pragma once
#include "User.h"
#include "Group.h"

#include <iostream>
#include <vector>
using namespace std;

class Coach : public User
{
private:
	vector<Group> groups;

public:
	Coach();
	Coach(string, string, vector<Group>);
	Coach(Coach &);
	virtual ~Coach();

	inline vector<Group> getGroups() const;

	inline Coach& setGroups(vector<Group>&);

	Coach& operator=(const Coach&);
};

