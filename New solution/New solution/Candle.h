#pragma once
#include <vector>
#include<string>
using namespace std;
class Candle
{
public:
	Candle(string Month, int Day, double Year, double Open, double High, double Low, double Close, double Volume, double Market_Cap);
    
private:
	string month;
	int day;
	double year;
	double open;
	double high;
	double low;
	double close;
	double volume;
	double market_cap;

};


