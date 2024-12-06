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

    void setPos(int x, int y) {
        pos = Pos(x, y);
    }

    Facing facing = Facing::UP;
    Pos pos;
};

int main(void) {
    std::vector<std::string> data = readFile("input.txt");

    Guard guard;

    int rows = data.size(), cols = data.at(0).size();

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            if (data.at(y).at(x) == '^') {
                guard.setPos(x, y);
            }
        }
    }

    long long sum = 1;

    while (true) {
        Pos nextPos = guard.nextPos();

        if (nextPos.x < 0 || nextPos.y < 0 || nextPos.x >= cols || nextPos.y >= rows) break;

        if (data.at(nextPos.y).at(nextPos.x) == '#') {
            guard.turn();
            continue;
        }

        guard.step();

        if (data.at(nextPos.y).at(nextPos.x) == '.') {
            sum++;
            data.at(nextPos.y).at(nextPos.x) = 'X';
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

// Solution: 5534