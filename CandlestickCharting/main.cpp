#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "FinanceDirector.h"
#include "DataManager.h"
#include <stdlib.h>

using namespace std;

int  main()
{
	FinanceDirector object;
	object.userinteraction();
	object.output();
	system("exit");
}


