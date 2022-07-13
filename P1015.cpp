#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int N;
string M;
int n = 0;
int *a;

void f() {
    int *t = new int[150];
    int i;
    for (i = 0; i < 150; i++)
        t[i] = 0;
    for (i = 0; i < n; i++) {
        t[i] += (a[i] + a[n - 1 - i]);
        if (t[i] >= N) {
            t[i + 1]++;
            t[i] %= N;
        }
    }
    while (t[i] >= N) {
        t[i + 1]++;
        t[i] %= N;
        i++;
    }
    while (t[i] != 0)
        i++;
    n = i;
    delete[] a;
    a = t;
}

bool check() {
    for (int i = 0; i < n / 2; i++)
        if (a[i] != a[n - 1 - i])
            return false;
    return true;
}

int main() {
    cin >> N >> M;
    a = new int[150];
    n = M.length();
    for (int i = 0; i < M.length(); i++) {
        if (M[i] == 'A')
            a[i] = 10;
        else if (M[i] == 'B')
            a[i] = 11;
        else if (M[i] == 'C')
            a[i] = 12;
        else if (M[i] == 'D')
            a[i] = 13;
        else if (M[i] == 'E')
            a[i] = 14;
        else if (M[i] == 'F')
            a[i] = 15;
        else
            a[i] = (int)(M[i] - '0');
    }
    int i = 0;
    while (!check() && i <= 30) {
        f();
        i++;
    }
    if (i > 30)
        cout << "Impossible!" << endl;
    else
        cout << "STEP=" << i << endl;
}