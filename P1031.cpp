#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int a[105];
    int average = 0;
    int ans = 0; // 移动次数
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        average += a[i];
    }
    average /= n;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == average) // 不需要通过编号i移动纸牌且自身也不需要移动纸牌
            continue;
        a[i + 1] += (a[i] - average);
        ans += 1;
    }
    cout << ans;
    return 0;
}