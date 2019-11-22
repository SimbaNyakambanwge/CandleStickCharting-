#include "Candle.h"



Candle::Candle(string Month, int Day, double Year, double Open, double High, double Low, double Close, double Volume, double Market_Cap)
{
	this->month = Month; 
	this->day = Day;
	this->year = Year;
	this->open = Open;
	this->high = High;
	this->low = Low;
	this->close = Close;
	this->volume = Volume;
	this->market_cap = Market_Cap;

}
