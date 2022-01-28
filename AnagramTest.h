// AnagramTest.h 
// Created by Robin Rowe 2022-01-28
// MIT License

#ifndef AnagramTest_h
#define AnagramTest_h

#include <iostream>
#include <vector>

class AnagramTest
{	AnagramTest(const AnagramTest&) = delete;
	void operator=(const AnagramTest&) = delete;

public:
	std::vector<bool> anagram; 
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
