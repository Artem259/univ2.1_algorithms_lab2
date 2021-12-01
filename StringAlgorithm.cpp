#include "StringAlgorithm.h"

std::vector<size_t> PrefixFunction(const std::string& s)
{
    size_t len = s.length(); //обчислення довжини вхідного рядка s
    std::vector<size_t> pi(len, 0); //створення результуючого масиву тієї ж довжини
    size_t j = 0; //вказівник у рядку
    for(size_t i=1; i<len; i++) //прохід рядком, обчислення значень елементів результуючого масиву pi
    {
        while(j!=0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
