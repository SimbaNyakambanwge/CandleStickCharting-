#pragma once
#ifndef FinanceDirector_H
#define FinanceDirector_H
#endif // !FinanceDirector_H
#include <string>
#include <vector>
#include "DataManager.h"
using namespace std;


class FinanceDirector
{
private:
	string director;
	vector<double>High;
	vector<double>Low;
	vector<double>Open;
	vector<double>Close;
	vector<double>Volume;
	vector<double>Market_Cap;
	vector<double> days;
	
	
public:
	FinanceDirector();
	void directorfiles();
	void calculations();
	
};

