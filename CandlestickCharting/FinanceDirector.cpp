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

FinanceDirector::FinanceDirector(){}


void FinanceDirector::output() {
	DataManager Managerobject;
	Managerobject.datasave();
	cout << "CandleStick Chart" << endl;
	cout << endl;
	Managerobject.plotcandlestick(cout);
	cout << "Bar Graph" << endl;
	cout << endl;
	Managerobject.plotbargraph(cout);
	cout << "Simple Moving Average" << endl;
	cout << endl;
	Managerobject.plotsma(cout);
	cout << "Moving Average" << endl;
	cout << endl;
	Managerobject.plotma(cout);
	Managerobject.outputtoconsole(cout);
	Managerobject.outputfile();
	
		




	while (true) {
		DataManager Managerobject;
		Managerobject.datasave();
		cout << "CandleStick Chart" << endl;
		cout << endl;
		Managerobject.plotcandlestick(cout);
		cout << "Bar Graph" << endl;
		cout << endl;
		Managerobject.plotbargraph(cout);
		cout << "Simple Moving Average" << endl;
		cout << endl;
		Managerobject.plotsma(cout);
		cout << "Moving Average" << endl;
		cout << endl;
		Managerobject.plotma(cout);
		Managerobject.outputtoconsole(cout);
		Managerobject.outputfile();

	}
	while (false) {
		system("exit");
	}


		
}
void FinanceDirector::error(){
	cout << "Please retype the name of the input file" << endl;
	DataManager object;
	object.datasave();
}
void FinanceDirector::userinteraction() {
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

	
	
	
	
	
	
	
	
	
	
	
	

	

	

