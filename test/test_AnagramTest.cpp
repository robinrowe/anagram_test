// test_AnagramTest.cpp 
// Created by Robin Rowe 2022-01-28
// MIT License

#include <iostream>
#include "../AnagramTest.h"
using namespace std;

int main(int argc,char* argv[])
{	cout << "Testing AnagramTest" << endl;
	AnagramTest anagramTest;
	if(!anagramTest)
	{	cout << "AnagramTest failed on operator!" << endl;
		return 1;
	}
	cout << anagramTest << endl;
	cout << "AnagramTest Passed!" << endl;
	return 0;
}
