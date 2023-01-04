/**
 * 这个题有一个坑点：
 * 输入层状态即为初始状态，不需要减去u[i]
 * 步骤就是：
 * 1.对所有神经进行拓扑排序
 * 2.按照排序进行处理
 * 3.统计需要输出的输出层神经元数量
 * 4.输出结果，结束
*/
#include <climits>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;
typedef long long ll;

const int N = 105;
int n, p; // n是神经元个数，p是边数
int c[N], u[N];
int w[N][N];
bool flag[N];
stack<int> s;

void dfs(int pre) {
    if (flag[pre])
        return;
    for (int i = 1; i <= n; i++) {
        if (w[pre][i] != INT_MAX)
            dfs(i);
    }
    flag[pre] = true;
    s.push(pre);
}

int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        cin >> c[i] >> u[i];
    int x, y;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            w[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= p; i++) {
        cin >> x >> y;
        cin >> w[x][y];
    }
    for (int i = 1; i <= n; i++)
        dfs(i);
    while (!s.empty()) {
        int i = s.top();
        // cout << i << endl; // 输出拓扑排序
        bool v = true; // 是否为输入层
        int sum = c[i];
        for (int j = 1; j <= n; j++) {
            if (w[j][i] != INT_MAX && c[j] > 0) {
                sum += (w[j][i] * c[j]);
                v = false;
            }
        }
        if (!v)
            c[i] = sum - u[i];
        // cout << i << "\t" << c[i] << endl;
        s.pop();
    }
    memset(flag, false, sizeof(flag));
    bool b;
    int r = n; // 统计输出层神经元最后状态大于0的个数
    for (int i = 1; i <= n; i++) {
        b = true;
        // cout << c[i] << "\t";
        for (int j = 1; j <= n; j++) {
            if (w[i][j] != INT_MAX || c[i] <= 0) // i可以到达j，说明i不是输出层
            {
                b = false;
                r--;
                break;
            }
        }
        flag[i] = b;
    }
    if (r == 0)
        cout << "NULL" << endl;
    else {
        for (int i = 1; i <= n; i++) {
            if (flag[i] && c[i] > 0)
                cout << i << " " << c[i] << endl;
        }
    }
    return 0;
}