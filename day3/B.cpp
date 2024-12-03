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

    std::regex pattern("mul\\(\\d{1,3},\\d{1,3}\\)|do\\(\\)|don't\\(\\)");
    std::smatch matches;

    long long sum = 0;

    bool active = true;

    for (std::string text : data) {
        while (std::regex_search(text, matches, pattern)) {
            if (((std::string)matches[0]).substr(0, 3) == "mul") {
                if (active) {
                    sum += evalMul(matches[0]);
                }
            } else if (((std::string)matches[0]).substr(0, 3) == "do(") {
                active = true;
            } else if (((std::string)matches[0]).substr(0, 3) == "don") {
                active= false;
            }

            // std::cout << matches[0] << std::endl;
            text = matches.suffix().str();
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 97529391