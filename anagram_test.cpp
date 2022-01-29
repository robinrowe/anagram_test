// anagram_test.cpp 
// Created by Robin Rowe 2022-01-28
// MIT License

#include <iostream>
#include "AnagramTest.h"
using namespace std;

void Usage()
{	cout << "Usage: anagram_test string1 string2..." << endl;
}

enum
{	ok,
	invalid_args

};

int main(int argc,char* argv[])
{	cout << "anagram_test starting..." << endl;
	if(argc < 2)
	{	Usage();
		return invalid_args;
	}
	cout << "Checking anagrams of " << argv[1] << ":" << endl;
	AnagramTest anagramTest;
	if(!anagramTest.CheckAnagrams(argc-1,argv+1))
	{	cout << "invalid data" << endl;
		return invalid_args;
	}
	cout << anagramTest << endl;
	for(size_t i=1;i<argc;i++)
	{	cout << argv[i] << " ";
	}
	cout << endl;
	cout << "anagram_test done!" << endl;
	return ok;
}

/* Output

$ ./build/Debug/anagram_test.exe cat atc tacc tac dog
anagram_test starting...
Checking anagrams of cat:
TTFTF
cat atc tacc tac dog
anagram_test done!

$ ./build/Debug/anagram_test.exe tut ttu tuc tutt dog
anagram_test starting...
Checking anagrams of tut:
TTFFF
tut ttu tuc tutt dog
anagram_test done!

*/
