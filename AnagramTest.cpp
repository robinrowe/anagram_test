// AnagramTest.cpp
// Created by Robin Rowe 2022-01-28
// MIT License

#include <algorithm>
#include <string.h>
#include "AnagramTest.h"
using namespace std;

ostream& AnagramTest::Print(ostream& os) const
{   const char* truth = "FT";
	for(const auto& flag : anagram)
    {   os << truth[flag];
    }
	return os;
} 

istream& AnagramTest::Input(std::istream& is) 
{	// to-do
	return is;
}

bool AnagramTest::CheckAnagrams(int count,char* words[])
{   if(!count || !words)
    {   return false;
    }
    const size_t length = strlen(words[0]);
    anagram.resize(count);
    fill(anagram.begin(),anagram.end(),false);
    anagram[0] = true;
    string baseWord = words[0];
    sort(baseWord.begin(),baseWord.end());
    for(unsigned i=0;i<count;i++)
    {   if(length != strlen(words[i]))
        {   continue;
        }
        string word = words[i];
        sort(word.begin(),word.end());
        if(baseWord != word)
        {   continue;
        }
        anagram[i] = true;
}   }