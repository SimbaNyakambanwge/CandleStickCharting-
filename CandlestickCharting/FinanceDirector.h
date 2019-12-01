#pragma once
#ifndef FinanceDirector_H
#define FincanceDirector_H
#endif // !financedirector_H
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class FinanceDirector
{
private:
	string director;
	int user;
	string choice;
public:
	FinanceDirector();
	
	void error();
	void output();
	void userinteraction();
	
	

};



