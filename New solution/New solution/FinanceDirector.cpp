#include "FinanceDirector.h"
using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

FinanceDirector::FinanceDirector()
{
	cout << "You are inside the default constructor for FinanceDirector";
}

 void FinanceDirector::openFile()
{
	string filename;
	//director = filename;
	cin >> filename;
	ifstream File;
	File.open(filename);

	ifstream inputFileStream;
	inputFileStream.open(filename); // hardcoded filename, for now...

	if (inputFileStream.good())
	{
		cout << "Input file is good start processing..." << endl << endl;

		string line;
		getline(inputFileStream, line); // read 1st line, skip 1st line (headers), might fail!
		getline(inputFileStream, line); // read 2nd line, might fail!

		while (!inputFileStream.fail()) // check for failbit
		{
			string MonthAndDay;
			double Year, Open, High, Low, Close, Volume, MarketCap;

			string yearString, openString, highString, lowString, closeString, volumeString, marketCapString;
			while (getline(inputFileStream, line)) {

				stringstream ss(line);
				getline(ss, MonthAndDay, ',');
				string trimmedDate = MonthAndDay.substr(1, MonthAndDay.size() - 1);

				getline(ss, yearString, ',');
				Year = stod(yearString);

				getline(ss, openString, ',');
				Open = stod(openString);

				getline(ss, highString, ',');
				High = stod(highString);

				getline(ss, lowString, ',');
				Low = stod(lowString);

				getline(ss, closeString, ',');
				Close = stod(closeString);

				getline(ss, volumeString, ',');
				Volume = stod(volumeString);

				getline(ss, marketCapString, ',');
				MarketCap = stod(marketCapString);
				cout << MarketCap;
			}
		}
		
	}
}