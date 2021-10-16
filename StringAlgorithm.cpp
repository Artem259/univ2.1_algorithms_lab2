//
// Created by Artem Poliakov on 16.10.2021.
//

#include "StringAlgorithm.h"

std::vector<size_t> PrefixFunction(const std::string& s)
{
    size_t len = s.length();
    std::vector<size_t> pi(len, 0);
    size_t j;
    for(size_t i=1; i<len; i++)
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
    size_t len = s1.length();
    size_t k = 0; //вказівник у основному рядку s1
    size_t l = 0; //вказівник у "підрядку" s2
    if(s2.length()!=len) return false;
    if(len==0) return true;
    auto pi = PrefixFunction(s2);
    bool cycle = false;
    while(true)
    {
        if(s1[k]==s2[l])
        {
            k++;
            l++;
        }
        else
        {
            if(l==0) k++;
            else l = pi[l-1];
        }

        if(l==len) return true;
        if(k==len)
        {
            if(cycle) return false;
            cycle = true;
            k=0;
        }
    }
}