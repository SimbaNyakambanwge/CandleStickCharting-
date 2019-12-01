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
	vector<double>high;
	vector<double>low;
	vector<double>open;
	vector<double>close;
	vector<long long>volume;
	vector<double>market_Cap;
	vector<double> days;
	const int DIVIDER = 1000000000;
	int filenumber;
public:
	
	void datasave();
	void xaxiscalculation(ostream& os);
	void bargraph(ostream& os);
	void reversedata(ostream& os);
	void sma(ostream& os);
	void ma(ostream& os);
	void candlestick(ostream& os);
	void savetofile(ostream& os);
	void outputfile();
	bool loopback();
	
	

};
