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
public:
	FinanceDirector();
	void finance();
	void error();
	void savingfileuser();
	void savingfileprogram();
};



