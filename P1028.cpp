#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int dp[1005];

ll ans = 0;
void f(int n) {
    ans += 1;
    for (int i = 1; i <= n / 2; i++)
        f(i);
}

int main() {
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    for (int i = 4; i < 1005; i++) {
        for (int j = 1; j <= i / 2; j++)
            dp[i] += dp[j];
        dp[i]++;
    }
    cout << dp[n];
}