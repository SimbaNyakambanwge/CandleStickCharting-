#include "FinanceDirector.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "DataManager.h"

using namespace std;

FinanceDirector::FinanceDirector() {

	cout << "Data Analysis" << endl;
	cout << "Author:  Simbarashe Nyakambangwe" << endl;
	cout << "SID:  8316064" << endl << endl;

	cout << "please enter a name of a file including .csv" << endl;
	cout << endl;
	cout << "The options are" << endl;
	cout << "BTChist.csv" << endl;
	cout << "BTChist2.csv" << endl;
	cout << "BTChist3.csv" << endl;
	cout << "BTChist4.csv" << endl;
	cout << endl;
}
void FinanceDirector::output() {

	DataManager Managerobject;
	Managerobject.datasave();
	Managerobject.candlestick(cout);
	Managerobject.bargraph(cout);
	Managerobject.sma(cout);
	Managerobject.ma(cout);
	Managerobject.savetofile(cout);
	Managerobject.outputfile();


	while (true) {
		DataManager Managerobject;
		Managerobject.datasave();
		Managerobject.candlestick(cout);
		Managerobject.bargraph(cout);
		Managerobject.sma(cout);
		Managerobject.ma(cout);
		Managerobject.savetofile(cout);
		Managerobject.outputfile();

	}

	
}
void FinanceDirector::error(){
	cout << "Please retype the name of the input file" << endl;
	
}

	
	
	
	
	
	
	
	
	
	
	
	

	

	

