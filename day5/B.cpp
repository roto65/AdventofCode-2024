#include <bits/stdc++.h>

#include "../shared.hpp"

std::map<int, std::vector<int>> rules;

std::vector<int> fixOrder(std::vector<int> pages) {
    std::vector<int> orderedPages;

    for (int p = 0; p < pages.size(); p++) {
        std::vector<int> rule;

        if (rules.find(pages.at(p)) != rules.end()) {
            rule = rules.at(pages.at(p));
        } else {
            continue;
        }

        bool found;

        for (int j = 0; j < pages.size(); j++) {
            if (p == j) continue;

            found = false;
            for (int r : rule) {
                if (r == pages.at(j)) {
                    found = true;
                    break;
                }
            }

            if (!found) break;
        }

        if (found) {
            orderedPages.push_back(pages.at(p));
            pages.erase(pages.begin() + p);
            p = -1;
        }
    }

    if (pages.size() == 1) {
        orderedPages.push_back(pages.at(0));
    }

    return orderedPages;
}

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    int i = 0;
    for (; i < data.size(); i++) {
        std::string row = data.at(i);
        if (row == "") break;

        int n1 = stoi(row.substr(0, 2)), n2 = stoi(row.substr(3));

        if (rules.find(n1) == rules.end()) {
            rules.insert(std::pair<int, std::vector<int>>(n1, {n2}));
        } else {
            rules.at(n1).push_back(n2);
        }
    }
    i++;

    long long sum = 0;

    for (; i < data.size(); i++) {
        std::vector<std::string> row = split(data.at(i), ',');

        std::vector<int> pages;
        for (std::string tmp : row) {
            pages.push_back(stoi(tmp));
        }

        bool found = false;

        for (int p = 0; p < pages.size() - 1; p++) {
            std::vector<int> rule;

            if (rules.find(pages.at(p)) != rules.end()) {
                rule = rules.at(pages.at(p));
            }

            for (int j = p + 1; j < pages.size(); j++) {
                found = false;
                for (int r : rule) {
                    if (r == pages.at(j)) {
                        found = true;
                        break;
                    }
                }

                if (!found) break;
            }
            if (!found) break;
        }

        if (!found) {
            std::vector<int> pagesFixed = fixOrder(pages);
            int mid = (pagesFixed.size() - 1) / 2;
            sum += pagesFixed.at(mid);
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 5770