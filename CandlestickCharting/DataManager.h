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
	const int DIVIDER = 100000000;
	



public:
	
	void datasave();
	void calculationsxaxis(ostream& os);
	void bargraph(ostream& os);
	void reversedata(ostream& os);
	void sma(ostream& os);
	void candlestick(ostream& os);
	void savetofile(ostream& os);
	void outputfile();
	
	

};
