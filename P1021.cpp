#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 1000000;
int dp[1005]; // dp[i]含义：邮资为i时，最少需要dp[i]张邮票
int N, K;
int a[21], b[21]; //邮票的面值；a是dfs遍历存储，b是暂存答案
int ans = 0;

// 当目前确定邮票的种类为now时求MAX
int solve(int now) {
    memset(dp, MAX, sizeof(dp));
    dp[0] = 0;
    int i = 0;
    do {
        i++;
        for (int j = 1; j < now && a[j] <= i; j++) // 单张邮票价格不大于总价格
            dp[i] = min(dp[i], dp[i - a[j]] + 1);
    } while (dp[i] <= N);
    i--;           // 因为dp[i]>N,所以需要i--
    if (i > ans) { //暂存答案
        for (int i = 1; i <= now; i++)
            b[i] = a[i];
        ans = i;
    }
    return i;
}

void dfs(int k) {
    int g = solve(k); // 获取当前邮票能组成连续的最大值
    if (k == K + 1)   //邮票种类够了
        return;
    /*  显然当前需要确定邮票的价格是大于上一张有邮票的价格
        而且为了连续，价格不能大于g+1，否则无法组成g+1，
        所以当前邮票的价格范围只能是[a[k-1]+1,g+1];
    */
    for (int i = a[k - 1] + 1; i <= g + 1; i++) {
        a[k] = i;
        dfs(k + 1);
    }
}

int main() {
    cin >> N >> K;
    a[1] = 1; //第一张邮票必须是1，否则无法组成1
    dfs(2);
    for (int i = 1; i <= K; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
    cout << "MAX=" << ans;
}