#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

constexpr size_t NUM_ITERS = 1'000;

using dist = double;

using value = size_t;

struct uf {
    uf* parent { nullptr };
    value val { numeric_limits<size_t>::max() };
    size_t sz {1};
};

uf* root(uf* node) {
    if (!node->parent) return node;
    return node->parent = root(node->parent);
}

value find(uf* node) {
    return root(node)->val;
}

// merge b into a
void merge(uf* a, uf* b) {
    uf* a_root = root(a);
    uf* b_root = root(b);
    if (a_root != b_root) {
        b_root->parent = a_root;
        a_root->sz += b_root->sz;
    }
}

struct point {
    uint64_t x { INT_MAX };
    uint64_t y { INT_MAX };
    uint64_t z { INT_MAX };

    friend ostream& operator<<(ostream& os, const point& p) {
        os << '(' << p.x << ", " << p.y << ", " << p.z << ')';
        return os;
    }
};

struct point_pair {
    size_t a;
    size_t b;
};

constexpr dist euclid(point& a, point& b) {
    dist x = (a.x - b.x) * (a.x - b.x);
    dist y = (a.y - b.y) * (a.y - b.y);
    dist z = (a.z - b.z) * (a.z - b.z);
    return sqrt(x + y + z);
}

auto main() -> int {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<point> points;
    map<dist, point_pair> dists;

    string line;
    while (getline(cin, line)) {
        uint32_t x {INT_MAX};
        uint32_t y {INT_MAX};
        uint32_t z {INT_MAX};
        char c {'_'};
        istringstream ss { line };
        ss >> x >> c >> y >> c >> z;

        size_t this_idx = points.size();
        point& this_point = points.emplace_back(x,y,z);

        for (size_t i{0}; i < points.size() - 1; i++) {
            point& other = points[i];
            dists.emplace(euclid(this_point, other), point_pair { .a = this_idx, .b = i });
        }
    }

    vector<uf*> circuits;
    for (size_t i {0}; i < points.size(); i++) {
        circuits.push_back(new uf {.parent = nullptr, .val = i});
    }

    size_t iter = NUM_ITERS;
    auto it = begin(dists);
    while (iter && it != end(dists)) {
        auto [dist, pair] = *it;
        auto [a, b] = pair;
        
        assert(a < circuits.size());
        assert(b < circuits.size());

        merge(root(circuits[a]), root(circuits[b]));
        iter--;
        it++;
    }

    map<value, size_t> circuit_sizes;
    for (uf* set : circuits) {
        root(set);
    }
    
    for (uf* set : circuits) {
        circuit_sizes[root(set)->val] = root(set)->sz;
    }

    vector<size_t> counts;
    for (auto [_, count] : circuit_sizes) {
        counts.push_back(count);
    }

    size_t ans {1};
    ranges::sort(counts);
    assert(counts.size() > 2);
    ans *= *(end(counts) - 1);
    ans *= *(end(counts) - 2);
    ans *= *(end(counts) - 3);

    cout << ans << '\n';

    for (uf* set : circuits) {
        delete set;
    }
}
