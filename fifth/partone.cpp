#include <climits>
#include <cstdint>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

using u64 = uint64_t;

struct range {
    u64 start {INT_MAX};
    u64 count {INT_MAX};
};

auto main() -> int {

    vector<range> ranges;

    u64 from {0};
    u64 to {0};
    char _ {'-'};

    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;

        istringstream(line) >> from >> _ >> to;
        ranges.emplace_back(from, to - from + 1);
    }

    u64 ingr {0};
    u64 ans {0};
    while (cin >> ingr) {
        for (range rg : ranges) {
            if (rg.start > ingr) continue;
            if (rg.start <= ingr && ingr <= rg.start + rg.count) {
                ans++;
                break;
            }
        }
    }
    cout << ans << '\n';
}
