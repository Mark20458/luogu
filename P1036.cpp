#include <climits>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

const int NUM = 25;
const int N = 1e8 + 7;
int n, k;
int x[NUM];
bool flag[NUM];
int ans = 0;

// 判断是否为素数
bool isPrime(int x) {
    int m = sqrt(x + 0.5);
    for (int i = 2; i <= m; i++)
        if (x % i == 0)
            return false;
    return true;
}

// 已经有l个相加了，结果为sum,该加第p个了
void dfs(int l, int sum, int p) {
    if (l == k) {
        if (isPrime(sum))
            ans++;
        return;
    }
    if (p == n)
        return;
    dfs(l + 1, sum + x[p], p + 1);
    dfs(l, sum, p + 1);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}