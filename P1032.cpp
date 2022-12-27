#include <iostream>
#include <map>
#include <queue>
#include <string>

using namespace std;

string a, b, x[10], y[10];
int len = 1;     // 变换规则个数
queue<string> q; // 转换字符串
queue<int> l;    // 转换步骤数
map<string, int> maps;

// 宽度优先搜索
int bfs() {
    string s, ss;
    // (没有转换字符串 转换步骤数最小值也大于10 转换成功)搜索结束
    while (!q.empty() && l.front() <= 10 && q.front() != b) {
        if (maps[q.front()] == 1) {
            q.pop();
            l.pop();
            continue;
        }
        maps[q.front()] = 1;
        for (int i = 1; i <= len; i++) {
            s = q.front();
            while (1) {
                int m = s.find(x[i]);
                // 如果没有找到
                if (m == -1)
                    break;
                ss = q.front();
                q.push(ss.replace(m, x[i].size(), y[i]));
                l.push(l.front() + 1);
                s[m] = '~';
            }
        }
        q.pop();
        l.pop();
    }
    if (l.front() > 10 || q.empty())
        return -1;
    else
        return l.front();
}

int main() {
    cin >> a >> b;
    len = 1;
    while (cin >> x[len] >> y[len])
        len++;
    len--;
    if (len == 0 && a != b) {
        cout << "NO ANSWER!";
        return 0;
    }
    q.push(a);
    l.push(0);
    int ans = bfs();
    if (ans == -1)
        cout << "NO ANSWER!";
    else
        cout << ans << endl;
    return 0;
}