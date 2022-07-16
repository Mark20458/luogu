#include <iostream>

using namespace std;

typedef long long ll;

int n, k;

// dfs搜索
int ans = 0;
void dfs(int sum, int t, int x) {
    if (x == k && sum == n) {
        ans++;
        return;
    }
    if (x < k && sum < n) {
        for (int i = t; i <= n - sum; i++) {
            dfs(sum + i, i, x + 1);
        }
    }
}

int main() {
    cin >> n >> k;
    dfs(0, 1, 0);
    cout << ans;
}