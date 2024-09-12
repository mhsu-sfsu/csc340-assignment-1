#ifndef TESTING_H
	#define TESTING_H

	#include <string>
	#include <vector>
	#include <sstream>

	using namespace std;
	
	typedef struct {
		vector<int> inputNumbers, expectedNumbers;
		int sum;
		pair<int, int> expectedPair;
	} testCase;

	void processNumbers (istringstream& iss, string line, vector<int>& numbers);
	bool readTestCases(string fileName, vector<testCase>& testCases);

#endif
