#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdint>
#include <sstream>
#include <vector>
#include <iostream>
#include <ostream>

using namespace std;

using u64 = uint64_t;

struct range {
    u64 start {INT_MAX};
    u64 count {INT_MAX};

    friend ostream& operator<<(ostream& o, range rg) {
        if (rg.count == 0) o << "[" << rg.start << ", " << "empty]";
        else o << "[" << rg.start << ", " << rg.start + rg.count - 1 << "]";
        return o;
    }

    u64 stop() { return start + count - 1; }
};

auto main() -> int {
    vector<range> ranges;
    u64 ans {0};

    u64 from {0};
    u64 to {0};
    char _ {'-'};

    string line;
    while (getline(cin, line)) {
        if (line.empty()) break;

        istringstream(line) >> from >> _ >> to;
        ranges.emplace_back(from, to - from + 1);
    }

    ranges::sort(ranges, [](range& a, range& b) {
        if (a.start != b.start) {
            return a.start < b.start;
        }
        return a.count > b.count;
    });

    u64 lower = ranges.front().start;
    u64 upper = ranges.front().stop();
    for (range& rg : ranges) {
        if (upper + 1 < rg.start) {
            ans += upper - lower + 1;
            lower = rg.start;
            upper = rg.stop();
            continue;
        }
        upper = max(upper, rg.stop());
    }
    ans += upper - lower + 1;

    cout << ans << '\n';
}
