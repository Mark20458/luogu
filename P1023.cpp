#include <iostream>

using namespace std;

typedef long long ll;

int expect, down;
int a[100005][2];

int main() {
    cin >> expect;
    int i = 0;
    while (cin >> a[i][0] >> a[i][1] && a[i][0] != -1 && a[i][1] != -1) {
        if (i > 0 && a[i][0] - a[i - 1][0] > 1) {
            int k = (a[i][1] - a[i - 1][1]) / (a[i][0] - a[i - 1][0]);
            int temp = a[i][0];
            int y = a[i][1];
            for (int j = a[i - 1][0] + 1; j <= temp; j++) {
                a[i][0] = j;
                a[i][1] = a[i - 1][1] + k;
                i++;
            }
        } else
            i++;
    }
    i--;
    cin >> down;
    int x = a[i][1];
    while (x > down) {
        a[i + 1][0] = a[i][0] + 1;
        a[i + 1][1] = x - down;
        x = a[i + 1][1];
        i++;
    }
    int num, price, p, max;
    for (int j = 0; j <= 100000; j++) {
        max = -9999;
        for (int k = 0; k <= i; k++) {
            num = (a[k][0] - a[0][0] + j) * a[k][1];
            if (num > max) {
                max = num;
                price = a[k][0];
                p = 1;
            } else if (num == max && a[k][0] == expect)
                price = a[k][0];
        }
        if (price == expect) {
            cout << j * p << endl;
            return 0;
        }
        max = -9999;
        for (int k = 1; k <= i; k++) {
            num = (a[k][0] - a[0][0] - j) * a[k][1];
            if (num > max) {
                max = num;
                price = a[k][0];
                p = -1;
            } else if (num == max && a[k][0] == expect)
                price = a[k][0];
        }
        if (price == expect) {
            cout << j * p << endl;
            return 0;
        }
    }
    cout << "NO SOLUTION" << endl;
}