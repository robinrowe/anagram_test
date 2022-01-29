// AnagramTest.h 
// Created by Robin Rowe 2022-01-28
// MIT License

#ifndef AnagramTest_h
#define AnagramTest_h

#include <iostream>
#include <vector>
#include <algorithm>

class AnagramTest
{	std::string baseWord;
	std::vector<bool> anagram; 
	AnagramTest(const AnagramTest&) = delete;
	void operator=(const AnagramTest&) = delete;
	void Reset(size_t count,const char* word)
	{   anagram.resize(count);
		anagram.assign(count,false);
		//fill(anagram.begin(),anagram.end(),false); // alternative to assign()
		baseWord = word;
	    sort(baseWord.begin(),baseWord.end());
	}
public:
	~AnagramTest()
	{}
	AnagramTest()
	{}
	bool CheckAnagrams(int count,char* words[]);
	bool operator!() const
	{	// to-do
		return true;
	}
	std::ostream& Print(std::ostream& os) const;
	std::istream& Input(std::istream& is);
};

inline
std::ostream& operator<<(std::ostream& os,const AnagramTest& anagramTest)
{	return anagramTest.Print(os);
}


inline
std::istream& operator>>(std::istream& is,AnagramTest& anagramTest)
{	return anagramTest.Input(is);
}

#endif
