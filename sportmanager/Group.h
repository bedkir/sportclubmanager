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
	Coach coach;
	vector<string> members;

	static int amountOfGroups;

public:
	Group();
	Group(string, Coach, vector<string>);
	Group(Group &);
	virtual ~Group();

	inline string getSportName() const;
	inline string getGroupName() const;
	inline Coach getCoach() const;
	inline vector<string> getMembers() const;
	static int getAmountOfGroups();

	inline Group& setSportName(string);
	inline Group& setGroupName(string);
	inline Group& setCoach(const Coach&);
	inline Group& setMembers(vector<string>&);
	static void setAmountOfGroups();

	void fillGroupData(string);

};

