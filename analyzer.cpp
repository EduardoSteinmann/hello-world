//
// Created by Kasra on 10/3/2024.
//
#include <iostream>
#include "StringData.h"
int linear_search(std::vector<std::string> list, std::string element){
    for(int i = 0; i < list.size(); i++)
    {
        if(list[i] == element)
        {
            return i;
        }
    }
return -1;
}
int binary_search(std::vector<std::string> list, std::string element)
{
    int low = 0;
    int high = list.size() - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if(element == list[mid])
        {
            return mid;
        }
        else if(list[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    std::vector<std::string> data = getStringData();
    std::string element = "mzzzz";
    auto starttime = std::chrono::system_clock::now();
    int result = binary_search(data, element);
    auto endtime = std::chrono::system_clock::now();
    std::cout << result << std::endl;
    std::chrono::duration<double> duration = endtime - starttime;
    std::cout << "time:" << duration.count() << std::endl;



    return 0;
}