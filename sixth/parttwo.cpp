#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include <sstream>

using namespace std;

constexpr size_t NUM_ROWS = 4;

using num = uint64_t;

auto main () -> int {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string line;
    num ans {0};
    vector<vector<char>> lines;

    ssize_t lineptr{-1};
    while (lineptr++, getline(cin, line)) {
        lines.emplace_back();

        for (char c : line)  lines[lineptr].emplace_back(c);
    }

    size_t len = lines.front().size();
    assert(all_of(begin(lines), end(lines) - 1, [len](auto&& line) { return line.size() == len; }));

    vector<vector<num>> equations(1);
    size_t eq_ptr {0};

    for (size_t col{0}; col < len; col++) {
        if (all_of(begin(lines), end(lines) - 1, [col](auto&& line) { return line[col] == ' '; })) {
            eq_ptr++;
            equations.emplace_back();
            assert(eq_ptr == equations.size() - 1);
            continue;
        }

        equations[eq_ptr].emplace_back();
        for (size_t row{0}; row < NUM_ROWS; row++) {
            if (lines[row][col] == ' ') continue;
            equations[eq_ptr].back() *= 10;
            equations[eq_ptr].back() += lines[row][col] - '0';
        }
    }

    string ops(begin(lines.back()), end(lines.back()));
    istringstream operators(ops);
    
    char optor {'\0'};
    size_t eq {0};
    while (operators >> optor) {
        auto& equation = equations[eq];
        if (optor == '*') {
            num total = reduce(begin(equation), end(equation), 1ULL, multiplies<num>{});
            ans += total;
        } else if (optor == '+') {
            num total = reduce(begin(equation), end(equation), 0ULL, plus<num>{});
            ans += total;
        } else abort();

        eq++;
    }

    cout << ans << '\n';
}
