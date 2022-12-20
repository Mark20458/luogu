#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

string p; //前序遍历
string m; //中序遍历
string n; //后序遍历

bool flag[10];

void f(int s, int e) {
    if (s >= e) {
        return;
    }
    int max = -1; //中序遍历[s::e]中和m相同的最大序号
    int idx = 0;
    for (int i = s; i < e; i++) {
        for (int j = 0; j < n.length(); j++) {
            if (m[i] == n[j]) {
                if (j > max) {
                    max = j;
                    idx = i;
                }
                continue;
            }
        }
    }
    // cout << max << "\t" << idx << m[idx] << endl
    p += m[idx];
    f(s, idx);
    f(idx + 1, e);
}

int main() {
    cin >> m >> n;
    f(0, m.length());
    cout << p;
}