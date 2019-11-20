#pragma once
#ifndef candlestick_H
#define candlestick_H
#endif // !candlestick_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
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
	FinanceDirector(string file);
	void directorfiles();
};

class Candle
{
private:
	vector<double>High;
	vector<double>Low;
	vector<double>Open;
	vector<double>Close;
	vector<double>days;
	string line;

public:
	double max;
	double min;
	double maxValue;
	double highest;
	void datasave();
	void calculations();
	void plot();
};
class Bargraph
{
public:

};
