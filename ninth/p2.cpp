#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct point {
    double x {numeric_limits<double>::signaling_NaN()};
    double y {numeric_limits<double>::signaling_NaN()};
};

double area(const point& a, const point& b) {
    return abs(a.x - b.x) * abs(a.y - b.y);
}

auto main () -> int {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<point> reds;
    double x {};
    double y {};
    char _ {','};

    while (cin >> x >> _ >> y) {
        reds.emplace_back(x ,y);
    }

    double best {numeric_limits<double>::lowest()};

    const size_t num_reds = reds.size();
    for (size_t i{0}; i < num_reds; i++ ) {
        for (size_t j{0}; j < num_reds; j++) {
            if (i == j) continue;
        }
    }
}
