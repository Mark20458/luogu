/**
 * 这道题就是先求出每个数字可以直接和间接转变的数字种类
 * 然后根据字符串把每个可以变化的相乘即可
*/
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;
typedef long long ll;

const int N = 16;
int k;
string n;
int x[N], y[N];
set<int> s[15];
bool flag[N];

struct BigInt {
    int a[100];
    const static int mod = 10000;
    int n = -1;

    // 只能初始化一个小于mod的数
    BigInt(int x) {
        n = 0;
        a[0] = x;
    }

    void mul(int k) {
        int p = 0;
        for (int i = 0; i <= n; i++) {
            p += (a[i] * k);
            a[i] = p % mod;
            p /= mod;
        }
        while (p != 0) {
            n++;
            a[n] = p % mod;
            p /= mod;
        }
    }

    void printf() {
        for (int i = n; i >= 0; i--)
            if (i != n)
                std::printf("%04d", a[i]);
            else
                cout << a[i];
    }
};

// 宽度优先搜索x[o]可以的变化
void bfs(int o) {
    memset(flag, false, sizeof(flag));
    int l = x[o];
    flag[l] = true;
    s[l].insert(l);
    queue<int> q;
    s[l].insert(y[o]);
    q.push(y[o]);
    flag[y[o]] = true;
    while (!q.empty()) {
        int a = q.front();
        for (int i = 0; i < k; i++) {
            if (!flag[y[i]] && (x[i] == a || x[i] == l)) {
                flag[y[i]] = true;
                s[l].insert(y[i]);
                q.push(y[i]);
            }
        }
        q.pop();
    }
}

int main() {
    cin >> n >> k;
    memset(x, 0, sizeof(x));
    memset(y, -1, sizeof(y));
    for (int i = 0; i < k; i++)
        cin >> x[i] >> y[i];
    // 获取所有变化
    for (int i = 0; i < k; i++)
        bfs(i);
    // for (int i = 0; i <= 9; i++)
    //     cout << s[i].size() << endl;
    BigInt ans(1);
    for (int i = 0; i < n.length(); i++) {
        if (s[n[i] - '0'].size() != 0)
            ans.mul(s[n[i] - '0'].size());
    }
    ans.printf();
}