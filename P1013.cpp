#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    string a[15][15];
    int n;
    cin >> n;
    string l;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    int t = 0;
    for (int i = 2; i <= n; i++) {
        t = 0;
        for (int j = 2; j <= n; j++)
            if (a[i][j].length() == 2)
                t++;
        a[i][0] = a[0][i] = to_string(t);
        if (t == 1)
            l = a[i][1];
    }
    int k = n - 1;
    int ans;
    bool f;
    string s;
    for (int i = 2; i <= n; i++) {

        f = true;
        for (int j = 2; j <= n; j++) {
            s = "";
            ans = a[i][0][0] + a[0][j][0] - '0' - '0';
            if (ans >= k) {
                ans %= k;
                s += l;
            }
            string c = to_string(ans);
            for (int i = 1; i <= n; i++) {
                if (a[0][i] == c) {
                    s += a[1][i];
                    break;
                }
            }
            if (s.compare(a[i][j]) != 0) {
                f = false;
                break;
            }
        }
        if (!f) {
            cout << "ERROR!" << endl;
            return 0;
        }
    }
    for (int i = 2; i <= n; i++)
        cout << a[1][i] << "=" << a[0][i] << " ";
    cout << endl;
    cout << k << endl;
}