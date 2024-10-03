#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include "StringData.h"

int64_t linear_search(const std::vector<std::string>& container, const std::string& element)
{
    int64_t index = -1;

    for (size_t i = 0; i < container.size(); i++)
    {
        const std::string& string = container[i];

        if (string == element)
        {
            index = i;
            break;
        }
    }

    return index;
}

int64_t binary_search(const std::vector<std::string>& container, const std::string& element)
{
    int64_t index = -1;

    size_t low_idx = 0;
    size_t high_idx = container.size();

    while (high_idx >= low_idx)
    {
        size_t mid = low_idx + (high_idx - low_idx) / 2;

        if (container[mid] == element)
        {
            index = mid;
            break;
        }
        else if (container[mid] > element)
        {
            high_idx = mid - 1;
        }
        else if (container[mid] < element)
        {
            low_idx = mid + 1;
        }
    }
    
    return index;
}

int main()
{
    std::string values[] = { "not_here", "mzzzz", "aaaaa" };

    auto dataset = getStringData();

    for (const auto& val : values)
    {
        auto begin_l = std::chrono::system_clock::now();
        auto l = linear_search(dataset, val);
        auto end_l = std::chrono::system_clock::now();

        std::cout << "Linear search time looking for " << val << ": " << (end_l - begin_l).count() << ". Index found: " << l << '\n';

        auto begin_b = std::chrono::system_clock::now();
        auto b = binary_search(dataset, val);
        auto end_b = std::chrono::system_clock::now();
        std::cout << "Binary search time looking for " << val << ": " << (end_b - begin_b).count() << ". Index found: " << l << '\n';
    }

    return 0;
}