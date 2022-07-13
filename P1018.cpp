#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 50;

struct P {
    int a[MAX], len = 0;
    P(int k = 0) {
        a[0] = k;
        for (int i = 1; i < MAX; i++)
            a[i] = 0;
    }

    P operator*(P x) {
        P ans;
        ans.len = len + x.len - 1;
        for (int i = 0; i < x.len; i++)
            for (int j = 0; j < len; j++)
                ans.a[i + j] += (x.a[i] * a[j]);
        int d = 0;
        for (int i = 0; i < ans.len; i++) {
            ans.a[i] += d;
            d = ans.a[i] / 10;
            ans.a[i] %= 10;
        }
        while (d > 0) {
            ans.a[ans.len++] = d % 10;
            d /= 10;
        }
        return ans;
    }

    void print() {
        int i = len;
        while (i--) {
            cout << a[i];
        }
    }
};

int n, k;
char s[50];

P f(int i, int j) {
    P k;
    k.len = j - i + 1;
    int l = k.len;
    for (int l = 0; l < k.len; l++, j--)
        k.a[l] = (int)(s[j - 1] - '0');
    return k;
}

P max(P a, P b) {
    if (a.len > b.len)
        return a;
    else if (a.len < b.len)
        return b;
    int i = a.len;
    while (i--) {
        if (a.a[i] > b.a[i])
            return a;
        else if (a.a[i] < b.a[i])
            return b;
    }
    return a;
}

P dp[10][50];

int main() {
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 50; j++) {
            dp[i][j].len = 1;
            dp[i][j].a[0] = 1;
        }
    for (int i = 1; i <= n; i++)
        dp[1][i] = f(1, i);
    for (int i = 2; i <= k + 1; i++) {
        for (int j = 1; j <= i; j++)
            dp[i][i] = dp[i][i] * f(j, j);
        for (int j = i + 1; j <= n; j++) {
            for (int l = i - 1; l < j; l++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][l] * f(l + 1, j));
            }
        }
    }
    dp[k + 1][n].print();
}