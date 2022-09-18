#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ll x, y;
    cin >> x >> y;
    if (y % x != 0) {
        cout << 0;
        return 0;
    }
    ll ans = 0;
    int k = y / x;
    for (int i = 1; i <= k; i++) {
        if (k % i == 0) {
            int j = k / i;
            if (gcd(i, j) == 1)
                ans++;
        }
        // for (int j = i + 1; j <= k / i + 1; j++) {
        //     ll m = gcd(i, j);
        //     if (m == 1 && (i * j == k)) {
        //         // cout << i * x << "  " << j * x << endl;
        //         if (i != j)
        //             ans++;
        //         ans++;
        //     }
        // }
    }
    cout << ans;
}