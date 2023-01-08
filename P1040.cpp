#include <climits>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long ll;

const int N = 35;
ll n;
ll a[N];
ll dp[N][N]; // dp[i][j]表示中序遍历节点编号i-j的最大加分,i<=j;i==j时，dp[i][j]=a[i];
int p[N][N]; // p[i][j]记录中序遍历节点编号i-j以节点p[i][j]为根节点时才是最大加分

// 查询中序遍历节点编号l-r的最大加分
ll f(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l > r) return 1;
    ll ans = -1;
    ll temp = 0;
    int k = -1;
    for (int i = l; i <= r; i++) {
        temp = f(l, i - 1) * f(i + 1, r) + a[i];
        if (temp > ans) {
            ans = temp;
            k = i;
        }
    }
    p[l][r] = k;
    dp[l][r] = ans;
    return ans;
}

void print(int l, int r) {
    if (l > r) return;
    if (l == r) {
        cout << l << " ";
        return;
    }
    cout << p[l][r] << " ";
    print(l, p[l][r] - 1);
    print(p[l][r] + 1, r);
}

int main() {
    cin >> n;
    memset(a, 0, sizeof(a));
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    cout << f(1, n) << endl;
    print(1, n);
    return 0;
}