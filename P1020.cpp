#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a[100005];
int r[100005];
int dp[100005];
int n = 0;
int len = 0;

void reset() {
    memset(r, 0, sizeof(r));
    r[0] = a[0];
    len = 1;
}

int LIS() {
    reset();
    for (int i = 1; i < n; i++) {
        if (a[i] > r[len - 1])
            r[len++] = a[i];
        else {
            int lo = 0, hi = len - 1;
            while (lo < hi) {
                int mid = (lo + hi) >> 1;
                if (a[i] <= r[mid]) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            r[lo] = a[i];
        }
    }
    return len;
}

int LNIS() {
    reset();
    for (int i = 1; i < n; i++) {
        if (a[i] <= r[len - 1])
            r[len++] = a[i];
        else {
            int lo = 0, hi = len - 1;
            while (lo < hi) {
                int mid = (lo + hi) >> 1;
                if (a[i] > r[mid]) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            r[lo] = a[i];
        }
    }
    return len;
}

int main() {
    int k;
    while (cin >> k) {
        a[n++] = k;
    }
    cout << LNIS() << endl;
    cout << LIS();
}
