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
			int columns = 6;
			for (int i = 0; i < columns; i++) { // loops through the remaining 6 columns
				string field;
				double fieldData;
				getline(ss, field, ','); // read next field, might fail
				stringstream fss(field);
				fss >> fieldData; // try to convert to a double, this might fail !!!

				if (i == 0)
					open.push_back(fieldData);
				if (i == 1)
					high.push_back(fieldData);
				if (i == 2)
					low.push_back(fieldData);
				if (i == 3)
					close.push_back(fieldData);
				if (i == 4)
					volume.push_back(fieldData);
				if (i == 5)
					market_Cap.push_back(fieldData);
				

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
	const int DAYS_INC = 3;
	os << endl;
	os << setw(7);
	os << "   ";
	for (int x = 0; x < days.size(); x += DAYS_INC)
	{
		os.fill('0');
		os << setw(2) <<setprecision(0)<< days[x] << " ";

	}
	os << endl;
	os << endl;

}
void DataManager::bargraph(ostream& os) {
	reverse(volume.begin(), volume.end());
	reverse(days.begin(), days.end());
	long long increment;
	long long difference;
	long long Yaxis;
	const int DIVISIONS = 30;
	long long highest = *max_element(volume.begin(), volume.end());
	long long lowest = *min_element(volume.begin(), volume.end());
	difference = highest - lowest;
	increment = (difference / DIVISIONS) ;
	
	os << "Bargraph" << endl;
	os << endl;
	for (int i = 0; i < DIVISIONS; i++) {
		highest = (highest - increment);
		
		Yaxis = highest / DIVIDER;
		
		os << setw(3) << setprecision(0)<< Yaxis << "Bil " << char(180);
		
		for (int j = 0; j < days.size(); j++) {
			if (volume[j] >= highest && open[j] < close[j]) {
				os << char(219);
			}
			else if (volume[j] >= highest && open[j] > close[j]) {
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
	
	
	
	
	
	reverse(market_Cap.begin(), market_Cap.end());
	
}
void DataManager::sma(ostream& os) {
	
	reverse(high.begin(), high.end());
	reverse(low.begin(), low.end());
	reverse(days.begin(), days.end());

	double maximum = *max_element(high.begin(), high.end());
    double minimum = *min_element(low.begin(), low.end());
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
					sma = close[j -x] + sma;
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
	reverse(open.begin(), open.end());
	reverse(high.begin(), high.end());
	reverse(low.begin(), low.end());
	reverse(close.begin(), close.end());

double maximum = *max_element(high.begin(), high.end());
double minimum = *min_element(low.begin(), low.end());
double difference;
double increment;
difference = maximum - minimum;
increment = difference / 30;
const double HALF_INC = increment / 2;
for (int rows = 0; rows < 30; rows++) { // looping through rows
		maximum = maximum - increment;
		os << setw(5) <<setprecision(0)<< maximum << " " << char(180);

 for (int j = 0; j < days.size(); j++) { // loop through col

		    if (close[j] >= maximum - HALF_INC && maximum + HALF_INC >= open[j])
			{
				os << char(219);

			}
			else if (open[j] >= maximum - HALF_INC && maximum + HALF_INC >= close[j])
			{
				os << char(176);
			}
			else if (maximum - HALF_INC <= high[j] && maximum + HALF_INC >= low[j]) {
				os << char(179);
			}
			else if (maximum + HALF_INC >= high[j] && maximum - HALF_INC <= low[j]) {
				os << char(179);
			}
			else
			{
				os << " ";
			}


 }
		os << endl;
}
calculationsxaxis(os);
}

void DataManager::savetofile(ostream& os)
{

}
void DataManager::outputfile() {
	savetofile(cout);
	char save;
	string filename;

	cout << "If you would like to save this file into a new text file enter 'y' or 'Y' if not enter n" << endl;
	cin >> save;
	if (save == 'y' || save == 'Y')
	{
		cout << "Pease enter the name of the file you want to save to" << endl;
		cin >> filename;
		ofstream outputFile;
		outputFile.open(filename);
		candlestick(outputFile);
		sma(outputFile);
		bargraph(outputFile);
		ma(outputFile);
		calculationsxaxis(outputFile);
		outputFile.close();
		cout << "saving has been done" << endl;
		
	}
	if (save == 'n' || save == 'N')
	{
		cout << "If you would like to open another file enter the name" << endl;
	}
	
}
void DataManager::ma(ostream& os) {
	reverse(high.begin(), high.end());
	reverse(low.begin(), low.end());
	reverse(days.begin(), days.end());

	double maximum = *max_element(high.begin(), high.end());
	double minimum = *min_element(low.begin(), low.end());
	double Difference;
	double increment;
	Difference = maximum - minimum;
	increment = Difference / 30;
	const double HALF_INC = 50;
	double ma1 = 0.0;
	double ma2 = 0.0;

	for (int rows = 0; rows < 30; rows++) { // looping through rows
		maximum = maximum - increment;
		os << setw(5) << setprecision(0) << maximum << " " << char(180);

		for (int j = 0; j < days.size(); j++) { // loop through col

			if (j > 9) {

				for (int x = 0; x < 9; x++) {
					ma1 = close[j - x] + ma1;
				}

				ma1 = ma1 / 9;

			}
			if (maximum + HALF_INC > ma1 && ma1 > maximum - HALF_INC) {

				os << char(167);
			}

			else if (j > 5) {
				for (int x = 0; x < 5; x++) {
					ma2 = close[j - x] + ma2;
				}
				ma2 = ma2 / 5;
			}
			if(maximum +HALF_INC > ma2 && ma2 > maximum - HALF_INC){
				os << ".";
				
			}
			else if((maximum + HALF_INC > ma1 && ma1 > maximum - HALF_INC) || (maximum + HALF_INC > ma2 && ma2 > maximum - HALF_INC)) 
			{
				os << char(167);
			}
			else
			{
				os << " ";
			}

		}
		os << endl;


	}
	calculationsxaxis(os);
}
bool DataManager::loopback() {
	string userinput;
	
	if (userinput == "y" || userinput == "Y" || userinput == "yes") {
		return true;
	}
	else if (userinput == "n" || userinput == "no" || userinput == "NO") {
		return false;
	}
}

