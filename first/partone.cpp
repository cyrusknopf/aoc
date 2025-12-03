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

    while (cin >> dir >> mag) {
        if (dir == 'R') {
          pos += mag;
        } else {
          pos -= mag;
        }

        if (pos < 0) {
            pos = MAX + pos;
        }
        pos %= MAX;

        if (pos == 0) num_zeros++;
    }

    cout << num_zeros << '\n';
}
