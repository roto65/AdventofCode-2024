#include <bits/stdc++.h>

#include "../shared.hpp"

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::vector<int> v1, v2;

    for (std::string s : data) {
        std::vector<std::string> row = split(s, ' ');

        v1.push_back(std::stoi(row.at(0)));
        v2.push_back(std::stoi(row.at(3)));
    }

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    long long sum = 0;

    for (int i = 0; i < v1.size(); i++) {
        sum += std::abs(v1.at(i) - v2.at(i));
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 1110981