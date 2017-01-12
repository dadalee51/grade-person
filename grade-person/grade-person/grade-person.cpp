#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;

struct person_t {
	string lastName;
	string firstName;
	int grade;
	//comparison order
	bool operator < (const person_t& rhs) const {
		if (grade < rhs.grade) return false;
		if (grade > rhs.grade) return true;
		if (lastName < rhs.lastName) return true;
		if (lastName > rhs.lastName) return false;
		if (firstName < rhs.firstName) return true;
		if (firstName > rhs.firstName) return false;
		return false;
	}
};

int main(int argc, char * argv[])
{

	if (argc <= 1) {
		cout << "usage: grade-person input" << endl;
		return 1;
	}

	//file read, vectorize.
	ifstream inF(argv[1]);
	vector<person_t> plist;

	if (inF && inF.is_open()) {
		string line;
		while (getline(inF, line)) {
			istringstream iss(line);
			vector<string> data{
				istream_iterator<string>{iss},
				istream_iterator<string>{}
			};
			person_t aper;
			aper.lastName = data[0];
			aper.firstName = data[1];
			aper.grade = stoi(data[2]);
			plist.push_back(aper);
		}
		sort(plist.begin(), plist.end());

		ofstream outF("names-graded.txt");
		if (outF && outF.is_open())
		{
			for (auto a : plist) {
				outF << a.lastName << " " << a.firstName << " " << a.grade << endl;
				cout << a.lastName << " " << a.firstName << " " << a.grade << endl;
			}
			outF.close();
			cout << "finished: created names-graded.txt";
		}
	}
	return 0;
}

