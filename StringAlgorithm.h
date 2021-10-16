//
// Created by Artem Poliakov on 16.10.2021.
//

#ifndef STRING_ALGORITHM_H
#define STRING_ALGORITHM_H

#include <string>
#include <vector>

std::vector<size_t> PrefixFunction(const std::string& s);
bool CyclicShift(const std::string& s1, const std::string& s2);

#endif