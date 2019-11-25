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

void DataManager::datasave() {

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
		reversedata();
		
		double maximum = *max_element(High.begin(), High.end());
		
		double minimum = *min_element(Low.begin(), Low.end());
		
		double Difference;

		double increment;

		Difference = maximum - minimum;
		
		increment = Difference / 30;

		const double HALF_INC = increment / 2;
		
		
		for (int rows = 0; rows < 30; rows++) { // looping through rows
			maximum = maximum - increment;
			cout << setw(5) << maximum << " " << char(180);

			for (int j = 0; j < days.size(); j++) { // loop through col

				if (Close[j] >= maximum - HALF_INC && maximum + HALF_INC >= Open[j])
				{
					cout << char(219);

				}
				else if (Open[j] >= maximum - HALF_INC && maximum + HALF_INC >= Close[j])
				{
					cout << char(176);
				}
				else if (maximum - HALF_INC <= High[j] && maximum + HALF_INC >= Low[j]) {
					cout << char(179);
				}
				else if (maximum + HALF_INC >= High[j] && maximum - HALF_INC <= Low[j]) {
					cout << char(179);
				}
				else
				{
					cout << " ";
				}


			}
			cout << endl;
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
void DataManager::calculationsXaxis() {
	 reversedata();
	/*for (int line = 0; line < 65; line++)
	{
		cout.fill(char(196));
		cout << char(196);

	}*/
	cout << endl;
	cout << setw(7);
	cout << "   ";
	for (int x = 0; x < days.size(); x += 3)
	{
		cout.fill('0');
		cout << setw(2) << days[x] << " ";

	}
	cout << endl;
	cout << endl;

}
void DataManager::bargraph() {
	reversedata();
	long long increment;
	long long difference;
	long long Yaxis;
	long long highest = *max_element(Volume.begin(), Volume.end());
	long long lowest = *min_element(Volume.begin(), Volume.end());
	difference = highest - lowest;
	increment = (difference / 30) ;
	
	
	for (int i = 0; i < 30; i++) {
		highest = (highest - increment);
		
		Yaxis = highest / divider;
		
		cout << setw(3) << Yaxis << "Bil " << char(180);
		
		for (int j = 0; j < days.size(); j++) {
			if (Volume[j] >= highest && Open[j] < Close[j]) {
				cout << char(219);
			}
			else if (Volume[j] >= highest && Open[j] > Close[j]) {
				cout << char(176);
			}
			else
				cout << " ";
				
		}
		cout << endl;
	}
	calculationsXaxis();
}
void DataManager::reversedata() {
	reverse(Open.begin(), Open.end());
	reverse(High.begin(), High.end());
	reverse(Low.begin(), Low.end());
	reverse(Close.begin(), Close.end());
	reverse(Volume.begin(), Volume.end());
	reverse(Market_Cap.begin(), Market_Cap.end());
	reverse(days.begin(), days.end());
}
void DataManager::sma() {
	reversedata();

	double maximum = *max_element(High.begin(), High.end());
    double minimum = *min_element(Low.begin(), Low.end());
	double Difference;
    double increment;
    Difference = maximum - minimum;
	increment = Difference / 30;
	double sma = 0.0;
	for (int rows = 0; rows < 30; rows++) { // looping through rows
		maximum = maximum - increment;
		cout << setw(5) << maximum << " " << char(180);

		for (int j = 0; j < days.size(); j++) { // loop through col

			if (j > 9) {
				
					for (int x = 0; x < 9; x++) {
						sma =  Close[j-x] + sma;
						
						
					}
				
			}
			sma = sma / 9;
			
		}
		cout << endl;
		cout << char(129);
		
	}
	calculationsXaxis();
}
