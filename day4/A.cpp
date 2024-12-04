#include <bits/stdc++.h>

#include "../shared.hpp"

std::string readDiag(std::vector<std::string> data) {
    std::string s = "";

    int i, j, t;
    int rows = data.size(), cols = data.at(0).size();
    for (t = 0; t < rows + cols; ++t) {
        for (i = t, j = 0; i >= 0; --i, ++j) {
            if ((i < rows) && (j < cols)) {
                s.push_back(data.at(i).at(j));
            }
        }
        s.push_back(' ');
    }
    return s;
}

std::string readDiagSec(std::vector<std::string> data) {
    std::string s = "";

    int i, j, t;
    int rows = data.size(), cols = data.at(0).size();
    for (t = 0; t < rows + cols; ++t) {
        for (i = t, j = 0; i >= 0; --i, ++j) {
            if ((i < rows) && (j < cols)) {
                s.push_back(data.at(i).at(cols - j - 1));
            }
        }
        s.push_back(' ');
    }
    return s;
}

std::string readRow(std::vector<std::string> data) {
    std::string s = "";

    for (std::string row : data) {
        s += row;
        s.push_back(' ');
    }

    return s;
}

std::string readCol(std::vector<std::string> data) {
    std::string s = "";

    for (int i = 0; i < data.size(); i++) {
        for (std::string row : data) {
            s.push_back(row.at(i));
        }
        s.push_back(' ');
    }

    return s;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    long long sum = 0;

    std::regex exp1("XMAS"), exp2("SAMX");
    std::string text;

    // Horizontal
    text = readRow(data);
    sum += std::distance(std::sregex_iterator(text.begin(), text.end(), exp1), std::sregex_iterator());
    sum += std::distance(std::sregex_iterator(text.begin(), text.end(), exp2), std::sregex_iterator());

    // Vertical
    text = readCol(data);
    sum += std::distance(std::sregex_iterator(text.begin(), text.end(), exp1), std::sregex_iterator());
    sum += std::distance(std::sregex_iterator(text.begin(), text.end(), exp2), std::sregex_iterator());

    // Diagonal TR-BL
    text = readDiag(data);
    sum += std::distance(std::sregex_iterator(text.begin(), text.end(), exp1), std::sregex_iterator());
    sum += std::distance(std::sregex_iterator(text.begin(), text.end(), exp2), std::sregex_iterator());

    // Diagonal TL-BR
    text = readDiagSec(data);
    sum += std::distance(std::sregex_iterator(text.begin(), text.end(), exp1), std::sregex_iterator());
    sum += std::distance(std::sregex_iterator(text.begin(), text.end(), exp2), std::sregex_iterator());

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 2521