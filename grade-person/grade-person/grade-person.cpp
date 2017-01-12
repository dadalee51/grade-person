#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
	string line;
	if (argc <= 1) {
		cout << "usage: grade-person input" << endl;
		return 1;
	}

	ifstream inF(argv[1]);

	return 0;
}

