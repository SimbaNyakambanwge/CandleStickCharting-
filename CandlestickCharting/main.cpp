#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "FinanceDirector.h"
#include "DataManager.h"

using namespace std;



int  main()

{

       
	DataManager Managerobject;
	Managerobject.datasave();
	Managerobject.candlestick(cout);
	Managerobject.calculationsxaxis();
	Managerobject.bargraph();
	Managerobject.sma();
	FinanceDirector object;
	
	
		
		
		
}

