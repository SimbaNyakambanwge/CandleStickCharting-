#pragma once
#ifndef DataManager_H
#define DataManager_H
#endif // !datamanager_H
#include <string>
#include <vector>
#include <algorithm>
#include "FinanceDirector.h"
using namespace std;

class DataManager
{
private:
	string director;
	vector<double>High;
	vector<double>Low;
	vector<double>Open;
	vector<double>Close;
	vector<long long>Volume;
	vector<double>Market_Cap;
	vector<double> days;
	int divider = 1000000000;



public:
	
	void datasave();
	void calculationsXaxis();
	void bargraph();
	void reversedata();

};
