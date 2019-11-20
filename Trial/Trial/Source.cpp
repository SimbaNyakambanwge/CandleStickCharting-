#include "Trial.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#pragma once
using namespace std;

FinanceDirector::FinanceDirector() {

	cout << "Candlestick" << endl;
	cout << "Author:  Simbarashe Nyakambangwe" << endl;
	cout << "SID:  8316064" << endl << endl;
	cout << "please enter a name of a file including csv" << endl;
}


void FinanceDirector::directorfiles() {

	string filename;
	director = filename;
	cin >> filename;
	ifstream File;
	File.open(filename);

	ifstream inputFileStream;
	inputFileStream.open(filename); // 

	(inputFileStream.good());
	//{
	cout << "Input file is processing below:" << endl << endl;

	string line;





	//}


	if (inputFileStream.eof()) {
		cout << "Reached the end of file marker.  File data read sucessfully." << endl;
	}
	else {
		cout << "Error in input file." << endl;
	}
}
}

	else
	{
	cout << "Error opening input file, ";
	cout << "check 'BTChist.csv' exists in correct directory." << endl;
	cout << "Please input another valid filename" << endl;


	}



	inputFileStream.close();


}

void Candle::datasave()
{



	stringstream ss(line);

	string date1;
	string date2;
	getline(ss, date1, ','); // read first field from line, might fail
	getline(ss, date2, ','); // read second field from line, might fail
	string date = date1 + date2;
	string trimmedDate = date.substr(1, date.size() - 2);
	stringstream iss(date1);
	string month;
	int day;
	getline(iss, month, ' ');
	iss >> day;
	days.push_back(day);




	//cout << setw(14) << trimmedDate << " " << char(179);

	cout << fixed;
}
for (int i = 0; i < 6; i++) { // loops through the remaining 6 columns
	string field;
	double fieldData;
	getline(ss, field, ','); // read next field, might fail
	stringstream fss(field);
	fss >> fieldData; // try to convert to a double, this might fail !!!

	if (i == 0)
		Open.push_back(fieldData);
	if (i == 1)
		High.push_back(fieldData);
	if (i == 2)
		Low.push_back(fieldData);
	if (i == 3) {
		Close.push_back(fieldData);
	}
}

}
void Candle::calculations
{
	double max;
	double min;
	double maxValue;
	double highest;
	void datasave();
	 max = *max_element(High.begin(), High.end());
	cout << max << " = Max" << endl;
	 min = *min_element(Low.begin(), Low.end());
	cout << min << " = Min" << endl;
	cout << days.size() << "Days" << endl;
	maxValue = max - min;
	cout << "minimum minus maximum value" << maxValue << endl;
	highest = maxValue / days.size();
	cout << " Highest value" << highest << endl;
}
void Candle::plot
{
	do
{
	max = max - highest;
	cout << setw(5) << max << char(179) << endl;
} while (max > min);

cout << " ";

for (int x_axis = 0; x_axis < 57; x_axis++)
{
	cout.fill(char(196));
	cout << setw(3) << char(196);
}
cout << endl;
cout << setw(1) << " ";
cout.fill(' ');
for (int line = 0; line < 30; line++)
{
	cout << setw(3) << "    " << days[line];
}
cout << endl;

}