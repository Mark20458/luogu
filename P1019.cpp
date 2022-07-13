#include <algorithm>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

typedef long long ll;

int f[30];
string s[30];
int n;
int ans = 0;

int check(int i, int j) {
    int len = min(s[i].length(), s[j].length());
    int r = 1;
    while (r<=len) {
        bool p = true;
        for (int l = 0; l < r; l++) {
            char a = s[i][s[i].length() - r + l];
            char b = s[j][l];
            if (a != b) {
                p = false;
                break;
            }
        }
        if (p)
            return r;
        r++;
    }
    return 0;
}

void dfs(int sum, int p) {
    ans = max(ans, sum);
    for (int i = 0; i <= n; i++) {
        if (f[i] < 2) {
            int a = check(p, i);
            if (a != 0) {
                f[i] += 1;
                dfs(sum + s[i].length() - a, i);
                f[i] -= 1;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n + 1; i++)
        cin >> s[i];
    f[n] = 1;
    dfs(1, n);
    cout << ans;
}