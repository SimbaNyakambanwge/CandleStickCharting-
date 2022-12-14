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
	const int COLUMNS = 6;
	const int DAYS_INC = 3;
	const int LARGE_DAYS_INC = 10;
	const int DIVISIONS = 30;
	const int PERIOD_9 = 9;
	const int PERIOD_5 = 5;
	char yaxisbar = char(180);
	char positivebar = char(219);
	char negativebar = char(176);
	char wick = char(179);
	const double HALF_INC = 50;
	char macharacter = char(167);
	double ma1 = 0.0;
	double ma2 = 0.0;
	const int SCALED_XAXIS = 100;
		
public:
	
	void datasave();// this function saves data into my six vectors
	void xaxiscalculation(ostream& os); // a generic code used to output my X axis for all my graphs
	void plotbargraph(ostream& os); // my bargraph plotting function
	void plotsma(ostream& os);
	void plotma(ostream& os);
	void plotcandlestick(ostream& os);
	void outputtoconsole(ostream& os);// using os to output either to text file or console
	void outputfile();
	bool loopback(); // function that allows user to rerun program for another file
	void reversecandledata();
	
	
};
