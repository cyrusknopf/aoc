#include <iostream>

constexpr int MAX = 100;

using namespace std;

int main() {
    cin.tie();
    ios::sync_with_stdio(false);

    size_t num_zeros {0};

    int pos{50};
    char dir{'R'};
    int mag{0};

    auto new_pos = [&]() {
      if (dir == 'R') pos += mag;
      else pos -= mag;

      if (pos < 0) pos = MAX + pos;

      pos %= MAX;

      if (pos == 0) num_zeros++;
    };

    while (cin >> dir >> mag) {
        int x = dir == 'L' ? -1 : 1;
        // cout << pos << " -" << dir << mag;
        while (mag) {
          pos += x;
          if (pos < 0) pos = MAX + pos;
          pos %= MAX;
          mag--;
          if (pos == 0)
            num_zeros++;
        }
        // cout <<"->" << pos << '\n';
    }
    cout << num_zeros << '\n';
}
