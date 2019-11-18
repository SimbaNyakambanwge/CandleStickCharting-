#pragma once
#ifndef candlestick_H
#define candlestick_H
#endif // !candlestick_H
#include <string>
#include <vector>
using namespace std;

class CandlestickChart
{
private: 
	
public:
	

};

class FinanceDirector
{
private:
	 string director;

public:
	FinanceDirector();
		void directorfiles();
};

class Candle
{
public:
	vector<double>High;
	vector<double>Low;
	vector<double>Open;
	vector<double>Close;
	vector<double>days;
	string line;
	
	void datasave();
	double max;
	double min;
	double maxValue;
	double highest;
	
	void calculations();
	void plot();
};
class Bargraph
{
public:
	
};
