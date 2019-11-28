#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "DataManager.h"
#include "FinanceDirector.h"
using namespace std;

FinanceDirector object;
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
			
			getline(inputFileStream, line); // read next line
			
		}
		
		cout << endl;
		
		
		

	}

	
	else
	{
	FinanceDirector object;
	object.error();
		
	}



	inputFileStream.close();


}
void DataManager::calculationsxaxis(ostream& os) {
	reverse(days.begin(), days.end());
	
	os << endl;
	os << setw(7);
	os << "   ";
	for (int x = 0; x < days.size(); x += 3)
	{
		os.fill('0');
		os << setw(2) <<setprecision(0)<< days[x] << " ";

	}
	os << endl;
	os << endl;

}
void DataManager::bargraph(ostream& os) {
	reverse(Volume.begin(), Volume.end());
	reverse(days.begin(), days.end());
	long long increment;
	long long difference;
	long long Yaxis;
	long long highest = *max_element(Volume.begin(), Volume.end());
	long long lowest = *min_element(Volume.begin(), Volume.end());
	difference = highest - lowest;
	increment = (difference / 30) ;
	
	
	for (int i = 0; i < 30; i++) {
		highest = (highest - increment);
		
		Yaxis = highest / DIVIDER;
		
		os << setw(3) << setprecision(0)<< Yaxis << "Bil " << char(180);
		
		for (int j = 0; j < days.size(); j++) {
			if (Volume[j] >= highest && Open[j] < Close[j]) {
				os << char(219);
			}
			else if (Volume[j] >= highest && Open[j] > Close[j]) {
				os << char(176);
			}
			else
				os << " ";
				
		}
		os << endl;
	}
	calculationsxaxis(os);
}
void DataManager::reversedata(ostream&os) {
	
	
	
	
	
	reverse(Market_Cap.begin(), Market_Cap.end());
	
}
void DataManager::sma(ostream& os) {
	
	reverse(High.begin(), High.end());
	reverse(Low.begin(), Low.end());
	reverse(days.begin(), days.end());

	double maximum = *max_element(High.begin(), High.end());
    double minimum = *min_element(Low.begin(), Low.end());
	double Difference;
    double increment;
    Difference = maximum - minimum;
	increment = Difference / 30;
	const double HALF_INC = increment / 2;
	double sma= 0.0;
	
	for (int rows = 0; rows < 30; rows++) { // looping through rows
		maximum = maximum - increment;
		os << setw(5) << setprecision(0)<< maximum << " " << char(180);

		for (int j = 0; j < days.size(); j++) { // loop through col

			if (j > 9) {

				for (int x = 0; x < 9; x++) {
					sma = Close[j -x] + sma;
				}
				
				sma = sma / 9;
				
			}
				if (maximum + HALF_INC > sma && sma > maximum - HALF_INC) {

					os << "x";
				}
				
				else {
					os << " " ;
				}
		
		}
		os << endl;
		
		
	}
	calculationsxaxis(os);
}

void DataManager::candlestick(ostream& os) {
	reverse(Open.begin(), Open.end());
	reverse(High.begin(), High.end());
	reverse(Low.begin(), Low.end());
	reverse(Close.begin(), Close.end());

double maximum = *max_element(High.begin(), High.end());
double minimum = *min_element(Low.begin(), Low.end());
double difference;
double increment;
difference = maximum - minimum;
increment = difference / 30;
const double HALF_INC = increment / 2;
for (int rows = 0; rows < 30; rows++) { // looping through rows
		maximum = maximum - increment;
		os << setw(5) <<setprecision(0)<< maximum << " " << char(180);

 for (int j = 0; j < days.size(); j++) { // loop through col

		    if (Close[j] >= maximum - HALF_INC && maximum + HALF_INC >= Open[j])
			{
				os << char(219);

			}
			else if (Open[j] >= maximum - HALF_INC && maximum + HALF_INC >= Close[j])
			{
				os << char(176);
			}
			else if (maximum - HALF_INC <= High[j] && maximum + HALF_INC >= Low[j]) {
				os << char(179);
			}
			else if (maximum + HALF_INC >= High[j] && maximum - HALF_INC <= Low[j]) {
				os << char(179);
			}
			else
			{
				os << " ";
			}


 }
		os << endl;
}
}

void DataManager::savetofile(ostream& os)
{

}
void DataManager::outputfile() {
	savetofile(cout);
	char save;
	cout << "If you would like to save this file into a new text file enter 'y' or 'Y' if not enter n" << endl;
	cin >> save;
	if (save == 'y' || save == 'Y')
	{
		ofstream outputFile;
		outputFile.open("output.txt");
		candlestick(outputFile);
		sma(outputFile);
		bargraph(outputFile);
		calculationsxaxis(outputFile);
		outputFile.close();
		
	}
	if (save == 'n' || save == 'N')
	{
		
	}
}

