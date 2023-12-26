#pragma once
#include "User.h"
#include "Group.h"

#include <iostream>
#include <vector>
using namespace std; 

class ClubMember : public User
{
private:
	vector<string> groups;

public:
	ClubMember();
	ClubMember(string, string, vector<string>);
	ClubMember(const ClubMember &);
	virtual ~ClubMember();

	inline vector<string> getGroups() const;

	inline ClubMember& setGroups(vector<string>&);

	bool SignIn(string, string) override;
	bool SignUp(string, string, string) override;
};

