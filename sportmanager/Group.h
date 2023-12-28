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

	static int amountOfGroups; // static-поле кількість груп

public:
	Group();
	Group(string, Coach, vector<string>);
	Group(Group &);
	~Group();

	Group& operator++(); // ++Group - префіксний інкремент
	Group operator++(int); // Group++ - постфіксний інкремент

	inline string getSportName() const;
	inline string getGroupName() const;
	inline Coach getCoach() const;
	inline vector<string> getMembers() const;
	static int getAmountOfGroups(); // static-метод, геттер

	inline Group& setSportName(string);
	inline Group& setGroupName(string);
	inline Group& setCoach(const Coach&);
	inline Group& setMembers(vector<string>&);
	static void setAmountOfGroups(); // static-метод, сеттер

	void fillGroupData(string);

};

