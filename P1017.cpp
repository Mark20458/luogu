#include <iostream>
#include <stack>

using namespace std;

typedef long long ll;

int main() {
    int n, r;
    cin >> n >> r;
    stack<int> a;
    int i = 0;
    int m = n;
    while (n != 0) {
        int mod = n % r;
        if (mod < 0) {
            mod -= r;
            n += r;
        }
        a.push(mod);
        n /= r;
    }
    cout << m << "=";
    while (!a.empty()) {

        if (a.top() < 10)
            cout << a.top();
        else
            cout << (char)(a.top() - 10 + 'A');
        a.pop();
    }
    cout << "(base" << r << ")";
}