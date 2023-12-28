#pragma once
#include "User.h"

using namespace std;

class Coach : public User
{
public:
	static Coach &C; // static-поле

	Coach();
	Coach(string, string, string, string, vector<string>);
	Coach(const Coach &);
	virtual ~Coach();

	Coach& operator=(const Coach&); // оператор присвоювання

	bool SignIn(string, string) override; // перевизначаємо віртальний метод
	bool SignUp(string, string, string, string, string);

	void getGroupsListFromFile() override;

	void createGroup(string);
	vector<string> openGroup(string);
	vector<string> searchMembers(string, string);
	vector<string> sortMembers(string);
	vector<string> getInfoOfMember(string);

	// оператори потокового вводу-виводу
	friend ostream& operator<<(ostream&, const Coach&);
	friend istream& operator>>(istream&, Coach&);
};

