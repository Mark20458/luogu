#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

string str;
string word[10];
int p, k, s;
int sum[207][207], dp[207][45];

void read() {
    cin >> p >> k;
    string t;
    for (int i = 0; i < p; i++) {
        cin >> t;
        str += t;
    }
    cin >> s;
    for (int i = 0; i < s; i++)
        cin >> word[i];
}

//判断是否有单词以s[l]为开头
bool check(int l, int r) {
    if (l > r)
        return false;
    string x = str.substr(l, r - l + 1); //取出字符串,防止找字符时超出了[l,r]的范围
    for (int i = 0; i < s; i++)
        if (x.find(word[i]) == 0)
            return true; //查找
    return false;
}

// 求sum数组
void f() {
    int m = str.length() - 1;
    for (int j = m; j >= 0; j--)
        for (int i = j; i >= 0; i--) {
            sum[i][j] = sum[i + 1][j];
            if (check(i, j))
                sum[i][j]++;
        }
}

// 求dp数组
void solve() {
    f();
    for (int i = 1; i <= k; i++)
        dp[i][i] = dp[i - 1][i - 1] + sum[i][i];
    for (int i = 0; i < 207; i++)
        dp[i][1] = sum[0][i];
    for (int j = 2; j <= k; j++) {
        for (int i = 0; i < str.length(); i++) {
            if (i < j)
                dp[i][j] = 0;
            else
                for (int l = j - 1; l < i; l++)
                    dp[i][j] = max(dp[i][j], dp[l][j - 1] + sum[l + 1][i]);
        }
    }
    // 输出答案
    cout << dp[str.length() - 1][k] << endl;
}

int main() {
    read();
    solve();
    // for (int i = 0; i < str.length(); i++) {
    //     for (int j = 0; j < str.length(); j++) {
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // for (int j = 1; j <= k; j++) {
    //     for (int i = 0; i < str.length(); i++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}