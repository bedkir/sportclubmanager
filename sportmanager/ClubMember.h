#pragma once
#include "User.h"
#include "Group.h"

#include <iostream>
#include <vector>
using namespace std; 

class ClubMember : public User
{
private:
	int birthYear;
	vector<string> groups;

public:
	ClubMember();
	ClubMember(string, string, string, string, int, vector<string>);
	ClubMember(const ClubMember &);
	virtual ~ClubMember();

	inline int getBirthYear() const;
	inline vector<string> getGroups() const;

	inline ClubMember& setBirthYear(int);
	inline ClubMember& setGroups(vector<string>&);

	bool SignIn(string, string) override;
	bool SignUp(string, string, string, string, string, int);
};

