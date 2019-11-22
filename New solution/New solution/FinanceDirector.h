#pragma once
#include "Candle.h"
#include<vector>
class FinanceDirector
{
public: FinanceDirector();

		void openFile();

private:
	vector<Candle>eachCandle;

};

