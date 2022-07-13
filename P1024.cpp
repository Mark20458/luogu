#include <cstdio>

using namespace std;

double a, b, c, d;

double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

double check(double x) {
    double hi = x + 1, lo = x;
    while (hi - lo >= 0.001) {
        double mid = (lo + hi) / 2;
        if (f(hi) * f(mid) <= 0) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    int num = 0;
    double x1, x2, l;
    for (int i = -100; i <= 100 && num <= 3; i++) {
        x1 = f(i);
        x2 = f(i + 1);
        l = i;
        if (x1 == 0) {
            printf("%.2lf ", l);
            num++;
            continue;
        }
        if (x1 * x2 < 0) {
            printf("%.2lf ", check(l));
            num++;
        }
    }
}