#pragma once
#include "User.h"

#include <iostream>
#include <vector>
using namespace std;

class Group
{
private:
	string sportName;
	vector<User> members;

public:
	Group();
	Group(string,  vector<User>);
	Group(Group &);
};

