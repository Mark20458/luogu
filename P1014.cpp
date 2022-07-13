#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll i = 0;
    while (((i + 1) * (i + 2)) / 2 < n)
        i++;
    int k = n - (i * (i + 1)) / 2 - 1;
    int l = 1, c = 1;
    if (i % 2 == 0) {
        l = i + 1;
        l -= k;
        c += k;
    } else {
        c = i + 1;
        l += k;
        c -= k;
    }
    cout << l << "/" << c << endl;
}