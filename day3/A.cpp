#include <bits/stdc++.h>

#include "../shared.hpp"

long long evalMul(std::string str) {
    str = str.substr(4);
    str = str.substr(0, str.size() - 1);

    std::vector<std::string> vec = split(str, ',');

    return stoi(vec.at(0)) * stoi(vec.at(1));
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::regex pattern("mul\\(\\d{1,3},\\d{1,3}\\)");
    std::smatch matches;

    long long sum = 0;

    for (std::string text : data) {
        while (std::regex_search(text, matches, pattern)) {
            sum += evalMul(matches[0]);        
        
            // std::cout << matches[0] << std::endl;
            text = matches.suffix().str();
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 168539636