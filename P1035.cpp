#include <climits>
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    double k;
    cin >> k;
    double sum = 0;
    double n = 1;
    while (sum <= k) {
        sum += (1 / n);
        n++;
    }
    n--;
    cout << n << endl;
    return 0;
}