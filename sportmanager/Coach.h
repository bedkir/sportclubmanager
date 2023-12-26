#pragma once
#include "User.h"

using namespace std;

class Coach : public User
{
public:
	static Coach &C;

	Coach();
	Coach(string, string, string, string, vector<string>);
	Coach(const Coach &);
	virtual ~Coach();

	Coach& operator=(const Coach&);

	bool SignIn(string, string) override;
	bool SignUp(string, string, string, string, string);

	void createGroup(string);
	vector<string> openGroup(string);
	vector<string> searchMembers(string, string);
	vector<string> sortMembers(string);
	vector<string> getInfoOfMember(string);
	void deleteMember(string, string, string, string);
};

