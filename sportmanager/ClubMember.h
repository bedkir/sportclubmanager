#pragma once
#include "User.h"
#include "Group.h"

#include <iostream>
#include <vector>
using namespace std; 

class ClubMember : public User
{
private:
	vector<Group> groups;

public:
	ClubMember();
	ClubMember(string, string, vector<Group>);
	ClubMember(ClubMember &);
	virtual ~ClubMember();

	inline vector<Group> getGroups() const;

	inline ClubMember& setGroups(vector<Group>&);
};

