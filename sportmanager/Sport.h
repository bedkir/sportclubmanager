#pragma once

#include <iostream>
using namespace std;

class Sport
{
private:
	string name;
	int amountOfMembers;

public:
	Sport();
	Sport(string, int);
	Sport(Sport &);

	inline string getName() const;
	inline int getAmountOfMembers() const;

	inline Sport& setName(string);
	inline Sport& setAmountOfMembers(int);
};

