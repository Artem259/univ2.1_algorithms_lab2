//
// Created by Artem Poliakov on 16.10.2021.
//

#include "StringAlgorithm.h"

std::vector<size_t> PrefixFunction(const std::string& s)
{
    std::vector<size_t> pi(s.length(), 0);
    size_t j;
    for(size_t i=1; i<s.length(); i++)
    {
        j = pi[i - 1];
        while(j>0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i] == s[j]) pi[i] = j+1;
        else pi[i] = j;
    }
    return pi;
}