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
void FinanceDirector::finance() {
	string filename;
	director = filename;
	cin >> filename;
	ifstream inputdata;
	inputdata.open(filename);

	ifstream inputFilestream;
	inputFilestream.open(filename);

	if (inputFilestream.good())
	{
		DataManager object;
		object.datasave();

	}
	else
		cout << "Please retype the name of the input file" << endl;
}
void FinanceDirector::error(){
	cout << "Please retype the name of the input file" << endl;
	
}
void FinanceDirector::savingfileprogram() {
	cout << "this is where the saving of the file will occur" << endl;
}
	
	
	
	
	
	
	
	
	
	
	/*DataManager();
	DataManager Managerobject;
	fstream analysisfile;
	analysisfile.open("output_file.txt");
	analysisfile.write  (Managerobject.bargraph();)
	analysisfile.close();*/
	

	

	

