#include <iostream>
#include "StringAlgorithm.h"


int main()
{
    std::string s = "abbaabbab";
    std::vector<size_t> arr = PrefixFunction(s);
    return 0;
}
