//
// Created by Artem Poliakov on 16.10.2021.
//

#include "StringAlgorithm.h"

//Перший етап алгоритму. Допоміжна префікс-функція, яка формує масив pi для вхідного рядка s
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

//Другий етап алгоритму. Основна функція, в якій реалізована перевірка циклічності вхідних рядків s1 та s2
bool CyclicShift(const std::string& s1, const std::string& s2)
{
    size_t len = s1.length();
    size_t k = 0; //вказівник у основному рядку s1
    size_t l = 0; //вказівник у "підрядку" s2
    if(s2.length()!=len) return false; //якщо довжини вхідних рядків не рівні - рядки не є циклічними
    if(len==0) return true; //якщо рядки порожні - повертається true
    auto pi = PrefixFunction(s2); //формування префікс-масиву для рядка s2
    bool cycle = false; //перший чи других прохід рядком s1?
    while(true) //порівняння рядків
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

        if(l==len) return true; //рядки є циклічними
        if(k==len)
        {
            if(cycle) return false; //рядки не є циклічними
            cycle = true;
            k=0;
        }
    }
}