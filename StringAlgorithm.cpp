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
        j = pi[i-1];
        while(j>0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i] == s[j]) pi[i] = j+1;
        else pi[i] = 0;
    }
    return pi;
}

bool CyclicShift(const std::string& s1, const std::string& s2)
{
    size_t k = 0; //вказівник у основному рядку s1
    size_t l = 0; //вказівник у "підрядку" s2
    if(s1.length()!=s2.length()) return false;
    auto pi = PrefixFunction(s2);
    bool cycle = false;
    while(true)
    {
        if(s1[k]==s2[l])
        {
            k++;
            l++;
            if(l==s2.length()) return true;
        }
        else
        {
            if(l==0)
            {
                k++;
                if(k==s1.length())
                {
                    if(cycle) return false;
                    cycle = true;
                    k=0;
                }
            }
            else
            {
                l = pi[l-1];
            }
        }
    }
}