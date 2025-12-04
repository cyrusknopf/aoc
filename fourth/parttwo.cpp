#include <climits>
#include <iostream>
#include <vector>
#include <mdspan>

constexpr size_t MAX_ITERS = INT_MAX;

using namespace std;

auto main() -> int {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string line;
    vector<char> flat;
    size_t width {0};
    size_t height {0};
    while (cin >> line) {
        height++;
        width = line.size();
        for (char c : line) flat.emplace_back(c);
    }

    auto grid = mdspan(flat.data(), height, width);

    size_t total {0};

    size_t can{1};
    size_t prev_can{1};

    size_t c {0};
    while (/*prev_can != 0 &&*/ c++ < MAX_ITERS) {
        prev_can = can;
        can = 0;
        for (size_t i{0}; i < grid.extent(0); i++) {
            bool is_top = i == 0;
            bool is_bot = i == height - 1;
            for (size_t j{0}; j < grid.extent(1); j++) {
                if (grid[i, j] != '@') continue;

                bool is_lhs = j == 0;
                bool is_rhs = j == width - 1;

                size_t adj{0};

                if (!is_bot && !is_lhs) adj += grid[i + 1, j - 1] == '@';
                if (!is_bot)            adj += grid[i + 1, j] == '@';
                if (!is_bot && !is_rhs) adj += grid[i + 1, j + 1] == '@';

                if (!is_lhs)            adj += grid[i, j - 1] == '@';
                if (!is_rhs)            adj += grid[i, j + 1] == '@';

                if (!is_top && !is_lhs) adj += grid[i - 1, j - 1] == '@';
                if (!is_top)            adj += grid[i - 1, j] == '@';
                if (!is_top && !is_rhs) adj += grid[i - 1, j + 1] == '@';

                if (adj < 4) {
                    can++;
                    grid[i, j] = '.';
                }
            }
        }
        if (prev_can == 0 && can == 0) break;
        total += can;
    }

    cout << total << '\n';
}
