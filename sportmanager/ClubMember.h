#pragma once
#include "User.h"
#include "Sport.h"

#include <iostream>
#include <vector>
using namespace std; 

class ClubMember : public User
{
private:
	vector<Sport> sports;

public:
	ClubMember();
	ClubMember(string, string, vector<Sport>);
	ClubMember(ClubMember &);

	inline vector<Sport> getSports() const;

	inline ClubMember& setSports(vector<Sport>&);
};

