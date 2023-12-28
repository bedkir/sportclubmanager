#pragma once
#include <iostream>
#include <vector>

using namespace std;

class User
{
protected:
	string login;
	string password;

	string name;
	string surname;

	vector<string> groups;

public:
	User(); // конструктор за замовчуванням
	User(string, string, string, string, vector<string>); // конструктор з параметрами
	User(const User &); // конструктор копій
	virtual ~User(); // віртуальний деструктор

	string operator[](int index) const; // оператор індексації

	bool operator==(const User&) const; // опертор порівняння

	inline string getLogin() const;
	inline string getPassword() const;
	inline string getName() const;
	inline string getSurname() const;
	inline vector<string> getGroups() const;

	inline User& setLogin(string);
	inline User& setPassword(string);
	inline User& setName(string);
	inline User& setSurname(string);
	inline User& setGroups(vector<string>&);

	// чисто віртуальні методи
	virtual bool SignIn(string, string) = 0;
	
	virtual void getGroupsListFromFile() = 0;

	void deleteMember(string, string, string, string);
};

