#include <climits>
#include <cstdint>
#include <string>
#include <iostream>

constexpr size_t NUM_DIGITS = 12;

using namespace std;

int main() {
    cin.tie();
    ios::sync_with_stdio(false);

    string bank;
    uint64_t sum {};

    while (cin >> bank) {
        auto start = begin(bank);
        auto stop = end(bank) - NUM_DIGITS + 1;

        for (size_t digit {0}; digit < NUM_DIGITS; digit++) {
          char max{'0'};
          size_t idx{0};
          auto it = start;
          size_t i = 0;
          for (; it != stop; it++, i++) {
            // cout << "considering " << *it << '\n';
            if (*it > max) {
              max = *it;
              idx = distance(begin(bank), it);
            }
          }
          // cout << "chose " << max << '\n';

          uint64_t addend = (max - '0') * pow(10, (double)NUM_DIGITS - digit-1);
          sum+= addend;
          // cout << "adding " << addend << '\n';
          start = begin(bank) + idx + 1;
          stop++;
        }
    }
    cout << sum << '\n';
}
