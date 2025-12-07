#include <cassert>
#include <set>
#include <iostream>

using namespace std;

auto main() -> int {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    size_t ans{0};
    set<size_t> beams;
    string line;

    // process start
    getline(cin, line);
    auto start = line.find('S');
    assert(start != string::npos);
    beams.emplace(start);

    while (getline(cin, line)) {
        for (auto it = begin(beams); it != end(beams);) {
            size_t beam = *it;
            assert(beam < line.size());
            if (line[beam] != '^') {
                it++;
                continue;
            }
            assert(beam + 1 < line.size());
            assert(beam - 1 >= 0);
            it = beams.erase(it);
            beams.emplace(beam + 1), beams.emplace(beam - 1);
            ans++;
        }
    }
    cout << ans << '\n';
}
