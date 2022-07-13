#include <iostream>

long long p = 1e18; //作mod用
struct int128 {
    long long hig = 0;
    long long low = 0;

    int128 operator+(int128 &a) {
        int128 k;
        k.low = low + a.low;
        k.hig = (k.low / p) + a.hig + hig;
        k.low %= p;
        return k;
    }

    int128 operator*(int a) {
        int128 k;
        k.low = a * low;
        k.hig = a * hig + (k.low / p);
        k.low %= p;
        return k;
    }
};

int n, m;

int128 ans, f[85][85], a[85];

int128 max(int128 a, int128 b) {
    if (a.hig > b.hig) return a;
    if (a.hig < b.hig) return b;
    if (a.low > b.low) return a;
    if (a.low < b.low) return b;
    return a;
}

int main() {
    scanf("%d%d", &n, &m);
    while (n--) {
        for (int i = 1; i <= m; i++)
            scanf("%lld", &a[i].low);
        for (int l = m; l > 0; l--)
            for (int r = l; r <= m; r++)
                f[l][r] = max(f[l + 1][r] + a[l], f[l][r - 1] + a[r]) * 2;
        ans = ans + f[1][m];
    }
    if (ans.hig == 0)
        printf("%lld", ans.low);
    else
        printf("%lld%018lld\n", ans.hig, ans.low);
}