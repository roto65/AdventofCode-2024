#include <bits/stdc++.h>

#include "../shared.hpp"

class Guard {
   public:
    enum Facing {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    Guard() = default;

    void turn() {
        switch (facing) {
            case Facing::UP:
                facing = Facing::RIGHT;
                break;
            case Facing::RIGHT:
                facing = Facing::DOWN;
                break;
            case Facing::DOWN:
                facing = Facing::LEFT;
                break;
            case Facing::LEFT:
                facing = Facing::UP;
                break;
        }
    }

    void step() {
        switch (facing) {
            case Facing::UP:
                pos.y--;
                break;
            case Facing::RIGHT:
                pos.x++;
                break;
            case Facing::DOWN:
                pos.y++;
                break;
            case Facing::LEFT:
                pos.x--;
                break;
        }
    }

    Pos nextPos() {
        Pos p(pos);

        switch (facing) {
            case Facing::UP:
                p.y--;
                break;
            case Facing::RIGHT:
                p.x++;
                break;
            case Facing::DOWN:
                p.y++;
                break;
            case Facing::LEFT:
                p.x--;
                break;
        }

        return p;
    }

    char getFacingSymbol() {
        switch (facing) {
            case Facing::UP:
                return '^';
            case Facing::RIGHT:
                return '>';
            case Facing::DOWN:
                return 'v';
            case Facing::LEFT:
                return '<';
        }
        return '.';
    }

    void setPos(int x, int y) {
        pos = Pos(x, y);
    }

    Facing facing = Facing::UP;
    Pos pos;
};

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    Pos startPos;
    int rows = data.size(), cols = data.at(0).size();

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            if (data.at(y).at(x) == '^') {
                startPos = Pos(x, y);
            }
        }
    }

    Guard guard;
    guard.setPos(startPos.x, startPos.y);

    long long sum = 0;

    std::vector<Pos> steps;

    while (true) {
        Pos nextPos = guard.nextPos();

        if (nextPos.x < 0 || nextPos.y < 0 || nextPos.x >= cols || nextPos.y >= rows) break;

        if (data.at(nextPos.y).at(nextPos.x) == '#') {
            guard.turn();
            continue;
        }

        guard.step();

        if (data.at(nextPos.y).at(nextPos.x) == '.') {
            steps.push_back(guard.pos);
            data.at(nextPos.y).at(nextPos.x) = 'X';
        }
    }

    for (Pos p : steps) {
        guard.setPos(startPos.x, startPos.y);
        guard.facing = Guard::Facing::UP;

        data.at(p.y).at(p.x) = '#';

        for (std::string& str : data) {
            for (char& c : str) {
                if (c != '#') {
                    c = '.';
                }
            }
        }

        data.at(startPos.y).at(startPos.x) = '^';

        bool loop = false;

        while (true) {
            Pos nextPos = guard.nextPos();

            if (nextPos.x < 0 || nextPos.y < 0 || nextPos.x >= cols || nextPos.y >= rows) break;

            if (data.at(nextPos.y).at(nextPos.x) == '#') {
                guard.turn();
                continue;
            }

            if (data.at(nextPos.y).at(nextPos.x) == guard.getFacingSymbol()) {
                loop = true;
                break;
            }

            guard.step();
            data.at(nextPos.y).at(nextPos.x) = guard.getFacingSymbol();
        }

        sum += loop;
        data.at(p.y).at(p.x) = '.';
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 2262