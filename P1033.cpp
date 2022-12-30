#include <cmath>
#include <iostream>

using namespace std;

const double g = 10;
double h, s, v, l, k, n;
double t1, t2;
int k1, k2;

int main() {
    cin >> h >> s >> v >> l >> k >> n;
    t1 = sqrt(2 * (h - k) / g);
    t2 = sqrt(2 * h / g);
    k1 = s + l - t1 * v;
    k2 = s - t2 * v;
    cout << min(k1, int(n)) - max(k2, 0);
    return 0;
}