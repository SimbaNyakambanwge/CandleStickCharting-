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
	FinanceDirector Financeobject;
       
	DataManager Managerobject;
	Managerobject.datasave();
	Managerobject.calculationsXaxis();
	Managerobject.bargraph();
	
		
		
		
}

