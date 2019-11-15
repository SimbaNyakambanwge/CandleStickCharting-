#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	cout << "Candlestick" << endl;
	cout << "Author:  Simbarashe Nyakambangwe" << endl;
	cout << "SID:  8520524" << endl << endl;

	// Read input data from .csv file.
	//  Assumes the data is in a particular format:
	//    Date,Open*,High,Low,Close**,Volume,Market Cap
	//    "Jul 28, 2019", 9491.63, 9575.55, 9252.3, 9552.86, 13738687093, 1.70462E+11
	//  First we can read line by line, then we can break the line into multiple values by comma.

	// Note that immediately after reading each field, we simply write them to the console.
	//  For the coursework you will want to change this, so that the values are stored
	//  in some form of temporary data-structure for further processing later on.

	// We should be checking for errors in the input file e.g. formatting at every point after a read.
	//  I.e. read line, check, read line, check...  or read field, check, read field, check.
	//  However, I have only checked for some of the input file reading errors at each point.


	cout << "What file would you like you like to open?:" << endl;
	cout << " BTChist.csv" << setw(20) << " BTChist1.csv" << endl;
	cout << " BTChist2.csv" << setw(20) << " BTChist3.csv" << endl;



	string filename;
	cin >> filename;
	ifstream File;
	File.open(filename);

	ifstream inputFileStream;
	inputFileStream.open(filename); // hardcoded filename, for now...

	vector<string>Date;
	vector<double> firstVector;
	vector<double> secondVector;

	vector<double>High;
	vector<double>Low;
	vector<double>Open;
	vector<double>Close;
	vector<double>Volume;
	vector<double>Market_Cap;
	vector<int> days;


	if (inputFileStream.good())
	{
		cout << "Input file is good start processing..." << endl << endl;

		cout << right << setw(14) << "Date:" << setw(16) << "Open:" << setw(16) << "High:" << setw(16) << "Low:" << setw(16) << "Close:" << setw(16) << "Volume:" << setw(16) << "Market Cap:" << endl;
		cout.fill(char(196));
		cout << setw(112) << char(191) << endl;
		cout.fill(' ');

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




			cout << setw(14) << trimmedDate << " " << char(179);

			cout << fixed;

			for (int i = 0; i < 6; i++) { // loops through the remaining 6 columns
				string field;
				double fieldData;
				getline(ss, field, ','); // read next field, might fail
				stringstream fss(field);
				fss >> fieldData; // try to convert to a double, this might fail !!!
				cout << setw(14) << setprecision(0) << fieldData << " " << char(179);
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

			getline(inputFileStream, line); // read next line
		}

		cout << endl;
		double max = *max_element(High.begin(), High.end());
		cout << max << " = Max" << endl;
		double min = *min_element(Low.begin(), Low.end());
		cout << min << " = Min" << endl;
		cout << days.size() << "Days" << endl;
		double maxValue;
		double highest;
		maxValue = max - min;
		cout << "minimum minus maximum value" << maxValue << endl;
	     highest = maxValue / days.size();
		cout << " Highest value" << highest << endl;



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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file