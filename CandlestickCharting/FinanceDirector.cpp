#include "Candlestick.h"
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
	
	cout << "Candlestick" << endl;
	cout << "Author:  Simbarashe Nyakambangwe" << endl;
	cout << "SID:  8520524" << endl << endl;

	cout << "please enter a name of a file including csv" << endl;
}

void FinanceDirector::directorfiles() {

	string filename;
	director = filename;
	cin >> filename;
	ifstream File;
	File.open(filename);

	ifstream inputFileStream;
	inputFileStream.open(filename); // hardcoded filename, for now...


	


	if (inputFileStream.good())
	{
		cout << "Input file is processing below:" << endl << endl;

		string line;
		getline(inputFileStream, line); // read 1st line, skip 1st line (headers), might fail!
		getline(inputFileStream, line); // read 2nd line, might fail!


		while (!inputFileStream.fail()) // check for failbit
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
				if (i == 3)
					Close.push_back(fieldData);
				if (i == 4)
					Volume.push_back(fieldData);
				if (i == 5)
					Market_Cap.push_back(fieldData);

			}
			cout << endl;
			cout << setprecision(0) << endl;;
			getline(inputFileStream, line); // read next line
		}

		cout << endl;
		//int user;
		//cout << "How many divisions?" << endl;
		//cin >> user;
		double maximum = *max_element(High.begin(), High.end());
		cout << maximum << " = Max" << endl;
		double minimum = *min_element(Low.begin(), Low.end());
		cout << minimum << " = Min" << endl;
		cout << days.size() <<" " << "Days" << endl;
		double Difference;
		double increment;
		Difference = maximum - minimum;
		cout << "minimum minus maximum value" <<" "<< Difference << endl;
		increment = Difference / High.size();
		cout << " Incrementing by" <<" "<< increment << endl;

		//Y Axis
		int spaces = 3;
				for (int j = 1; j < increment; j++) {
					maximum = maximum - increment;
					
					//cout << setw(5) << maximum << char(180) << endl;
					if (Close[j] > maximum )
					{
						cout << setw(8)<< maximum << char(180)<< setw(spaces)<< char(219) << endl;

					}
					else
					{
						cout << setw(8) << maximum << char(180) << setw(spaces)<< " " << endl;
					}
					if
						(Close[j] < Open[j])
					{
						cout << setw(8) << maximum << char(180) <<setw(spaces)<< char(176) << endl;
					
					
						cout << setw(8) << maximum << char(180) << setw(spaces)<<char(192) << endl;
					}
					
					if (High[j] >= maximum)
					{
						cout << setw(8) << maximum << char(180) <<setw(spaces)<< char(194) << endl;
					}
					spaces++;
					
				}


		for (int x_axis = 0; x_axis < 50; x_axis++)
		{
			cout.fill(char(196));
			cout << setw(3) << char(196);
		}
		cout << endl;
		cout << setw(0) << "      ";
	    cout.fill(' ');
		for (int line = 1; line < 30; line++)
		{
			cout << setw(3) << " " << days[line];
		}
		cout << endl;
		cout << endl;

		if (inputFileStream.eof()) {
			cout << "Reached the end of file marker.  File data read sucessfully." << endl;
		}
		else {
			cout << "Error in input file." << endl;
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
void FinanceDirector::calculations() {
	
}