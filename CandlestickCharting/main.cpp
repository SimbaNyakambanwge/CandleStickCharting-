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
	Managerobject.calculationsxaxis(cout);
	Managerobject.bargraph(cout);
	Managerobject.sma(cout);
	Managerobject.ma(cout);
	Managerobject.savetofile(cout);
	FinanceDirector object;
	
	
		
		
		
}

