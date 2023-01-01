#include <climits>
#include <iostream>

using namespace std;
typedef long long ll;

struct Rec {
    int lx, ly, rx, ry; // 左上角点和右上角点
    bool flag = false;  // 矩形是否被使用过（是否覆盖过点）

    // 往矩形中加点
    void add(int x, int y) {
        if (!flag) {
            lx = rx = x;
            ly = ry = y;
            flag = true;
        } else {
            if (x < lx)
                lx = x;
            else if (x > rx)
                rx = x;
            if (y < ly)
                ly = y;
            else if (y > ry)
                ry = y;
        }
    }

    // 判断点是否在矩形中
    bool inRec(int x, int y) const {
        return lx <= x && x <= rx && ly <= y && y <= ry;
    }

    // 计算面积
    int Area() {
        if (!flag)
            return 0;
        return (rx - lx) * (ry - ly);
    }

    // 判断两个矩形是否相交
    bool intersection(const Rec &r) {
        if (!flag || !r.flag)
            return false;
        return r.inRec(lx, ly) || r.inRec(rx, ry) || r.inRec(lx, ry) || r.inRec(rx, ly);
    }
};

int n, k;
Rec a[10];
int x[505], y[505];
int ans = INT_MAX; // 记录当前最佳答案

// 判断全部矩形是否相加
bool check() {
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (a[i].intersection(a[j]))
                return false;
        }
    }
    return true;
}

// 搜索第i个结点，当前所有矩形面积和为area;
void dsf(int i, int area) {
    if (area >= ans)
        return;
    if (i == n) {
        if (check())
            if (area < ans)
                ans = area;
        return;
    }
    Rec temp;
    for (int j = 0; j < k; j++) {
        temp = a[j];
        a[j].add(x[i], y[i]);
        dsf(i + 1, area + a[j].Area() - temp.Area());
        a[j] = temp;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    dsf(0, 0);
    cout << ans << endl;
    return 0;
}