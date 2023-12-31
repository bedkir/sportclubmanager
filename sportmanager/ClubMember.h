#pragma once
#include "User.h"
#include "Group.h"

using namespace std; 

class ClubMember : public User
{
private:
	int birthYear;

public:
	static ClubMember& CM;

	ClubMember();
	ClubMember(string, string, string, string, int, vector<string>);
	ClubMember(const ClubMember &);
	virtual ~ClubMember();

	inline int getBirthYear() const;

	inline ClubMember& setBirthYear(int);

	bool SignIn(string, string) override;
	bool SignUp(string, string, string, string, string, int);

	void getGroupsListFromFile() override;
	vector<string> showAvailableGroups();
	vector<string> searchGroup(string);
	void enterTheGroup(string, string);
	Group groupInfo(string);
};