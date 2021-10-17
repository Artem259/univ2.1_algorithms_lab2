#include <iostream>
#include <chrono>
#include "StringAlgorithm.h"

bool Test()
{
    std::vector<std::string> input1;
    std::vector<std::string> input2;
    std::vector<bool> output;

    //-------------------------------------------------------------------------------------------------//
    // Test 0
    input1.emplace_back("abc");
    input2.emplace_back("cab");
    output.push_back(true);
    //-------------------------------------------------------------------------------------------------//
    // Test 1
    input1.emplace_back("abc");
    input2.emplace_back("abc");
    output.push_back(true);
    //-------------------------------------------------------------------------------------------------//
    // Test 2
    input1.emplace_back("abcc");
    input2.emplace_back("cab");
    output.push_back(false);
    //-------------------------------------------------------------------------------------------------//
    // Test 3
    input1.emplace_back("lololo");
    input2.emplace_back("ololol");
    output.push_back(true);
    //-------------------------------------------------------------------------------------------------//
    // Test 4
    input1.emplace_back("Hello, World ");
    input2.emplace_back("World Hello, ");
    output.push_back(true);
    //-------------------------------------------------------------------------------------------------//
    // Test 5
    input1.emplace_back("Hello, World ");
    input2.emplace_back("Worl# Hello, ");
    output.push_back(false);
    //-------------------------------------------------------------------------------------------------//
    // Test 6
    input1.emplace_back("");
    input2.emplace_back("");
    output.push_back(true);
    //-------------------------------------------------------------------------------------------------//
    // Test 7
    input1.emplace_back("f");
    input2.emplace_back("g");
    output.push_back(false);
    //-------------------------------------------------------------------------------------------------//
    // Test 8
    input1.emplace_back("fffff");
    input2.emplace_back("ggggg");
    output.push_back(false);
    //-------------------------------------------------------------------------------------------------//
    // Test 9
    input1.emplace_back("abcabdabcabeabc");
    input2.emplace_back("abcabeabcabcabd");
    output.push_back(true);
    //-------------------------------------------------------------------------------------------------//
    // Test 10
    input1.emplace_back("bbababbaa");
    input2.emplace_back("abbaabbab");
    output.push_back(true);
    //-------------------------------------------------------------------------------------------------//

    bool res;
    for(size_t i=0; i<input1.size(); i++)
    {
        std::cout<<"Test "<<i<<": ";

        auto start = std::chrono::high_resolution_clock::now();
        res = CyclicShift(input1[i], input2[i]);
        auto end = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        if(res != output[i])
        {
            std::cout<<"Failed ("<<time.count()<<" ms)\n";
            return false;
        }
        else
        {
            std::cout<<"Passed ("<<time.count()<<" ms)\n";
        }
    }
    std::cout<<"Testing passed\n";
    return true;
}

int main()
{
    Test();
    return 0;
}
