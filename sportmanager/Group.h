#pragma once
#include "Coach.h"

#include <iostream>
#include <vector>
using namespace std;

class Group
{
private:
	string sportName;
	string groupName;
	string coach;
	vector<string> members;

	static int amountOfGroups;

public:
	Group();
	Group(string, string, vector<string>);
	Group(Group &);
	virtual ~Group();

	inline string getSportName() const;
	inline string getGroupName() const;
	inline string getCoach() const;
	inline vector<string> getMembers() const;
	static int getAmountOfGroups();

	inline Group& setSportName(string);
	inline Group& setGroupName(string);
	inline Group& setCoach(string);
	inline Group& setMembers(vector<string>&);
	static void setAmountOfGroups();

	void fillGroupData(string);

};

