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


void DataManager::datasave() {
	
    string filename;
	director = filename;
	cin >> filename;
	ifstream File;
	File.open(filename);

	ifstream inputFileStream;
	inputFileStream.open(filename);

	if (inputFileStream.good())
	{
		cout << "Input file is being analysed" << endl << endl;
		string line;
		getline(inputFileStream, line); 
		getline(inputFileStream, line); 
        while (!inputFileStream.fail()) 
		{
			stringstream ss(line);

			string date1;
			string date2;
			getline(ss, date1, ','); 
			getline(ss, date2, ','); 
			string date = date1 + date2;
			string trimmedDate = date.substr(1, date.size() - 2);
			stringstream digits(date1);
			string month;
			int day;
			getline(digits, month, ' ');
			digits >> day;
			days.push_back(day);
            cout << fixed; 

			for (int i = 0; i < COLUMNS; i++) { // loops through the remaining 6 columns
				string field;
				double fieldData;
				getline(ss, field, ','); 
				stringstream fss(field);
				fss >> fieldData; 

				if (i == 0) {
					open.push_back(fieldData);
				}
				if (i == 1) {
					high.push_back(fieldData);
				}
				if (i == 2) {
					low.push_back(fieldData);
				}
				if (i == 3) {
					close.push_back(fieldData);
				}
				if (i == 4) {
					volume.push_back(fieldData);
				}
				if (i == 5) {
					market_Cap.push_back(fieldData);
				}
				
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

void DataManager::xaxiscalculation(ostream& os) {
	reverse(days.begin(), days.end());
	os << endl;
	os << setw(7);
	os << "   ";
	for (int x = 0; x < days.size(); x += DAYS_INC)
	{
		os.fill('0'); //compensate for any single digit dates
		os << setw(2) <<setprecision(0)<< days[x] << " ";

	}
	os << endl;
	os << endl;
} // caclulates x axis for all the graphs to be outputted
void DataManager::plotbargraph(ostream& os) {
	reverse(volume.begin(), volume.end());
	reverse(days.begin(), days.end());
	long long decrement;
	long long difference;
	long long Yaxis;
	long long highest = *max_element(volume.begin(), volume.end());
	long long lowest = *min_element(volume.begin(), volume.end());
	difference = highest - lowest;
	decrement = (difference / DIVISIONS) ;
	os << endl;
	for (int i = 0; i < DIVISIONS; i++) {
		highest = (highest - decrement);
		
		Yaxis = highest / DIVIDER;
		
		os << setw(3) << setprecision(0)<< Yaxis << "Bil " <<yaxisbar;
		
		for (int j = 0; j < days.size(); j++) {
			if (volume[j] >= highest - HALF_INC && open[j] < close[j]) {
				os << positivebar;
			}
			else if (volume[j] >= highest + HALF_INC && open[j] > close[j]) {
				os << negativebar;
			}
			else
				os << " ";
				
		}
		os << endl;
	}
	xaxiscalculation(os);
}

void DataManager::plotsma(ostream& os) {
	
	reverse(high.begin(), high.end());
	reverse(low.begin(), low.end());
	reverse(days.begin(), days.end());

	double maximum = *max_element(high.begin(), high.end());
    double minimum = *min_element(low.begin(), low.end());
	double Difference;
    double decrement;
    Difference = maximum - minimum;
	decrement = Difference / DIVISIONS;
	const double HALF_INC = decrement / 2;
	double sma= 0.0;
	
	for (int rows = 0; rows < DIVISIONS; rows++) { // looping through rows
		maximum = maximum - decrement;
		os << setw(5) << setprecision(0)<< maximum << " " << yaxisbar;

		for (int j = 0; j < days.size(); j++) { // loop through col

			if (j > PERIOD_9) {

				for (int x = 0; x <PERIOD_9; x++) {
					sma = close[j-x] + sma;
				}
				sma = sma /PERIOD_9;
				
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
	xaxiscalculation(os);
}

void DataManager::plotcandlestick(ostream& os) {
	reverse(open.begin(), open.end());
	reverse(high.begin(), high.end());
	reverse(low.begin(), low.end());
	reverse(close.begin(), close.end());
	
		double maximum = *max_element(high.begin(), high.end());
		double minimum = *min_element(low.begin(), low.end());
		double difference;
		double decrement;
		difference = maximum - minimum;
		decrement = difference / DIVISIONS;
		const double HALF_INC = decrement / 2;
		for (int rows = 0; rows < DIVISIONS; rows++) { // looping through rows
			maximum = maximum - decrement;
			os << setw(5) << setprecision(0) << maximum << " " << yaxisbar;

			for (int j = 0; j < days.size(); j++) { // loop to output candlesticks

				if (close[j] >= maximum - HALF_INC && maximum + HALF_INC >= open[j])
				{
					os << positivebar;

				}
				else if (open[j] >= maximum - HALF_INC && maximum + HALF_INC >= close[j])
				{
					os << negativebar;
				}
				else if (maximum - HALF_INC <= high[j] && maximum + HALF_INC >= low[j]) {
					os << wick;
				}
				else if (maximum + HALF_INC >= high[j] && maximum - HALF_INC <= low[j]) {
					os << wick;
				}
				else
				{
					os << " ";
				}


			}
			os << endl;
		}
		xaxiscalculation(os);
	
}

void DataManager::outputtoconsole(ostream& os)
{
// function used to create an object to output into a text file
}
void DataManager::outputfile() {
	outputtoconsole(cout);
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
		plotcandlestick(outputFile);
		plotsma(outputFile);
		plotbargraph(outputFile);
		plotma(outputFile);
		outputFile.close();
		cout << "saving has been done" << endl;
		loopback();
		
	}
	else if (save == 'n' || save == 'N')
	{
		loopback();
	}
	
	
}
void DataManager::plotma(ostream& os) {
	reverse(high.begin(), high.end());
	reverse(low.begin(), low.end());
	reverse(days.begin(), days.end());

	double maximum = *max_element(high.begin(), high.end());
	double minimum = *min_element(low.begin(), low.end());
	double Difference;
	double decrement;
	Difference = maximum - minimum;
	decrement = Difference / DIVISIONS;
	

	for (int rows = 0; rows < DIVISIONS; rows++) { // looping through rows
		maximum = maximum - decrement;
		os << setw(5) << setprecision(0) << maximum << " " << yaxisbar;

		for (int j = 0; j < days.size(); j++) { // loop through col

			if (j > PERIOD_9) {

				for (int x = 0; x < PERIOD_9; x++) {
					ma1 = close[j - x] + ma1;
				}

				ma1 = ma1 / PERIOD_9;

			}
			if (maximum + HALF_INC > ma1 && ma1 > maximum - HALF_INC) {

				os << macharacter;
			}

			else if (j > PERIOD_5) {
				for (int x = 0; x < PERIOD_5; x++) {
					ma2 = close[j - x] + ma2;
				}
				ma2 = ma2 /PERIOD_5;
			}
			if(maximum +HALF_INC > ma2 && ma2 > maximum - HALF_INC){
				os << ".";
				
			}
			else if((maximum + HALF_INC > ma1 && ma1 > maximum - HALF_INC) || (maximum + HALF_INC > ma2 && ma2 > maximum - HALF_INC)) 
			{
				os << macharacter;
			}
			else
			{
				os << " ";
			}

		}
		os << endl;


	}
	xaxiscalculation(os);
}
bool DataManager::loopback() {
	string userinput;
	cout << "Would you like to open another file?" << endl;
	cin >> userinput;
	if (userinput == "y" || userinput == "Y" || userinput == "yes"|| userinput == "YES") {
		cout << "Please enter the file you would like to open"<< endl;
		return true;
	}
	else if (userinput == "n" || userinput == "no" || userinput == "NO"|| userinput== "N") {
		return false;
	}
}// enables user to be able to rerun the program with a different file


