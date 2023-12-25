#pragma once
#include "User.h"

#include <iostream>
#include <vector>
using namespace std;

class Group
{
private:
	string sportName;
	User coach;
	vector<User> members;

public:
	Group();
	Group(string, User, vector<User>);
	Group(Group &);
	virtual ~Group();

	inline string getSportName() const;
	inline User getCoach() const;
	inline vector<User> getMembers() const;

	inline Group& setSportName(string);
	inline Group& setCoach(User&);
	inline Group& setMembers(vector<User>&);
};

