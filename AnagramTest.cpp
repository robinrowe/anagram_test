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
    Reset(count,words[0]);
    anagram[0] = true;// always an anagram of itself
    // Due to SSO (Short String Optimization) there is typically no heap allocation for a small std::string,
    // that the STL will have 10 to 20 bytes allocated in the string object typically. However, longer
    // strings will create a heap allocation and global lock, such that optimization in C may be better.
    for(size_t i=1;i<count;i++)
    {   if(!CheckWord2(words[i]))
        {   continue;
        }
        anagram[i] = true;
}   }

// Optimization alternative used instead of CheckWord():
bool AnagramTest::CheckWord2(const char* testWord)
{	if(!IsSameSize(testWord))
    {   return false;
    }
	const char* match = testWord;
	for(size_t i=0;i<baseWord.size();i++)
	{	match = strchr(match,baseWord[i]);
		if(!match)
		{	return false;
		}
		if(IsLetterRepeats(i))
		{	match++;
			continue;
		}
		match = testWord;
	}
	return true;
}