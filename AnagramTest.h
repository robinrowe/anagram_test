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
	bool IsSameSize(const char* testWord) const
	{	return baseWord.size() == strlen(testWord);
	}
	bool IsLetterRepeats(size_t i) const
	{	return baseWord[i] == baseWord[i+1];
	}
	// CheckWord() has been replaced by optimized CheckWord2()
	bool CheckWord(const char* testWord) const
	{   if(!IsSameSize(testWord))
        {   return false;
        }
        std::string word(testWord);
        std::sort(word.begin(),word.end()); 
        if(baseWord != word)
        {   return false;
        }
		return true;
	}
	bool CheckWord2(const char* testWord) const;
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
