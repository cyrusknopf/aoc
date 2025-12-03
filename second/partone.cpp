#include <cstdint>
#include <iostream>

using num = uint64_t;

using namespace std;

/*
an n digit number, y, is invalid if
it is even

let x be a n / 2 digit number

y = (x * 10 ^ (n / 2)) + x

y = x(10^(n/2) + 1)

y = 1010, n = 4

1010 / (10^(4/2) + 1)
*/

int main() {
  cin.tie();
  ios::sync_with_stdio(false);

  num start {};
  char dash {'-'};
  num end {};

  size_t ans {0};
  // x = y / (10^(n / 2) + 1)
  while (cin >> start >> dash >> end) {
    for (num y = start; y <= end; y++) {
      size_t n = to_string(y).size();

      if (n % 2 != 0) continue;
      if (y % (int)(pow(10, n / 2) + 1) == 0) {
        ans += y;
      }
    }
  }
  cout << ans << '\n';
}
