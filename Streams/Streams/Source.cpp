#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <exception>

using namespace std;


void CheckTimeDivider(stringstream& stream) {
	if (stream.peek() != ':') {
		stringstream ss;
		ss << "\"" << char(stream.peek()) << "\" is in stream.\n";
		throw runtime_error(ss.str());
	}
	stream.ignore(1);
}

void main() {
	stringstream ssDay("2019-12-31");
	string sYesr;
	string sMonth;
	string sDay;

	getline(ssDay, sYesr, '-');
	getline(ssDay, sMonth, '-');
	getline(ssDay, sDay);

	cout << setfill('.');
	cout << left;

	cout << setw(5);
	cout << sDay << " ";
	cout << setw(5);
	cout << sMonth << " ";
	cout << setw(5);
	cout << sYesr << endl;


	stringstream ssTime("12:59:03"); //12/12/12
	int iHH;
	int iMM;
	int iSS;

	try { 
		ssTime >> iHH;
		CheckTimeDivider(ssTime);
		ssTime >> iMM;
		CheckTimeDivider(ssTime);
		ssTime >> iSS;

		cout << setfill('0');
		cout << right;
		cout << setw(2);
		cout << iHH << " ";
		cout << setw(2);
		cout << iMM << " ";
		cout << setw(2);
		cout << iSS << endl;
	}
	catch (exception& ex) {
		cout << "Exception: " << ex.what() << endl;
	}

	system("pause");
}