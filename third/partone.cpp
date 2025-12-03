#include <algorithm>
#include <functional>
#include <string>
#include <iostream>

using namespace std;

int main() {
    cin.tie();
    ios::sync_with_stdio(false);

    string bank;
    int sum {};

    while (cin >> bank) {
      char max {'0'};
      size_t maxidx{0};

      for (auto it = begin(bank); it != end(bank) - 1; it++) {
          char c = *it;
          if (c > max) {
              max = c;
              maxidx = distance(begin(bank), it);
          }
      }
      int f = max - '0';

      max = '0';
      for (auto it = begin(bank) + maxidx + 1; it != end(bank); it++) {
          char c = *it;
          if (c > max) max = c;
      }

      int s = max - '0';

      sum+= f * 10 + s;

      // cout << bank << '\n';
      // cout << f << ' ' << s << '\n';
    }
    cout << sum << '\n';
}
