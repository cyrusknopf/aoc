#include <cassert>
#include <set>
#include <map>
#include <iostream>

using namespace std;

auto main() -> int {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    size_t ans{0};
    map<size_t, size_t> beams;
    string line;

    // process start
    getline(cin, line);
    auto start = line.find('S');
    assert(start != string::npos);
    beams.emplace(start, 1);

    while (getline(cin, line)) {
        for (auto it = begin(beams); it != end(beams);) {
            auto [beam, worlds] = *it;
            if (line[beam] != '^') {
                it++;
                continue;
            }
            it = beams.erase(it);
            beams[beam + 1] += worlds;
            beams[beam - 1] += worlds;
        }
    }
    for (auto [beam, worlds] : beams) {
        ans += worlds;
    }
    cout << ans << '\n';
}
