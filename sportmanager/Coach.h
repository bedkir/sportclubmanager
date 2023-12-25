#pragma once
#include "User.h"

#include <iostream>
#include <vector>
using namespace std;

class Coach : public User
{
public:
	Coach();
	Coach(string, string);
	Coach(Coach &);
};

