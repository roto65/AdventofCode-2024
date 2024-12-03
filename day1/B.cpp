#include <bits/stdc++.h>

#include "../shared.hpp"

std::map<int, int> evalCount(std::vector<int> vec) {
    std::map<int, int> m;

    for (int num : vec) {
        if (m.find(num) == m.end()) {
            m.insert(std::pair<int, int> (num, 1));
        } else {
            m.at(num) = m.at(num) + 1;
        }
    }

    return m;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::vector<int> v1, v2;

    for (std::string s : data) {
        std::vector<std::string> row = split(s, ' ');

        v1.push_back(std::stoi(row.at(0)));
        v2.push_back(std::stoi(row.at(3)));
    }

    std::map<int, int> m = evalCount(v2);

    long long sum = 0;

    for (int num : v1) {
        if (m.find(num) != m.end()) {
            sum += num * m.at(num);
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 24869388