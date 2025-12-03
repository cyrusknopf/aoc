#include <cstdint>
#include <iostream>

using num = uint64_t;

using namespace std;

int main() {
  cin.tie();
  ios::sync_with_stdio(false);

  num start {};
  char dash {'-'};
  num end {};

  size_t ans {0};
  while (cin >> start >> dash >> end) {
    string pattern;
    string out;

    for (num y = start; y <= end; y++) {
      auto ys = to_string(y);
      size_t n = ys.size();

      for (size_t cs = 1; cs <= n / 2; cs++) {
        out.clear();
        pattern.clear();

        if (n % cs != 0) {
          continue;
        }

        size_t nc = n / cs;
        pattern = ys.substr(0, cs);

        for (size_t i{1}; i <= nc; i++) {
          out += pattern;
          if (out != ys.substr(0, cs * i)) {
            break; // doesnt match
          }
        }

        if (out == ys) {
          ans += y;
          break; // dont count this y more than once
        }
      }
    }
  }
  cout << ans << '\n';
}
