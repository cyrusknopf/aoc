#include <cassert>
#include <climits>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include <sstream>

using namespace std;

using num = uint64_t;

auto main () -> int {
    string line;
    vector<vector<num>> operations;
    vector<char> operators;

    while (getline(cin, line)) {
        size_t idx {0};
        istringstream iss{line};

        {
            num operand{INT_MAX};
            while (iss >> operand) {
                if (operations.size() <= idx) {
                    operations.emplace_back();
                    assert(operations.size() == idx + 1);
                }
                operations[idx].push_back(operand);
                idx++;
            }
        }

        iss.clear();
        iss >> ws;
        operators.resize(operations.size());

        {
            char operator_{'_'};
            while (iss >> operator_) {
                assert(idx < operations.size());
                operators[idx] = operator_;
                idx++;
            }
        }
    }

    assert(operations.size() == operators.size());

    num ans {0};
    for (size_t i {0}; i < operations.size(); i++) {
        if (operators[i] == '+')
            ans += reduce(begin(operations[i]), end(operations[i]), 0ULL, std::plus<num>{});
        else
            ans += reduce(begin(operations[i]), end(operations[i]), 1ULL, std::multiplies<num>{});
    }
    cout << ans << '\n';
}
