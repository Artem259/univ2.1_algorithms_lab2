#include <iostream>
#include "StringAlgorithm.h"

int main()
{
    std::cout<<"\n Welcome to the Prefix Function Solver ^_O\n";
    std::string input_string;
    std::cout<<" Input string: ";
    std::cin>>input_string;
    std::vector<size_t> output_arr = PrefixFunction(input_string);
    std::cout<<"\n";
    for(size_t i=0; i<output_arr.size(); i++)
    {
        //"       "
        //"        ___           ___"
        //"i=5 >> "aabsdef"="aabsdef" >> pi(5)=3
        std::cout<<"        ";
        for(size_t j=0; j<std::to_string(i).size(); j++) std::cout<<" ";
        for(size_t j=0; j<=i; j++)
        {
            if(j<output_arr[i]) std::cout<<"_";
            else std::cout<<" ";
        }
        std::cout<<"   ";
        for(size_t j=0; j<=i; j++)
        {
            if(j>i-output_arr[i]) std::cout<<"_";
            else std::cout<<" ";
        }
        std::cout<<"\n i="<<i<<" >> \""<<input_string.substr(0,i+1)<<"\"=\""<<input_string.substr(0,i+1)<<"\""<<" >> pi["<<i<<"]="<<output_arr[i]<<"\n";
    }
    std::cout<<"\n pi = [";
    for(size_t i=0; i<output_arr.size()-1; i++)
    {
        std::cout<<output_arr[i]<<", ";
    }
    std::cout<<output_arr[output_arr.size()-1]<<"]\n\n\n";
    std::cout<<" Kubik, 2021\n";
    system("pause");
    return 0;
}
