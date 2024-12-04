#include <bits/stdc++.h>

#include "../shared.hpp"

long long matchPattern(std::regex pattern, std::vector<std::string> &data) {
    std::string text = "";

    for (std::string row : data) {
        text += row + 'n';
    }

    long long sum = 0;

    std::smatch matches;
    while (std::regex_search(text, matches, pattern)) {
        sum++;
        text = matches.prefix().str() + "." + matches.str().substr(1) + matches.suffix().str();
    }
    return sum;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    std::string len = std::to_string(data.at(0).size() - 1);

    long long sum = 0;

    sum += matchPattern(std::regex("S.(?!n)S.{" + len + "}A.{" + len + "}M.(?!n)M"), data);
    sum += matchPattern(std::regex("S.(?!n)M.{" + len + "}A.{" + len + "}S.(?!n)M"), data);
    sum += matchPattern(std::regex("M.(?!n)M.{" + len + "}A.{" + len + "}S.(?!n)S"), data);
    sum += matchPattern(std::regex("M.(?!n)S.{" + len + "}A.{" + len + "}M.(?!n)S"), data);

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 1912