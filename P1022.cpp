#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
string s;

int main() {
    cin >> s;
    int i = 0;
    double a = 0, b = 0;
    bool k, l;
    char r;
    while (s[i] != '=') {
        k = true, l = false;
        if (s[i] == '-') {
            k = false;
            i++;
        }
        if (s[i] == '+') {
            k = true;
            i++;
        }
        string p;
        while (s[i] != '=' && s[i] != '+' && s[i] != '-') {
            if (s[i] < '0' || s[i] > '9') {
                r = s[i];
                l = true;
                if (p.size() == 0)
                    p = "1";
            } else {
                p += s[i];
            }
            i++;
        }
        int t = stoi(p);
        if (!k)
            t = -t;
        if (l)
            a += t;
        else
            b += t;
    }
    i++;
    double c = a, d = b;
    a = 0, b = 0;
    while (i < s.length()) {
        k = true, l = false;
        if (s[i] == '-') {
            k = false;
            i++;
        }
        if (s[i] == '+') {
            k = true;
            i++;
        }
        string p;
        while (s[i] != '\0' && s[i] != '+' && s[i] != '-') {
            if (s[i] < '0' || s[i] > '9') {
                r = s[i];
                l = true;
                if (p.size() == 0)
                    p = "1";
            } else {
                p += s[i];
            }
            i++;
        }
        int t = stoi(p);
        if (!k)
            t = -t;
        if (l)
            a += t;
        else
            b += t;
    }
    double ans = (b - d) / (c - a);
    if (ans == 0)
        ans = abs(ans);
    printf("%c=%.3lf", r, ans);
}